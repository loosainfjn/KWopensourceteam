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

void gotoxy(int, int);
void Calendar(int year, int month); //달력
void Calendar_week(int year, int month, int wknum);
void Mainscreen(); //메인스크린
void Option1(); //옵션1
void Option2(); //옵션2
void Option3(); //옵션3
void Option4(); //옵션4
void changeColor();
void ColorString(char* str, int color);

int opt; //몇번 옵션갈지 받아줄거
string sch[4][31];

time_t t = time(NULL);
struct tm tm = *localtime(&t);

#pragma warning (disable:4996)
#define _CRT_SECURE_NO_WARNINGS

#define STD_OUTPUT_HANDLE ((DWORD)-11)

int main()
{
	system("mode con cols=112 lines=180");
	system("tiTle Calendar");
	Mainscreen();

	return 0;
}


void Calendar(int year, int month)
{
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

		if ((fp[i] = fopen(path.c_str(), "r")) != NULL) //파일을 열었을때
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
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //윤년(2/29)
				day[1] = 29;
			else
				day[1] = 28;
		}

		days += day[i];
	}
	//7일씩 나눠주면 전달에서 다음달로 넘어갈때 첫주 칸을 채울 count
	first_date = days % 7;

	//여기서부터 달력출력
	char eng_month[][12] = { "January","February","March","April","May","June","July","August","September","October","November", "December" }; //월 영어이름

	printf("\n\n▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n\n");
	printf("%55s %d\n\n", eng_month[month - 1], year);
	printf("================================================================================================================\n");
	printf("|      SUN       |     MON      |      TUE     |       WED      |      THU     |       FRI     |       SAT     |\n");
	printf("================================================================================================================\n");
	//1년 1월 1일은 월요일. (시작은 일요일부터)
	for (int i = 0; i <= first_date; i++)
		printf("        \t"); //그냥띄우기

	for (int i = 1; i <= day[month - 1]; i++)
	{
		if ((i + first_date) % 7 == 0)
		{
			for (int k = 0; k < 4; k++) {
				for (int j = 0; j < 7; j++) {
					int index = i + j - 8;
					if (sch[k][index] != ""&&index >= 0) {
						gotoxy(16 * ((i + j + first_date) % 7) + 1, ((i + j + first_date) / 7) * 6 + 5 + k);
						printf(sch[k][index].c_str());
					}
					else
						printf("\t\t");
				}
			}
			printf("\n");
		}
		printf("▤ %-8d\t", i);
	}

	printf("\n\n\n\n\n\n\n");
	printf("▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n");
}
void Mainscreen()
{
	Calendar(tm.tm_year + 1900, tm.tm_mon + 1);

	printf("\n\n\n");
	printf("    Choose the desired from of plan from 4 options.\n\n\n");

	printf("     opt1. A monthly unit\n\n");
	printf("     opt2. A weekly unit\n\n");
	printf("     opt3. A Daily unit\n\n");
	printf("     opt4. Change Schedule\n\n");
	printf("     opt0. Change Color\n\n");
	while (1)
	{
		printf("    Choose option : ");

		scanf("%d", &opt);
		system("cls"); //화면 전체지우기
		if (opt == 1)
		{
			Sleep(100); //느리게
			Option1();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100); //느리게
			Option2();
			break;
		}
		else if (opt == 3)
		{
			Sleep(100); //느리게
			Option3();
			break;
		}
		else if (opt == 4)
		{
			Sleep(100); //느리게
			Option4();
			break;
		}
		else if (opt == 0)
		{
			Sleep(100);
			changeColor();
			break;
		}
		else if (opt < 1 || opt>4)
		{
			system("cls"); //화면 전체지우기
			Calendar(tm.tm_year + 1900, tm.tm_mon + 1);
			printf("\n             ☆★☆★☆ Please re-enter ★☆★☆★\n\n");
			printf("    Choose the desired from of plan from 4 options.\n\n\n");

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
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void Option1()
{
	int year = 0, month = 0;
	while (1)
	{
		printf("Year : ____\b\b\b\b     Month : __\b\b");
		gotoxy(7, 1);
		scanf("%d", &year);
		gotoxy(21, 1);
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
	Calendar(year, month); //달력출력

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
			Option4();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100);
			system("cls"); //화면 전체지우기
			Mainscreen();
			break;
		}
		else if (opt < 1 || opt>2)
		{
			system("cls"); //화면 전체지우기
			Calendar(year, month); //옵션1 결과물 재출력후
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
void Option2()
{
	int wknum;
	int year, month;
	int day[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int days = 0;
	int first_date = 0;

	printf("Year : ____\b\b\b\b     Month : __\b\b    Week : _\b\b");
	gotoxy(7, 1);
	scanf("%d", &year);
	gotoxy(21, 1);
	scanf("%d", &month);
	gotoxy(32, 1);
	scanf("%d", &wknum);

	days = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;

	for (int i = 0; i < month - 1; i++)
	{
		if (i == 1)
		{
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //윤년(2/29)
				day[1] = 29;
			else
				day[1] = 28;
		}
		days += day[i];
	}
	//7일씩 나눠주면 전달에서 다음달로 넘어갈때 첫주 칸을 채울 count
	first_date = days % 7;

	Calendar_week(tm.tm_year + 1900, tm.tm_mon + 1, wknum - 1);
	//옵션2 진행 후

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
			Option4();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100);
			system("cls"); //화면 전체지우기
			Mainscreen();
			break;
		}
		else if (opt < 1 || opt>2)
		{
			system("cls"); //화면 전체지우기
						   //옵션2결과물 출력후
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
void Option3()
{
	int year = 0, month = 0, date = 0;
	while (1)
	{
		printf("Year : ____\b\b\b\b     Month : __\b\b    Date : __\b\b");
		gotoxy(7, 1);
		scanf("%d", &year);
		gotoxy(21, 1);
		scanf("%d", &month);
		gotoxy(31, 1);
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
			Option4();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100);
			system("cls"); //화면 전체지우기
			Mainscreen();
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
void Option4()
{
	char schd[20];
	char title[40];
	char path_file[50] = "Calendar_data/";
	FILE* fp = NULL;
	printf("Enter file name to save(ex. 2017.12.12): ");
	gotoxy(42, 1);
	system("mkdir Calendar_data");
	for (int i = 1; i < 60; i++)
	{
		gotoxy(42 + i, 1);
		printf(" ");
	}
	gotoxy(42, 1);
	scanf("%s", title);
	printf("\n\n");
	strcat(title, ".txt");
	strcat(path_file, title);
	fp = fopen(path_file, "w"); //포인트에 입력받은 제목으로 파일을 쓰기 형식으로 열기
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

	//옵션4진행후

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
			Option4();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100); //느리게
			system("cls"); //화면 전체지우기
			Mainscreen();
			break;
		}
		else if (opt < 1 || opt>2)
		{
			system("cls"); //화면 전체지우기
						   //옵션4 결과물 출력후
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
void changeColor()
{
	system("cls");
	printf("Change Color\n");
	ColorString(" 0 Black \t", 0); ColorString(" 1 Blue \t", 1); ColorString(" 2 Green \t", 2);
	ColorString(" 3 Greenblue \t", 3); ColorString(" 4 Red \n", 4); ColorString(" 5 purple \t", 5);
	ColorString(" 6 Yellow \t", 6); ColorString(" 7 White \t", 7); ColorString(" 8 Gray \t", 8);
	ColorString(" 9 Skyblue \n", 9); ColorString(" 10 Softgreen \t", 10); ColorString(" 11 Softblue \t", 11);
	ColorString(" 12 Softred\t", 12); ColorString(" 13 Softpurple \t", 13); ColorString(" 14 Softyellow \n", 14);

	int scan;
	printf("Enter want color : ");
	scanf("%d", &scan);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), scan);
	system("cls");
	Mainscreen();
}
void ColorString(char* str, int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	printf(str);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}


void Calendar_week(int year, int month, int wknum)
{
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
		if ((fp[i] = fopen(path.c_str(), "r")) != NULL) //파일을 열었을때
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
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //윤년(2/29)
				day[1] = 29;
			else
				day[1] = 28;
		}
		days += day[i];
	}
	//7일씩 나눠주면 전달에서 다음달로 넘어갈때 첫주 칸을 채울 count
	first_date = days % 7;

	//여기서부터 달력출력
	char eng_month[][12] = { "January","February","March","April","May","June","July","August","September","October","November", "December" }; //월 영어이름

	printf("\n\n▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n\n");
	printf("%55s %d\n\n", eng_month[month - 1], year);
	printf("================================================================================================================\n");
	printf("       SUN             MON             TUE             WED             THU             FRI             SAT      \n");
	printf("================================================================================================================\n");
	//1년 1월 1일은 월요일. (시작은 일요일부터)
	for (int i = 0; i <= first_date; i++)
		printf("        \t"); //그냥띄우기

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
						gotoxy(16 * ((7 + j) % 7) + 1, ((7 + j) / 7) * 6 + 7 + k);
						printf(sch[k][index].c_str());
					}
					else
						printf("\t\t");
				}
			}
		}
		if ((first_date + i) / 7 == wknum) {
			gotoxy(16 * ((7 + (first_date + i) % 7) % 7) + 1, ((7 + (first_date + i) % 7) / 7) * 6 + 5);
			printf("▤ %-8d\t", i);
		}
	}

	printf("\n\n▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩▩\n");
}