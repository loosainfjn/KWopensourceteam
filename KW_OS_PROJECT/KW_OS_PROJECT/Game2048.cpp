#include<stdio.h>

#include<time.h>

#include<conio.h>

#include<windows.h>

#include<math.h>

#include"Game2048.h"

#pragma warning (disable : 4996)

#define LEFT 75

#define RIGHT 77

#define UP 72

#define DOWN 80

#define ESC 27



#define MAP_ADJ_X 10

#define MAP_ADJ_Y 5



void gotoxy_Game2048(int x, int y) { //모니터상의 x,y 좌표로 이동시키는 함수 

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}



typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;

void setcursortype_Game2048(CURSOR_TYPE c) { //커서 표시를 바꿔주는 함수  

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






void Game2048::Game2048_main() {

	setcursortype_Game2048(NOCURSOR); //마우스 커서를 지우기 



	reset(); //게임을 초기화 



	while (1) {

		if (get_key()) { //키 입력후 움직임이 있는 경우에만 

			check_2048(); // 블록체크 

			new_num();    //새로운 숫자를 만듦 

		}

		check_game_over(); // 게임오버판단 

	}

}



void Game2048::reset(void) {

	int i, j; // for문을 돌리는 변수들 



	system("cls"); //화면을 지움 



	for (i = 0; i<4; i++) for (j = 0; j<4; j++) board[i][j] = 0; //게임판을 초기화 



																 //각종변수 초기화 

	score = 0;

	game_over_on = 0;



	made_32 = 0;

	made_64 = 0;

	made_128 = 0;

	made_256 = 0;

	made_512 = 0;

	made_1024 = 0;

	made_2048 = 0;

	made_4096 = 0;



	//배경을 그림     

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y - 4);

	printf("  ─┐┌┐││┌┐");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y - 3);

	printf("  ┌┘││└┤├┤");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y - 2);

	printf("  └─└┘  │└┘");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y - 1);

	printf("┌────────────┐");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 1);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 2);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 3);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 4);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 5);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 6);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 7);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 8);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 9);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 10);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 11);

	printf("│                        │");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 12);

	printf("└────────────┘");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 14);

	printf(" ◇ ←,→,↑,↓ : Move");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 16);

	printf(" ◇ ESC : Quit");

	gotoxy_Game2048(MAP_ADJ_X - 2, MAP_ADJ_Y + 18);

	



	//새로운 숫자를 2개 만듦 

	new_num();

	new_num();

}



