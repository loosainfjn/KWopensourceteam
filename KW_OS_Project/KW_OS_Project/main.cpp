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

int main()
{
	system("mode con cols=112 lines=180");
	system("tiTle Calendar");

	Screen Screen_in_main;

	
	Screen_in_main.Main_Screen();
	
	return 0;
}