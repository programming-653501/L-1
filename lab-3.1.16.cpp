#include <iostream>
#include <vector>
#include<conio.h>
using namespace std;

int fact(int i)
{
    if(i==0)
        return 1;
    return i*fact(i-1);
}

void getPermutations(int n)
{
    vector<vector<int> >permutations;
    int index=1;
    while(index<n+1)
    {
        long long int a = fact(index), b = fact(index-1);
        permutations.resize(a);
        for (int i = 0; i < permutations.size(); i++) {
            permutations[i]=permutations[i%b];
            permutations[i].resize(index);
        }
        long long int i=0, current=0, prevsize = fact(index-1);
        while(current<a)
        {
            for (int j = permutations[current%prevsize].size()-1; j > i ; j--) {
                permutations[current][j]=permutations[current][j-1];
            }
            permutations[current][i]=index;
            current++;
            i=current/prevsize;
        }

        index++;
    }
    for(int i = 0; i < permutations.size(); i++)
    {
        for (int j = 0; j < permutations[i].size(); ++j) {
            cout<<permutations[i][j]<<" ";
        }
        cout<<"\n";
    }
}

int main() {
	setlocale(LC_ALL, "rus");
    std::cout << "Введите любое число от 1 до 10(!!). 10 - это уже очень много, т.к. это выдаст вам примерно 3600000 сторчек вывода. При вводе 12"
            "комп просто ляжет и не встанет, так что настоятельная рекомендация ограничиться 10-ю. Введите число:" << std::endl;
    int a;
    cin>>a;
    cout<<"=====================================\n";
    getPermutations(a);
    getch();
    return 0;
}



