#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct SUBmenu{
    int id;
    int level;
    string text;
}submenu;

int main(){
    submenu menu[21];
    for (int i = 0; i < 21 ;i++) {
        menu[i].id = i;
        if (i == 0 || i == 3 || i == 7 || i == 19 || i == 20) menu[i].level = 0;
        if (i == 1 || i == 2 || i == 4 || i == 5 || i == 6 || i == 8 || i == 11 || i == 17 || i == 18) menu[i].level = 1;
        if (i == 9 || i == 10 || i == 12 || i == 13 || i == 14 || i == 15 || i == 16) menu[i].level = 2;
    }
    menu[0].text = "New game";
    menu[1].text = "Yes";
    menu[2].text = "No";
    menu[3].text = "Load game";
    menu[4].text = "Save 1";
    menu[5].text = "Save 2";
    menu[6].text = "Save 3";
    menu[7].text = "Settings";
    menu[8].text = "Sound";
    menu[9].text = "ON";
    menu[10].text = "OFF";
    menu[11].text = "Game Speed";
    menu[12].text = "Very slow";
    menu[13].text = "Slow";
    menu[14].text = "Normal";
    menu[15].text = "Fast";
    menu[16].text = "GONNA GO FAST!";
    menu[17].text = "X size =";
    menu[18].text = "Y size =";
    menu[19].text = "Credits";
    menu[20].text = "Exit";


    char move = _getch();
    if ()
    int curr_id = 0;
    int curr_lvl = 0;
    for (int i = 0; i < 21; i++) if (menu[i].level == curr_lvl) cout << menu[i].text << endl;






    return 0;
}
