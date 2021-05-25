//This is the 1.2. version of the D.O.T. game
//
//Update changes:
//1) green dot included
//2) Yellow points included (Eat them and get a higher score)
//
//summer 2018



#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(void)
{

	//step[1]: define parameters
	const int side_x = 5;
	const int side_y = 5;

	const int times_to_play = 1000;//available steps
	const int yellow_points_number = 2;

	char plant [side_x] [side_y];//field for gaming
	int current_point_x=1;//the current x position of red dot
	int current_point_y=1;//the current y position of red dot

	int score = 0;//your score

	int yellow_point_x [yellow_points_number];
	int yellow_point_y [yellow_points_number];

	for(int k=0; k<yellow_points_number; k++)
	{
        yellow_point_x [k] = rand()%side_x;//the current x position of yellow dot
        yellow_point_y [k] = rand()%side_y;//the current y position of yellow dot
	}









	//step[2.1]: Define colors, writing the title
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);//Define RED, BLUE,GREEN and other colors
    SetConsoleTextAttribute(hOUTPUT,FOREGROUND_GREEN | FOREGROUND_INTENSITY);//Using Green color
    cout<<"Welcome to D.O.T. game!\n";

	//step[2.2]: define UP,LEFT,DOWN,RIGHT buttons (press it for save yor move buttons)
	SetConsoleTextAttribute(hOUTPUT,FOREGROUND_RED   | FOREGROUND_INTENSITY);//Using red color

	cout<<"Please, press any button to establish it to move up.\n";
	char moveUP = _getch();//move red dot up

	cout<<"Please, press any button to establish it to move left.\n";
	char moveLEFT = _getch();//move red dot left

	cout<<"Please, press any button to establish it to move down.\n";
	char moveDOWN = _getch();//move red dot down

	cout<<"Please, press any button to establish it to move right.\n";
	char moveRIGHT = _getch();//move red dot right

	SetConsoleTextAttribute(hOUTPUT,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout<<"\nThank you! Press any button and enjoy the game!\n\n";






	//step[3.0]: it makes an array and draw a blue field for initial statement (Building a frame)
	for (int y = 0; y < side_y; y++)//makes a row
	{
		for (int x = 0; x < side_x; x++)//makes a column
		{
			if(x == current_point_x && y == current_point_y)//this is the red dot case
			{
                SetConsoleTextAttribute(hOUTPUT,FOREGROUND_RED   | FOREGROUND_INTENSITY);//state text color in red
                plant [x] [y] = '*';//red dot adress
                cout<< plant [x] [y]<<" ";//cout this dot
			}

			else //this is the blue dots case
			{
                SetConsoleTextAttribute(hOUTPUT,FOREGROUND_BLUE   | FOREGROUND_INTENSITY);//state text color in blue
                plant [x] [y] = '*';//blue dots
                cout<< plant [x] [y]<<" ";//cout this dots
			}

		}
		cout<<endl;//this is for new row (with that looks much aesthetically)
	}

	SetConsoleTextAttribute(hOUTPUT,FOREGROUND_GREEN   | FOREGROUND_INTENSITY);// Using green color
	cout<<"\nYour Score: "<<score<<endl;








	//step[4.0.]: using "for" for playing this game "times_to_play" times!!!
	for(int times=0; times<=times_to_play; times++)
	{

	//step[4.1]: define your current action
	char nowmove = _getch();//You press "W-A-S-D" and this button would be saved for nowmove

	//step[4.2]: clean previous frame
	system("cls");

	//step[4.3]: Writing the title
	SetConsoleTextAttribute(hOUTPUT,FOREGROUND_GREEN | FOREGROUND_INTENSITY);//Use Green color
    cout<<"Welcome to D.O.T. game!\n\n";
    cout<<"Game's rule:\n\n";
    SetConsoleTextAttribute(hOUTPUT,FOREGROUND_RED   | FOREGROUND_INTENSITY);//Use Red color
    cout<<"You are a red dot\n";
    cout<<"You need to wakl across this field and eat yellow dots!\n";
    cout<<"Enjoy the game.\n\n";

	//step[4.4]: making a statement for UP, LEFT, DOWN, RIGHT cases
	if(nowmove == moveUP)//move up case
	{
		current_point_y = current_point_y - 1;
	}

	if(nowmove == moveLEFT)//move left case
	{
		current_point_x = current_point_x - 1;
	}

	if(nowmove == moveDOWN)//move down case
	{
		current_point_y = current_point_y + 1;
	}

	if(nowmove == moveRIGHT)//move right case
	{
		current_point_x = current_point_x + 1;
	}

	//Step[4.5.]: state a borderlines for red dot
	if(current_point_x<0)
	{
		current_point_x = current_point_x + 1;
	}
	if(current_point_x >= side_x)
	{
		current_point_x = current_point_x - 1;
	}
	if(current_point_y<0)
	{
		current_point_y = current_point_y + 1;
	}
	if(current_point_y >= side_y)
	{
		current_point_y = current_point_y - 1;
	}

	//step[5.0.]: Makes an array and draw a field with dots (and this Building other frames)
	for (int y=0; y<side_y; y++)//makes a row
	{
		for (int x=0; x<side_x; x++)//makes a column
		{
			for(int i=0; i<yellow_points_number; i++)
			{
				if(current_point_x == yellow_point_x[i] && current_point_y == yellow_point_y[i])//if red dot eats yellow dot
				{
					cout<<"\a";
					score = score + 1;
					yellow_point_x[i] = rand()%side_x;//random x position after eating
					yellow_point_y[i] = rand()%side_y;//random y position after eating
				}
			}




			for(int j=0; j<yellow_points_number; j++)
			{
				if(x==yellow_point_x [j] && y==yellow_point_y [j])//Yellow dot
				{
					SetConsoleTextAttribute(hOUTPUT,FOREGROUND_RED | FOREGROUND_GREEN  | FOREGROUND_INTENSITY);//state text color yellow
					plant [x] [y] = '*';// yellow dot
				}
				else
				{
					if(x==current_point_x && y==current_point_y)//Red dot
					{
						SetConsoleTextAttribute(hOUTPUT,FOREGROUND_RED   | FOREGROUND_INTENSITY);//state text color red
						plant [x] [y] = '*';//red dot address
					}
					else//Blue dots
					{
						SetConsoleTextAttribute(hOUTPUT,FOREGROUND_BLUE   | FOREGROUND_INTENSITY);//state text color blue
						plant [x] [y] = '*';// blue dots

					}
				}

				if (j = yellow_points_number - 1 )
				{
				cout<< plant [x] [y] <<" ";
				}
			}



		}

		cout<<endl;//this is for a new row
	}

	SetConsoleTextAttribute(hOUTPUT,FOREGROUND_GREEN   | FOREGROUND_INTENSITY);//Use green color
	cout<<"\nYour Score: "<<score<<endl;

	}










	//step[6.0.]: funny end for not funny and stupid game
	cout<<"\nWooops, time's out. Pay money and play again :)"<<endl;//just kidding
	cout<<"Yes, i'm Electrinic Arts and I want to eat your money"<<endl;//it's a prank, bro :D
	cin.get();//Press Enter to end this
	return 0;//Return this zero and get a life



	//p.s. 2021: I feel cringe after watching my this code...
}
