//Автор: Хикари Тайо
//Да, я делаю игры необычным способом.

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>

using namespace std;
enum {sky = 1, cloud = 2, grass = 3, player = 4, canal = 5, platform = 6, coin = 7, enemy = 8 ,gameover_trigger = 9};
void print_instructions();
void print_closing();
void print_main_menu();
void print_choice (char pick);
int turn_controllerUP(int curr_pos_y);
int turn_controllerLEFT(int curr_pos_x);
int turn_controllerDOWN(int curr_pos_y, int MAX_y);
int turn_controllerRIGHT(int curr_pos_x, int MAX_x);
int increase_curr_lvl_pos (int curr_lvl_pos, int c_shift, int size_x);
int decrease_curr_lvl_pos (int curr_lvl_pos, int c_shift, int size_x);

int main()
{
    int menu_choice;
    print_main_menu();
    cin >> menu_choice;

    if (menu_choice == 1){
        int size_x;
        int size_y = 6;
        int controller_x = 0;
        int controller_y = 0;
        int put_block = 1;
        int curr_lvl_pos = 0;
        int c_shift = 16;
        char pick;
        char chosen_block = '1';

        system("cls");
        cout << "How long (in blocks) will your level be? (from 6 to 1024)" << endl;
        cout << "It's would be: ";
        cin >> size_x;
        if (size_x < 6) size_x = 6;
        if (size_x > 1024) size_x = 1024;
        int field[size_x][size_y];
        for (int y = 0; y < size_y; y++){
            for (int x = 0; x < size_x; x++){
                field[x][y] = sky;
                if (y == size_y - 1) field[x][y] = grass;
                if (x == size_x - 1) field[x][y] = gameover_trigger;
            }
        }
        while (1){
            system("cls");
            if (pick == 'q'){
                FILE *lvl;
                if ((lvl = fopen("level.txt", "w")) == NULL){
                    system("cls");
                    cout << "Could not open the file" << endl;
                    print_closing();
                    fclose(lvl);
                    return 0;
                }
                for (int y = 0; y < size_y; y++){
                    for (int x = 0; x < size_x; x++){
                        fprintf(lvl, "%d", field[x][y]);
                    }
                    fprintf(lvl, "\n");
                }
                fclose(lvl);

                cout << "Saved! ";
                print_closing();
                return 0;
                //safe project in file and exit
            }
            if (pick == 'w') controller_y = turn_controllerUP(controller_y);
            if (pick == 'a') controller_x = turn_controllerLEFT(controller_x);
            if (pick == 's') controller_y = turn_controllerDOWN(controller_y, size_y);
            if (pick == 'd') controller_x = turn_controllerRIGHT(controller_x, size_x);
            if (pick == '1'){
                put_block = sky;
                chosen_block = '1';
            }
            if (pick == '2'){
                put_block = cloud;
                chosen_block = '2';
            }
            if (pick == '3'){
                put_block = grass;
                chosen_block = '3';
            }
            if (pick == '4'){
                put_block = player;
                chosen_block = '4';
            }
            if (pick == '5'){
                put_block = canal;
                chosen_block = '5';
            }
            if (pick == '6'){
                put_block = platform;
                chosen_block = '6';
            }
            if (pick == '7'){
                put_block = coin;
                chosen_block = '7';
            }
            if (pick == '8'){
                put_block = enemy;
                chosen_block = '8';
            }
            if (pick == '9'){
                put_block = gameover_trigger;
                chosen_block = '9';
            }
            if (pick == 'e') field[controller_x][controller_y] = put_block;
            if (pick == 'r') c_shift++;
            if (pick == 'f') c_shift--;
            if (pick == 'c') curr_lvl_pos = increase_curr_lvl_pos (curr_lvl_pos, c_shift, size_x);
            if (pick == 'z') curr_lvl_pos = decrease_curr_lvl_pos (curr_lvl_pos, c_shift, size_x);

            cout << "Shift parameter: " << c_shift << endl;
            print_choice (chosen_block);
            int print_lvl_limit = increase_curr_lvl_pos(curr_lvl_pos, c_shift, size_x + 1);
            for (int y = 0; y < size_y; y++){
                for (int x = curr_lvl_pos; x < print_lvl_limit; x++){
                    if (x == controller_x && y == controller_y){
                        if (field[x][y] == sky){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),227);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == cloud){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),231);
                            cout << "##";
                            continue;
                        }
                        if (field[x][y] == grass){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),234);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == player){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),228);
                            cout << "P ";
                            continue;
                        }
                        if (field[x][y] == canal){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
                            cout << "TT";
                            continue;
                        }
                        if (field[x][y] == platform){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),236);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == coin){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
                            cout << "o ";
                            continue;
                        }
                        if (field[x][y] == gameover_trigger){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),231);
                            cout << "@@";
                            continue;
                        }
                        if (field[x][y] == enemy){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),229);
                            cout << "!j";
                            continue;
                        }
                    }
                    else{
                        if (field[x][y] == sky){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),187);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == cloud){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),191);
                            cout << "##";
                            continue;
                        }
                        if (field[x][y] == grass){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),170);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == player){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),180);
                            cout << "P ";
                            continue;
                        }
                        if (field[x][y] == canal){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),176);
                            cout << "TT";
                            continue;
                        }
                        if (field[x][y] == platform){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),102);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == coin){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),182);
                            cout << "o ";
                            continue;
                        }
                        if (field[x][y] == gameover_trigger){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),196);
                            cout << "@@";
                            continue;
                        }
                        if (field[x][y] == enemy){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),189);
                            cout << "!j";
                            continue;
                        }
                    }
                }
                cout << endl;
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            print_instructions();
            pick = _getch();
        }
    }


    if (menu_choice == 2){
        system("cls");
        char temp[1024];
        int size_x = 0;
        int size_y = 6;

        FILE *lvl;
            if ((lvl = fopen("level.txt", "r")) == NULL){
                system("cls");
                cout << "Could not open the file" << endl;
                cout << "Maybe your file is not named like level.txt?\n\n" << endl;
                print_closing();
                fclose(lvl);
                return 0;
            }
            fgets(temp, 1024, lvl);
            for (int i = 0; i < 1024; i++){
                if (temp[i] == '\0'){
                    size_x--;
                    break;
                }
                size_x++;
            }
        fclose(lvl);

        char pre_field [size_x][size_y];
        FILE *lvlone;
            if ((lvlone = fopen("level.txt", "r")) == NULL){
                system("cls");
                cout << "Could not open the file" << endl;
                cout << "Maybe your file is not named like level.txt?\n\n" << endl;
                print_closing();
                fclose(lvl);
                return 0;
            }
            for (int j = 0; j < size_y; j++){
                fgets(temp, size_x + 2, lvl);
                for (int i = 0; i < size_x; i++){
                    pre_field [i][j] = temp[i];
                }
            }
        fclose(lvlone);

        int field[size_x][size_y];
        for (int y = 0; y < size_y; y++){
            for (int x = 0; x < size_x; x++){
                if (pre_field[x][y] == '1'){
                    field[x][y] = 1;
                    continue;
                }
                if (pre_field[x][y] == '2'){
                    field[x][y] = 2;
                    continue;
                }
                if (pre_field[x][y] == '3'){
                    field[x][y] = 3;
                    continue;
                }
                if (pre_field[x][y] == '4'){
                    field[x][y] = 4;
                    continue;
                }
                if (pre_field[x][y] == '5'){
                    field[x][y] = 5;
                    continue;
                }
                if (pre_field[x][y] == '6'){
                    field[x][y] = 6;
                    continue;
                }
                if (pre_field[x][y] == '7'){
                    field[x][y] = 7;
                    continue;
                }
                if (pre_field[x][y] == '8'){
                    field[x][y] = 8;
                    continue;
                }
                if (pre_field[x][y] == '9'){
                    field[x][y] = 9;
                    continue;
                }
            }
        }

        int controller_x = 0;
        int controller_y = 0;
        int put_block = 1;
        int curr_lvl_pos = 0;
        int c_shift = 16;
        char pick;
        char chosen_block = '1';

        system("cls");
        while (1){
            system("cls");
            if (pick == 'q'){
                FILE *lvl;
                if ((lvl = fopen("level.txt", "w")) == NULL){
                    system("cls");
                    cout << "Could not open the file" << endl;
                    print_closing();
                    fclose(lvl);
                    return 0;
                }
                for (int y = 0; y < size_y; y++){
                    for (int x = 0; x < size_x; x++){
                        fprintf(lvl, "%d", field[x][y]);
                    }
                    fprintf(lvl, "\n");
                }
                fclose(lvl);

                cout << "Saved! ";
                print_closing();
                return 0;
                //safe project in file and exit
            }
            if (pick == 'w') controller_y = turn_controllerUP(controller_y);
            if (pick == 'a') controller_x = turn_controllerLEFT(controller_x);
            if (pick == 's') controller_y = turn_controllerDOWN(controller_y, size_y);
            if (pick == 'd') controller_x = turn_controllerRIGHT(controller_x, size_x);
            if (pick == '1'){
                put_block = sky;
                chosen_block = '1';
            }
            if (pick == '2'){
                put_block = cloud;
                chosen_block = '2';
            }
            if (pick == '3'){
                put_block = grass;
                chosen_block = '3';
            }
            if (pick == '4'){
                put_block = player;
                chosen_block = '4';
            }
            if (pick == '5'){
                put_block = canal;
                chosen_block = '5';
            }
            if (pick == '6'){
                put_block = platform;
                chosen_block = '6';
            }
            if (pick == '7'){
                put_block = coin;
                chosen_block = '7';
            }
            if (pick == '8'){
                put_block = enemy;
                chosen_block = '8';
            }
            if (pick == '9'){
                put_block = gameover_trigger;
                chosen_block = '9';
            }
            if (pick == 'e') field[controller_x][controller_y] = put_block;
            if (pick == 'r') c_shift++;
            if (pick == 'f') c_shift--;
            if (pick == 'c') curr_lvl_pos = increase_curr_lvl_pos (curr_lvl_pos, c_shift, size_x);
            if (pick == 'z') curr_lvl_pos = decrease_curr_lvl_pos (curr_lvl_pos, c_shift, size_x);

            cout << "Shift parameter: " << c_shift << endl;
            print_choice (chosen_block);
            int print_lvl_limit = increase_curr_lvl_pos(curr_lvl_pos, c_shift, size_x + 1);
            for (int y = 0; y < size_y; y++){
                for (int x = curr_lvl_pos; x < print_lvl_limit; x++){
                    if (x == controller_x && y == controller_y){
                        if (field[x][y] == sky){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),227);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == cloud){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),231);
                            cout << "##";
                            continue;
                        }
                        if (field[x][y] == grass){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),234);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == player){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),228);
                            cout << "P ";
                            continue;
                        }
                        if (field[x][y] == canal){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),224);
                            cout << "TT";
                            continue;
                        }
                        if (field[x][y] == platform){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),236);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == coin){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),230);
                            cout << "o ";
                            continue;
                        }
                        if (field[x][y] == gameover_trigger){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),231);
                            cout << "@@";
                            continue;
                        }
                        if (field[x][y] == enemy){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),229);
                            cout << "!j";
                            continue;
                        }
                    }
                    else{
                        if (field[x][y] == sky){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),187);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == cloud){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),191);
                            cout << "##";
                            continue;
                        }
                        if (field[x][y] == grass){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),170);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == player){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),180);
                            cout << "P ";
                            continue;
                        }
                        if (field[x][y] == canal){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),176);
                            cout << "TT";
                            continue;
                        }
                        if (field[x][y] == platform){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),102);
                            cout << "  ";
                            continue;
                        }
                        if (field[x][y] == coin){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),182);
                            cout << "o ";
                            continue;
                        }
                        if (field[x][y] == gameover_trigger){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),196);
                            cout << "@@";
                            continue;
                        }
                        if (field[x][y] == enemy){
                            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),189);
                            cout << "!j";
                            continue;
                        }
                    }
                }
                cout << endl;
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
            print_instructions();
            pick = _getch();
        }

    }


    else{
        print_closing();
        return 0;
    }

}

