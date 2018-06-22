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
	int board[4][4] = { // ������ 

		{ 0,0,0,0 },

	{ 0,0,0,0 },

	{ 0,0,0,0 },

	{ 0,0,0,0 }

	};



	int game_over_on = 0; //���� ���� ����ġ 

	int score; //���� �����Լ� 



	int made_32; // �� �ش��ϴ� ��ȣ�� ����� ��������� �޼��� ����ֱ� ���� flag��.. 

	int made_64;

	int made_128;

	int made_256;

	int made_512;

	int made_1024;

	int made_2048;

	int made_4096;



	void reset(void); //������ �ʱ�ȭ 

	void draw(void); // �������� �׸� 

	void new_num(void); // ���ο� ���� 2�� 4�� �����ǿ� ���� 

	int get_key(void); // Ű�Է¹ް� �����̴� �Լ� 

	void check_2048(void); // ����� ��������� �޼��� ����ִ� �Լ� 

	void check_game_over(void); // ���ӿ����� �Ǵ��ϴ� �Լ� 

	void Game2048_main();
};