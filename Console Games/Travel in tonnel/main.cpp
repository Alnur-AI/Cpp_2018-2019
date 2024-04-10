#include <iostream>
#include <windows.h>
using namespace std;

int sizeX = 16;
int sizeY = 16;

int main() {
    int counter = 1;
	while (1){

        counter--;
        if (counter < 1 ) counter = sizeX/2;

        for (int y = 0; y < sizeY; y++){
            for (int x = 0; x < sizeX; x++){
                //if ( (x == sizeX/2 - 1 && y == sizeY/2 - 1) || (x == sizeX/2 && y == sizeY/2 - 1) || (x == sizeX/2 - 1 && y == sizeY/2) || (x == sizeX/2 && y == sizeY/2) ) && counter == 0{
                if ( (x == y || x == (sizeX - 1) - y) && (x < counter || (sizeX - x - 1)<counter) || (y == counter - 1 && x > counter - 1 && (sizeX - x - 1) > counter - 1) || ((sizeX - y - 1) == counter - 1 && x > counter - 1 && (sizeX - x - 1) > counter - 1) || ((sizeX - x - 1) == counter - 1 && y > counter - 1 && (sizeX - y - 1) > counter - 1) || (x == counter - 1 && y > counter - 1 && (sizeX - y - 1) > counter - 1)) {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
                    cout << "& ";
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
                    continue;
                }
                else{
                    cout << "* ";
                }
            }
            cout << endl;
        }
        //Sleep(250);
        system("cls");
    }
}
