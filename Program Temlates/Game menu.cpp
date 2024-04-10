#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

void setting();

int main(void)
{
	setting;
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);//Define RED, BLUE,GREEN and other colors
    SetConsoleTextAttribute(hOUTPUT,FOREGROUND_GREEN | FOREGROUND_INTENSITY);//Using Green color
    cout<<"Welcome to D.O.T. game!\nPlease, enter some";
	
	SetConsoleTextAttribute(hOUTPUT,FOREGROUND_RED   | FOREGROUND_INTENSITY);//Using red color
	
	cout<<"Press any button to establish it to move up.\n";
	char moveUP = _getch();//move red dot up
	
	cout<<"Press any button to establish it to move left.\n";
	char moveLEFT = _getch();//move red dot left
	
	cout<<"Press any button to establish it to move down.\n";
	char moveDOWN = _getch();//move red dot down
	
	cout<<"Press any button to establish it to move right.\n";
	char moveRIGHT = _getch();//move red dot right
	
	SetConsoleTextAttribute(hOUTPUT,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"\nThank you! Press any button and enjoy the game!\n\n";
	
}

void setting()
{
	cout<<"Sound: ";
}

