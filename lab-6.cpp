#include <iostream>
#include<vector>
#include<exception>
#include<algorithm>
using namespace std;


class Node{
public:
    Node*l,*r;
    int val;
    Node(int _val){
        val=_val;
        l=r=NULL;
    }
};

void print(Node* node){
    if(!node){
        return;
    }
    else{
        print(node->l);
        cout<<node->val<<" ";
        print(node->r);
    }
}

void addNewNode(int _val, Node* &node)
{
    if(node){
        if(node->val>_val){
            if(!node->l)
            {
                node->l=new Node(_val);
            }
            else
            {
                addNewNode(_val, node->l);
            }
        }
        else if(node->val<_val){
            if(!node->r)
            {
                node->r=new Node(_val);
            }
            else {
                addNewNode(_val, node->r);
            }
        }
        else return;
    }
    else
    {
        node=new Node(_val);
        return;
    }
}

void buildBST(Node* &node, int*a, int l, int r, int n)
{
    int mid = (l+r)/2;
    if(l>=r){
        if(l==r)
        addNewNode(a[mid], node);
        return;
    }
    addNewNode(a[mid], node);
    buildBST(node->l,a,l,mid-1,n);
    buildBST(node->r,a,mid+1,r,n);
}

void convertFromTreeToArray(Node* &node, int* &a, int&n){
    if(!node){
        return;
    }
    convertFromTreeToArray(node->l, a, n);
    n++;
    a = (int*)realloc(a,sizeof(int)*n);
    a[n-1]=node->val;
    convertFromTreeToArray(node->r, a, n);
}

void addRightOrLeftNode(Node* &parent, Node* son, bool right){
    if(right){
        parent->r = son;
    }
    else
    {
        parent->l = son;
    }
}

void convertFromSimpleTreeToBST(Node* &simpletree, Node* &resultBST){
    int n = 0, *a = new int[n];
    convertFromTreeToArray(simpletree,a,n);
    sort(&a[0],&a[n]);
    buildBST(resultBST,a,0,n-1,n);
}

void buildSomeTree(int n, Node* &tree)
{
    int *u1 = new int[n], *u2 = new int[n], *val1 = new int[n], *vals = new int[n];
    bool* right = new bool[n];
    Node **nodes = new Node*[n], **nodes2 = new Node*[n];
    cout<<"Enter the value for the root:\n";
    int val=0;
    cin>>val;
    nodes[0] = new Node(val);
    for (int i = 0; i < n; i++) {
        cin>>u1[i]>>u2[i]>>vals[i]>>right[i];
        u1[i]--; u2[i]--;
        nodes[u2[i]] = new Node(vals[i]);
        addRightOrLeftNode(nodes[u1[i]],nodes[u2[i]],right[i]);
    }
    tree = nodes[0];
}

int main(void)
{
    Node* tree = NULL, *resultBST=NULL;
    cout<<"Enter the number of vertixes in a tree\n";
    int n;
    cin>>n;
    buildSomeTree(n-1, tree);
    print(tree);
    n = 0;
    int*a=new int[n];
    convertFromSimpleTreeToBST(tree,resultBST);
    cout<<"\nBinary search tree:\n";
    print(resultBST);
    return 0;
}