void print_closing(){
    cout << "Closing application";
        for (int i = 0; i < 3; i++){
            Sleep(1000);
            cout << ".";
        }
        Sleep(1000);
}
void print_main_menu(){
    cout << "Input level.txt to app root" << endl;
    cout << "1: Create new level" << endl;
    cout << "2: Edit level" << endl;
    cout << "3: Exit" << endl;
    cout << "Choice: ";
}
void print_instructions(){
    cout << "Press W to shift controller up" << endl;
    cout << "Press A to shift controller left" << endl;
    cout << "Press S to shift controller down" << endl;
    cout << "Press D to shift controller right" << endl;
    cout << "Press E to paste chosen block" << endl;
    cout << "Press 1 to choice sky block" << endl;
    cout << "Press 2 to choice cloud block" << endl;
    cout << "Press 3 to choice grass block" << endl;
    cout << "Press 4 to choice player block" << endl;
    cout << "Press 5 to choice canal block" << endl;
    cout << "Press 6 to choice platform block" << endl;
    cout << "Press 7 to choice coin block" << endl;
    cout << "Press 8 to choice enemy block" << endl;
    cout << "Press 9 to choice trigger block" << endl;
    cout << "Press Z to shift level left" << endl;
    cout << "Press C to shift level right" << endl;
    cout << "Press R to increase shift parameter" << endl;
    cout << "Press F to decrease shift parameter" << endl;
    cout << "Press Q to save level and quit" << endl;
}
void print_choice (char pick){
    cout << "You choice ";
    if (pick == '1'){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout << "sky";
    }
    if (pick == '2'){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout << "cloud";
    }
    if (pick == '3'){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout << "grass";
    }
    if (pick == '4'){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        cout << "player";
    }
    if (pick == '5'){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
        cout << "canal";
    }
    if (pick == '6'){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        cout << "platform";
    }
    if (pick == '7'){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);
        cout << "coin";
    }
    if (pick == '8'){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
        cout << "enemy";
    }
    if (pick == '9'){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        cout << "trigger";
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    cout << " block" << endl;
}
int turn_controllerUP(int curr_pos_y){
    curr_pos_y--;
    if (curr_pos_y < 0) curr_pos_y = 0;
    return curr_pos_y;
}
int turn_controllerLEFT(int curr_pos_x){
    curr_pos_x--;
    if (curr_pos_x < 0) curr_pos_x = 0;
    return curr_pos_x;
}
int turn_controllerDOWN(int curr_pos_y, int MAX_y){
    curr_pos_y++;
    if (curr_pos_y >= MAX_y) curr_pos_y = MAX_y - 1;
    return curr_pos_y;
}
int turn_controllerRIGHT(int curr_pos_x, int MAX_x){
    curr_pos_x++;
    if (curr_pos_x >= MAX_x) curr_pos_x = MAX_x - 1;
    return curr_pos_x;
}
int increase_curr_lvl_pos (int curr_lvl_pos, int c_shift, int size_x){
    curr_lvl_pos = curr_lvl_pos + c_shift;
    if (curr_lvl_pos >= size_x) curr_lvl_pos = size_x - 1;
    return curr_lvl_pos;
}
int decrease_curr_lvl_pos (int curr_lvl_pos, int c_shift, int size_x){
    curr_lvl_pos = curr_lvl_pos - c_shift;
    if (curr_lvl_pos < 0) curr_lvl_pos = 0;
    return curr_lvl_pos;
}

/*

int field [size_x][size_y];
        for (int j = 0; j < size_y; j++){
            for ()
        }
*/
