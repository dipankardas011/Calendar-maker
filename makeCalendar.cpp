// makeCalendar.cpp : Defines the entry point for the application.
/************************************************
*                                               *
*   +----------------------------------------+  *
*   |  Compiled on the Cmaker Visual Studio  |  *
*   |   MSVC Compiler (C) 2021               |  *
*   |   AUTHOR: DIPANKAR DAS                 |  *
*   +----------------------------------------+  *
*                                               *
* ***********************************************
*/

/*
 * CALENDAR(): constructor to assigne default values default 01,01,0001
 * yearInput(int): it takes the input from the user (YEAR)
 * monthInput(int): it takes the input from the user (MONTH)
 * -------------
 * yearVal(): it return the YEAR value to the caller method()
 * startingDayNumber(): returns the starting day number
 * monthNames: enum contains the monthnames
 * monthVal(): it return the MONTH value to the caller method()
 * -------------
 * printMonthName(int): it prints the month name from the month number [1..12]
 * startingDayNumber(int, int, int): it returns the starting position for specified month and year [0...6]
 * lastDayOfMonth(int, int): it returns 31 or 30 or 28 or 29 depending upon the month and year
 * isLeapYear(int yy): it returns the boolean value if it is a leap year
 * lastDayOfMonth(): it returns the last day of every month
 * welcomePage(): dislays the welcome page
 * -------------
 * CustomCalendar(): it prints the yealy calendar for the specified year { 3months in one row format}
 * displayMonth(): it prints the month of specified year from usr
 */
#include <iostream>
#include <string>
#include <cstdio>
#include "makeCalendar.h"
#include "defineFun.h"

FILE *f = fopen("print.txt", "w");

void welcomePage(void)
{
	cout << "+---------------------------------------+" << endl;
	cout << "|  Welcome to the \"Calendar Maker\" CLI  |" << endl;
	cout << "+---------------------------------------+" << endl;
}

// Function to print the calendar of the given year

void printDash(void)
{
	cout << "  ";
	fprintf(f, "  ");
	for (int i = 1; i <= 35; i++)
	{
		cout << "-";
		fprintf(f, "-");
	}
	cout << "\t";
	fprintf(f, "\t");
}

void printMonthName(FILE *f, int mm)
{
	/* it prints the month name wrt to the month number */
	switch (mm)
	{
	case Jan:
		fprintf(f,"%10s", "January");
		break;
	case Feb:
		fprintf(f,"%10s", "February");
		break;
	case Mar:
		fprintf(f,"%10s", "March");
		break;
	case Apr:
		fprintf(f,"%10s", "April");
		break;
	case May:
		fprintf(f,"%10s", "May");
		break;
	case Jun:
		fprintf(f,"%10s", "June");
		break;
	case Jul:
		fprintf(f,"%10s", "July");
		break;
	case Aug:
		fprintf(f,"%10s", "August");
		break;
	case Sep:
		fprintf(f,"%10s", "September");
		break;
	case Oct:
		fprintf(f,"%10s", "October");
		break;
	case Nov:
		fprintf(f,"%10s", "November");
		break;
	case Dec:
		fprintf(f,"%10s", "December");
		break;
	}
}

