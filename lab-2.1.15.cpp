// L-2_C_1.cpp : Defines the entry point for the console application.
//

#include<conio.h>
#include<iostream>
#define averagePayment 400
#define workingHours 8
#define pricePerHour 9

static int LengthOfProject=0;
static int CostOfProject=0;
static int numberOfWorkers = 0;
static int numberOfWorkingDays = 0;
static double costOfProject = 0.0;
static double profit = 0.0;


void inputDate()
{
	system("cls");
	int day, month, year, Day, Month, Year;
	printf("Define the date of starting project in format: Day Month Year \n");
	scanf("%d%d%d", &day, &month, &year);
	printf("Now define the date of finishing project in format: Day Month Year \n");
	scanf("%d%d%d", &Day, &Month, &Year);
	LengthOfProject = 365 * (Year - year) + 30 * (Month - month) + (Day - day);
	getch();
	system("cls");
}

void inputNumberOfWorkers()
{
	system("cls");
	int numOfWorkers;
	printf("Enter the number of workers you need for this project:");
	scanf("%d", &numOfWorkers);
	numberOfWorkers = numOfWorkers;
	getch();
	system("cls");
}

void viewTheLengthOfProject()
{
	system("cls");
	printf("The length of project in days is: %d\n", LengthOfProject);
	numberOfWorkingDays = (LengthOfProject * 5) / 7;
	printf("The number of working days is about %d\n", numberOfWorkingDays);
	getch();
	system("cls");
}

void getTheDifficultyOfProject()
{
	system("cls");
	if (numberOfWorkers <= 0)
	{
		printf("You entered wrong number of workers");
		getch();
		system("cls");
		return;
	}
	else
	{
		double humanPerDays = ((double)(numberOfWorkers*numberOfWorkingDays)) / ((double)LengthOfProject);
		double humanPerHours = humanPerDays*(8.0 / 24.0);
		printf("The average number of human per days is: %f\n", humanPerDays);
		printf("The average number of human per hours is: %f\n", humanPerHours);
		getch();
		system("cls");
	}
}

void calculateTheCostOfProject() 
{
	system("cls");
	double payment = numberOfWorkers*averagePayment*((double)LengthOfProject / 30);
	double price = LengthOfProject*pricePerHour*24;
	profit = price - payment;
	printf("The sum you will pay to your workers is: %f\n", payment);
	printf("The sum you will earn is: %f\n", price);
	getch();
	system("cls");
}

void getThePrice()
{
	system("cls");
	printf("The profit is: %f\n", profit);
	if (profit < 1000)printf("You are not recommended to take this project because its profit is less than 1000$\n");
	else printf("You are recommended to take this project because its profit more than 1000$\n");
	getch();
	system("cls");
}

void getInformationAboutProgram()
{
	system("cls");
	printf("This program was created by the student of the group 653501 Liskavets Boris.\n");
	printf("This is a commercial project. All rights reserved. \nContact pfone: +375445920132.");
	getch();
	system("cls");
}

int main(void)
{
	char a = '\0';
	while (a!='e')
	{
		printf("1. press 1 to input the date of project\n");
		printf("2. press 2 to input the number of workers for project\n");
		printf("3. press 3 to view the length of project\n");
		printf("4. press 4 to view the complexity of project\n");
		printf("5. press 5 to see the profit of project\n");
		printf("6. press 6 to make sure that the project will be profitable\n");
		printf("7. press 7 to viewthe informatin about the program\n");
		printf("8. press 8 to exit\n");
			
		a = getch();
		
		switch (a)
		{
		case '1':
			inputDate();
			break;
		case '2':
			inputNumberOfWorkers();
			break;
		case '3':
			viewTheLengthOfProject();
			break;
		case '4':
			getTheDifficultyOfProject();
			break;
		case '5':
			calculateTheCostOfProject();
			break;
		case '6':
			getThePrice();
			break;
		case '7':
			getInformationAboutProgram();
			break;
		case '8':
			return 0;
			break;
		default:
			printf("type again please:");
			getch();
			system("cls");
			break;
		}
	}
    return 0;
}

