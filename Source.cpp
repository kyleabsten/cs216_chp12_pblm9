/*
Programmer: Kyle Absten
Date: 04/13/2020
Description:
This program is for cs216 chapter 12 problem 9.  This program will ask the user for a line of input.  It will then run the user input
through three different functions.  Function 1 will turn all upper case character to lower case, and turn all lowercase characters to uppercase.\
Function two will turn all upper case characters to lower case.  Function three will turn all lower case characters uppercase.
*/

#include <cctype>
#include <iostream>
#include <string>
using namespace std;



void flip(char*);  //Function prototype.  Takes a pointer to a char; returns void
void lower(char*); //Function prototype.  Takes a pointer to a char; returns void
void upper(char*); //Function prototype.  Takes a pointer to a char; returns void

int main()
{
	string userInput;  //String to hold user input
	int inputSize;
	cout << "Enter a string to see it in other ways: ";
	getline(cin, userInput);  //Record user input to userInput string
	inputSize = userInput.length(); //Set inputSize int to length of userInput string
	char* cString = new char[inputSize + 1]; //Dynamically allocate memory for an array of characters called cString
	strcpy_s(cString, inputSize + 1, userInput.c_str());// Ust strcpy_s to convert userInput from a string to a c-string and store it in cString
	cout << cString << endl; //Print the original cString
	flip(cString);  //Call flip with cString as the argument
	cout << cString << endl; //Print cString after the call to flip
	lower(cString);  //Call lower with cStrgin as the argument
	cout << cString << endl; //Print cString after the call to lower
	upper(cString);  //Call upper with cString as the argument
	cout << cString << endl;  //Print cString after the call to upper

	return 0;
}

void flip(char* inputCstring) //Void function that accepts a pointer to a char as and argument
{
	while (*inputCstring != NULL) //Loop until you reach a Null character
	{ 
		if (*inputCstring == toupper(*inputCstring))  //If the pointer points to a character that is equal to the upper case of that character
		{
			*inputCstring = tolower(*inputCstring);  //Set the character that the pointer points to to the lowercase of that character
		}
		else { //If it doesn't
			*inputCstring = toupper(*inputCstring); //Set the character pointed to by the pointer to the uppercase of that character
		}
		inputCstring++;  //Move ahead one address

	}
}

void lower(char* inputCstring)  //Void function that accepts a pointer to a char as and argument
{
	while (*inputCstring != NULL)  //Loop over char array until a Null character is reached
	{
		if (*inputCstring == toupper(*inputCstring))  //If character pointed to by inputCstring is the same as the upper case version of that
		{
			*inputCstring = tolower(*inputCstring);  //Set the character pointed to by inputCstring to the lower case version
		}
		inputCstring++; //Move to the next memory location of the array

	}
}

void upper(char* inputCstring)  //Void function that accepts a pointer to a char as and argument
{
	while (*inputCstring != NULL)  //Loop over char array until a Null character is reached
	{
		if (*inputCstring == tolower(*inputCstring))//If character pointed to by inputCstring is the same as the lower case version of that
		{
			*inputCstring = toupper(*inputCstring);  //Set the character pointed to by inputCstring to the upper case version
		}
		inputCstring++;  //Move to the next memory location

	}
}