int Game2048::get_key(void) {

	int i, j;



	int key = 0; //입력받은 키를 저장하는 변수 

	int act = 0; //입력받은 키가 유효한 작용을 했을때 함수가 값을 return하는 것을 돕는 변수 

	int mov = -1; //입력받은 키가 유효한 작용을 했을때 반복문을 탈출할수 있게 하는 변수 



	gotoxy_Game2048(0, 24); //ESC키를 눌렀을때 화면 제일 아래에 종료문구를 띄우기 위해 커서 이동 

	key = getch(); //키입력받음 

	if (key == ESC) {

		gotoxy_Game2048(0, 21); //화면 제일 아래에 종료문구를 띄우기 위해 커서 이동 

		exit(0); // ESC키를 누르면 게임종료 

	}

	if (key == 0xE0 || key == 0) {

		key = getch();



		switch (key) {

		case LEFT:     //왼쪽방향키를 누른경우 

			for (; mov != 0;) {     //함수 실행시 mov값이 -1이므로 처음엔 반드시 실행되고 실행후 0으로 변경, 

				mov = 0;         //이후 게임판에 변화가 있는 경우에 수치 증가하여 게임판에 변화가 없을때까지 반복 

				for (i = 0; i<4; i++) {  // 모든행을 검사 

					for (j = 1; j <= 3; j++) { //가장 왼쪽열(0번째열)은 검사할 필요가 없으므로 1~3번열을 순서대로 검사 

						if (board[i][j] == 0 || board[i][j]>10000) continue; //자기 값이 0 혹은 10000보다 큰 경우,

						if (board[i][j - 1] != 0 && board[i][j - 1] != board[i][j]) continue;

						//자기 왼쪽값이 0이 아니고 자신과 다른 경우 다시 검사(j++은 적용됨)

						if (board[i][j - 1] == 0) board[i][j - 1] = board[i][j]; //자기 왼쪽값이 0인경우 자기값 복사 

						else if (board[i][j] == board[i][j - 1]) { //자기 왼쪽값과 동일한 경우에 

							board[i][j - 1] *= 2; //왼쪽값을 2배로(자기 값을 더하는것과 같음) 

							board[i][j - 1] += 10000; // 임시로 값증가 함수 마지막에 다시 값을 감소시킴 

							score += 2 * (board[i][j]); //점수를 증가     

						}

						board[i][j] = 0; //자기 값은 0으로 지움 

						act++; // action이 있음을 알림(get_key 함수 종료시 판단됨) 

						mov++; // mov가 있음을 알림(for문안에서만 사용되고 리셋됨) 

					}   /* 10000을 안더하면 만약 한줄에 값이 2,2,2,2 인 경우 왼쪽키를 누르면 한번에       */

				}       /* 8,0,0,0으로 바뀜.. 10000을 더하고, 값이 10000보다 큰 경우 연산을 하지 않게 하여*/

						/* 2,2,2,2 에서 4,4,0,0으로 바뀜 */

				if (mov != 0) draw();// 게임판 변화가 있는 경우 

			}                      // 제일 바깥 for문을 한번 돌때마다 화면을 그려줌(애니메이션 효과) 

			break;



		case RIGHT: // 오른쪽 방향키를 누른경우. 작동원리는 동일 좌우만 바뀜 

			for (; mov != 0;) {

				mov = 0;

				for (j = 2; j >= 0; j--) { //2번열, 1번열, 0번열을 순서대로 검사. 

					for (i = 0; i<4; i++) {  // 모든행을 검사

						if (board[i][j] == 0 || board[i][j]>10000) continue;

						if (board[i][j + 1] != 0 && board[i][j + 1] != board[i][j]) continue;

						if (board[i][j + 1] == 0) board[i][j + 1] = board[i][j];

						else if (board[i][j]<10000 && board[i][j] == board[i][j + 1]) {

							board[i][j + 1] *= 2;

							board[i][j + 1] += 10000;

							score += 2 * (board[i][j]);

						}

						board[i][j] = 0;

						mov++;

						act++;

					}

				}

				if (mov != 0) draw();

			}

			break;



		case UP: // 위쪽 방향키를 누른경우. 작동원리는 동일 

			for (; mov != 0;) {

				mov = 0;

				for (i = 1; i <= 3; i++) { //1번행, 2번행, 3번행을 순서대로 검사 

					for (j = 0; j<4; j++) { //모든 열을 검사 

						if (board[i][j] == 0 || board[i][j]>10000) continue;

						if (board[i - 1][j] != 0 && board[i - 1][j] != board[i][j]) continue;

						if (board[i - 1][j] == 0) board[i - 1][j] = board[i][j];

						else if (board[i][j]<10000 && board[i][j] == board[i - 1][j]) {

							board[i - 1][j] *= 2;

							board[i - 1][j] += 10000;

							score += 2 * (board[i][j]);

						}

						board[i][j] = 0;

						act++;

						mov++;

					}

				}

				if (mov != 0) draw();

			}

			break;



		case DOWN: // 아래쪽 방향키를 누른경우. 작동원리는 동일

			for (; mov != 0;) {

				mov = 0;

				for (i = 2; i >= 0; i--) { //2번행, 1번행, 0번행을 순서대로 검사  

					for (j = 0; j<4; j++) { //모든 열을 검사  

						if (board[i][j] == 0 || board[i][j]>10000) continue;

						if (board[i + 1][j] != 0 && board[i + 1][j] != board[i][j]) continue;

						if (board[i + 1][j] == 0) board[i + 1][j] = board[i][j];

						else if (board[i][j]<10000 && board[i][j] == board[i + 1][j]) {

							board[i + 1][j] *= 2;

							board[i + 1][j] += 10000;

							score += 2 * (board[i][j]);

						}

						board[i][j] = 0;

						act++;

						mov++;

					}

				}

				if (mov != 0) draw();

			}

			break;

		}

	}



	for (i = 0; i<4; i++) { //임시로 증가시켰던 10000을 빼줌. 

		for (j = 0; j<4; j++) {

			if (board[i][j]>10000)board[i][j] -= 10000;

		}

	}



	if (act == 0) return 0; //만약 키입력후 변화가 없으면 0을 return 

	else return 1;  //키입력후 변화가 있으면 1을 return 

}



