#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<string>
using namespace std;

int main(void)
{
	string s; //vvedite chislo
	getline(cin, s);
	cout << "old s = " << s << endl;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9' || s[i] == '0')
		{
			if (s[i] == '0')
			{
				for (int j = i; j < s.size() - 1; j++)
				{
					s[j] = s[j + 1];
				}
				s.resize(s.size()-1);
			}
			else
			{
				int step = s[i] - 48;
				s.resize(s.size()+step-1);
				char c = (step % 2 == 0) ? '+' : '-';
				for (int j = s.size(); j >=i+step; j--)
				{
					s[j] = s[j-step+1];
				}
				for (int j = i; j < i+step; j++)
				{
					s[j] = c;
				}
			}
		}
	}
	cout << "new s = " << s << endl;
	getch();
	return 0;
}
