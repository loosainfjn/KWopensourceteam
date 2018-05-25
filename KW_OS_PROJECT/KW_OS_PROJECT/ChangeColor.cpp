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
#define STD_OUTPUT_HANDLE ((DWORD)-11)
#include "Color_String.h"

void Calendar_Option::Calendar_ChangeColor()
{
	Color_String Color_String_in_ChangeColor;
	Screen Screen_in_ChangeColor;
	system("cls");
	printf("Change Color\n");
	Color_String_in_ChangeColor.colorstring(" 0 Black \t", 0);
	Color_String_in_ChangeColor.colorstring(" 1 Blue \t", 1);
	Color_String_in_ChangeColor.colorstring(" 2 Green \t", 2);
	Color_String_in_ChangeColor.colorstring(" 3 Greenblue \t", 3);
	Color_String_in_ChangeColor.colorstring(" 4 Red \n", 4);
	Color_String_in_ChangeColor.colorstring(" 5 purple \t", 5);
	Color_String_in_ChangeColor.colorstring(" 6 Yellow \t", 6);
	Color_String_in_ChangeColor.colorstring(" 7 White \t", 7);
	Color_String_in_ChangeColor.colorstring(" 8 Gray \t", 8);
	Color_String_in_ChangeColor.colorstring(" 9 Skyblue \n", 9);
	Color_String_in_ChangeColor.colorstring(" 10 Softgreen \t", 10);
	Color_String_in_ChangeColor.colorstring(" 11 Softblue \t", 11);
	Color_String_in_ChangeColor.colorstring(" 12 Softred\t", 12);
	Color_String_in_ChangeColor.colorstring(" 13 Softpurple \t", 13);
	Color_String_in_ChangeColor.colorstring(" 14 Softyellow \n", 14);

	int scan;
	printf("Enter want color : ");
	scanf("%d", &scan);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), scan);
	system("cls");
	Screen_in_ChangeColor.Calendar_Main_Screen();
}
void Color_String::colorstring(char* str, int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	printf(str);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}