#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;
const int sizeX = 10;
const int sizeY = 10;
// 0 - empty, 1 - ship, 2 - hit, 3 - miss

int abs(int a){
    if (a >= 0) return a;
    return (-1)*a;
}
bool anti_eqv(bool x, bool y){
    if (x == true && y == true || x == false && y == false) return false;
    return true;
}

bool value_lays_between_hard (int value, int a, int b){
    if (value == a && a == b) return true;

    if (a < b) if (a <= value && value >= b) return true;
    if (a > b) if (b <= value && value >= a) return true;
}

int increase_turn(int turn, int maxplayer){
    turn++;
    if (turn >= maxplayer) turn = 0;
    return turn;
}
int increase_coordX(int coordX){
    coordX++;
    if (coordX >= sizeX) coordX = sizeX - 1;
    return coordX;
}
int increase_coordY(int coordY){
    coordY++;
    if (coordY >= sizeY) coordY = sizeY - 1;
    return coordY;
}
int decrease_coordX(int coordX){
    coordX--;
    if (coordX < 0) coordX = 0;
    return coordX;
}
int decrease_coordY(int coordY){
    coordY--;
    if (coordY < 0) coordY = 0;
    return coordY;
}

int shipsleft(int player, int field[][sizeX][sizeY]){
    int result = 0;
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            if (field[player][x][y] == 1) result++;
        }
    }
    return result;
}

void printfield(int player, int contrX, int contrY, int field[][sizeX][sizeY]){
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            if (field[player][x][y] == 0 && x == contrX && y == contrY){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
                cout << ". ";
                continue;
            }
            if (field[player][x][y] == 1 && x == contrX && y == contrY ){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 234);
                cout << "# ";
                continue;
            }
            if (field[player][x][y] == 0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << ". ";
                continue;
            }
            if (field[player][x][y] == 1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout << "# ";
                continue;
            }
        }
        cout << endl;
    }
}
void printBATTLEfield(int player,int contrX, int contrY, int field[][sizeX][sizeY]){
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
             if (field[player][x][y] == 0 && x == contrX && y == contrY){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
                cout << ". ";
                continue;
            }
            if (field[player][x][y] == 1 && x == contrX && y == contrY ){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
                cout << ". ";
                continue;
            }
            if (field[player][x][y] == 2 && x == contrX && y == contrY){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 228);
                cout << "# ";
                continue;
            }
            if (field[player][x][y] == 3 && x == contrX && y == contrY){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 228);
                cout << ". ";
                continue;
            }
            if (field[player][x][y] == 0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << ". ";
                continue;
            }
            if (field[player][x][y] == 1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << ". ";
                continue;
            }
            if (field[player][x][y] == 2){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << "# ";
                continue;
            }
            if (field[player][x][y] == 3){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                cout << ". ";
                continue;
            }
        }
        cout << endl;
    }
}
void printMODfield (int player, int contrX, int contrY, int prevX, int prevY, int field[][sizeX][sizeY]){
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            if (field[player][x][y] == 0 && (x == contrX || x == prevX) && (y == contrY || y == prevY)){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 224);
                cout << ". ";
                continue;
            }
            if (field[player][x][y] == 1 && (x == contrX || x == prevX) && (y == contrY || y == prevY) ){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 234);
                cout << "# ";
                continue;
            }
            if (field[player][x][y] == 0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                cout << ". ";
                continue;
            }
            if (field[player][x][y] == 1){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
                cout << "# ";
                continue;
            }
        }
        cout << endl;
    }
}

