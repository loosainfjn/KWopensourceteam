#pragma once
#include<stdio.h>

#include<time.h>

#include<conio.h>

#include<windows.h>

#include<math.h>

#pragma warning (disable : 4996)

#define LEFT 75

#define RIGHT 77

#define UP 72

#define DOWN 80

#define ESC 27



#define MAP_ADJ_X 10

#define MAP_ADJ_Y 5

class Game2048{
public:
	int board[4][4] = { // 게임판 

		{ 0,0,0,0 },

	{ 0,0,0,0 },

	{ 0,0,0,0 },

	{ 0,0,0,0 }

	};



	int game_over_on = 0; //게임 오버 스위치 

	int score; //점수 저장함수 



	int made_32; // 각 해당하는 번호의 블록을 만들었을때 메세지 띄워주기 위한 flag들.. 

	int made_64;

	int made_128;

	int made_256;

	int made_512;

	int made_1024;

	int made_2048;

	int made_4096;



	void reset(void); //게임을 초기화 

	void draw(void); // 게임판을 그림 

	void new_num(void); // 새로운 숫자 2나 4를 게임판에 만듦 

	int get_key(void); // 키입력받고 움직이는 함수 

	void check_2048(void); // 블록을 만들었을때 메세지 띄어주는 함수 

	void check_game_over(void); // 게임오버를 판단하는 함수 

	void Game2048_main();
};