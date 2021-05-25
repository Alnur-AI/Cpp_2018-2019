//Автор: logiteg00
//Да, я делаю очень странные программы
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

enum{ZERO = 0, CROSS = 1, EMPTY = 2};
int size;

typedef struct Cross_zero{
    int type;
    int pointX;
    int pointY;
}cross_zero;

int checkTURNandUP (int turn){//Эта функция эквивалентна операции "%2"
    turn++;
    if (turn > 1){
        turn = 0;
    }
    return turn;
}

cross_zero define_element (int x, int y, int type){//Заполняет структуру вводимыми данными
    cross_zero element;
    element.pointX = x;
    element.pointY = y;
    element.type = type;
    return element;
}

void printTIPS(){
    cout << "Enter:" << endl;
    cout << "W - up" << endl;
    cout << "A - left" << endl;
    cout << "S - down" << endl;
    cout << "D - right" << endl;
    cout << "E - pick choice" << endl;
}

int main(){
    // Константы
    char pick;//Кнопка нажатия
    char moveUP = 'w';
    char moveLEFT = 'a';
    char moveDOWN = 's';
    char moveRIGHT = 'd';
    char pickBlock = 'e';
    int score = 0;
    int turn = 0;

    //Устанавливаем размеры поля игры
    cout << "Enter size of matrix: ";
    cin >> size;
    if (size < 2) size = 2;
    cross_zero element[size][size];//координата [x][y]. Как понятно по структуре Cross_zero в каждом элементе спрятаны свои свойства
    cross_zero controller = define_element(0, 0, turn);//Помещаем контроллер в левый верхний угол и начинаем игру
    for (int y = 0; y < size; y++){
        for (int x = 0; x < size; x++){
            element[x][y] = define_element(x, y, EMPTY);//заполняем элемент массива
        }
    }

    while (score != size*size){//Полный процесс игры
        system("cls");

        if (pick == moveUP || pick == 'ц') controller.pointY = controller.pointY - 1;//Сдвиг вверх
        if (pick == moveLEFT || pick == 'ф') controller.pointX = controller.pointX - 1;
        if (pick == moveDOWN || pick == 'ы') controller.pointY = controller.pointY + 1;
        if (pick == moveRIGHT || pick == 'в') controller.pointX = controller.pointX + 1;

        if (controller.pointX < 0)           {controller.pointX = controller.pointX + 1;}//Чтобы контроллер не ушел далеко влево
        if (controller.pointX >= size)      {controller.pointX = controller.pointX - 1;}//Чтобы контроллер не ушел далеко вправо
        if (controller.pointY < 0)           {controller.pointY = controller.pointY + 1;}//Чтобы контроллер не ушел далеко вверх
        if (controller.pointY >= size)      {controller.pointY = controller.pointY - 1;}//Чтобы контроллер не ушел далеко вниз

        if (pick == pickBlock || pick == 'у') {
            if (element[controller.pointX][controller.pointY].type == EMPTY){
                element[controller.pointX][controller.pointY] = define_element(controller.pointX, controller.pointY, controller.type);
                turn = checkTURNandUP (turn);
                score++;
            }
        }

        if (turn == 0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
            cout << "Player 1 turn" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
        if (turn == 1){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
            cout << "Player 2 turn" << endl;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        }
        for (int y = 0; y < size; y++){//Печатает поле игры
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
        printTIPS();

        pick = _getch();//Вводим WASD или E
        if (element[controller.pointX][controller.pointY].type == EMPTY) controller.type = turn;//Меняемся на другого игрока

        //Переменные для завершения игры
        bool left_right_diag = true;
        bool left_right_diag_condition;
        bool right_left_diag = true;
        bool right_left_diag_condition;
        bool row[size];
        for (int i = 0; i < size; i++) row[i] = true;
        bool condition_row[size];
        bool column[size];
        for (int i = 0; i < size; i++) column[i] = true;
        bool condition_column[size];

        //left to right diagonal condition
        for (int i = 0; i < size - 1; i++){
            left_right_diag_condition = element[i][i].type == element[i + 1][i + 1].type && element[i][i].type != EMPTY;
            left_right_diag = left_right_diag && left_right_diag_condition;
            if (left_right_diag == false) continue;
        }
        if (left_right_diag == true) {
            if (turn == 1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
                cout << "Player 1 wins!" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                system("pause");
                return 0;
            }
            if (turn == 0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                cout << "Player 2 wins!" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                system("pause");
                return 0;
            }
        }

        //right to left diagonal condition
        for (int i = size - 1; i > 0; i--){
            right_left_diag_condition = element[i][size - 1 - i].type == element[i - 1][size - 1 - (i - 1)].type && element[i - 1][size - 1 - (i - 1)].type != EMPTY;
            right_left_diag = right_left_diag && right_left_diag_condition;
            if (right_left_diag == false) continue;
        }
        if (right_left_diag == true){
            if (turn == 1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
                cout << "Player 1 wins!" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                system("pause");
                return 0;
            }
            if (turn == 0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                cout << "Player 2 wins!" << endl;
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                system("pause");
                return 0;
            }
        }

        //row condition
        for (int yrow = 0; yrow < size; yrow++){
            for (int xrow = 0; xrow < size - 1; xrow++){
                condition_row[yrow] = element[xrow][yrow].type == element[xrow + 1][yrow].type && element[xrow + 1][yrow].type != EMPTY;
                row[yrow] = row[yrow] && condition_row[yrow];
                if (row[yrow] == false) continue;
            }
            if (row[yrow] == true) {
                if (turn == 1){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
                    cout << "Player 1 wins!" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    system("pause");
                    return 0;
                }
                if (turn == 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                    cout << "Player 2 wins!" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    system("pause");
                    return 0;
                }
            }
        }

        //column condition
        for (int xcol = 0; xcol < size; xcol++){
            for (int ycol = 0; ycol < size - 1; ycol++){
                condition_column[xcol] = element[xcol][ycol].type == element[xcol][ycol + 1].type && element[xcol][ycol + 1].type != EMPTY;
                column[xcol] = column[xcol] && condition_column[xcol];
                if (column[xcol] == false) continue;
            }
            if (column[xcol] == true) {
                if (turn == 1){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
                    cout << "Player 1 wins!" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    system("pause");
                    return 0;
                }
                if (turn == 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
                    cout << "Player 2 wins!" << endl;
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    system("pause");
                    return 0;
                }
            }
        }
    }

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),223);
    cout << "DRAW!!!" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
    system("pause");
    return 0;
}