int main(){
    // DEFINE CONSTANTS
    int turn = 0;
    int maxplayer;
    cout << "SHIP BATTLE ROYALE!!!\nHow much players would play?\nPlayers: ";
    cin >> maxplayer;
    if (maxplayer < 2) maxplayer = 2;
    system("cls");
    int field[maxplayer][sizeX][sizeY];
    for (int z = 0; z < maxplayer; z++)
        for (int x = 0; x < sizeX; x++)
            for (int y = 0; y < sizeY; y++)
                field[z][x][y] = 0;
    // PLACE A SHIPS
    for (turn = 0; turn < maxplayer; turn++){
        char move;
        int contrX = sizeX/2, contrY = sizeY/2;
        int shipSIZE4 = 1;
        int shipSIZE3 = 2;
        int shipSIZE2 = 3;
        int shipSIZE1 = 4;
        while(shipSIZE1 != 0 || shipSIZE2 != 0 || shipSIZE3 != 0 || shipSIZE4 != 0){
            cout << "PLAYER " << turn + 1 << " turn!" << endl;
            cout << "Press E to place # ships" << endl;
            if (move == 'w') contrY = decrease_coordY (contrY);
            if (move == 'a') contrX = decrease_coordX (contrX);
            if (move == 's') contrY = increase_coordY (contrY);
            if (move == 'd') contrX = increase_coordX (contrX);
            if (move == 'e' && field[turn][contrX][contrY] != 1 && (shipSIZE1 != 0 || shipSIZE2 != 0 || shipSIZE3 != 0 || shipSIZE4 != 0) ){
                int prevX = contrX, prevY = contrY;
                field[turn][contrX][contrY] = 1;
                bool near_some_ships = field[turn][contrX - 1][contrY] == 1 || field[turn][contrX + 1][contrY] == 1 || field[turn][contrX][contrY + 1] == 1 || field[turn][contrX][contrY - 1] == 1 || field[turn][contrX + 1][contrY + 1] || field[turn][contrX - 1][contrY + 1] || field[turn][contrX + 1][contrY - 1] || field[turn][contrX - 1][contrY - 1];
                if (near_some_ships == true){
                    field[turn][contrX][contrY] = 0;
                    move = 'l';
                    continue;
                }
                while(1){
                    system("cls");
                    cout << "PLAYER " << turn + 1 << " turn!" << endl;
                    cout << "Press E to place # ships" << endl;

                    if (move == 'w') contrY = decrease_coordY (contrY);
                    if (move == 'a') contrX = decrease_coordX (contrX);
                    if (move == 's') contrY = increase_coordY (contrY);
                    if (move == 'd') contrX = increase_coordX (contrX);
                    if (move == 'q'){
                        field[turn][prevX][prevY] = 0;
                        move = 'l';
                        break;
                    }
                    //bool problem_ship_around = field[turn][contrX][contrY]!= 1 || field[turn][contrX - 1][contrY] == 1 || field[turn][contrX + 1][contrY] == 1 || field[turn][contrX][contrY + 1] == 1 || field[turn][contrX][contrY - 1] == 1 || field[turn][contrX + 1][contrY + 1] || field[turn][contrX - 1][contrY + 1] || field[turn][contrX + 1][contrY - 1] || field[turn][contrX - 1][contrY - 1];
                    bool shipx4_cnd = anti_eqv(abs(contrX - prevX) == 3, abs(contrY - prevY) == 3) && shipSIZE4 != 0 && field[turn][contrX][contrY]!= 1;
                    bool shipx3_cnd = anti_eqv(abs(contrX - prevX) == 2, abs(contrY - prevY) == 2) && shipSIZE3 != 0 && field[turn][contrX][contrY]!= 1;
                    bool shipx2_cnd = anti_eqv(abs(contrX - prevX) == 1, abs(contrY - prevY) == 1) && shipSIZE2 != 0 && field[turn][contrX][contrY]!= 1;
                    bool shipx1_cnd = shipSIZE1 != 0;
                    if (move == 'e' && (shipx1_cnd == true || shipx2_cnd == true || shipx3_cnd == true || shipx4_cnd == true)){
                        if (shipx4_cnd == true){
                            shipSIZE4--;
                            if (contrX - prevX < 0 && contrY == prevY){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX - 1][prevY] = 1;
                                field[turn][prevX - 2][prevY] = 1;
                                field[turn][prevX - 3][prevY] = 1;
                            }
                            if (contrX - prevX > 0 && contrY == prevY){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX + 1][prevY] = 1;
                                field[turn][prevX + 2][prevY] = 1;
                                field[turn][prevX + 3][prevY] = 1;
                            }
                            if (contrY - prevY < 0 && contrX == prevX){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX][prevY - 1] = 1;
                                field[turn][prevX][prevY - 2] = 1;
                                field[turn][prevX][prevY - 3] = 1;
                            }
                            if (contrY - prevY > 0 && contrX == prevX){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX][prevY + 1] = 1;
                                field[turn][prevX][prevY + 2] = 1;
                                field[turn][prevX][prevY + 3] = 1;
                            }
                            move = 'l';
                            break;
                        }
                        if (shipx3_cnd == true){
                            shipSIZE3--;
                            if (contrX - prevX < 0 && contrY == prevY){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX - 1][prevY] = 1;
                                field[turn][prevX - 2][prevY] = 1;
                            }
                            if (contrX - prevX > 0 && contrY == prevY){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX + 1][prevY] = 1;
                                field[turn][prevX + 2][prevY] = 1;
                            }
                            if (contrY - prevY < 0 && contrX == prevX){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX][prevY - 1] = 1;
                                field[turn][prevX][prevY - 2] = 1;
                            }
                            if (contrY - prevY > 0 && contrX == prevX){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX][prevY + 1] = 1;
                                field[turn][prevX][prevY + 2] = 1;
                            }
                            move = 'l';
                            break;
                        }
                        if (shipx2_cnd == true){
                            shipSIZE2--;
                            if (contrX - prevX < 0 && contrY == prevY){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX - 1][prevY] = 1;

                            }
                            if (contrX - prevX > 0 && contrY == prevY){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX + 1][prevY] = 1;

                            }
                            if (contrY - prevY < 0 && contrX == prevX){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX][prevY - 1] = 1;

                            }
                            if (contrY - prevY > 0 && contrX == prevX){
                                field[turn][prevX][prevY] = 1;
                                field[turn][prevX][prevY + 1] = 1;

                            }
                            move = 'l';
                            break;
                        }
                        if (shipx1_cnd == true){
                            shipSIZE1--;
                            //field[turn][prevX][prevY] = 1;
                            move = 'l';
                            break;
                        }
                    }
                    system("cls");
                    cout << "PLAYER " << turn + 1 << " turn!" << endl;
                    cout << "Press E to select the second position of your ship" << endl;
                    cout << "Press Q to cancel" << endl;
                    printMODfield(turn, contrX, contrY, prevX, prevY, field);
                    cout << "#### ships " << shipSIZE4 << " left" << endl;
                    cout << " ### ships " << shipSIZE3 << " left" << endl;
                    cout << "  ## ships " << shipSIZE2 << " left" << endl;
                    cout << "   # ships " << shipSIZE1 << " left" << endl;
                    move = _getch();
                    system("cls");
                }
            }
            printfield(turn, contrX, contrY, field);
            move = _getch();
            system("cls");
        }
    }
    //BATTLE!!!!!!!!!!!!!!!!
    char move;
    int contrX = sizeX/2, contrY = sizeY/2;
    turn = -1;
    int enemy = 0;
    int scoreplayer[maxplayer];
    for (int i = 0; i < maxplayer; i++)
        scoreplayer[i] = shipsleft(i, field);
    int left_players;

    while(1){
        left_players = 0;
        for (int i = 0; i < maxplayer; i++) left_players = left_players + (scoreplayer[i] != 0);
        if (left_players == 1){
            system("cls");
            cout << "Player " << turn + 1 << " wins!!!" << endl;
            printBATTLEfield(enemy, contrX, contrY, field);
            cout << "Press any key to exit..." << endl;
            move = _getch();
            return 0;
        }
        if (left_players > 1){
            enemy = increase_turn(enemy, maxplayer);
                if (scoreplayer[enemy] == 0)
                    while(scoreplayer[enemy] == 0 || enemy == turn)
                        enemy = increase_turn(enemy, maxplayer);
            turn = increase_turn(turn, maxplayer);
                if (scoreplayer[turn] == 0)
                    while(scoreplayer[turn] == 0 || enemy == turn)
                        turn = increase_turn(turn, maxplayer);
            if (enemy == turn){
                while(scoreplayer[enemy] == 0 || enemy == turn)
                        enemy = increase_turn(enemy, maxplayer);
            }
        }
        while(1){//put choice
            system("cls");
            if (move == 'w') contrY = decrease_coordY (contrY);
            if (move == 'a') contrX = decrease_coordX (contrX);
            if (move == 's') contrY = increase_coordY (contrY);
            if (move == 'd') contrX = increase_coordX (contrX);
            if (move == 'e' && field[enemy][contrX][contrY] == 1){
                move = 'l';
                field[enemy][contrX][contrY] = 2;
                scoreplayer[enemy]--;
                system("cls");
                cout << "Player " << turn + 1 << " attacks "  << "Player " << enemy + 1 << endl;
                printBATTLEfield(enemy, contrX, contrY, field);
                break;
            }
            if (move == 'e' && field[enemy][contrX][contrY] == 0){
                move = 'l';
                field[enemy][contrX][contrY] = 3;
                system("cls");
                cout << "Player " << turn + 1 << " attacks "  << "Player " << enemy + 1 << endl;
                printBATTLEfield(enemy, contrX, contrY, field);
                break;
            }
            cout << "Player " << turn + 1 << " attacks "  << "Player " << enemy + 1 << endl;
            printBATTLEfield(enemy, contrX, contrY, field);
            move = _getch();
        }

    }
}