void CustomCalendar(int year)
{
	fprintf(f, "CALENDAR YEAR %d\n", year);
	/**
	 * as we are going to print 3 months side by side
	 * so 12/3 = 4 loops required
	 */
	int day1, day2, day3;
	int dispIter = 4;
	int month1 = -2, month2 = -1, month3 = 0;

	while (dispIter--)
	{
		month1 += 3;
		month2 += 3;
		month3 += 3;

		int current1 = startingDayNumber(1, month1, year);
		int current2 = startingDayNumber(1, month2, year);
		int current3 = startingDayNumber(1, month3, year);

		cout << "\n  \t";
		fprintf(f, "\n  \t");
		printMonthName(f, month1);
		printMonthName(month1);

		cout << "\t\t  \t\t";
		fprintf(f, "\t\t  \t\t");
		printMonthName(f, month2);
		printMonthName(month2);

		cout << "\t\t  \t\t";
		fprintf(f, "\t\t  \t\t");
		printMonthName(month3);
		printMonthName(f, month3);
		cout << endl;
		fprintf(f, "\n");
		printDash();
		printDash();
		printDash();
		cout << endl;
		fprintf(f, "\n");
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\t"); // for each month
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\t");
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		fprintf(f,"  Sun  Mon  Tue  Wed  Thu  Fri  Sat\t");
		fprintf(f,"  Sun  Mon  Tue  Wed  Thu  Fri  Sat\t"); // for each month
		fprintf(f,"  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

		int k1, k2, k3;
		day1 = lastDayOfMonth(month1, year);
		day2 = lastDayOfMonth(month2, year);
		day3 = lastDayOfMonth(month3, year);
		int weeks = 1;
		int j1 = 1, j2 = 1, j3 = 1;
		while (weeks <= 6)
		{
			// month 1
			for (k1 = 0; k1 < current1 && weeks == 1; k1++)
			{
				printf("     ");
				fprintf(f,"     ");
			}

			while (k1 <= 6 && j1 <= day1)
			{
				k1++;
				printf("%5d", j1);
				fprintf(f, "%5d", j1);
				j1++;
			}
			if (k1 < 7)
			{
				// blank spaces
				for (int i = k1; i <= 6; i++)
				{
					printf("     ");
					fprintf(f, "     ");
				}
				k1 = 0; //don't require as the spacing one will automatically assisgn 0
			}

			cout << "\t";
			fprintf(f, "\t");
			// month 2
			for (k2 = 0; k2 < current2 && weeks == 1; k2++)
			{
				printf("     ");
				fprintf(f, "     ");
			}

			while (k2 <= 6 && j2 <= day2)
			{
				k2++;
				printf("%5d", j2);
				fprintf(f, "%5d", j2);
				j2++;
			}
			if (k2 < 7)
			{
				// blank spaces
				for (int i = k2; i <= 6; i++)
				{
					printf("     ");
					fprintf(f,"     ");
				}
				k2 = 0;
			}

			cout << "\t";
			fprintf(f, "\t");
			// month 3
			for (k3 = 0; k3 < current3 && weeks == 1; k3++)
			{
				printf("     ");
				fprintf(f,"     ");
			}
			while (k3 <= 6 && j3 <= day3)
			{
				k3++;
				printf("%5d", j3);
				fprintf(f, "%5d", j3);
				j3++;
			}
			if (k3 < 7)
			{
				// blank spaces
				for (int i = k3; i <= 6; i++)
				{
					printf("     ");
					fprintf(f, "     ");
				}
				k3 = 0;
			}

			cout << endl;
			fprintf(f, "\n");
			weeks++;
		}
	}
	f.close();
}

void Calendar::displayMonth(void)
{
	// we are joing to use the month var to find the month
	// using the month var stored
	int starting = startingDayNumber(1, this->MONTH, this->YEAR);

	cout << endl
		<< "\t\t";
	printMonthName(this->MONTH);
	cout << "\nweeks\tSun\tMon\tTue\tWed\tThur\tFri\tSat" << endl;
	cout << "------------------------------------------------------------" << endl;
	for (int week_no = 0, space = 0, days = 1; week_no < 6; week_no++)
	{ // iterating through the 0 to 6 i.e. week number
		cout << week_no << "|\t";
		int index = 0; // it represents the index for the calender[][][][] in the one week
		while (space++ < starting)
		{
			index++;
			cout << " \t";
		}
		starting = 0;

		for (; index < 7; index++)
		{

			if (days == lastDayOfMonth(this->MONTH, this->YEAR) + 1)
			{ //last day change according to the month
				starting = index;
				return;
			}
			cout << days << "\t";
			days++;
		}
		cout << endl;
	}
}

int main(void)
{
	welcomePage();
	Calendar obj;

	cout << endl
		<< "Press the [E] for user input OR [D] for currrent year.. ";

	char choice;
	cin >> choice;
	/* usr asked for the year or else the default is current year*/
	int year;

	if (choice == 'E' || choice == 'e')
	{
		cout << endl
			<< "enter the year for the calendar... ";
		cin >> year;
	}

	else if (choice == 'D' || choice == 'd')
		year = ((__DATE__[7] - '0') * 1000 + (__DATE__[8] - '0') * 100 + (__DATE__[9] - '0') * 10 + (__DATE__[10] - '0'));
	else
	{
		std::cerr << "^~~~  ERROR! Key binding error\n";
		return 0;
	}
	obj.yearInput(year);

	/* usr asked for the month or else default -> January */
	cout << "Enter [y] for entering the month default[d] is no..";
	cin >> choice;
	if (choice == 'y')
		obj.monthInput();

	cout << "the year entered by user= " << obj.yearVal() << endl;
	cout << endl;
	obj.displayMonth();

	cout << endl;
	CustomCalendar(obj.yearVal());
	return 0;
}
