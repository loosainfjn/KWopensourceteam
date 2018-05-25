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
		if (month < 1 || month>12) //�� �߸��Է�
		{
			printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
			continue;
		}
		else if (month == 1) //1���϶� �߸��Է�
		{
			if (date < 1 || date>31)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 3) //3���϶� �߸��Է�
		{
			if (date < 1 || date>31)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 5) //5���϶� �߸��Է�
		{
			if (date < 1 || date>31)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 7) //7���϶� �߸��Է�
		{
			if (date < 1 || date>31)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 8) //8���϶� �߸��Է�
		{
			if (date < 1 || date>31)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 10) //10���϶� �߸��Է�
		{
			if (date < 1 || date>31)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 12) //12���϶� �߸��Է�
		{
			if (date < 1 || date>31)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 4)  //4���϶� �߸��Է�
		{
			if (date < 1 || date>30)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 6) //6���϶� �߸��Է�
		{
			if (date < 1 || date>30)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 9) //9���϶� �߸��Է�
		{
			if (date < 1 || date>30)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 11) //11���϶� �߸��Է�
		{
			if (date < 1 || date>30)
			{
				printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
				continue;
			}
			else
				break;
		}
		else if (month == 2) //2���϶�
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //����(2/29)
			{
				if (date < 1 || date>29)
				{
					printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
					continue;
				}
				else
					break;
			}
			else
			{
				if (date < 1 || date>28)
				{
					printf("\n�١ڡ١ڡ�Please re-enter�ڡ١ڡ١�\n\n");
					continue;
				}
				else
					break;
			}
		}
		else
			break;
	}
	system("cls"); //ȭ�� ��ü�����
	char eng_month[][12] = { "January","February","March","April","May","June","July","August","September","October","November", "December" }; //�� �����̸�

	printf("\n\n�̢̢̢̢̢̢̢̢�\n\n");
	printf("%7s %d\n\n", eng_month[month - 1], year);
	char eng_day[][6] = { "SUN","MON","TUE","WED","THU","FRI","SAT" }; //���� �����̸�
	if (month >= 3 && month <= 12)
	{
		printf("=================\n");
		printf("       %s        \n", eng_day[(year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + date) % 7]); //���ϱ��ϱ� ÿ���� �յ��� ���
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
	printf("�� %-8d\n", date);
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
	if ((fp = fopen(path.c_str(), "r")) != NULL) //������ ��������
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
	printf("\n�̢̢̢̢̢̢̢̢�\n");


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
			Option_in_Calendar_Option3.Calendar_Option4();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100);
			system("cls"); //ȭ�� ��ü�����
			Screen_in_Calendar_Option3.Calendar_Main_Screen();
			break;
		}
		else if (opt < 1 || opt>2)
		{
			system("cls"); //ȭ�� ��ü�����

			printf("\n\n�̢̢̢̢̢̢̢̢�\n\n");
			printf("%7s %d\n\n", eng_month[month - 1], year);
			char eng_day[][6] = { "SUN","MON","TUE","WED","THU","FRI","SAT" }; //���� �����̸�
			if (month >= 3 && month <= 12)
			{
				printf("=================\n");
				printf("       %s        \n", eng_day[(year + year / 4 - year / 100 + year / 400 + (13 * month + 8) / 5 + date) % 7]); //���ϱ��ϱ� ÿ���� �յ��� ���
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
			printf("�� %-8d", date);
			printf("\n\n\n\n\n\n\n");
			printf("�̢̢̢̢̢̢̢̢�\n");

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