//field[turn][contrX][contrY]!= 1 && field[turn][contrX - 1][contrY] == 1 && field[turn][contrX + 1][contrY] == 1 && field[turn][contrX][contrY + 1] == 1 && field[turn][contrX][contrY - 1] == 1 && field[turn][contrX + 1][contrY + 1] && field[turn][contrX - 1][contrY + 1] && field[turn][contrX + 1][contrY - 1] && field[turn][contrX - 1][contrY - 1];
//field[turn][contrX][contrY]!= 1 || field[turn][contrX - 1][contrY] == 1 || field[turn][contrX + 1][contrY] == 1 || field[turn][contrX][contrY + 1] == 1 || field[turn][contrX][contrY - 1] == 1 || field[turn][contrX + 1][contrY + 1] || field[turn][contrX - 1][contrY + 1] || field[turn][contrX + 1][contrY - 1] || field[turn][contrX - 1][contrY - 1];

/*

while (1){//game process
        if (endgame == true){
            cout << "PLAYER " << lastplayer << " WINS!!!" << endl;
            cout << "Press any button to exit" << endl;
            move = _getch();
            return 0;
        }
        endgame = true;
        for (int i = 0; i < maxplayer; i++){
            endgame = endgame && shipsleft(i, field) == 0;
            if (shipsleft(i,field) != 0) lastplayer = i + 1;
        }
        if (shipsleft(turn, field) == 0){
            turn = increase_turn(turn, maxplayer);
            if (enemy == turn) turn = increase_turn(turn, maxplayer);
            continue;
        }

        if (shipsleft(enemy, field) == 0){
            enemy = increase_turn(enemy, maxplayer);
            if (enemy == turn) enemy = increase_turn(enemy, maxplayer);
            continue;
        }

        while (1){
            system("cls");
            cout << "enemy: " << shipsleft(enemy, field) << "player" << enemy + 1 << endl;
            cout << "me: " << shipsleft(turn, field) << "player" << turn + 1 << endl;
            if (move == 'w') contrY = decrease_coordY (contrY);
            if (move == 'a') contrX = decrease_coordX (contrX);
            if (move == 's') contrY = increase_coordY (contrY);
            if (move == 'd') contrX = increase_coordX (contrX);
            if (move == 'e' && field[enemy][contrX][contrY] == 1){
                move = 'l';
                field[enemy][contrX][contrY] = 2;
                printBATTLEfield(enemy, contrX, contrY, field);
                enemy = increase_turn(enemy, maxplayer);
                turn = increase_turn(turn, maxplayer);
                break;
            }
            if (move == 'e' && field[enemy][contrX][contrY] == 0){
                move = 'l';
                field[enemy][contrX][contrY] = 3;
                printBATTLEfield(enemy, contrX, contrY, field);
                enemy = increase_turn(enemy, maxplayer);
                turn = increase_turn(turn, maxplayer);
                break;
            }
            cout << "Player " << turn + 1 << " attacks "  << "Player " << enemy + 1 << endl;
            printBATTLEfield(enemy, contrX, contrY, field);
            move = _getch();
        }
    }
    return 0;
*/
