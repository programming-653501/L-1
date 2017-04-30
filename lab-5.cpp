#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

class Node {
public:
	Node*next;
	Node*head;
	long long int value;
	bool hasNext() { return head != NULL; }
	Node() {
		head = NULL;
		next = head;
	}
};

void add(int value, Node*&Stack)
{
	Node* temp = new Node();
	temp->value = value;
	temp->next = Stack->head;
	Stack->head = temp;
}

Node pop(Node*&Stack)
{
	Node*node = new Node();
	node = Stack->head;
	Stack->head = Stack->head->next;
	return *node;
}

void showElem(Node*&Stack)
{
	Node*current = Stack->head;
	int index = 0;
	while (current != NULL)
	{
		cout <<++index<<" "<< current->value << "\n";
		current = current->next;
	}
}

Node* merge(Node*&Stack1, Node*&Stack2, Node*&Result)
{
	if ((!Stack1->hasNext()) && (!Stack2->hasNext()))
	{
		return Result;
	}
	Node* node1 = Stack1->head;
	Node* node2 = Stack2->head;
	if (node2 != NULL&&node1 != NULL)
	{
		if (node1->value > node2->value) { add(node1->value, Result); pop(Stack1); }
		else if (node1->value < node2->value) { add(node2->value, Result); pop(Stack2); }
		else {
			add(node1->value, Result);
			int value = node1->value;
			while (value == node2->value)
			{
				node2 = node2->next;
				pop(Stack2);
				if (node2 == NULL)break;
			}
			while (value == node1->value)
			{
				node1 = node1->next;
				pop(Stack1);
				if (node1 == NULL)break;
			}
		}
	}
	else if (node2 != NULL&&node1 == NULL)
	{
		int value = node2->value;
		while (value == node2->value&&node2->next!=NULL)
		{
			node2 = node2->next;
			pop(Stack2);
		}
		add(node2->value, Result); pop(Stack2);
	}
	else if (node1 != NULL&&node2 == NULL)
	{
		int value = node1->value;
		while (value == node1->value&&node1->next != NULL)
		{
			node1 = node1->next;
			pop(Stack1);
		}
		add(node1->value, Result); pop(Stack1);
	}
	return merge(Stack1, Stack2, Result);
}

int main(void)
{
	Node*Stack1 = new Node();
	Node*Stack2 = new Node();
	cout << "Enter the values of the first stack: \n";
	while (cin.peek()!='\n')//13 - код клавиши энтер
	{
		long long int n;
		cin >> n;
		Node* new_node = new Node();
		new_node->next = Stack1->head;
		Stack1->head = new_node;
		Stack1->head->value = n;
	}

	showElem(Stack1);

	cout << "Enter the values of the second stack: \n";
	cin.ignore();
	cin.clear();
	while (cin.peek() != '\n')//13 - код клавиши энтер
	{
		long long int n;
		cin >> n;
		Node* new_node = new Node();
		new_node->next = Stack2->head;
		Stack2->head = new_node;
		Stack2->head->value = n;
	}
	
	showElem(Stack2);
	
	Node*ResultStack = new Node();

	merge(Stack1, Stack2, ResultStack);
	
	cout << "\n\n---------------------------------------------------------------------------\n\nResulting Stack\n";

	showElem(ResultStack);

	_getch();
	return 0;
}
