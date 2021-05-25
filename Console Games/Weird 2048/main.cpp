#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>

int sizeX = 12, sizeY = 12;

using namespace std;

void print_top_border();
void print_bottom_border();
void print_LR_borders();
void print_2048_name();

int main(){
    int randx, randy;
    int freespace = 0;
    int actions = 0;
    char move;
    int field [sizeX][sizeY];
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            field[x][y] = 0;
        }
    }



    while (1){

        system("cls");
        if (move == 'w'){
            for (int tact = 1; tact < sizeY; tact++){
                for (int turn = 0; turn < sizeX; turn++){
                    if (field[turn][tact] != 0 && field [turn][tact - 1] == 0){
                        int ze;
                        for (ze = tact; ze > 0; ze--){
                            if (field[turn][ze - 1] == 0){
                                field[turn][ze - 1] = field[turn][ze];
                                field[turn][ze] = 0;
                            }
                            else{
                                break;
                            }
                        }
                        for (;ze > 0; ze--)
                            if (field[turn][ze] == field [turn][ze - 1]){
                                field[turn][ze - 1]++;
                                field [turn][ze] = 0;
                            }
                    }

                    for (int de = tact; de > 0; de--){
                        if (field[turn][de] == field [turn][de - 1] && field[turn][de] != 0){
                            field[turn][de - 1]++;
                            field[turn][de] = 0;
                            //continue;
                        }
                    }

                }
            }
        }
        if (move == 'a'){
            for (int tact = 1; tact < sizeX; tact++){
                for (int turn = 0; turn < sizeY; turn++){
                    if (field[tact][turn] != 0 && field [tact - 1][turn] == 0){
                        int ze;
                        for (ze = tact; ze > 0; ze--){
                            if (field[ze - 1][turn] == 0){
                                field[ze - 1][turn] = field[ze][turn];
                                field[ze][turn] = 0;
                            }
                            else{
                                break;
                            }
                        }
                        for (;ze > 0; ze--)
                            if (field[ze - 1][turn] == field [ze][turn]){
                                field[ze - 1][turn]++;
                                field[ze][turn] = 0;
                            }
                    }
                    for (int de = tact; de > 0; de--){
                        if (field[de][turn] == field [de - 1][turn] && field[de][turn] != 0){
                            field[de - 1][turn]++;
                            field[de][turn] = 0;
                            //continue;
                        }
                    }
                }
            }
        }
        if (move == 's'){
            for (int tact = sizeY - 1; tact >= 0; tact--){
                for (int turn = 0; turn < sizeX; turn++){
                    if (field[turn][tact] != 0 && field [turn][tact + 1] == 0){
                        int ze;
                        for (ze = tact; ze < sizeY - 1; ze++){
                            if (field[turn][ze + 1] == 0){
                                field[turn][ze + 1] = field[turn][ze];
                                field[turn][ze] = 0;
                            }
                            else{
                                break;
                            }
                        }
                        for (;ze < sizeY - 1; ze++)
                            if (field[turn][ze] == field [turn][ze + 1]){
                                field[turn][ze + 1]++;
                                field [turn][ze] = 0;
                            }
                    }

                    for (int de = tact; de < sizeY - 1; de++){
                        if (field[turn][de] == field [turn][de + 1] && field[turn][de] != 0){
                            field[turn][de + 1]++;
                            field[turn][de] = 0;
                            //continue;
                        }
                    }

                }
            }
        }
        if (move == 'd'){
            for (int tact = sizeX - 1; tact >= 0; tact--){
                for (int turn = 0; turn < sizeY; turn++){
                    if (field[tact][turn] != 0 && field [tact + 1][turn] == 0){
                        int ze;
                        for (ze = tact; ze < sizeX - 1; ze++){
                            if (field[ze + 1][turn] == 0){
                                field[ze + 1][turn] = field[ze][turn];
                                field[ze][turn] = 0;
                            }
                            else{
                                break;
                            }
                        }
                        for (;ze < sizeX - 1; ze++)
                            if (field[ze + 1][turn] == field [ze][turn]){
                                field[ze + 1][turn]++;
                                field[ze][turn] = 0;
                            }
                    }
                    for (int de = tact; de < sizeX - 1; de++){
                        if (field[de][turn] == field [de + 1][turn] && field[de][turn] != 0){
                            field[de + 1][turn]++;
                            field[de][turn] = 0;
                            //continue;
                        }
                    }
                }
            }
        }
        randx = rand()%sizeX;
        randy = rand()%sizeY;

        if (field[randx][randy] == 0){
            field[randx][randy] = 1;//first
        }
        else{
            while (field[randx][randy] != 0){
                randx = rand()%sizeX;
                randy = rand()%sizeY;
            }
            field[randx][randy] = 1;
        }


        print_2048_name();
        print_top_border();
        for (int y = 0; y < sizeY; y++){
            print_LR_borders();
            for (int x = 0; x < sizeX; x++){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),field[x][y]%15);
                if (field[x][y] == 0){
                    cout << "  ";
                    continue;
                }
                printf("%2d", field[x][y]);
            }
            print_LR_borders();
            cout << endl;
        }
        print_bottom_border();

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout << actions++;
        move = _getch();
    }




}

void print_2048_name(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
    printf("2048 GAME PARODY\n");
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


/*
        if (move == 'w'){
            for (int tact = sizeY - 1; tact > 0; tact--){
                for (int turn = 0; turn < sizeX; turn++){
                    if (field[turn][tact] == field [turn][tact - 1] && field[turn][tact - 1] != 0){
                        field[turn][tact - 1]++;
                        field[turn][tact] = 0;
                    }
                    if (field[turn][tact] != 0 && field[turn][tact - 1] == 0){
                        field[turn][tact - 1] = field [turn][tact];
                        field[turn][tact] = 0;
                    }
                }
            }
        }
        if (move == 'a'){
            for (int tact = sizeX - 1; tact > 0; tact--){
                for (int turn = 0; turn < sizeY; turn++){
                    if (field[tact][turn] == field [tact - 1][turn] && field[tact - 1][turn] != 0){
                        field[tact - 1][turn]++;
                        field[tact][turn] = 0;
                    }
                    if (field[tact][turn] != 0 && field[tact - 1][turn] == 0){
                        field[tact - 1][turn] = field [tact][turn];
                        field[tact][turn] = 0;
                    }
                }
            }
        }
        if (move == 's'){
            for (int tact = 0; tact < sizeY - 1; tact++){
                for (int turn = 0; turn < sizeX; turn++){
                    if (field[turn][tact] == field [turn][tact + 1] && field[turn][tact + 1] != 0){
                        field[turn][tact + 1]++;
                        field[turn][tact] = 0;
                    }
                    if (field[turn][tact] != 0 && field[turn][tact + 1] == 0){
                        field[turn][tact + 1] = field [turn][tact];
                        field[turn][tact] = 0;
                    }
                }
            }
        }
        if (move == 'd'){
            for (int tact = 0; tact < sizeX - 1; tact++){
                for (int turn = 0; turn < sizeY; turn++){
                    if (field[tact][turn] == field [tact + 1][turn] && field[tact + 1][turn] != 0){
                        field[tact + 1][turn]++;
                        field[tact][turn] = 0;
                    }
                    if (field[tact][turn] != 0 && field[tact + 1][turn] == 0){
                        field[tact + 1][turn] = field [tact][turn];
                        field[tact][turn] = 0;
                    }
                }
            }
        }
*/
