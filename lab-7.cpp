#include <iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include<conio.h>

using namespace std;

class User{
public:
    int sum;
    string name, surname, password;
    User()
    {
        sum=0;
        name=surname=password="";
    }
};

fstream inputFile, outputFile;


void error(int param)
{
    switch(param)
    {
        case 1:
            std::cerr << "Error: List is empty" << std::endl;
            exit(1);
    }
}

struct Node
{
    User user;
    Node* next;
    Node* prev;
};

class List
{
public:
    List();
    void push_back(User);
    void push_front(User);
    User pop_back();
    User pop_front();
    bool is_empty();
    bool search(User&);
    void print();
    void remove(User&);
    bool changesum(User&,int);
    ~List();
    Node* head;
};

void List::remove(User& user)
{
    Node*cur = head;
    while(cur)
    {
        if(user.name==cur->user.name&&user.surname==cur->user.surname)
        {
            break;
        }
        cur = cur ->next;
    }
    if(!head)return;
    if(cur->next!=0) {
        cur->next->prev = cur->prev;
    }
    if(cur->prev!=0)
        cur->prev->next=cur->next;
}

bool List::search(User& user)
{
    bool res = false;
    Node*cur = head;
    while(cur)
    {
        if(user.name==cur->user.name&&user.surname==cur->user.surname)
        {
            res=true;
            user.password=cur->user.password;
            user.sum=cur->user.sum;
            break;
        }
        cur = cur ->next;
    }
    return res;
}

bool List::changesum(User&user, int sum)
{
    bool res = true;
    Node*cur = head;
    while(cur)
    {
        if(user.name==cur->user.name&&user.surname==cur->user.surname)
        {
            if(cur->user.sum+sum<0)
            {
                cout<<"\nUnable to change sum.\n";
                res = false;
                break;
            }
            else{
                cur->user.sum+=sum;
            }
        }
        cur = cur ->next;
    }
    return res;
}

void List::print()
{
    if(is_empty())
    {
        std::cout << "***List is empty***" << std::endl;
    }
    else
    {
        Node* cur = head;
        while(cur)
        {
            std::cout <<"\t"<< cur->user.name << " | "<< cur->user.surname << " | " << cur->user.password << " | " << cur->user.sum << std::endl;
            cur = cur ->next;
        }
    }
}

List::List()
{
    head = 0;
}

List::~List()
{
    if(!is_empty())
    {
        while(head->next)
        {
            head = head->next;
            delete head->prev;
        }
        delete head;
    }
}

bool List::is_empty()
{
    return !head;
}

void List::push_back(User usr)
{
    if(is_empty())
    {
        Node* tmp = new Node;
        tmp->user = usr;
        tmp->prev = 0;
        tmp->next = 0;
        head = tmp;
    }
    else
    {
        Node* cur = head;
        while(cur->next)
            cur = cur->next;
        Node* tmp = new Node;
        tmp->user = usr;
        tmp->prev = cur;
        tmp->next = 0;
        cur->next = tmp;
    }
}

User List::pop_back()
{
    if(is_empty())
        error(1);
    else
    {
        Node* cur = head;
        while(cur->next)
            cur = cur->next;
        User temp = cur->user;
        if(!(cur->prev))
            head = 0;
        else
            cur->prev->next = 0;
        delete cur;
        return temp;
    }
}

void List::push_front(User usr)
{
    if(is_empty())
    {
        push_back(usr);
    }
    else
    {
        Node* tmp = new Node;
        tmp->user = usr;
        tmp->next = head;
        tmp->prev = 0;
        head->prev = tmp;
        head = tmp;
    }
}

User List::pop_front()
{
    if(is_empty())
        error(1);
    else
    {
        User temp = head->user;
        Node* tmp = head;
        head = tmp->next;
        if(head)
            head->prev = 0;
        delete tmp;
        return temp;
    }
}

int convertToInt(string s)
{
    int res=0;
    for (int i = s.size()-1; i >=0 ; i--) {
        res+=(int)((int)(s[i]-48)*pow(10,s.size()-1-i));
    }
    return res;
}

vector<string> parseString(string s)
{
    vector<string> res;
    int i=0;
    int j=0;
    while(i!=s.size())
    {
        if(s[i]==' '&&s[j]!=' '){
            res.push_back(s.substr(j,i-j));
            j=i+1;
        }
        i++;
        if(i==s.size()-1&&s[i]!=' '&&s[j]!=' ')
        {
            res.push_back(s.substr(j,i-j+1));
        }
    }
    return res;
}

