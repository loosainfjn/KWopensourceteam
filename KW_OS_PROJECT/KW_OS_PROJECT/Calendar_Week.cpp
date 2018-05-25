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


void Calendar::Calendar_Week(int year, int month, int wknum)
{
	Go_to_xy Go_to_xy_in_Calendar_Week;
	string sch[4][31];

	for (int i = 0; i < 31; i++)
		for (int k = 0; k < 4; k++)
			sch[k][i] = "";
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;
	int first_date = 0;

	FILE* fp[31];
	for (int i = 0; i < 31; i++)
	{
		string file_name;
		string str_Y = to_string(year);
		string str_M;
		string str_D;
		if (month < 10)
			str_M = '0';
		str_M += to_string(month);

		if (i + 1 < 10)
			str_D = '0';
		str_D += to_string(i + 1);
		file_name = str_Y + "." + str_M + "." + str_D + ".txt"; //YEAR.MO.DA.txt
		string path = "Calendar_data/";
		path += file_name;
		if ((fp[i] = fopen(path.c_str(), "r")) != NULL) //������ ��������
		{
			char cp[300];
			int j = 0;
			while (!feof(fp[i]))
			{
				char* pStr = fgets(cp, sizeof(cp), fp[i]);
				if (pStr == NULL)
					break;
				sch[j][i] = pStr;
				sch[j][i].erase(sch[j][i].find_last_not_of("\t\n") + 1);
				j++;
			}
		}
	}

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

	//���⼭���� �޷����
	char eng_month[][12] = { "January","February","March","April","May","June","July","August","September","October","November", "December" }; //�� �����̸�

	printf("\n\n�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�\n\n");
	printf("%55s %d\n\n", eng_month[month - 1], year);
	printf("================================================================================================================\n");
	printf("       SUN             MON             TUE             WED             THU             FRI             SAT      \n");
	printf("================================================================================================================\n");
	//1�� 1�� 1���� ������. (������ �Ͽ��Ϻ���)
	for (int i = 0; i <= first_date; i++)
		printf("        \t"); //�׳ɶ���

	for (int i = 1; i <= day[month - 1]; i++)
	{
		if ((first_date + i) / 7 == wknum + 1 && (first_date + i) % 7 == 0)
		{
			for (int k = 0; k < 4; k++)
			{
				for (int j = 0; j < 7; j++)
				{
					int index = i + j - 8;
					if (sch[k][index] != ""&&index >= 0) {
						Go_to_xy_in_Calendar_Week.gotoxy(16 * ((7 + j) % 7) + 1, ((7 + j) / 7) * 6 + 7 + k);
						printf(sch[k][index].c_str());
					}
					else
						printf("\t\t");
				}
			}
		}
		if ((first_date + i) / 7 == wknum) {
			Go_to_xy_in_Calendar_Week.gotoxy(16 * ((7 + (first_date + i) % 7) % 7) + 1, ((7 + (first_date + i) % 7) / 7) * 6 + 5);
			printf("�� %-8d\t", i);
		}
	}

	printf("\n\n�̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢̢�\n");
}