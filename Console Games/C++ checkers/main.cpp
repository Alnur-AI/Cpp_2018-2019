#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
const int sideX = 8;
const int sideY = 8;

int main()
{
    int controllerX;
    int controllerY;
    int playerUPwaste = 0;
    int playerDOWNwaste = 0;

    //while (playerUPwaste == 12 || playerDOWNwaste == 12)
    //{
    //
    //}
        for (int i = 0; i < sideX; i++)
        {
            if (i == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
                cout << "/--";
            }

            if (i == sideX - 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
                cout << "--\\";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
                cout<< "--";
            }
        }
        cout << endl;


        for (int y = 0; y < sideY;y++)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
            cout<< "| ";
            for (int x = 0; x < sideX; x++)
            {
                if (x % 2 == 0 && y%2 == 1)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
                }
                else
                {
                    if (x % 2 == 1 && y%2 == 0)
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
                    }
                    else
                    {
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    }
                }
            cout << "  ";
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
            cout<< " |";
        cout << endl;
        }

        for (int i = 0; i < sideX; i++)
        {
            if (i == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
                cout << "\\--";
            }

            if (i == sideX - 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
                cout << "--/";
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
                cout<< "--";
            }
        }
    cout << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
    cout << "Player1 ( UP ) had lost: " << playerUPwaste << " cherkers" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout << "Player2 (DOWN) had lost: " << playerDOWNwaste << " cherkers" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    return 0;
}
