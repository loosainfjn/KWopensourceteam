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


void Calendar_Option::Calendar_Option3()
{
	int opt;
	Calendar Calendar_in_Calendar_Option3;
	Calendar_Option Option_in_Calendar_Option3;
	Screen Screen_in_Calendar_Option3;
	Go_to_xy Go_to_xy_in_Calendar_Option3;
	int year = 0, month = 0, date = 0;

	while (1)
	{
		printf("Year : ____\b\b\b\b     Month : __\b\b    Date : __\b\b");
		Go_to_xy_in_Calendar_Option3.gotoxy(7, 1);
		scanf("%d", &year);
		Go_to_xy_in_Calendar_Option3.gotoxy(21, 1);
		scanf("%d", &month);
		Go_to_xy_in_Calendar_Option3.gotoxy(31, 1);
		scanf("%d", &date);
		if (month < 1 || month>12) //월 잘못입력
		{
			printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
			continue;
		}
		else if (month == 1) //1월일때 잘못입력
		{
			if (date < 1 || date>31)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 3) //3월일때 잘못입력
		{
			if (date < 1 || date>31)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 5) //5월일때 잘못입력
		{
			if (date < 1 || date>31)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 7) //7월일때 잘못입력
		{
			if (date < 1 || date>31)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 8) //8월일때 잘못입력
		{
			if (date < 1 || date>31)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 10) //10월일때 잘못입력
		{
			if (date < 1 || date>31)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 12) //12월일때 잘못입력
		{
			if (date < 1 || date>31)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 4)  //4월일때 잘못입력
		{
			if (date < 1 || date>30)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 6) //6월일때 잘못입력
		{
			if (date < 1 || date>30)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 9) //9월일때 잘못입력
		{
			if (date < 1 || date>30)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 11) //11월일때 잘못입력
		{
			if (date < 1 || date>30)
			{
				printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 2) //2월일때
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //윤년(2/29)
			{
				if (date < 1 || date>29)
				{
					printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
					continue;
				}
				else
					break;
			}
			else
			{
				if (date < 1 || date>28)
				{
					printf("\n☆★☆★☆Please re-enter★☆★☆★\n\n");
					continue;
				}
				else
					break;
			}
		}
		else
			break;
	}
	system("cls"); //화면 전체지우기
	char eng_month[][12] = { "January","February","March","April","May","June","July","August","September","October","November", "December" }; //월 영어이름

	printf("\n\n▩▩▩▩▩▩▩▩▩\n\n");
	printf("%7s %d\n\n", eng_month[month - 1], year);
	char eng_day[][6] = { "SUN","MON","TUE","WED","THU","FRI","SAT" }; //요일 영어이름
	if (month >= 3 && month <= 12)
	{
		printf("=================\n");
		printf("       %s        \n", eng_day[(year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + date) % 7]); //요일구하기 첼러의 합동식 사용
		printf("=================\n");
	}

	else if (month == 1 || month == 2)
	{
		year -= 1, month += 12;
		printf("=================\n");
		printf("       %s        \n", eng_day[(year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + date) % 7]);
		printf("=================\n");
		year += 1, month -= 12;
	}
	printf("▤ %-8d\n", date);
	FILE* fp;
	string file_name, str_M, str_D;
	string str_Y = to_string(year);
	if (month < 10)
		str_M = "0";
	if (date < 10)
		str_D = "0";
	str_M += to_string(month), str_D += to_string(date);
	file_name = str_Y + "." + str_M + "." + str_D + ".txt";
	string path = "Calendar_data/";
	path += file_name;
	if ((fp = fopen(path.c_str(), "r")) != NULL) //파일을 열었을때
	{
		char cp[300];
		while (!feof(fp))
		{
			string px;
			char* pStr = fgets(cp, sizeof(cp), fp);
			if (pStr == NULL)
				break;
			px = pStr;
			px.erase(px.find_last_not_of("\t\n") + 1);
			printf("\n%s\n", px.c_str());
		}
	}
	printf("\n▩▩▩▩▩▩▩▩▩\n");


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
			Option_in_Calendar_Option3.Calendar_Option4();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100);
			system("cls"); //화면 전체지우기
			Screen_in_Calendar_Option3.Calendar_Main_Screen();
			break;
		}
		else if (opt < 1 || opt>2)
		{
			system("cls"); //화면 전체지우기

			printf("\n\n▩▩▩▩▩▩▩▩▩\n\n");
			printf("%7s %d\n\n", eng_month[month - 1], year);
			char eng_day[][6] = { "SUN","MON","TUE","WED","THU","FRI","SAT" }; //요일 영어이름
			if (month >= 3 && month <= 12)
			{
				printf("=================\n");
				printf("       %s        \n", eng_day[(year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + date) % 7]); //요일구하기 첼러의 합동식 사용
				printf("=================\n");
			}

			else if (month == 1 || month == 2)
			{
				year -= 1, month += 12;
				printf("=================\n");
				printf("        %s       \n", eng_day[(year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + date) % 7]);
				printf("=================\n");
				year += 1, month -= 12;
			}
			printf("▤ %-8d", date);
			printf("\n\n\n\n\n\n\n");
			printf("▩▩▩▩▩▩▩▩▩\n");

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