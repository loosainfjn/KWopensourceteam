#pragma once
#include <stdio.h>

#include <conio.h> //getch�Լ���� 

#include <windows.h> //gotoxy�Լ���� 

#pragma warning(disable:4996)

class HanoiTower {
public:

	int cursor_p; //Ŀ���� ��ġ(0:ù��° ���, 1:�ι��� ���, 2:����° ���)

	int cursor_s; //Ŀ���� ������ �ִ� ����� ũ�Ⱚ 

	int cnt; // ��� �̵��ߴ����� ���� 

	int x, y; // ��ǥ��  

	int key; // Ű �Է��� �����ϴ� ���� 



	int hanoi[4][3]; //hanoi tower ��� ��ġ, ������ �����ϴ� ������ �迭 



	void reset(void); // ������ �ʱ�ȭ 

	void draw(void); // ȭ���� �׸��� �Լ� 

	void getblock(void); //����� ���� �Լ� 

	void dropblock(void); //����� ����Ʈ���� �Լ� 

	void win(void); // �¸����� Ȯ�� 

	void menu(void); //�޴��� ȣ�� 

	void HanoiTower_main();
};