void printmenue(){
    cout<<"press 1 to view the list of users\n";
    cout<<"press 2 to add user (this option works only if you are admin)\n";
    cout<<"press 3 to make a transaction to another user\n";
    cout<<"press 4 to get money from somebodies account (this also works only if you are admin)\n";
    cout<<"press 5 to remove user (this option works only if you are admin)\n";
    cout<<"press 6 to log out\n";
}

bool signin(List &list, User&user)
{
	cout<<"Do you want to continue (y/n)?\n(press y to exit)";
	char a;
	while(true){
		cin>>a;
		if(a=='y'){
			system("cls");
			break;
		}
		else if(a=='n')exit(0);
		else {
			cout<<"wrong input, try again:\n";
			continue;
		}
	}
    cout<<"Authorisation:\nPlease, enter your first name:";
    cin>>user.name;
    cout<<"\nPlease, enter your surname:";
    cin>>user.surname;
    cout<<"\nPlease, enter your password:";
    string password;
    cin>>password;

    if(!list.search(user))
        return false;

    if(user.password!=password)
        return false;

    cout<<"You signed in sccessfully! Press Enter to continue!\n";
	getch();
	system("cls");
    return true;
}

int main()
{
    List users;
    inputFile.open("input.txt",ios::in);
    string str;
    while(getline(inputFile,str))
    {
    	try{
        User user;
        user.name=parseString(str)[0];
        user.surname=parseString(str)[1];
        user.password=parseString(str)[2];
        user.sum=convertToInt(parseString(str)[3]);
        users.push_back(user);
        }catch(exception e){
    	
		}
    }
    inputFile.close();
    cout<<"\t\t\tDATABASE\n";
    cout<<"\tNAME | SURNAME | PASSWORD | SCORE\n";
    users.print();
	
	cout<<"\n\nYou can choose one of this characters to sign in. Admin is super user - \n"<<
	"you are allowed to use all options by using this account: we recommend to use \nhim\n";
	
	getch();
	system("cls");
	
    User current_user;

    bool start = true;

    while(start)
    {
        bool run = false, exit = false;
        if(signin(users,current_user))
            run = true;

        while(run)
        {
            char a;
            printmenue();
            cin>>a;
            if(a == '1') {
				system("cls");
			    cout<<"\t\t\tDATABASE\n";
			    cout<<"\tNAME | SURNAME | PASSWORD | SCORE\n";
                users.print();
                getch();
				system("cls");
            }
            else if(a == '2') {
				system("cls");
                if (current_user.name != "admin"){
                    cout<<"You can't use this option\n";
                    getch();
				    system("cls");
                }
                else
                {
	                User user;
	                cout << "Enter the name of user:\n";
	                cin >> user.name;
	                cout << "Enter the surname of user:\n";
	                cin >> user.surname;
	                cout << "Enter the password of user:\n";
	                cin >> user.password;
	                cout << "Enter the sum of user:\n";
	                cin >> user.sum;
	                inputFile.open("input.txt",ios::app);
	                inputFile<<user.name<<" "<<user.surname<<" "<<user.password<<" "<<user.sum<<"\n";
	                inputFile.close();
	                outputFile.open("output.txt", ios::app);
	                outputFile<<"New user added: "<<user.name<<" "<<user.surname<<". It's score is: "<<user.sum<<"$\n";
	                outputFile.close();
	                users.push_back(user);
	                getch();
					system("cls");
				}
            }
            else if(a == '3') {
				system("cls");
                User user1;
                cout << "Enter the name of user:\n";
                while(true)
                {
                try{
                	cin >> user1.name;
                }catch(exception e){
                	cout<<"\nwrong input! Try again please!\n";
                	continue;
				}
				break;
				}
                cout << "Enter the surname of user:\n";
                while(true)
                {
                try{
                	cin >> user1.surname;
                }catch(exception e){
                	cout<<"\nwrong input! Try again please!\n";
                	continue;
				}
				break;
				}
                cout << "--------------------\n";
                if (!users.search(user1)) {
                    cout << "wrong data input\n";
                    getch();
                    system("cls");
                }
                else
                {
	                cout << "Your score is: " << current_user.sum << "$. Enter the sum of transaction:\n";
	                int sum = 0;
	                while(true)
	                {
	                try{
	                	cin >> sum;
	                }catch(exception e){
	                	cout<<"\nwrong input! Try again please!\n";
	                	continue;
					}
					break;
					}
	                if (sum < 0) {
	                    cout << "\nUse operation #4 for this option.";
	                    getch();
	                    system("cls");
	                }
	                else
	                {
		                if (sum > current_user.sum) {
		                    cout << "\nTransaction failed. You don't have enough money.\n";
		                    getch();
		                    system("cls");
		                }
		                else
		                {
		                cout<<"Performing operation ...\n";
		                outputFile.open("output.txt", ios::app);
		
		                outputFile << "Transaction from " << current_user.name << " " << current_user.surname << " to " <<
		                           user1.name << " " << user1.surname << ". Sum: " << sum << "\n";
		                try
			            {
			                outputFile.close();
			                users.changesum(current_user,-sum);
			                users.changesum(user1,sum);
			                inputFile.open("input.txt",ios::out);
			                Node*cur = users.head;
			                while(cur){
			                	inputFile<<cur->user.name<<" "<<cur->user.surname<<" "<<cur->user.password<<" "<<cur->user.sum<<"\n";
			                	cur=cur->next;
							}
			                inputFile.close();
			                cout<<"Operation completed successfully!\n(press enter to continue)\n";
		            	}catch(exception e)
		            	{
		            		cout<<"An error occured! Try again later!\n(press enter to continue)\n";
						}
		                getch();
						system("cls");
						}
					}
				}
            }
            else if(a == '4') {
				system("cls");
                if (current_user.name != "admin"){
                    cout<<"You can't use this option\n";
                    getch();
				    system("cls");
                }
                else{
	                User user2;
	                int sum1 = 0;
	                cout << "Enter the name of user:\n";
	                cin >> user2.name;
	                cout << "Enter the surname of user:\n";
	                cin >> user2.surname;
	                cout << "Enter the sum that you want to get:\n";
	                cin >> sum1;
	                if (sum1 < 0) {
	                    cout << "Use operation #3 for this.";
	                    getch();
	                }
	                else
	                {
		                if (users.changesum(user2, sum1 *(-1))) {
		                    users.changesum(current_user, sum1);
		                    cout<<"Performing operation ...\n";
		                    outputFile.open("output.txt",ios::app);
		                    outputFile << "Transaction from " << user2.name << " " << user2.surname << " to " <<
		                               current_user.name << " " << current_user.surname << ". Sum: " << sum1 << "\n";
		                    outputFile.close();
		                    try
				            {
				                outputFile.close();
				                inputFile.open("input.txt",ios::out);
				                Node*cur = users.head;
				                while(cur){
				                	inputFile<<cur->user.name<<" "<<cur->user.surname<<" "<<cur->user.password<<" "<<cur->user.sum<<"\n";
				                	cur=cur->next;
								}
				                inputFile.close();
		                    	cout << "You got "<<sum1<<"$ from "<<user2.name<<" "<<user2.surname<<"\n";
				                cout<<"Operation completed successfully!\n(press enter to continue)\n";
			            	}catch(exception e)
			            	{
			            		cout<<"An error occured! Try again later!\n(press enter to continue)\n";
							}
		                }
	            	}
	                getch();
					system("cls");
				}
            }
            else if(a == '5') {
				system("cls");
                if (current_user.name != "admin"){
                    cout<<"You can't use this option\n";
                    getch();
				    system("cls");
                }
                else{
	                User user3;
	                cout << "Deleting user:\n";
	                cout << "Enter the name of user:\n";
	                cin >> user3.name;
	                cout << "Enter the surname of user:\n";
	                cin >> user3.surname;
	                if (!users.search(user3)) {
	                    cout << "No such user.\n";
	                    getch();
	                    system("cls");
	                }
	                else{
		                users.remove(user3);
		                outputFile.open("output.txt", ios::app);
		                outputFile<<"User deleted: "<<user3.name<<" "<<user3.surname<<"\n";
		                outputFile.close();
		                inputFile.open("input.txt",ios::out);
				        Node*cur = users.head;
				        while(cur){
				            inputFile<<cur->user.name<<" "<<cur->user.surname<<" "<<cur->user.password<<" "<<cur->user.sum<<"\n";
				           	cur=cur->next;
						}
				        inputFile.close();
		                cout << "removed successful.\n";
		                getch();
						system("cls");
					}
				}
            }
            else if(a == '6')
                    return 0;
            else{
                cout<<"Type again please!\n";
                getch();
				system("cls");
            }
        }
    }
    return 0;
}
