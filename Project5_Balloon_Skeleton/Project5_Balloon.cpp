#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <vector>
#include "controller.h"
#include "Instructions.h"
#include "constants.h"
#include "ThreadUserInput.h"

using namespace std;

BOOL gotoxy(const WORD x, const WORD y) {
	COORD xy;
	xy.X = x;
	xy.Y = y;
	return SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

int main() {
	int width = DEFAULT_WIDTH;
	int height = DEFAULT_HEIGHT;

	/* get the width and height of the console window*/
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if ( GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)){
		
		width = csbi.dwSize.X;
		height = csbi.srWindow.Bottom - csbi.srWindow.Top;
	}

	ThreadUserInput myInput;
	myInput.start();

	//set up controller
	Controller		myController(width,height,CONTROLLER_SPEED);

	//user input
	char myChar;

	//this is the game loop it runs until we close the app
	for (;;) {
		//go back to location 00 on screen and redraw
		gotoxy(0,0);

		//render the scene
		myController.draw();

		//see if user wants to go anywhere
		myChar = myInput.getInput();
		switch (myChar){
			//if left arrow key is pressed then cosmo will go to the left
		case LEFT_ARROW:
			myController.changeCosmoDirection(LEFT);
			break;
			//if right arrow key is pressed then cosmo will go to the right
		case RIGHT_ARROW:
			myController.changeCosmoDirection(RIGHT);
			break;
			//if up arrow key is pressed then cosmo will stay in place but his arms will point upward
		case UP_ARROW:
			myController.changeCosmoDirection(UP);
			break;
			//if down arrow key is pressed then cosmo will stay in place but his arms will point downward
		case DOWN_ARROW:
			myController.changeCosmoDirection(NO_DIR);
			break;
		//if i or I is pressed then the instructions will appear
		case 'i':
		case 'I':
			myController.setControllerState(SHOW_INTRO);
			break;
		//if r or R is pressed then game will reset
		case 'r':
		case 'R':
			myController.setControllerState(RESET);
			break;
		case 'b':
		case 'B':
			myController.setControllerState(RUN);
			break;
		//if t or T is pressed then terrible balloon will be implemented
		case 't':
		case 'T':
			if (myController.getTerribleBalloonsOn())
				myController.setTerribleBalloonsOn(false);
			else
				myController.setTerribleBalloonsOn(true);
			break;
		case 'x':
		case 'X':
			// safely exit the program
			exit(EXIT_SUCCESS);
			break;
		}
	}

	//this kills the thread that inputs chars
	myInput.stop();

	return 0; 

}
