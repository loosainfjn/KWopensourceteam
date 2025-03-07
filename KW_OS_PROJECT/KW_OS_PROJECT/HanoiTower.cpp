#include <stdio.h>

#include <conio.h> //getch함수헤더 

#include <windows.h> //gotoxy_HanoiTower함수헤더 

#include "HanoiTower.h"

#pragma warning(disable:4996)

#define LEFT 75

#define RIGHT 77

#define ENTER 13

#define ESC 27



void gotoxy_HanoiTower(int x, int y)

{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}



typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE; //커서숨기기 함수 

void setcursortype_HanoiTower(CURSOR_TYPE c) {

	CONSOLE_CURSOR_INFO CurInfo;



	switch (c) {

	case NOCURSOR:

		CurInfo.dwSize = 1;

		CurInfo.bVisible = FALSE;

		break;

	case SOLIDCURSOR:

		CurInfo.dwSize = 100;

		CurInfo.bVisible = TRUE;

		break;

	case NORMALCURSOR:

		CurInfo.dwSize = 20;

		CurInfo.bVisible = TRUE;

		break;

	}

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);

}





void HanoiTower::HanoiTower_main() {



	reset();



	while (1) {

		key = getch();

		if (key == 0xE0 || key == 0) {

			key = getch();

			switch (key) {

			case LEFT:

				if (cursor_p>0) cursor_p--;

				break;

			case RIGHT:

				if (cursor_p<2) cursor_p++;

				break;

			}

		}

		else if (key == ENTER && cursor_s == 0) getblock();

		else if (key == ENTER && cursor_s != 0) dropblock();

		else if (key == ESC) menu();

		draw();



		if (hanoi[0][2] == 3) win(); // 오른쪽 젤 윗칸에 3칸짜리 블록이 위치하면 승리 

	}

}



void HanoiTower::reset(void) {

	int i, j;



	setcursortype_HanoiTower(NOCURSOR);



	for (i = 0; i<4; i++) {

		for (j = 0; j<3; j++) {

			hanoi[i][j] = 0;

		}

	}

	hanoi[0][0] = 3;

	hanoi[1][0] = 5;

	hanoi[2][0] = 7;

	hanoi[3][0] = 9;



	cursor_p = 0;

	cursor_s = 0;

	cnt = 0;



	draw();

}



void HanoiTower::draw(void) {

	int i, j, k;

	x = 24;

	y = 3;



	gotoxy_HanoiTower(x, y);



	switch (cursor_p) { //커서부분을 그리는 부분 

	case 0:

		if (cursor_s == 0) {

			printf("     *                            ");

		}

		else {

			for (k = 0; k<(11 - cursor_s) / 2; k++) {

				putchar(' ');

			}

			for (k = 0; k<cursor_s; k++) {

				putchar('#');

			}

			for (k = 0; k<(11 - cursor_s) / 2; k++) {

				putchar(' ');

			}

			printf("                       ");

		}

		break;

	case 1:

		if (cursor_s == 0) {

			printf("                *                 ");

		}

		else {

			printf("           ");

			for (k = 0; k<(11 - cursor_s) / 2; k++) {

				putchar(' ');

			}

			for (k = 0; k<cursor_s; k++) {

				putchar('#');

			}

			for (k = 0; k<(11 - cursor_s) / 2; k++) {

				putchar(' ');

			}

			printf("            ");

		}

		break;

	case 2:

		if (cursor_s == 0) {

			printf("                           *      ");

		}

		else {

			printf("                      ");

			for (k = 0; k<(11 - cursor_s) / 2; k++) {

				putchar(' ');

			}

			for (k = 0; k<cursor_s; k++) {

				putchar('#');

			}

			for (k = 0; k<(11 - cursor_s) / 2; k++) {

				putchar(' ');

			}

		}

		break;

	}



	y += 2;

	gotoxy_HanoiTower(x, y++);

	printf("     |          |          |     ");    //이건 그냥 장식용 장대입니다.. 



	for (i = 0; i<4; i++) { // 하노이 타워 그리는 부분 

		gotoxy_HanoiTower(x, y + i);

		for (j = 0; j<3; j++) {

			if (hanoi[i][j] == 0) {

				printf("     |     ");

			}

			else {

				for (k = 0; k<(11 - hanoi[i][j]) / 2; k++) {

					putchar(' ');

				}

				for (k = 0; k<hanoi[i][j]; k++) {

					putchar('#');

				}

				for (k = 0; k<(11 - hanoi[i][j]) / 2; k++) {

					putchar(' ');

				}

			}



		}

	}

	y += 4;



	gotoxy_HanoiTower(x - 2, y);

	printf("──────────────────"); //타워 받침 

	gotoxy_HanoiTower(x - 2, ++y);

	printf("MOVES : %3d", cnt);

	y++;



	gotoxy_HanoiTower(x + 4, ++y);

	printf("┌─────────┐");

	gotoxy_HanoiTower(x + 4, ++y);

	printf("│ HANOI TOWER GAME │");

	gotoxy_HanoiTower(x + 4, ++y);

	printf("└─────────┘");

	y++;

	y++;



	gotoxy_HanoiTower(x - 2, ++y); printf("KEYS : ENTER, ←, →,  ESC (MENU)");

	y++;

	



}



