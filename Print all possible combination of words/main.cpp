#include <iostream>
using namespace std;
// Í Ð Ñ Ò Î À

void associate(int number){
    if (number == 0){
        cout << "H ";
        return;
    }
    if (number == 1){
        cout << "P ";
        return;
    }
    if (number == 2){
        cout << "C ";
        return;
    }
    if (number == 3){
        cout << "T ";
        return;
    }
    if (number == 4){
        cout << "O ";
        return;
    }
    if (number == 5){
        cout << "A ";
        return;
    }
}

int main()
{
    int letters = 6;
    for (int a = 0; a < letters; a++)
        for (int b = 0; b < letters; b++)
            for (int c = 0; c < letters; c++)
                for (int d = 0; d < letters; d++)
                    for (int e = 0; e < letters; e++)
                        for (int f = 0; f < letters; f++)
                            if (a != b && a != c && a != d && a != e && a != f &&
                                b != c && b != d && b != e && b != f &&
                                c != d && c != e && c != f &&
                                d != e && d != f &&
                                e != f){
                                associate(a);
                                associate(b);
                                associate(c);
                                associate(d);
                                associate(e);
                                associate(f);
                                cout << endl;
                            }

    return 0;
}
