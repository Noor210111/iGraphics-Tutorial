#include <iostream>
#include <string>
#include "iGraphics.h"

using namespace std;

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://



char dino[5][50] = { "image\\1.bmp", "image\\2.bmp", "image\\3.bmp", "image\\4.bmp", "image\\5.bmp" };
int dinoIndx = 0;
int dy = 225;
int bx = 800;
char str[50], strOver[50];
string s, sOver;
int score = 0, over = 0;
int bh = 50, bw = 25;


void iDraw()
{
	iClear();

	if (over == 0)
	{
		iSetColor(255, 255, 255);
		iFilledRectangle(0, 0, 1000, 800);

		iSetColor(0, 0, 0);
		iRectangle(100, 100, 800, 500);
		iFilledRectangle(bx, 225, bw, bh);

		iSetColor(155, 155, 155);
		iFilledRectangle(100, 200, 800, 25);

		iShowBMP(200, dy, dino[dinoIndx]);

		iSetColor(0, 0, 0);
		iText(720, 650, "Your Score: ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(900, 650, str, GLUT_BITMAP_TIMES_ROMAN_24);
	}

	else
	{
		iShowBMP(0, 0, "image\\frontPage.bmp");

		iSetColor(0, 255, 0);
		iText(500, 500, "Your Score is: ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(650, 500, strOver, GLUT_BITMAP_TIMES_ROMAN_24);
	}

}





/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{


}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{


	}


	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{

	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == ' ' && dy == 225)
	{
		dy = dy + 60;
	}

}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{


	if (key == GLUT_KEY_RIGHT)
	{

	}
	if (key == GLUT_KEY_LEFT)
	{

	}

	if (key == GLUT_KEY_HOME)
	{

	}

}


void change()
{
	if (dinoIndx == 4) dinoIndx = -1;
	dinoIndx++;
}

void change2()
{
	if (bx == 125)
	{
		bx = 800;

		bh = rand() % 50;
		if (bh < 10) bh = 10;

		bw = rand() % 25;
		if (bw < 5) bw = 5;
	}
	bx -= 3;
}

void change3()
{
	if (dy > 225)
		dy -= 10;
}

void change4()
{
	if (bx <= 298 && bx >= 200 && dy == 225)
	{
		over = 1;

		sOver = s;
		int size = sOver.size();
		int i;
		for (i = 0; i < size; i++)
		{
			strOver[i] = s[i];
		}
		strOver[i] = '\0';
		
		bx += 1;
	}
}

void change5()
{
	score++;

	s = to_string(score);

	int size = s.size();
	int i;
	for (i = 0; i < size; i++)
	{
		str[i] = s[i];
	}
	str[i] = '\0';
}

int main()
{
	iSetTimer(50, change);
	iSetTimer(1, change2);
	iSetTimer(300, change3);
	iSetTimer(1, change4);
	iSetTimer(100, change5);

	PlaySound("music\\sound.wav", NULL, SND_ASYNC | SND_LOOP);

	iInitialize(1000, 800, "Dinosaur Run");
	iStart();

	return 0;
}