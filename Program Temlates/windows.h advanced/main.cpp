#include <iostream>
#include <windows.h>

using namespace std;

const int BLACK = 0,
 BLUE_DARK = 1,
 GREEN_DARK = 2,
 BLUE = 3,
 RED = 4,
 PURPLE_LIGHT = 5,
 YELLOW_DARK = 6,
 WHITE_DARK = 7,
 GRAY = 8,
 BLUE_NOTDARK = 9,
 GREEN_LIGHT = 10,
 BLUE_LIGHT = 11,
 PINK = 12,
 PURPLE_DARK = 13,
 YELLOW_LIGHT = 14,
 WHITE = 15;


void chanceColor(int background, int text){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD) ((background << 4) | text));
}

void setcur(int x, int y){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);//Дескриптор для передачи управления программисту
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(hConsole, coord);
}

int main()
{
    //system("color bf");// B - Background, F - TEXT, Шестнадцатеричная система
    SetConsoleTitle("NAME OF MY PROGRAM");
    chanceColor(BLACK, RED);
    setcur(0,0);
    cout << "Hello world!" << endl;
    setcur(20,10);
    cout << "Hello world!" << endl;
    return 0;
}
