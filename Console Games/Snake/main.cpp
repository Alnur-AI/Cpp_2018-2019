#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

char move;
const int sizeX = 20;
const int sizeY = 20;
const int MAXscore = sizeX*sizeY;

int snake_x[sizeX*sizeY];
int snake_y[sizeX*sizeY];
int yellowPointX = rand()%sizeX;
int yellowPointY = rand()%sizeY;

bool yellowPointFIX (bool main_condition, bool secondary_condition);
void printFIELD(int &lenght, int &score);
void fillFILED();
void check_player_move_and_shift_snake(char move, int lenght);
void print_closing();
void print_top_border();
void print_bottom_border();
void print_LR_borders();


int main(){
    int score = 0;
    int lenght_of_snake = 1;
    snake_x[0] = sizeX/2;
    snake_y[0] = sizeY/2;
    fillFILED();

    while(score != MAXscore){
        system("cls");
        check_player_move_and_shift_snake(move, lenght_of_snake);//Перемещаем змею в новую позицию
        printFIELD(lenght_of_snake, score);//Выполняется основная логика и вывод результата на экран
        cout << "Score: "<< score << endl;
        move = _getch();
    }
    system("cls");
    cout << "GAMEOVER! YOU WIN!!!" << endl;
    print_closing();
    return 0;
}



bool yellowPointFIX (bool main_condition, bool secondary_condition){
    if (main_condition == true && secondary_condition == true) return true;
    if (main_condition == false && secondary_condition == true) return true;
    if (main_condition == true && secondary_condition == false) return false;
    if (main_condition == false && secondary_condition == false) return false;
}

void fillFILED(){
    for (int h = 1; h < sizeX*sizeY; h++){
        snake_x[h] = sizeX + 2;
        snake_y[h] = sizeY + 2;
    }
}

void check_player_move_and_shift_snake(char move, int lenght){
    if(move == 'w'){
        snake_y[0] -= 1;
        if (snake_y[0] < 0){
            cout << "GAMEOVER! Snake hits the wall!" << endl;
            print_closing();
            exit(1);
        }

        for (int j = lenght; j > 1; j--){
            snake_x[j - 1] = snake_x[j - 2];
            snake_y[j - 1] = snake_y[j - 2];
        }
    }
    if(move == 'a'){
        snake_x[0] -= 1;
        if (snake_x[0] < 0){
            cout << "GAMEOVER! Snake hits the wall!" << endl;
            print_closing();
            exit(1);
        }

        for (int j = lenght; j > 1; j--){
            snake_x[j - 1] = snake_x[j - 2];
            snake_y[j - 1] = snake_y[j - 2];
        }
    }
    if(move == 's'){
        snake_y[0] += 1;
        if (snake_y[0] >= sizeY){
            cout << "GAMEOVER! Snake hits the wall!" << endl;
            print_closing();
            exit(1);
        }

        for (int j = lenght; j > 1; j--){
            snake_x[j - 1] = snake_x[j - 2];
            snake_y[j - 1] = snake_y[j - 2];
        }
    }
    if(move == 'd'){
        snake_x[0] += 1;
        if (snake_x[0] >= sizeX){
            cout << "GAMEOVER! Snake hits the wall!" << endl;
            print_closing();
            exit(1);
        }

        for (int j = lenght; j > 1; j--){
            snake_x[j - 1] = snake_x[j - 2];
            snake_y[j - 1] = snake_y[j - 2];
        }
    }
}

void printFIELD(int &lenght, int &score){
    bool if_yellow_point_is_missing_in_snake = false;
    bool if_snake_hit_itself = false;
    bool body_snake_block = false;

    if (snake_x[0] == yellowPointX && snake_y[0] == yellowPointY){
        cout<<"\a";
        yellowPointX = rand()%sizeX;
        yellowPointY = rand()%sizeY;
        for (int i = 0; i < lenght; i++){
            if_yellow_point_is_missing_in_snake = yellowPointFIX(if_yellow_point_is_missing_in_snake, (snake_x[i] == yellowPointX && snake_y[i] == yellowPointY));
            if (if_yellow_point_is_missing_in_snake == true){
                break;
            }
        }
        if (if_yellow_point_is_missing_in_snake == true){
            while (if_yellow_point_is_missing_in_snake == true){
                //srand(time(0));
                yellowPointX = rand()%sizeX;
                yellowPointY = rand()%sizeY;
                for (int i = 0; i < lenght; i++){
                    if_yellow_point_is_missing_in_snake = yellowPointFIX(if_yellow_point_is_missing_in_snake, (snake_x[i] == yellowPointX && snake_y[i] == yellowPointY));
                    if (if_yellow_point_is_missing_in_snake == true) break;
                }
                if_yellow_point_is_missing_in_snake == false;
            }
        }
        score++;
        lenght++;
    }
    for (int i = 2; i <= lenght; i++) if_snake_hit_itself = if_snake_hit_itself || (snake_x[i] == snake_x[0] && snake_y[i] == snake_y[0]);
    if (if_snake_hit_itself == true){
        cout << "GAMEOVER! Snake hits itself!" << endl;
        print_closing();
        exit(1);
    }




    print_top_border();
    for (int y = 0; y < sizeY; y++){
        print_LR_borders();
        for (int x = 0; x < sizeX; x++){
            if (x == snake_x[0] && y == snake_y[0]){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                    cout << "@ ";
                    continue;
            }

            for (int i = 1; i < lenght; i++){
                if (x == snake_x[i] && y == snake_y[i]){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                    body_snake_block = true;
                    cout << "# ";
                    break;
                }
            }
            if (body_snake_block == true){
                body_snake_block = false;
                continue;
            }

            if (x == yellowPointX && y == yellowPointY){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
                cout << "* ";
                continue;
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),1);
                cout << ". ";
                continue;
            }
        }
        print_LR_borders();
        cout << endl;
    }
    print_bottom_border();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
}

void print_closing(){
    cout << "Closing the game";
    for (int i = 0; i < 3; i++){
        Sleep(1000);
        cout << ".";
    }
    Sleep(1000);
}

void print_top_border(){
    for (int i = 0; i < sizeX; i++){
        if (i == 0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout << "//=";
        }
        if (i == sizeX - 1){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout << "=\\\\";
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout<< "==";
        }
    }
    cout << endl;
}

void print_bottom_border(){
    for (int i = 0; i < sizeX; i++){
        if (i == 0){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout << "\\\\=";
        }
        if (i == sizeX - 1){
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout << "=//";
        }
        else{
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
            cout<< "==";
        }
    }
    cout << endl;
}

void print_LR_borders(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
    cout<< "||";
}


