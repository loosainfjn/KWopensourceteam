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


void Calendar_Option::Calendar_Option4()
{
	int opt;
	Calendar Calendar_in_Calendar_Option4;
	Calendar_Option Calendar_Option_in_Calendar_Option4;
	Screen Screen_in_Calendar_Option4;
	Go_to_xy Go_to_xy_in_Calendar_Option4;
	char schd[20];
	char title[40];
	char path_file[50] = "Calendar_in_Calendar_Option4_data/";
	FILE* fp = NULL;
	printf("Enter file name to save(ex. 2017.12.12): ");
	Go_to_xy_in_Calendar_Option4.gotoxy(42, 1);
	system("mkdir Calendar_in_Calendar_Option4_data");
	for (int i = 1; i < 60; i++)
	{
		Go_to_xy_in_Calendar_Option4.gotoxy(42 + i, 1);
		printf(" ");
	}
	Go_to_xy_in_Calendar_Option4.gotoxy(42, 1);
	scanf("%s", title);
	printf("\n\n");
	strcat(title, ".txt");
	strcat(path_file, title);
	fp = fopen(path_file, "w"); //����Ʈ�� �Է¹��� �������� ������ ���� �������� ����
	printf("Press 'Q' if you want to end.\n");
	for (int i = 0; i < 4; i++)
	{
		printf("Enter schedule %d : ", i + 1);
		scanf("%s", schd);
		if (!strcmp(schd, "Q") || !strcmp(schd, "q"))
			break;
		fprintf(fp, "%d. %s\n", i + 1, schd);
	}
	fclose(fp);

	//�ɼ�4������

	printf("\n\n\n");
	printf("    Choose the desired from of plan from 2 Calendar_Options.\n\n\n");
	printf("     1. Change schedule\n\n");
	printf("     2. Go to Mainscreen\n\n");
	while (1)
	{
		printf("    Choose Calendar_Option : ");

		scanf("%d", &opt);

		if (opt == 1)
		{
			Sleep(100); //������
			system("cls"); //ȭ�� ��ü�����
			Calendar_Option_in_Calendar_Option4.Calendar_Option4();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100); //������
			system("cls"); //ȭ�� ��ü�����
			Screen_in_Calendar_Option4.Calendar_Main_Screen();
			break;
		}
		else if (opt < 1 || opt>2)
		{
			system("cls"); //ȭ�� ��ü�����
						   //�ɼ�4 ����� �����
			printf("\n             �١ڡ١ڡ� Please re-enter �ڡ١ڡ١�\n\n");
			printf("    Choose the desired from of plan from 2 Calendar_Options.\n\n\n");

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