// L-1-C.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>

int main()
{
	printf("This program will calculate the length of the interval of atime between two moments.\n");
	printf("Type the first moment of time in the next form: HH MM SS\n");
	int seconds = 0, minutes = 0, hours = 0, Hours = 0, Minutes = 0, Seconds = 0;
	char c1, c2;
	scanf_s("%d%d%d", &hours, &minutes, &hours);
	printf("Type the second moment of time in the next form: HH MM SS\n");
	scanf_s("%d%d%d", &Hours, &Minutes, &Hours);
	int delta = 3600 * (Hours - hours) + 60 * (Minutes - minutes) + (Seconds - seconds);
	int deltaSeconds = delta % 60;
	int deltaMinutes = (delta / 60) % 60;
	int deltaHours = (delta / 3600) % 60;
	printf("\nTime passed: %d %d %d\n", deltaHours, deltaMinutes, deltaHours);
    return 0;
}