void HanoiTower::getblock(void) {

	int i;



	for (i = 0; i<4; i++) { //위에서 부터 아래로 체크해가면서  

		if (hanoi[i][cursor_p] != 0) { //블록이 나타나면 (값이 0이 아니면)?

			cursor_s = hanoi[i][cursor_p]; //그 값을 저장하고 

			hanoi[i][cursor_p] = 0; // 그 칸을 지움(값을 0으로) 

			return;

		}

	}

}



void HanoiTower::dropblock(void) {

	int i;



	for (i = 1; i<4; i++) {

		if (hanoi[i][cursor_p] != 0 && hanoi[i][cursor_p]>cursor_s) {

			// 블록값이 있고 잡고있는 블록값보다 높은 경우 

			hanoi[i - 1][cursor_p] = cursor_s;    // 그 블록 위에(i-1) 블록값을 전달 

			cursor_s = 0;            //잡고 있는 블록값은 0으로 

			cnt++;    //턴수 증가 

			return;

		}

	}

	if (hanoi[3][cursor_p] == 0) { // 장대에 블록이 하나도 없는 경우 

		hanoi[3][cursor_p] = cursor_s; // 제일 바닥칸에 블록을 넣음 

		cursor_s = 0; // 잡고 있는 불록값은 0으로 

		cnt++; //턴수 증가 

		return;

	}

}



void HanoiTower::win(void) {

	int ch;



	gotoxy_HanoiTower(7, 1);

	printf("Completed! Your move : %3d", cnt);

	gotoxy_HanoiTower(7, 2);

	printf("Play again?(Y/N) : ");

	setcursortype_HanoiTower(NORMALCURSOR);



	while (1) {

		fflush(stdin);



		ch = getch();

		switch (ch) {

		case 89:

		case 121:

			system("cls");

			setcursortype_HanoiTower(NOCURSOR);

			reset();

			return;

		case 78:

		case 110:

			system("cls");

			exit(0);

		}

	}

}



void HanoiTower::menu(void) {

	int ch;



	setcursortype_HanoiTower(NORMALCURSOR);



	gotoxy_HanoiTower(7, 1);

	printf("MENU: RESUME(ENTER), RESTART(1), QUIT(2) :");



	while (1) {

		ch = getch();

		switch (ch) {

		case 49:

			system("cls");

			setcursortype_HanoiTower(NOCURSOR);

			reset();

			return;

		case 50:

			system("cls");

			exit(0);

		case ENTER:

			system("cls");

			setcursortype_HanoiTower(NOCURSOR);

			draw();

			return;

		}

	}

}