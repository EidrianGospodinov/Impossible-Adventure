#pragma once
#include <Windows.h>
#include <conio.h>

// Auxiliary definitions for coloured output
enum concol // enumeration type, gives names to the built-in colours 
{
	black = 0, dark_blue = 1, dark_green = 2, dark_cyan = 3, dark_red = 4, dark_purple = 5, dark_yellow = 6, light_gray = 7, gray = 8, blue = 9, green = 10, cyan = 11, red = 12, purple = 13, yellow = 14, white = 15
};

void setColours(concol textcol, concol backcol); // set text/background colour 