void Game2048::draw() {

	int i, j, k; // for문을 돌리기 위한 변수 

	int num; // 게임판의 값을 화변에 칸을 표시하기 위한 색깔을 검사하게 되는데 

			 // 10000이 더해진 경우,  이값을 임시로 뺀 숫자를 저장하는 변수 

	for (i = 0; i<4; i++) {

		for (j = 0; j<4; j++) {

			gotoxy_Game2048(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));

			if (board[i][j] == 0) { //값이 0일때 달성한 블록flag에 따라 다른 배경을 보여줌 

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

				gotoxy_Game2048(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));

				printf("      ");

				gotoxy_Game2048(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 1);

				if (made_2048 == 1) printf("  ♥  ");

				else if (made_1024 == 1) printf("  ♡  ");

				else if (made_512 == 1) printf("  ♬  ");

				else if (made_256 == 1) printf("  ♪  ");

				else if (made_128 == 1) printf("  ♩  ");

				else if (made_64 == 1) printf("  ♣  ");

				else if (made_32 == 1) printf("  ♤  ");

				else printf("  ┿  ");

				gotoxy_Game2048(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 2);

				printf("      ");

			}

			else {

				num = ((board[i][j]>10000) ? board[i][j] - 10000 : board[i][j]); //10000이 더해진 경우 보정 

				if (game_over_on == 1) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

				else { //게임오버인 경우에는 회색으로  

					for (k = 0; k<12;) if ((int)pow(2, ++k) == num) break; //값에 따라 다른 색깔값을 구함

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k + 1);//색깔값 적용 

				}

				gotoxy_Game2048(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3));

				printf("┌─┐");

				gotoxy_Game2048(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 1);

				printf(" %4d ", num);

				gotoxy_Game2048(MAP_ADJ_X + (j * 6), MAP_ADJ_Y + (i * 3) + 2);

				printf("└─┘");

				if (game_over_on == 1) Sleep(200);  //게임오버인 경우 한칸 그리고 0.2초의 딜레이 

			}

		}

	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); //원래 색깔로 고침 



	gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y + 11);

	printf("Score : %6d \n", score); //점수표시 

	Sleep(50);

}



void Game2048::new_num() {

	int i, j; //for문을 돌리는 변수



	int cnt; //게임판에 빈칸을 세어 저장하는 변수 

	int rdm; //난수표에 의해 생성된 값을 저장하는 변수 

	int n_num; // 새로운 숫자 2, 4를 저장하는 변수 

	int* p0[16] = { 0 }; //빈칸의 위치를 기억할 포인터 배열 



	for (i = 0, cnt = 0; i<4; i++) { //전체 게임판을 검사

		for (j = 0; j<4; j++) {

			if (board[i][j] == 0) { //빈칸이 있으면 

				p0[cnt++] = &board[i][j]; //그 위치를 포인터 배열에 저장, cnt값 증가 

			}

		}

	}



	srand(time(0)); //난수 생성 

	rdm = rand() % (cnt); //포인터 배열cnt수보다 작은 값으로 저장. 

	n_num = (rand() % 100<80) ? 2 : 4; //80%확률로 2을 만들고, 20%확률로 4를 만듦 



	*p0[rdm] = n_num; //빈칸에 수를 넣음 

	draw();

	*p0[rdm] = 0;        //애니메이션 효과 두번깜박임 

	draw();

	*p0[rdm] = n_num;

	draw();

}



