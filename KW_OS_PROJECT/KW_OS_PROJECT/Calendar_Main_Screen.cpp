#include <iostream>
#include <string>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#pragma warning (disable : 4996)
using namespace std;
#include "Calendar.h"
#include "Calendar_Option.h"
#include "Screen.h"
#include "Go_to_xy.h"


int opt;
time_t t = time(NULL);
struct tm tm = *localtime(&t); 

void Screen::Calendar_Main_Screen()
{
	Calendar Calendar_in_Calendar_Main_Screen;
	Calendar_Option Calendar_Option_in_Calendar_Main_Screen;
	Calendar_in_Calendar_Main_Screen.Calendar_Month(tm.tm_year + 1900, tm.tm_mon + 1);

	printf("\n\n\n");
	printf("    Choose the desired from of plan from 4 Calendar_Options.\n\n\n");

	printf("     opt1. A monthly unit\n\n");
	printf("     opt2. A weekly unit\n\n");
	printf("     opt3. A Daily unit\n\n");
	printf("     opt4. Change Schedule\n\n");
	printf("     opt0. Change Color\n\n");
	while (1)
	{
		printf("    Choose Calendar_Option : ");

		scanf("%d", &opt);
		system("cls"); //ȭ�� ��ü�����
		if (opt == 1)
		{
			Sleep(100); //������
			Calendar_Option_in_Calendar_Main_Screen.Calendar_Option1();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100); //������
			Calendar_Option_in_Calendar_Main_Screen.Calendar_Option2();
			break;
		}
		else if (opt == 3)
		{
			Sleep(100); //������
			Calendar_Option_in_Calendar_Main_Screen.Calendar_Option3();
			break;
		}
		else if (opt == 4)
		{
			Sleep(100); //������
			Calendar_Option_in_Calendar_Main_Screen.Calendar_Option4();
			break;
		}
		else if (opt == 0)
		{
			Sleep(100);
			Calendar_Option_in_Calendar_Main_Screen.Calendar_ChangeColor();
			break;
		}
		else if (opt < 1 || opt>4)
		{
			system("cls"); //ȭ�� ��ü�����
			Calendar_in_Calendar_Main_Screen.Calendar_Month(tm.tm_year + 1900, tm.tm_mon + 1);
			printf("\n             �١ڡ١ڡ� Please re-enter �ڡ١ڡ١�\n\n");
			printf("    Choose the desired from of plan from 4 Calendar_Options.\n\n\n");

			printf("     opt1. A monthly unit\n\n");
			printf("     opt2. A weekly unit\n\n");
			printf("     opt3. A Daily unit\n\n");
			printf("     opt4. Change Schedule\n\n");
			continue;
		}
		else
		{
			printf("\n\n");
			break;
		}
	}
}