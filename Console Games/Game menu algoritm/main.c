#include <iostream>
using namespace std;

typedef struct Menu{
    int id;
    int level;
    struct Menu *next;
    struct prev *prev;
}menu;

int main(){
    return 0;
}

/*
—“–” “”–ј: двусв€зный список

    —делать выбор в меню:
        „итать все меню уровнем выше пока не встретим тот же уровень
*/
