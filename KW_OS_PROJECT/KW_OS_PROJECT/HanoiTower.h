#pragma once
#include <stdio.h>

#include <conio.h> //getch함수헤더 

#include <windows.h> //gotoxy함수헤더 

#pragma warning(disable:4996)

class HanoiTower {
public:

	int cursor_p; //커서의 위치(0:첫번째 장대, 1:두번재 장대, 2:세번째 장대)

	int cursor_s; //커서가 가지고 있는 블록의 크기값 

	int cnt; // 몇번 이동했는지를 저장 

	int x, y; // 좌표값  

	int key; // 키 입력을 저장하는 변수 



	int hanoi[4][3]; //hanoi tower 블록 위치, 갯수를 저장하는 이차원 배열 



	void reset(void); // 게임을 초기화 

	void draw(void); // 화면을 그리는 함수 

	void getblock(void); //블록을 잡은 함수 

	void dropblock(void); //블록을 떨어트리는 함수 

	void win(void); // 승리조건 확인 

	void menu(void); //메뉴를 호출 

	void HanoiTower_main();
};