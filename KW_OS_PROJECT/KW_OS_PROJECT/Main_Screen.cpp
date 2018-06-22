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
#include "Tetris.h"
#include "Game2048.h"
#include "SnakeGame.h"
#include "HanoiTower.h"

int opt;
time_t t = time(NULL);
struct tm tm = *localtime(&t); 

void Screen::Main_Screen()
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
	printf("     opt5. Playing Game\n\n");
	printf("     opt0. Change Color\n\n");
	while (1)
	{
		printf("    Choose Option : ");

		scanf("%d", &opt);
		system("cls"); //화면 전체지우기
		if (opt == 1)
		{
			Sleep(100); //느리게
			Calendar_Option_in_Calendar_Main_Screen.Calendar_Option1();
			break;
		}
		else if (opt == 2)
		{
			Sleep(100); //느리게
			Calendar_Option_in_Calendar_Main_Screen.Calendar_Option2();
			break;
		}
		else if (opt == 3)
		{
			Sleep(100); //느리게
			Calendar_Option_in_Calendar_Main_Screen.Calendar_Option3();
			break;
		}
		else if (opt == 4)
		{
			Sleep(100); //느리게
			Calendar_Option_in_Calendar_Main_Screen.Calendar_Option4();
			break;
		}
		else if (opt == 5)
		{
			system("cls");
			Sleep(100);
			printf("\n\n\n\n\n");
			printf("<Game1> Tetris\n\n\n");
			printf("<Game2> 2048\n\n\n");
			printf("<Game3> Snake\n\n\n");
			printf("<Game4> Hanoi Tower\n\n\n");

			while (1) {
				printf("    Choose Game : ");
				int gameopt;
				scanf("%d", &gameopt);
				system("cls"); //화면 전체지우기
				if (gameopt == 1)
				{
					Sleep(100); //느리게
					Tetris Tetris_in_Calendar_Main_Screen;
					Tetris_in_Calendar_Main_Screen.Tetris_main();
					break;
				}
				else if (gameopt == 2)
				{
					Sleep(100); //느리게
					Game2048 Game2048_in_Main_Screen;
					Game2048_in_Main_Screen.Game2048_main();
					break;
				}
				else if (gameopt == 3)
				{
					Sleep(100); //느리게
					SnakeGame SnakeGame_in_Main_Screen;
					SnakeGame_in_Main_Screen.SnakeGame_main();
					break;
				}
				else if (gameopt == 4)
				{
					Sleep(100); //느리게
					HanoiTower HanoiTower_in_Main_Screen;
					HanoiTower_in_Main_Screen.HanoiTower_main();
					break;
				}
				else if (gameopt < 1 || gameopt>4)
				{
					system("cls"); //화면 전체지우기
					printf("\n             ☆★☆★☆ Please re-enter ★☆★☆★\n\n");
					printf("    Choose the desired from of Game from 4 Options.\n\n");
					printf("<Game1> Tetris\n\n\n");
					printf("<Game2> 2048\n\n\n");
					printf("<Game3> Snake\n\n\n");
					printf("<Game4> Hanoi Tower\n\n\n");
					
					continue;
				}
				else
				{
					printf("\n\n");
					break;
				}
			}
			break;
		}
		
		else if (opt == 0)
		{
			Sleep(100);
			Calendar_Option_in_Calendar_Main_Screen.Calendar_ChangeColor();
			break;
		}
		else if (opt < 0 || opt>5)
		{
			system("cls"); //화면 전체지우기
			Calendar_in_Calendar_Main_Screen.Calendar_Month(tm.tm_year + 1900, tm.tm_mon + 1);
			printf("\n             ☆★☆★☆ Please re-enter ★☆★☆★\n\n");
			printf("    Choose the desired from of plan from 6 Options.\n\n\n");

			printf("     opt1. A monthly unit\n\n");
			printf("     opt2. A weekly unit\n\n");
			printf("     opt3. A Daily unit\n\n");
			printf("     opt4. Change Schedule\n\n");
			printf("     opt5. Playing Game\n\n");
			printf("     opt0. Change Color\n\n");
			continue;
		}
		else
		{
			printf("\n\n");
			break;
		}
	}
}