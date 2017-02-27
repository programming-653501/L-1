// L-1-C-2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

long long int* F;

int Fibonacci(int n)
{
	F = new long long int[n/16];
	F[0] = 0; F[1] = 1;
	int i = 2;
	while (F[i - 1]<(long long int)n)
	{
		F[i] = F[i - 1] + F[i - 2];
		i++;
	}
	return (i - 1);
}

int main(void)
{
	printf("This program will calculate the largest Fibonacci number which is lower than 2^31-1.");
	int index = Fibonacci(_CRT_INT_MAX);
	printf("The index is: %d\n", index);
	//evaluating the sum
	int i = 0; long long int s = 0;
	while (s < _CRT_INT_MAX)
	{
		s += F[i++];
	}
	printf("The number of the biggest Fibonacci element which sum is less than 2^31-1 is: %d\n", i-1);
    return 0;
}

