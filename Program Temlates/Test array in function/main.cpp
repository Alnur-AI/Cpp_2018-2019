#include <iostream>

using namespace std;
const int x;
const int y;
int arr[x][y];

void printARRAY(int y, int x, int arr[][10]){
    for (int j = 0; j < y; j++){
        for (int i = 0; i < x; i++){
            cout << arr[i][j];
        }
        cout << endl;
    }
}

void fillARRAY(int y, int x, int arr[][10]){
    for (int j = 0; j < y; j++){
        for (int i = 0; i < x; i++){
            arr[i][j] = 0;
        }
    }
}

int main()
{
    x = 10;
    y = 10;
    fillARRAY(y, x, arr);
    printARRAY(y,x,arr);
    return 0;
}
