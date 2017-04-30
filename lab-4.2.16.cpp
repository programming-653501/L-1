#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
#include<string>
#include<vector>
#include<fstream>
using namespace std;

bool findWords(string startWord, vector<string>allWords, vector<int>&indexes, string resultWord, string prevWord)
{
	if (resultWord == startWord&&prevWord!="")return true;
	bool contin = false;
	for (int i = 0; i < allWords.size(); i++)
	{
		bool notUsed = true;
		for (int j = 0; j < indexes.size(); j++)
		{
			if (i == indexes[j])notUsed = false;
		}//проверяем не использовали ли мы это слово раньше
		if (!notUsed)continue;
		string s = resultWord + allWords[i];//проверяем нормальная ли длина
		bool is_part_of = true;
		if (s.size() > startWord.size())continue;
		for (int j = 0; j < allWords[i].size(); j++)
		{
			if (startWord[j + resultWord.size()] != allWords[i][j])
			{
				is_part_of = false;
			}
		}
		if (!is_part_of)continue;
		else {
			indexes.push_back(i);
			return findWords(startWord, allWords, indexes, s, resultWord);
		}
	}
	return false;
}

int main(void)
{
	vector<string>words;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	fstream file;
	file.open("file.txt", ios::in);
	while (!file.eof())
	{
		string s;
		file >> s;
		words.push_back(s);
	}
	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i] << endl;
	}

	cout << "\n--------------------------------------------------------------------------------\n\n";
	vector<int>indexes;
	vector<vector<string> >concat_words;
	int index = 0;
	for (int i = 0; i < words.size(); i++)
	{
		if (findWords(words[i], words, indexes, "", ""))
		{
			concat_words.resize(++index);
			concat_words[index-1].push_back(words[i]);
			for (int j = 0; j < indexes.size(); j++)
			{
				concat_words[index-1].push_back(words[indexes[j]]);
			}
		}
		indexes.resize(0);
	}
	for (int i = 0; i < concat_words.size(); i++)
	{
		cout << i + 1 << ". ";
		for (int j = 0; j < concat_words[i].size(); j++)
		{
			cout << concat_words[i][j] << " ";
		}
		cout << endl;
	}
	_getch();
	return 0;
}
