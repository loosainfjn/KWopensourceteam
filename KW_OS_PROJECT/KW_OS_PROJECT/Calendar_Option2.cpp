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


void Calendar_Option::Calendar_Option2()
{
	int opt;
	Calendar Calendar_in_Calendar_Option2;
	Calendar_Option Option_in_Calendar_Option2;
	Screen Screen_in_Calendar_Option2;
	Go_to_xy Go_to_xy_in_Calendar_Option2;
	int wknum;
	int year, month;
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;
	int first_date = 0;
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);


	printf("Year : ____\b\b\b\b     Month : __\b\b    Week : _\b\b");
	Go_to_xy_in_Calendar_Option2.gotoxy(7, 1);
	scanf("%d", &year);
	Go_to_xy_in_Calendar_Option2.gotoxy(21, 1);
	scanf("%d", &month);
	Go_to_xy_in_Calendar_Option2.gotoxy(32, 1);
	scanf("%d", &wknum);

	days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

	for (int i = 0; i < month - 1; i++)
	{
		if (i == 1)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //����(2/29)
				day[1] = 29;
			else
				day[1] = 28;
		}
		days += day[i];
	}
	//7�Ͼ� �����ָ� ���޿��� �����޷� �Ѿ�� ù�� ĭ�� ä�� count
	first_date = days % 7;

	Calendar_in_Calendar_Option2.Calendar_Week(tm.tm_year + 1900, tm.tm_mon + 1, wknum - 1);
	//�ɼ�2 ���� ��

	printf("\n\n\n");
	printf("    Choose the desired from of plan from 2 options.\n\n\n");

	printf("     1. Change schedule\n\n");
	printf("     2. Go to Mainscreen\n\n");
	while (1)
	{
		printf("    Choose option : ");

		scanf("%d", &opt);

		if (opt == 1)
		{
			Sleep(100); //������
			system("cls"); //ȭ�� ��ü�����
			Option_in_Calendar_Option2.Calendar_Option4();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100);
			system("cls"); //ȭ�� ��ü�����
			Screen_in_Calendar_Option2.Calendar_Main_Screen();
			break;
		}
		else if (opt < 1 || opt>2)
		{
			system("cls"); //ȭ�� ��ü�����
						   //�ɼ�2����� �����
			printf("\n             �١ڡ١ڡ� Please re-enter �ڡ١ڡ١�\n\n");
			printf("    Choose the desired from of plan from 2 options.\n\n\n");
			printf("     1. Change schedule\n\n");
			printf("     2. Go to Mainscreen\n\n");
			continue;
		}
		else
		{
			printf("\n\n");
			break;
		}
	}
}