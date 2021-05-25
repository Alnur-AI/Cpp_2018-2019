#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main()
{
    for (int i = 0; i <= 256; i++)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),i);
        cout << i << ") " << "Hello world!" << endl;
    }
    return 0;
}
