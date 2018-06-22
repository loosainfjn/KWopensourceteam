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


void Calendar_Option::Calendar_Option1() //달력옵션1
{
	int year = 0, month = 0;
	int opt;
	Calendar Calendar_in_Calendar_Option1;
	Calendar_Option Calendar_Option_in_Calendar_Option1;
	Screen Screen_in_Calendar_Option1;
	Go_to_xy Go_to_xy_in_Calendar_Option1;

	while (1) //년도와 월 입력받기
	{
		printf("Year : ____\b\b\b\b     Month : __\b\b");
		Go_to_xy_in_Calendar_Option1.gotoxy(7, 1);
		scanf("%d", &year);
		Go_to_xy_in_Calendar_Option1.gotoxy(21, 1);
		scanf("%d", &month);
		if (month < 1 || month>12)
		{
			printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
			continue;
		}
		else
		{
			printf("\n\n");
			break;
		}
	}
	system("cls"); //화면 전체지우기
	Calendar_in_Calendar_Option1.Calendar_Month(year, month); //달력출력

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
			Sleep(100); //느리게
			system("cls"); //화면 전체지우기
			Calendar_Option_in_Calendar_Option1.Calendar_Option4();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100);
			system("cls"); //화면 전체지우기
			Screen_in_Calendar_Option1.Main_Screen();
			break;
		}
		else if (opt < 1 || opt>2)
		{
			system("cls"); //화면 전체지우기
			Calendar_in_Calendar_Option1.Calendar_Month(year, month); //옵션1 결과물 재출력후
			printf("\n             ☆★☆★☆ Please re-enter ★☆★☆★\n\n");
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