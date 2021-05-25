// 2018
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAXscore = 50;
const int sideX = 9;
const int sideY = 6;

int main()
{
    // Basic integers:
    int score = 0;
    int lengthOfSnake = 1;
    char plant [sideX][sideY];
    int currentPointX [sideX * sideY];
    int currentPointY [sideX * sideY];
    int yellowPointX = rand()%sideX;
    int yellowPointY = rand()%sideY;
        currentPointX [0] = 1;
        currentPointY [0] = 1;




    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    cout << "Welcome to the snake game!\n" << endl;


    cout<<"Please, press any button to establish it to move up.\n";    char moveUP = _getch();
	cout<<"Please, press any button to establish it to move left.\n";  char moveLEFT = _getch();
	cout<<"Please, press any button to establish it to move down.\n";  char moveDOWN = _getch();
	cout<<"Please, press any button to establish it to move right.\n"; char moveRIGHT = _getch();


	cout<<"\nThank you! Press any button and enjoy the game!\n\n";


	while (score != MAXscore)
    {
        char nowmove = _getch();


        if(nowmove == moveUP)
        {
            if (lengthOfSnake >= 13)
            {
                currentPointX[12] = currentPointX[11];
                currentPointY[12] = currentPointY[11];
            }
            if (lengthOfSnake >= 12)
            {
                currentPointX[11] = currentPointX[10];
                currentPointY[11] = currentPointY[10];
            }
            if (lengthOfSnake >= 11)
            {
                currentPointX[10] = currentPointX[9];
                currentPointY[10] = currentPointY[9];
            }
            if (lengthOfSnake >= 10)
            {
                currentPointX[9] = currentPointX[8];
                currentPointY[9] = currentPointY[8];
            }
            if (lengthOfSnake >= 9)
            {
                currentPointX[8] = currentPointX[7];
                currentPointY[8] = currentPointY[7];
            }
            if (lengthOfSnake >= 8)
            {
                currentPointX[7] = currentPointX[6];
                currentPointY[7] = currentPointY[6];
            }
            if (lengthOfSnake >= 7)
            {
                currentPointX[6] = currentPointX[5];
                currentPointY[6] = currentPointY[5];
            }
            if (lengthOfSnake >= 6)
            {
                currentPointX[5] = currentPointX[4];
                currentPointY[5] = currentPointY[4];
            }
            if (lengthOfSnake >= 5)
            {
                currentPointX[4] = currentPointX[3];
                currentPointY[4] = currentPointY[3];
            }
            if (lengthOfSnake >= 4)
            {
                currentPointX[3] = currentPointX[2];
                currentPointY[3] = currentPointY[2];
            }
            if (lengthOfSnake >= 3)
            {
                currentPointX[2] = currentPointX[1];
                currentPointY[2] = currentPointY[1];
            }
            if (lengthOfSnake >= 2)
            {
                currentPointX[1] = currentPointX[0];
                currentPointY[1] = currentPointY[0];
            }
            currentPointY[0] = currentPointY[0] - 1;
        }

        if(nowmove == moveLEFT)
        {
            if (lengthOfSnake >= 13)
            {
                currentPointX[12] = currentPointX[11];
                currentPointY[12] = currentPointY[11];
            }
            if (lengthOfSnake >= 12)
            {
                currentPointX[11] = currentPointX[10];
                currentPointY[11] = currentPointY[10];
            }
            if (lengthOfSnake >= 11)
            {
                currentPointX[10] = currentPointX[9];
                currentPointY[10] = currentPointY[9];
            }
            if (lengthOfSnake >= 10)
            {
                currentPointX[9] = currentPointX[8];
                currentPointY[9] = currentPointY[8];
            }
            if (lengthOfSnake >= 9)
            {
                currentPointX[8] = currentPointX[7];
                currentPointY[8] = currentPointY[7];
            }
            if (lengthOfSnake >= 8)
            {
                currentPointX[7] = currentPointX[6];
                currentPointY[7] = currentPointY[6];
            }
            if (lengthOfSnake >= 7)
            {
                currentPointX[6] = currentPointX[5];
                currentPointY[6] = currentPointY[5];
            }
            if (lengthOfSnake >= 6)
            {
                currentPointX[5] = currentPointX[4];
                currentPointY[5] = currentPointY[4];
            }
            if (lengthOfSnake >= 5)
            {
                currentPointX[4] = currentPointX[3];
                currentPointY[4] = currentPointY[3];
            }
            if (lengthOfSnake >= 4)
            {
                currentPointX[3] = currentPointX[2];
                currentPointY[3] = currentPointY[2];
            }
            if (lengthOfSnake >= 3)
            {
                currentPointX[2] = currentPointX[1];
                currentPointY[2] = currentPointY[1];
            }
            if (lengthOfSnake >= 2)
            {
                currentPointX[1] = currentPointX[0];
                currentPointY[1] = currentPointY[0];
            }
            currentPointX[0] = currentPointX[0] - 1;
        }

        if(nowmove == moveDOWN)
        {
            if (lengthOfSnake >= 13)
            {
                currentPointX[12] = currentPointX[11];
                currentPointY[12] = currentPointY[11];
            }
            if (lengthOfSnake >= 12)
            {
                currentPointX[11] = currentPointX[10];
                currentPointY[11] = currentPointY[10];
            }
            if (lengthOfSnake >= 11)
            {
                currentPointX[10] = currentPointX[9];
                currentPointY[10] = currentPointY[9];
            }
            if (lengthOfSnake >= 10)
            {
                currentPointX[9] = currentPointX[8];
                currentPointY[9] = currentPointY[8];
            }
            if (lengthOfSnake >= 9)
            {
                currentPointX[8] = currentPointX[7];
                currentPointY[8] = currentPointY[7];
            }
            if (lengthOfSnake >= 8)
            {
                currentPointX[7] = currentPointX[6];
                currentPointY[7] = currentPointY[6];
            }
            if (lengthOfSnake >= 7)
            {
                currentPointX[6] = currentPointX[5];
                currentPointY[6] = currentPointY[5];
            }
            if (lengthOfSnake >= 6)
            {
                currentPointX[5] = currentPointX[4];
                currentPointY[5] = currentPointY[4];
            }
            if (lengthOfSnake >= 5)
            {
                currentPointX[4] = currentPointX[3];
                currentPointY[4] = currentPointY[3];
            }
            if (lengthOfSnake >= 4)
            {
                currentPointX[3] = currentPointX[2];
                currentPointY[3] = currentPointY[2];
            }
            if (lengthOfSnake >= 3)
            {
                currentPointX[2] = currentPointX[1];
                currentPointY[2] = currentPointY[1];
            }
            if (lengthOfSnake >= 2)
            {
                currentPointX[1] = currentPointX[0];
                currentPointY[1] = currentPointY[0];
            }
            currentPointY[0] = currentPointY[0] + 1;
        }

        if(nowmove == moveRIGHT)
        {
            if (lengthOfSnake >= 13)
            {
                currentPointX[12] = currentPointX[11];
                currentPointY[12] = currentPointY[11];
            }
            if (lengthOfSnake >= 12)
            {
                currentPointX[11] = currentPointX[10];
                currentPointY[11] = currentPointY[10];
            }
            if (lengthOfSnake >= 11)
            {
                currentPointX[10] = currentPointX[9];
                currentPointY[10] = currentPointY[9];
            }
            if (lengthOfSnake >= 10)
            {
                currentPointX[9] = currentPointX[8];
                currentPointY[9] = currentPointY[8];
            }
            if (lengthOfSnake >= 9)
            {
                currentPointX[8] = currentPointX[7];
                currentPointY[8] = currentPointY[7];
            }
            if (lengthOfSnake >= 8)
            {
                currentPointX[7] = currentPointX[6];
                currentPointY[7] = currentPointY[6];
            }
            if (lengthOfSnake >= 7)
            {
                currentPointX[6] = currentPointX[5];
                currentPointY[6] = currentPointY[5];
            }
            if (lengthOfSnake >= 6)
            {
                currentPointX[5] = currentPointX[4];
                currentPointY[5] = currentPointY[4];
            }
            if (lengthOfSnake >= 5)
            {
                currentPointX[4] = currentPointX[3];
                currentPointY[4] = currentPointY[3];
            }
            if (lengthOfSnake >= 4)
            {
                currentPointX[3] = currentPointX[2];
                currentPointY[3] = currentPointY[2];
            }
            if (lengthOfSnake >= 3)
            {
                currentPointX[2] = currentPointX[1];
                currentPointY[2] = currentPointY[1];
            }
            if (lengthOfSnake >= 2)
            {
                currentPointX[1] = currentPointX[0];
                currentPointY[1] = currentPointY[0];
            }
            currentPointX[0] = currentPointX[0] + 1;
        }

        if (currentPointX[0] < 0)                {currentPointX[0] = currentPointX[0] + 1;}
        if (currentPointX[0] >= sideX)           {currentPointX[0] = currentPointX[0] - 1;}
        if (currentPointY[0] < 0)                {currentPointY[0] = currentPointY[0] + 1;}
        if (currentPointY[0] >= sideY)           {currentPointY[0] = currentPointY[0] - 1;}

        system("cls");

        //define
        for (int y = 0; y < sideY; y++)
        {
            for (int x = 0; x < sideX; x++)
            {


                if(currentPointX[0] == yellowPointX && currentPointY[0] == yellowPointY)//if red dot eats yellow dot
                {
                    cout<<"\a";
                    score = score + 1;
                    lengthOfSnake++;
                    yellowPointX = rand()%sideX;
                    yellowPointY = rand()%sideY;
                }




                if (x == currentPointX[0] && y == currentPointY[0])
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                    plant [x] [y] = '@';
                }
                else
                {
                    if (x == currentPointX[1] && y == currentPointY[1])
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                        plant [x] [y] = '#';
                    }
                    else
                    {
                        if (x == currentPointX[2] && y == currentPointY[2])
                        {
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                            plant [x] [y] = '#';
                        }
                        else
                        {
                            if (x == currentPointX[3] && y == currentPointY[3])
                            {
                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                                plant [x] [y] = '#';
                            }
                            else
                            {
                                if (x == currentPointX[4] && y == currentPointY[4])
                                {
                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                                    plant [x] [y] = '#';
                                }
                                else
                                {
                                    if (x == currentPointX[5] && y == currentPointY[5])
                                    {
                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                                        plant [x] [y] = '#';
                                    }
                                    else
                                    {
                                        if (x == currentPointX[6] && y == currentPointY[6])
                                        {
                                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                                            plant [x] [y] = '#';
                                        }
                                        else
                                        {
                                            if (x == currentPointX[7] && y == currentPointY[7])
                                            {
                                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                                                plant [x] [y] = '#';
                                            }
                                            else
                                            {
                                                if (x == currentPointX[8] && y == currentPointY[8])
                                                {
                                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                                                    plant [x] [y] = '#';
                                                }
                                                else
                                                {
                                                    if (x == currentPointX[9] && y == currentPointY[9])
                                                    {
                                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                                                        plant [x] [y] = '#';
                                                    }
                                                    else
                                                    {
                                                        if (x == currentPointX[10] && y == currentPointY[10])
                                                        {
                                                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                                                            plant [x] [y] = '#';
                                                        }
                                                        else
                                                        {
                                                            if (x == currentPointX[11] && y == currentPointY[11])
                                                            {
                                                                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                                                                plant [x] [y] = '#';
                                                            }
                                                            else
                                                            {
                                                                if (x == currentPointX[12] && y == currentPointY[12])
                                                                {
                                                                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                                                                    plant [x] [y] = '#';
                                                                }
                                                                else
                                                                {
                                                                    if (x == yellowPointX && y == yellowPointY)
                                                                    {
                                                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
                                                                        plant [x] [y] = '*';
                                                                    }
                                                                    else
                                                                    {
                                                                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                                                                        plant [x] [y] = '.';
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                cout << plant [x] [y] << " ";
            }
        cout << endl;
        }
        cout<<"\nYour Score: "<<score<<endl;
    }




    return 0;
}
