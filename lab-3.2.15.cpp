// L-3-C-2.cpp : Defines the entry point for the console application.
//


#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<stdio.h>

static int*** A;
int I, J, K;

void startSettings()
{
	printf("Enter I, J ,K: \n");
	scanf("%d", &I);
	scanf("%d", &J);
	scanf("%d", &K);
	printf("\ntype \'y\' if you want to enter the elements of matrix yourself, if no, type \'n\'\n");
	char a;
	bool userInput = false;
	while(true){
		scanf("%c",&a);
		if(a=='y'){
		userInput = true; break;
		}
		else if(a=='n'){
		userInput = false; break;
		}
		else {
			printf("\nwrong input, type again:");
			continue;
		}
	}
	A = new int**[I];
	for (int i = 0; i < I; i++)
	{
		A[i] = new int*[J];
	}
	for (int i = 0; i < I; i++)
		for (int j = 0; j < J; j++)
		{
			A[i][j] = new int[K];
		}
	if(!userInput)
		for (int i = 0; i < I; i++)
		{
			for (int j = 0; j < J; j++)
			{
				for (int k = 0; k < K; k++)
				{
					A[i][j][k] = rand() % 2;
				}
			}
		}
	else
		for (int i = 0; i < I; i++)
		{
			for (int j = 0; j < J; j++)
			{
				for (int k = 0; k < K; k++)
				{
					printf("\nA[%d][%d][%d] = ",i+1,j+1,k+1);
					scanf("%d", &A[i][j][k]);
				}
			}
		}
}

void printingProections()
{
	int **IJ = new int*[I];
	for (int i = 0; i < I; i++)
	{
		IJ[i] = new int[J];
	}
	int **KI = new int*[K];
	for (int k = 0; k < K; k++)
	{
		KI[k] = new int[I];
	}
	int **JK = new int*[J];
	for (int j = 0; j < J; j++)
	{
		JK[j] = new int[K];
	}
	for (int i = 0; i < I; i++)
	{
		for (int j = 0; j < J; j++)
		{
			IJ[i][j] = 0;
			for (int k = 0; k < K; k++)
			{
				if (A[i][j][k])
				{
					IJ[i][j] = 1;
				}
			}
		}
	}

	for (int j = 0; j < J; j++)
	{
		for (int k = 0; k < K; k++)
		{
			JK[j][k] = 0;
			for (int i = 0; i < I; i++)
			{
				if (A[i][j][k])
				{
					JK[j][k] = 1;
				}
			}
		}
	}

	for (int k = 0; k < K; k++)
	{
		for (int i = 0; i < I; i++)
		{
			KI[k][i] = 0;
			for (int j = 0; j < J; j++)
			{
				if (A[i][j][k])
				{
					KI[k][i] = 1;
				}
			}
		}
	}
	printf("The I-J proection is: \n");
	for (int i = 0; i < I; i++)
	{
		for (int j = 0; j < J; j++)
		{
			printf("%d ", IJ[i][j]);
		}
		printf("\n\n");
	}
	printf("\nThe J-K proection is: \n");
	for (int j = 0; j < J; j++)
	{
		for (int k = 0; k < K; k++)
		{
			printf("%d ", JK[j][k]);
		}
		printf("\n\n");
	}
	printf("The K-I proection is: \n");
	for (int k = 0; k < K; k++)
	{
		for (int i = 0; i < I; i++)
		{
			printf("%d ", KI[k][i]);
		}
		printf("\n\n");
	}
}

int main()
{
	srand((unsigned int)time(0));
	startSettings();
	printingProections();
	getch();
    return 0;
}

