#include <iostream>
#include <windows.h>
#include <conio.h>
enum{ZERO = 0, CROSS = 1, EMPTY = 2};
const int size = 9;

typedef struct Cross_zero{
    int type;
    int pointX;
    int pointY;
}cross_zero;

int checkTURNandUP (int turn){
    turn++;
    if (turn > 1){
        turn = 0;
    }
    return turn;
}

cross_zero define_element (int x, int y, int type){
    cross_zero element;
    element.pointX = x;
    element.pointY = y;
    element.type = type;
    return element;
}

using namespace std;

int main()
{
    int score = 0;
    int turn = 0;
    cross_zero element[size][size];//[x][y]
    for (int y = 0; y < size; y++){
        for (int x = 0; x < size; x++){
            element[x][y] = define_element(x, y, EMPTY);
        }
    }

    cross_zero controller = define_element(0, 0, turn);

    char pick;
    char moveUP = 'w';
    char moveLEFT = 'a';
    char moveDOWN = 's';
    char moveRIGHT = 'd';
    char pickBlock = 'e';

    cout << "Enter your name: ";
    string name;
    cin >> name;


        for (int y = 0; y < size; y++){
            for (int x = 0; x < size; x++){
                 if (controller.pointX == x && controller.pointY == y && element[x][y].type == ZERO){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),225);
                    cout << "o ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                if (controller.pointX == x && controller.pointY == y && element[x][y].type == CROSS){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),228);
                    cout << "x ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                if (controller.pointX == x && controller.pointY == y && element[x][y].type == EMPTY){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),228);
                    cout << "  ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                if (element[x][y].pointX == x && element[x][y].pointY == y && element[x][y].type == ZERO){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
                    cout << "o ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                if (element[x][y].pointX == x && element[x][y].pointY == y && element[x][y].type == CROSS){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                    cout << "x ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                if (element[x][y].pointX == x && element[x][y].pointY == y &&  element[x][y].type == EMPTY){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    cout << ". ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
            }
            cout << endl;
        }

    while (score != size*size + 100){
        system("cls");
        cout << name << turn << "turn" << endl;
        if (pick == moveUP) controller.pointY = controller.pointY - 1;
        if (pick == moveLEFT) controller.pointX = controller.pointX - 1;
        if (pick == moveDOWN) controller.pointY = controller.pointY + 1;
        if (pick == moveRIGHT) controller.pointX = controller.pointX + 1;

        if (controller.pointX < 0)           {controller.pointX = controller.pointX + 1;}
        if (controller.pointX >= size)      {controller.pointX = controller.pointX - 1;}
        if (controller.pointY < 0)           {controller.pointY = controller.pointY + 1;}
        if (controller.pointY >= size)      {controller.pointY = controller.pointY - 1;}

        if (pick == pickBlock) element[controller.pointX][controller.pointY] = define_element(controller.pointX, controller.pointY, controller.type);
        turn = checkTURNandUP (turn);

        for (int y = 0; y < size; y++){
            for (int x = 0; x < size; x++){
                 if (controller.pointX == x && controller.pointY == y && element[x][y].type == ZERO){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),225);
                    cout << "o ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                if (controller.pointX == x && controller.pointY == y && element[x][y].type == CROSS){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),228);
                    cout << "x ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                if (controller.pointX == x && controller.pointY == y && element[x][y].type == EMPTY){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),228);
                    cout << "  ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                if (element[x][y].pointX == x && element[x][y].pointY == y && element[x][y].type == ZERO){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
                    cout << "o ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                if (element[x][y].pointX == x && element[x][y].pointY == y && element[x][y].type == CROSS){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                    cout << "x ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                if (element[x][y].pointX == x && element[x][y].pointY == y &&  element[x][y].type == EMPTY){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    cout << ". ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
            }
            cout << endl;
        }
        pick = _getch();
        score++;
        controller.type = turn;
    }
    return 0;
}
