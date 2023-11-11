#include "Pen.h"

//-----------------------------------------------------------------------------
// The Magic Pen
// -----------
//
// General : A program that allows a user to write a string.
//			 Then, its gives the user variety of options.
//			 Among the options, the user can edit the string, add him anoter text and write it to a file.
//
// Input : The program waits that the user will pick a choice from a menu, then each choice has different input.
//
// Process : According to the user choice. The program can add a text to the main string, edit the string, delete
//			 part of him, writing him into a file or to get a string that already written in the file.
//
// Output : The output is according to the user choice. The program will show the string after every change on it and
//			also prints the string that it ggets from the file.
//
//-----------------------------------------------------------------------------
// Programmer : Alon Yaari
// Date : 7.12.22
//-----------------------------------------------------------------------------
void main()
{
	char* string = malloc(sizeof(char) * 12);
	char* arsenal = "arffffsenal";
	strcpy(string, arsenal);
	menu(&string);
}