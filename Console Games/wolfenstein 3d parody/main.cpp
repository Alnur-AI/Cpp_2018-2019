#include <iostream>
#include <cmath>
#include <conio.h>
#include <windows.h>
using namespace std;

const int X_MAP = 30;
const int Y_MAP = 30;
const int X_SCREEN = 60;
const int Y_SCREEN = 40;
const double pi = 3.1415;
double AOV = pi/2.0; //angle of view
double ROT = 0.0; // rotation
double dangle = (AOV - ROT) / X_SCREEN; // delta angle for scanning walls

short map[X_MAP][Y_MAP]; //0 - void, 1 - wall, 2 - player
short screen[X_SCREEN][Y_SCREEN];// 1 - wall
double player_x = X_MAP/2.0;
double player_y = Y_MAP/2.0;

void readmap(){
    for (int j = 0; j < Y_MAP; j++){
        for (int i = 0; i < X_MAP; i++){
            if (i == (int)player_x && j == (int)player_y){
                map[i][j] = 2;
                continue;
            }
            if ( i == 0 || j == 0 || i == X_MAP - 1 || j == Y_MAP - 1){
                map[i][j] = 1;
                continue;
            }
            map[i][j] = 0;
        }
    }
}
double y_view (double angle, double x){
    double y = tan(angle) * (x - player_x) + player_y;
    return y;
}
void print_map(){
    for (int y = 0; y < Y_MAP; y++){
        for (int x = 0; x < X_MAP; x++){
            if (y == (int)y_view(ROT,x)){
                cout << "i ";
                continue;
            }
            if (y == (int)y_view(AOV,x)){
                cout << "7 ";
                continue;
            }
            if ( map[x][y] == 2){
                cout << "P ";
                continue;
            }
            if ( map[x][y] == 1){
                cout << "# ";
                continue;
            }
            cout << ". ";
        }
        cout << endl;
    }
}
double square (double a){
    return a*a;
}
double distance_to_wall(double x_wall, double y_wall){
    return sqrt(square(player_x - x_wall) + square(player_y - y_wall));
}
double num_percent (double percent, double num){
    return num * percent / 100.0;
}
double screen_line (double dist){
    double a = num_percent(95.0, Y_SCREEN) - num_percent(5.0, Y_SCREEN);
    double b = (-1) * sqrt( square(X_SCREEN) + square(Y_SCREEN) );
    double c = dist + b;
    double d = num_percent(5.0, Y_SCREEN);
    double res = (a * c) / b + d;
    return res;
}

void fill_scr_column (double screen_size, int x_column){
    int scr_c = ((int)screen_size) / 2;
    int scr_half = Y_SCREEN / 2 - 1;
    for (int i = 0; i < scr_c; i++){
        screen[x_column][scr_half - i] = 1;
        screen[x_column][scr_half + i] = 1;
    }
}
void print_screen(){
    for (int j = 0; j < Y_SCREEN; j++){
        for (int i = 0; i < X_SCREEN; i++){
            if (screen[i][j] == 1){
                cout << "* ";
                continue;
            }
            cout << ". ";
        }
        cout << endl;
    }
}

double x_find_wall(double ang){
    double dx = 0.1;
    if (ang == 0){
        return (double)X_MAP - player_x;
    }
    if (0 < ang && ang < pi/2.0)
        for (double x = player_x; x < X_MAP; x = x + dx)
             if (map[(int)x][(int)y_view(ang, x)] == 1)
                return x;
    if (ang == pi / 2.0){
        return player_x;
    }
    if (pi / 2.0 < ang && ang < pi){
        for (double x = player_x; x >= 0; x = x - dx)
             if (map[(int)x][(int)y_view(ang, x)] == 1)
                return x;
    }
    if (ang == pi){
        return 0.0;
    }
    if (pi < ang && ang < 3 * pi / 2){
        for (double x = player_x; x >= 0; x = x - dx)
             if (map[(int)x][(int)y_view(ang, x)] == 1)
                return x;
    }
    if (ang == 3 * pi / 2){
        return player_x;
    }
    if (3 * pi / 2 < ang && ang < 2 * pi)
        for (double x = player_x; x < X_MAP; x = x + dx)
             if (map[(int)x][(int)y_view(ang, x)] == 1)
                return x;
}

double y_find_wall(double ang){
    double dx = 0.1;
    if (ang == 0){
        return player_y;
    }
    if (0 < ang && ang < pi/2.0)
        for (double x = player_x; x < X_MAP; x = x + dx)
             if (map[(int)x][(int)y_view(ang, x)] == 1)
                return y_view(ang, x);
    if (ang == pi / 2.0){
        return Y_MAP;
    }
    if (pi / 2.0 < ang && ang < pi){
        for (double x = player_x; x >= 0; x = x - dx)
             if (map[(int)x][(int)y_view(ang, x)] == 1)
                return y_view(ang, x);
    }
    if (ang == pi){
        return player_y;
    }
    if (pi < ang && ang < 3 * pi / 2){
        for (double x = player_x; x >= 0; x = x - dx)
             if (map[(int)x][(int)y_view(ang, x)] == 1)
                return y_view(ang, x);
    }
    if (ang == 3 * pi / 2){
        return 0.0;
    }
    if (3 * pi / 2 < ang && ang < 2 * pi)
        for (double x = player_x; x < X_MAP; x = x + dx)
             if (map[(int)x][(int)y_view(ang, x)] == 1)
                return y_view(ang, x);
}

void shift_player(char move){
    if (move == 'q'){
        ROT = ROT + dangle;
        if (ROT >= 2*pi){
            ROT = ROT - 2*pi;
        }
        AOV = AOV + dangle;
        if (AOV >= 2*pi){
            AOV = AOV - 2*pi;
        }
    }
    if (move == 'e'){
        ROT = ROT - dangle;
        if (ROT <= 0){
            ROT = ROT + 2*pi;
        }
        AOV = AOV - dangle;
        if (AOV <= 0){
            AOV = AOV + 2*pi;
        }
    }
    if (move == 'w'){
        player_y = player_y - 1;
        if (player_y < 0)
            player_y = 0;
    }
    if (move == 'a'){
        player_x = player_x + 1;
        if(player_x > X_MAP - 1)
            player_x = X_MAP - 1;
    }
    if (move == 's'){
        player_y = player_y + 1;
        if(player_y > Y_MAP - 1)
            player_y = Y_MAP - 1;
    }
    if (move == 'd'){
        player_x = player_x + 1;
        if (player_x < 0)
            player_x = 0;
    }
    if (move == 'z'){
        exit(0);
    }
}

int main(void){
    readmap();
    double view = ROT;
    char move = 'w';
    while (1){
        system("cls");
        for (int i = 0; i < X_SCREEN; i++){
            view += dangle;
            fill_scr_column(screen_line(distance_to_wall(x_find_wall(view),y_find_wall(view))), i);
        }
        view = ROT;
        print_screen();
        print_map();
        move = _getch();
        shift_player(move);
        readmap();
    }


    return 0;
}