void Game2048::check_2048(void) { //32번부터 새로운 큰 수를 처음 만들었을때 메세지 표시. 

	int i, j, k;



	for (i = 0; i<4; i++) {

		for (j = 0; j<4; j++) {

			if (board[i][j] == 32 && made_32 == 0) {

				made_32 = 1;

				for (k = 0; k<3; k++) {

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					printf("                                        ");

					Sleep(100);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					printf("Yon made 32 : ");

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

					printf("Good job!");

					Sleep(100);

				}

				gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);

				printf("Keep play to make 2048");

			}

			if (board[i][j] == 64 && made_64 == 0) {

				made_64 = 1;

				for (k = 0; k<3; k++) {

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					printf("                                        ");

					Sleep(100);

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

					printf("Yon made 64 : ");

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

					printf("Great!   ");

					Sleep(100);

				}

			}

			if (board[i][j] == 128 && made_128 == 0) {

				made_128 = 1;

				for (k = 0; k<3; k++) {

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					printf("                                        ");

					Sleep(100);

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);

					printf("Yon made 128 : ");

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

					printf("Hooray!!");

					Sleep(100);

				}

			}

			if (board[i][j] == 256 && made_256 == 0) {

				made_256 = 1;

				for (k = 0; k<3; k++) {

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					printf("                                        ");

					Sleep(100);

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);

					printf("Yon made 256 : ");

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

					printf("I believe you can do it!");

					Sleep(100);

				}

			}

			if (board[i][j] == 512 && made_512 == 0) {

				made_512 = 1;

				for (k = 0; k<3; k++) {

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					printf("                                        ");

					Sleep(100);

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);

					printf("Yon made 512 : ");

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

					printf("awesome!! Keep going!!");

					Sleep(100);

				}

			}

			if (board[i][j] == 1024 && made_1024 == 0) {

				made_1024 = 1;

				for (k = 0; k<3; k++) {

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					printf("                                        ");

					Sleep(100);

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);

					printf("Yon made 1024!! : ");

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

					printf("Almost done!!");

					Sleep(100);

				}

			}

			if (board[i][j] == 2048 && made_2048 == 0) {

				made_2048 = 1;

				for (k = 0; k<3; k++) {

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					printf("                                        ");

					Sleep(100);

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

					printf("Congratulations! Yon made 2048 !!");

					Sleep(100);

				}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);

				printf("You can keep play for a high score;)");

			}

			if (board[i][j] == 4096 && made_4096 == 0) {

				made_4096 = 1;

				for (k = 0; k<3; k++) {

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					printf("                                        ");

					Sleep(100);

					gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);

					printf("Yon made 4086 !!! : I'm impressed    ");

					Sleep(100);

				}

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

				gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);

				printf("You can keep play for a high score;)");

			}

		}

	}

}



void Game2048::check_game_over(void) { //게임오버인지 체크 

	int i, j;



	for (i = 0; i<4; i++) for (j = 0; j<4; j++) if (board[i][j] == 0) return; //일단 빈칸이 있으면 게임오버가 아님 

	for (i = 0; i<3; i++) for (j = 0; j<3; j++) if (board[i][j] == board[i + 1][j] || board[i][j] == board[i][j + 1]) return;

	//0,0부터 2,2까지 오른쪽과 아래를 검사 

	for (i = 0; i<3; i++) if (board[i][3] == board[i + 1][3]) return; //0~2번행은 아래만 검사(오른쪽값이 없으므로) 

	for (j = 0; j<3; j++) if (board[3][j] == board[3][j + 1]) return; //0~2번열은 오른쪽만 검사(아래쪽값이 없으므로) 



	game_over_on = 1;    //게임오버 flag를 on. draw함수에서 애니메이션 효과를 주기 위함 



	gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y);

	printf("Game Over..                             ");

	gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);

	printf("                                        ");

	draw();

	gotoxy_Game2048(MAP_ADJ_X + 28, MAP_ADJ_Y + 2);

	printf("Restart? (Y/N:quit)                     "); // 게임을 다시할건지 물어봄 



	while (1) {

		switch (getch()) {

		case 121: // 'Y'

		case 89: // 'y'

			reset(); //게임을 초기화  

			break;

		case 110: // 'N'

		case 78: //'n'

		case ESC:

			gotoxy_Game2048(0, 21); //화면 제일 아래에 종료문구를 띄우기 위해 커서 이동 

			exit(0);

		}

		break;

	}

}