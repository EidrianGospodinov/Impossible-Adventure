#include "Colours.h"

void setColours(concol textcol, concol backcol) // set text/background colour 
{   // Combine the two 4-bit numbers into a single 8-bit number 
    // If backcol is abcd in binary, and textcol is efgh, the result is abcdefgh 
	unsigned short colours = (backcol << 4) | textcol;
	// set the attributes for the console 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colours);
}