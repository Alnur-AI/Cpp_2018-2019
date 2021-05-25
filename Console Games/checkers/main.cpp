#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

enum {EMPTY_BLACK = 3, EMPTY_WHITE = 2, CHECKER_RED = 1, CHECKER_BLUE = 0};

void print_top_border();
void print_bottom_border();
void print_LR_borders();

void print_name(int turn);
void print_score(int p1, int p2);
int inc_turn (int turn);
const int sizeX = 8;
const int sizeY = 8;

int main()
{
    char move;
    int turn = 0;
    int remain_player[2] = {12, 12};
    int controller_X = sizeX/2;
    int controller_Y = sizeY/2;
    int picked_controllerX;
    int picked_controllerY;
    int field [sizeX][sizeY];
    for (int y = 0; y < sizeY; y++){//define field
        for (int x = 0; x < sizeX; x++){
            if (x % 2 == 0 && y%2 == 1){
                if (y < sizeY/2 - 1){
                    field[x][y] = CHECKER_RED;
                    continue;
                }
                if (y > sizeY/2){
                    field[x][y] = CHECKER_BLUE;
                    continue;
                }
                else field[x][y] = EMPTY_BLACK;
            }
            else{
                if (x % 2 == 1 && y%2 == 0){
                    if (y < sizeY/2 - 1){
                        field[x][y] = CHECKER_RED;
                        continue;
                    }
                    if (y > sizeY/2){
                        field[x][y] = CHECKER_BLUE;
                        continue;
                    }
                    else field[x][y] = EMPTY_BLACK;
                }
                else{
                    field[x][y] = EMPTY_WHITE;
                }
            }
        }
    }

    while (1){//GAME PROCESS
        system("cls");

        if (move == 'w'){
            controller_Y -= 1;
            if (controller_Y < 0) controller_Y = 0;
        }
        if (move == 'a'){
            controller_X -= 1;
            if (controller_X < 0) controller_X = 0;
        }
        if (move == 's'){
            controller_Y += 1;
            if (controller_Y > sizeY - 1) controller_Y = sizeY - 1;
        }
        if (move == 'd'){
            controller_X += 1;
            if (controller_X > sizeX - 1) controller_X = sizeX - 1;
        }
        if (move == 'e' && (field[controller_X][controller_Y] == CHECKER_RED || field[controller_X][controller_Y] == CHECKER_BLUE)){
            picked_controllerX = controller_X;
            picked_controllerY = controller_Y;
            while (1){

                if (move == 'w'){
                    controller_Y -= 1;
                    if (controller_Y < 0) controller_Y = 0;
                }
                if (move == 'a'){
                    controller_X -= 1;
                    if (controller_X < 0) controller_X = 0;
                }
                if (move == 's'){
                    controller_Y += 1;
                    if (controller_Y > sizeY - 1) controller_Y = sizeY - 1;
                }
                if (move == 'd'){
                    controller_X += 1;
                    if (controller_X > sizeX - 1) controller_X = sizeX - 1;
                }
                if (move == 'e'){
                    if ( abs(picked_controllerX - controller_X) == 1 && abs(picked_controllerY - controller_Y) == 1 && (field[controller_X][controller_Y] != CHECKER_BLUE || field[controller_X][controller_Y] != CHECKER_RED )){
                        field [controller_X][controller_Y] = field[picked_controllerX][picked_controllerY];
                        field[picked_controllerX][picked_controllerY] = EMPTY_BLACK;
                        turn = inc_turn(turn);
                        break;
                    }
                    if ( abs(picked_controllerX - controller_X) == 2 && abs(picked_controllerY - controller_Y) == 2 && (field[controller_X][controller_Y] != CHECKER_BLUE || field[controller_X][controller_Y] != CHECKER_RED ) && field [controller_X + 1][controller_Y + 1] != EMPTY_BLACK && (picked_controllerX - controller_X > 0 && picked_controllerY - controller_Y > 0)){
                        field [controller_X][controller_Y] = field[picked_controllerX][picked_controllerY];
                        field [controller_X + 1][controller_Y + 1] = EMPTY_BLACK;
                        field[picked_controllerX][picked_controllerY] = EMPTY_BLACK;

                        turn = inc_turn(turn);
                        remain_player[turn]--;

                        break;
                    }
                    if ( abs(picked_controllerX - controller_X) == 2 && abs(picked_controllerY - controller_Y) == 2 && (field[controller_X][controller_Y] != CHECKER_BLUE || field[controller_X][controller_Y] != CHECKER_RED ) && field [controller_X - 1][controller_Y + 1] != EMPTY_BLACK && (picked_controllerX - controller_X < 0 && picked_controllerY - controller_Y > 0)){
                        field [controller_X][controller_Y] = field[picked_controllerX][picked_controllerY];
                        field [controller_X - 1][controller_Y + 1] = EMPTY_BLACK;
                        field[picked_controllerX][picked_controllerY] = EMPTY_BLACK;

                        turn = inc_turn(turn);
                        remain_player[turn]--;
                        break;
                    }
                    if ( abs(picked_controllerX - controller_X) == 2 && abs(picked_controllerY - controller_Y) == 2 && (field[controller_X][controller_Y] != CHECKER_BLUE || field[controller_X][controller_Y] != CHECKER_RED ) && field [controller_X + 1][controller_Y - 1] != EMPTY_BLACK && (picked_controllerX - controller_X > 0 && picked_controllerY - controller_Y < 0)){
                        field [controller_X][controller_Y] = field[picked_controllerX][picked_controllerY];
                        field [controller_X + 1][controller_Y - 1] = EMPTY_BLACK;
                        field[picked_controllerX][picked_controllerY] = EMPTY_BLACK;

                        turn = inc_turn(turn);
                        remain_player[turn]--;
                        break;
                    }
                    if ( abs(picked_controllerX - controller_X) == 2 && abs(picked_controllerY - controller_Y) == 2 && (field[controller_X][controller_Y] != CHECKER_BLUE || field[controller_X][controller_Y] != CHECKER_RED ) && field [controller_X - 1][controller_Y - 1] != EMPTY_BLACK && (picked_controllerX - controller_X < 0 && picked_controllerY - controller_Y < 0)){
                        field [controller_X][controller_Y] = field[picked_controllerX][picked_controllerY];
                        field [controller_X - 1][controller_Y - 1] = EMPTY_BLACK;
                        field[picked_controllerX][picked_controllerY] = EMPTY_BLACK;

                        turn = inc_turn(turn);
                        remain_player[turn]--;
                        break;
                    }
                    else{
                        move = _getch();
                        continue;
                    }
                }
                print_top_border();
                for (int y = 0; y < sizeY; y++){
                    print_LR_borders();
                    for (int x = 0; x < sizeX; x++){
                        if (x == picked_controllerX && y == picked_controllerY && field[x][y] == CHECKER_RED){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),100);
                            cout << "* ";
                            continue;
                        }
                        if (x == picked_controllerX && y == picked_controllerY && field[x][y] == CHECKER_BLUE){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),97);
                            cout << "* ";
                            continue;
                        }
                        if ( x == controller_X && y == controller_Y && field[x][y] == CHECKER_RED){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),228);
                            cout << "* ";
                            continue;
                        }
                         if ( x == controller_X && y == controller_Y && field[x][y] == CHECKER_BLUE){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),225);
                            cout << "* ";
                            continue;
                        }
                         if ( x == controller_X && y == controller_Y){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == EMPTY_BLACK){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == EMPTY_WHITE){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),255);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == CHECKER_RED){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                            cout << "* ";
                            continue;
                        }
                        if (field[x][y] == CHECKER_BLUE){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
                            cout << "* ";
                            continue;
                        }
                    }
                    print_LR_borders();
                    cout << endl;
                }
                print_bottom_border();
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                print_name(turn);
                cout << endl << endl;
                print_score(remain_player[0], remain_player[1]);
                if (remain_player[0] == 0 || remain_player[1] == 0) return 0;
                move = _getch();
                system("cls");
            }

        }

        //field [controller_X][controller_Y]


        print_top_border();
        for (int y = 0; y < sizeY; y++){
            print_LR_borders();
            for (int x = 0; x < sizeX; x++){
                if ( x == controller_X && y == controller_Y && field[x][y] == CHECKER_RED){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),228);
                    cout << "* ";
                    continue;
                }
                 if ( x == controller_X && y == controller_Y && field[x][y] == CHECKER_BLUE){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),225);
                    cout << "* ";
                    continue;
                }
                 if ( x == controller_X && y == controller_Y){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
                    cout << "  ";
                    continue;
                }
                if (field[x][y] == EMPTY_BLACK){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
                    cout << "  ";
                    continue;
                }
                if (field[x][y] == EMPTY_WHITE){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),255);
                    cout << "  ";
                    continue;
                }
                if (field[x][y] == CHECKER_RED){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                    cout << "* ";
                    continue;
                }
                if (field[x][y] == CHECKER_BLUE){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
                    cout << "* ";
                    continue;
                }
            }
            print_LR_borders();
            cout << endl;
        }
        print_bottom_border();
        print_name(turn);
        cout << endl << endl;
        print_score(remain_player[0], remain_player[1]);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

        move = _getch();
        //return 0;
    }





    return 0;
}


