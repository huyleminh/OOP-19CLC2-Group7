#ifndef GRAPHIC_H
#define GRAPHIC_H
#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
using namespace std;
const int BLUE = 1;
const int GREEN = 2;
const int AQUA = 3;
const int RED = 4;
const int PURPLE = 5;
const int YELLOW = 6;
const int GRAY = 8;
const int LIGHT_BLUE = 9;
const int LIGHT_GREEN = 10;
const int LIGHT_AQUA = 11;
const int LIGHT_PURPLE = 13;
const int LIGHT_YELLOW = 14;
const int WHITE = 15;
const int PINK = 12;

class Graphic
{
public:
	static string transPassword(); // transform password to *******
	static void changeColour(string s,int colour);//Input number to change colour
	static void setWidth(int n);// \t n times
	static void setHeight(int n);// \n n times;
	static void font(int x, int y);// upsize console
};

#endif

