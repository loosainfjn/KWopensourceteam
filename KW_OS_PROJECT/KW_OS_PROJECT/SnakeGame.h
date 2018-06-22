#pragma once
#include<stdio.h>

#include<windows.h>

#include<conio.h>

#include<stdlib.h>

#include<time.h>

#pragma warning(disable:4996)

#define LEFT 75

#define RIGHT 77

#define UP 72

#define DOWN 80

#define PAUSE 112

#define ESC 27



#define MAP_ADJ_X 3

#define MAP_ADJ_Y 2

#define MAP_X 30

#define MAP_Y 20


class SnakeGame {
public:
	int x[100], y[100]; //x,y ��ǥ���� ���� �� 100�� 

	int food_x, food_y; //food�� ��ǥ���� ���� 

	int length; //�����̸� ��� 

	int speed; //���� �ӵ� 

	int score; //���� ����  --reset�Լ��� ���� �ʱ�ȭ��

	int best_score = 0; //�ְ� ���� ���� --reset�Լ��� ���� �ʱ�ȭ ���� ���� 

	int last_score = 0; //������ ���� ����  --reset�Լ��� ���� �ʱ�ȭ ���� ����

	int dir; //�̵����� ���� 

	int key; //�Է¹��� Ű ���� 

	int status_on = 0; // �����ڿ� status ǥ��Ȱ��ȭ ����.. �����߿� SŰ�� ������ Ȱ�� 

	void title(void); //���� ����ȭ�� 

	void reset(void); //������ �ʱ�ȭ 

	void draw_map(void); // ������ �׵θ��� �׸� 

	void move(int dir); //��Ӹ��� �̵� 

	void pause(void); //�Ͻ����� 

	void game_over(void); //���� ������ Ȯ�� 

	void food(void); // ���� ���� 

	void status(void); // �����ڿ� statusǥ��  

	void SnakeGame_main();
};