void print_top_border(){
    for (int i = 0; i < sizeX; i++){
        if (i == 0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
            cout << "//=";
        }
        if (i == sizeX - 1){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
            cout << "=\\\\";
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
            cout<< "==";
        }
    }
    cout << endl;
}

void print_bottom_border(){
    for (int i = 0; i < sizeX; i++){
        if (i == 0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
            cout << "\\\\=";
        }
        if (i == sizeX - 1){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
            cout << "=//";
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
            cout<< "==";
        }
    }
    cout << endl;
}

void print_LR_borders(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
    cout<< "||";
}

int abs(int a){
    if (a < 0) return (-1)*a;
    if (a >= 0) return a;
}

int inc_turn (int turn){
    turn++;
    if (turn == 2) turn = 0;
    return turn;
}

void print_name(int turn){
    if (turn == CHECKER_RED){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        cout << "PLAYER 2 TURN" << endl;
    }
    if (turn == CHECKER_BLUE){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
        cout << "PLAYER 1 TURN" << endl;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void print_score(int rem_p1, int rem_p2){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
    cout << "PLAYER 1 " << rem_p1 << " CHECKERS LEFT!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    cout << "PLAYER 2 " << rem_p2 << " CHECKERS LEFT!" << endl;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}
/*


print_top_border();
    for (int y = 0; y < sizeY; y++){
        print_LR_borders();
        for (int x = 0; x < sizeX; x++){
            if (field[x][y] == EMPTY_BLACK){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
                cout << "  ";
                continue;
            }
            if (field[x][y] == EMPTY_WHITE){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),255);
                cout << "  ";
                continue;
            }
            if (field[x][y] == CHECKER_RED){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                cout << "* ";
                continue;
            }
            if (field[x][y] == CHECKER_BLUE){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
                cout << "* ";
                continue;
            }
        }
        print_LR_borders();
        cout << endl;

    }
    print_bottom_border();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);






for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            if (y == 0){
                if (x%2 == 0) field[x][y] = CHECKER_BLUE;
                if (x%2 == 1) field[x][y] = EMPTY_WHITE;
            }
            if (y == 1){
                if (x%2 == 1) field[x][y] = CHECKER_BLUE;
                if (x%2 == 0) field[x][y] = EMPTY_WHITE;
            }
            if (y == 2){
                if (x%2 == 0) field[x][y] = CHECKER_BLUE;
                if (x%2 == 1) field[x][y] = EMPTY_WHITE;
            }
            if (y == 3){
                if (x%2 == 1) field[x][y] = EMPTY_BLACK;
                if (x%2 == 0) field[x][y] = EMPTY_WHITE;
            }
            if (y == 4){
                if (x%2 == 0) field[x][y] = EMPTY_BLACK;
                if (x%2 == 1) field[x][y] = EMPTY_WHITE;
            }
            if (y == 5){
                if (x%2 == 1) field[x][y] = CHECKER_RED;
                if (x%2 == 0) field[x][y] = EMPTY_WHITE;
            }
            if (y == 6){
                if (x%2 == 0) field[x][y] = CHECKER_RED;
                if (x%2 == 1) field[x][y] = EMPTY_WHITE;
            }
            if (y == 7){
                if (x%2 == 1) field[x][y] = CHECKER_RED;
                if (x%2 == 0) field[x][y] = EMPTY_WHITE;
            }
        }
    }

*/
