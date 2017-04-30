#include <iostream>
#include<math.h>
#include<vector>
#include <exception>
using namespace std;

double recurssum=0;

double fact(int i)
{
    if(i==1||i==0)return i;
    return i*fact(i-1);
}

double recursSumForI(double x, int i)
{
    if(i==1)return x;
    return recursSumForI(x, i-2)+pow(-1,(i%4==1)?(0):(1))*pow(x,i)/fact(i);
}

int power = 0;

double recursiveSum(double x, double eps)
{
    int index = 1;
    double sum = 0, save_sum=0;
    while(index<100) {
        save_sum=sum;
        try {
        	if(fabs(save_sum-sin(x))>eps)
        	{
        		power+=2;
            	sum=recursSumForI(x, index);
            }
            else
    			break;
        }
        catch (exception) {
            break;
        }
        index+=2;
    }
    return save_sum;
}

double iterSum(double x)
{
    vector<double>seq;
    double a1=x, sum=a1;
    double index=3.0;
    while(a1!=0)
    {
        int p = (int)index;
        a1=(-1)*pow(x,2)*a1/((index-1.0)*index);
        sum+=a1;
        index+=2;
    }
    return sum;
}

int main() {
    setlocale(LC_ALL,"rus");
    cout<<"Введедите чило от -35 до 35 (это обусловлено тем, что мы работаем с большими степенями и рискуем выйти за границы диапазонов чисел)\n";
    double a, eps;
    cin>>a;
    cout<<"\nТеперь задайте погрешность ( >0.000001 ):\n";
    cin>>eps;
    cout<<"Результат функции: "<<recursiveSum(a,eps)<<endl;
    cout<<"Реальное значение: "<<sin(a)<<endl;
    cout<<"n = "<<power<<endl;
    power = 0;
    return 0;
}
