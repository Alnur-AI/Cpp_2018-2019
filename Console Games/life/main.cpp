#include <iostream>
#include <windows.h>
#include <time.h>
using namespace std;

void inc_bacteria_x(int id);//increase bacteria pointX by 1
void inc_bacteria_y(int id);//increase bacteria pointY by 1
void dec_bacteria_x(int id);//decrease bacteria pointX by 1
void dec_bacteria_y(int id);//decrease bacteria pointY by 1
int find_free_id();//searching free ID for new bacteria in register_bacteria
int random_moving();//creating new direction for bacteria
void move_bacteria(int id);//move bacteria in
void initialize_bacteria(int id, int x, int y, int sight, int eating);
void mutation(int id);
void bacteria_info(int id);
void printfield();
void print_prev_field();
void prev_equal_curr();
void chanceColor(int background, int text);
void setcur(int x, int y);
void initialize_fields();
void eat_food_poison_cond(int id);
void input_pos_bacteria_alive();
void input_pos_ENERGY_NEWGEN();
void input_pos_numFOOD();
void input_pos_numPOISON();
void input_pos_GAMESPEED();

typedef struct life_form{
    int sight;// sight - chance that bacteria will eat this
    int moving;// direction
    int eating;// what it will eat: 1 - grass, 2 - grass + meat
    int energy;// if this parameter will equal 20 (number of eaten meal) then will created two childs with same statements
    int lifespan;// how much times it will lives: MAX = 99
    int pointX;
    int pointY;
}lifeform;

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
const int EMPTY = 0,
          FOOD = 1,
          POISON = 2,
          BACTERIA = 3,
          MEAT = 4;
const int sizeX = 10,
          sizeY = 10;
int prev_field[sizeX][sizeY],// 0 - nothing, 1 - food, 2 - poison, 3 - bacteria
    curr_field[sizeX][sizeY],// 0 - nothing, 1 - food, 2 - poison, 3 - bacteria
    bacteria_alive,
    ENERGY_NEWGEN,
    numFOOD,
    numPOISON,
    GAMESPEED;
bool register_bacteria[sizeX*sizeY];// tells what bacterias are alive
lifeform bacteria[sizeX*sizeY];//Bacterias

int main(){
    chanceColor(BLACK, GREEN_LIGHT);
    cout << "Welcome to bacteria life simulation!"<< endl << endl;
    chanceColor(BLACK, WHITE);
    cout << "HOW MUCH BACTERIAS IN FIELD:[_____] (MAX " << sizeX*sizeY << " ONLY!)" << endl;
    cout << "ENERGY FOR NEW GENERATION:[_____]" << endl;
    cout << "HOW MUCH FOOD IN FIELD:[_____]" << endl;
    cout << "HOW MUCH POISON IN FIELD:[_____]" << endl;
    cout << "GAMESPEED(in ms):[_____]" << endl;
    setcur(29,2);
    input_pos_bacteria_alive();
    setcur(27,3);
    input_pos_ENERGY_NEWGEN();
    setcur(24,4);
    input_pos_numFOOD();
    setcur(26,5);
    input_pos_numPOISON();
    setcur(18,6);
    input_pos_GAMESPEED();
    system("cls");

    for (int id = 0; id < bacteria_alive; id++)
        initialize_bacteria(id, sizeX/2, sizeY/2, 0, 1);
    initialize_fields();
    print_prev_field();//prepare field to rewriting
    while (bacteria_alive != 0){
        for (int id = 0; id < sizeX*sizeY; id++)
            if (register_bacteria[id] == true){
                move_bacteria(id);
                mutation(id);
            }

        printfield();
        Sleep(GAMESPEED);

        for (int id = 0; id < 3;id++)
            if (register_bacteria[id] == true){
                bacteria_info(id);
            }

        setcur(0, sizeY + 1);
        cout << "BACTERIA ALIVE: " << bacteria_alive << "    ";
    }
    Sleep(1000);
    return 0;
}
void initialize_bacteria(int id, int x, int y, int sight, int eating){
    register_bacteria[id] = true;
    bacteria[id].eating = eating;//grass eating
    bacteria[id].energy = 0;//no energy to create childs
    bacteria[id].lifespan = 99;
    bacteria[id].moving = random_moving();
    bacteria[id].sight = sight;
    bacteria[id].pointX = x;
    bacteria[id].pointY = y;
}
void initialize_fields(){
    srand(time(0));
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            prev_field[x][y] = EMPTY;
            curr_field[x][y] = EMPTY;
        }
    }
    for (int i = 0; i < numPOISON; i++){
        int x = rand()%sizeX;
        int y = rand()%sizeY;
        curr_field[x][y] = POISON;
    }
    for (int i = 0; i < numFOOD; i++){
        int x = rand()%sizeX;
        int y = rand()%sizeY;
        curr_field[x][y] = FOOD;
    }
}
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
void printfield(){
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            if (prev_field[x][y] != curr_field[x][y]){
                setcur(2 * x,y);
                if (curr_field[x][y] == EMPTY){
                    chanceColor(BLACK, WHITE);
                    cout << "." << " ";
                    continue;
                }
                if (curr_field[x][y] == FOOD){
                    chanceColor(BLACK, GREEN_LIGHT);
                    cout << "*" << " ";
                    continue;
                }
                if (curr_field[x][y] == POISON){
                    chanceColor(BLACK, RED);
                    cout << "x" << " ";
                    continue;
                }
                if (curr_field[x][y] == BACTERIA){
                    chanceColor(BLACK, BLUE);
                    cout << "@" << " ";
                    continue;
                }
                if (curr_field[x][y] == MEAT){
                    chanceColor(BLACK, PURPLE_LIGHT);
                    cout << "@" << " ";
                    continue;
                }
            }
        }
    }
    chanceColor(BLACK, WHITE);
    prev_equal_curr();
}
int random_moving(){
    int a = rand()%8;
    return a;
}
void inc_bacteria_x(int id){
    bacteria[id].pointX++;
    if (bacteria[id].pointX >= sizeX)
        bacteria[id].pointX = 0;
}
void dec_bacteria_x(int id){
    bacteria[id].pointX--;
    if (bacteria[id].pointX < 0)
        bacteria[id].pointX = sizeX - 1;
}
void inc_bacteria_y(int id){
    bacteria[id].pointY++;
    if (bacteria[id].pointY >= sizeY)
        bacteria[id].pointY = 0;
}
void dec_bacteria_y(int id){
    bacteria[id].pointY--;
    if (bacteria[id].pointY < 0)
        bacteria[id].pointY = sizeY - 1;
}
void move_bacteria(int id){
    if (register_bacteria[id] == false)
        return;
    curr_field[bacteria[id].pointX][bacteria[id].pointY] = EMPTY;
    if (bacteria[id].sight > 0){
        if (bacteria[id].eating == 1){
            if(curr_field[bacteria[id].pointX - 1][bacteria[id].pointY] == FOOD && bacteria[id].pointX - 1 >= 0){
                dec_bacteria_x(id);
                eat_food_poison_cond(id);
                return;
            }
            if(curr_field[bacteria[id].pointX + 1][bacteria[id].pointY] == FOOD && bacteria[id].pointX + 1 < sizeX){
                inc_bacteria_x(id);
                eat_food_poison_cond(id);
                return;
            }
            if(curr_field[bacteria[id].pointX][bacteria[id].pointY - 1] == FOOD && bacteria[id].pointY - 1 >= 0){
                dec_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
            if(curr_field[bacteria[id].pointX][bacteria[id].pointY + 1] == FOOD && bacteria[id].pointY + 1 < sizeY){
                inc_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
            if(curr_field[bacteria[id].pointX - 1][bacteria[id].pointY + 1] == FOOD && bacteria[id].pointX - 1 >= 0 && bacteria[id].pointY + 1 < sizeY){
                dec_bacteria_x(id);
                inc_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
            if(curr_field[bacteria[id].pointX + 1][bacteria[id].pointY + 1] == FOOD && bacteria[id].pointX + 1 < sizeX && bacteria[id].pointY + 1 < sizeY){
                inc_bacteria_x(id);
                inc_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
            if(curr_field[bacteria[id].pointX - 1][bacteria[id].pointY - 1] == FOOD && bacteria[id].pointX - 1 >= 0 && bacteria[id].pointY - 1 >= 0){
                dec_bacteria_x(id);
                dec_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
            if(curr_field[bacteria[id].pointX + 1][bacteria[id].pointY - 1] == FOOD && bacteria[id].pointX + 1 < sizeX && bacteria[id].pointY - 1 >= 0){
                inc_bacteria_x(id);
                dec_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
        }
    }
    bacteria[id].moving = random_moving();
    if (bacteria[id].moving == 0){
        dec_bacteria_x(id);
        dec_bacteria_y(id);
    }
    if (bacteria[id].moving == 1){
        dec_bacteria_y(id);
    }
    if (bacteria[id].moving == 2){
        inc_bacteria_x(id);
        dec_bacteria_y(id);
    }
    if (bacteria[id].moving == 3){
        inc_bacteria_x(id);
    }
    if (bacteria[id].moving == 4){
        inc_bacteria_x(id);
        inc_bacteria_y(id);
    }
    if (bacteria[id].moving == 5){
        inc_bacteria_y(id);
    }
    if (bacteria[id].moving == 6){
        dec_bacteria_x(id);
        inc_bacteria_y(id);
    }
    if (bacteria[id].moving == 7){
        dec_bacteria_x(id);
    }
    eat_food_poison_cond(id);
}
void print_prev_field(){
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            setcur(2*x, y);
            cout << "." << " ";
        }
    }
}
void prev_equal_curr(){
    for (int y = 0; y < sizeY; y++){
        for (int x = 0; x < sizeX; x++){
            prev_field[x][y] = curr_field[x][y];
        }
    }
}
void bacteria_info(int id){
    setcur(2*(sizeX + 1), 1 + 6*(id));
    cout << "BACTERIA ID: #" << id << "    ";
    setcur(2*(sizeX + 1), 1 + 1 + 6*(id));
    cout << "ENERGY: " << bacteria[id].energy << "    ";
    setcur(2*(sizeX + 1), 1 + 2 + 6*(id));
    cout << "LIFESPAN: " << bacteria[id].lifespan << "    ";
    setcur(2*(sizeX + 1), 1 + 3 + 6*(id));
    cout << "SIGHT: " << bacteria[id].sight << "    ";
    setcur(2*(sizeX + 1), 1 + 4 + 6*(id));
    cout << "VEGAN OR OMNIVOROUS: " << bacteria[id].eating << "    ";
}
void mutation(int id){
    int chance_of_mutation = rand()%100;
    if (chance_of_mutation < 6){
        bacteria[id].sight++;
    }
    if (chance_of_mutation == 4){
        bacteria[id].sight--;
        if (bacteria[id].sight < 0) bacteria[id].sight = 0;
    }
}
int find_free_id(){
    for (int i = 0; i < sizeX*sizeY; i++){
        if (register_bacteria[i] == false){
            return i;
        }
    }
    return -1;
}
void eat_food_poison_cond(int id){
    int x,y;
    if (curr_field[bacteria[id].pointX][bacteria[id].pointY] == FOOD){
        bacteria[id].energy++;
        do{
            x = rand()%sizeX;
            y = rand()%sizeY;
        }while(curr_field[x][y] == BACTERIA);
        curr_field[x][y] = FOOD;
    }
    if (curr_field[bacteria[id].pointX][bacteria[id].pointY] == POISON)
        bacteria[id].lifespan = 1;
    bacteria[id].lifespan--;
    curr_field[bacteria[id].pointX][bacteria[id].pointY] = BACTERIA;
    if (bacteria[id].lifespan == 0){
        curr_field[bacteria[id].pointX][bacteria[id].pointY] = MEAT;
        register_bacteria[id] = false;
        bacteria_alive--;
    }
    if (bacteria[id].energy == ENERGY_NEWGEN){
        bacteria[id].energy = 0;
        bacteria[id].lifespan = 99;
        if (find_free_id() == -1) return;
        initialize_bacteria(find_free_id(), bacteria[id].pointX, bacteria[id].pointY, bacteria[id].sight, bacteria[id].eating);
        bacteria_alive++;
        return;
    }
}
void input_pos_bacteria_alive(){
    cin >> bacteria_alive;
    if (bacteria_alive == 0)
        bacteria_alive = 1;
    if (bacteria_alive > sizeX*sizeY)
        bacteria_alive = sizeX*sizeY;
    if (bacteria_alive < 0)
        bacteria_alive = bacteria_alive * (-1);
}
void input_pos_ENERGY_NEWGEN(){
    cin >> ENERGY_NEWGEN;
    if (ENERGY_NEWGEN == 0)
        ENERGY_NEWGEN = 1;
    if (ENERGY_NEWGEN < 0)
        ENERGY_NEWGEN = ENERGY_NEWGEN * (-1);
}
void input_pos_numFOOD(){
    cin >> numFOOD;
    if (numFOOD < 0)
        numFOOD = numFOOD * (-1);
}
void input_pos_numPOISON(){
    cin >> numPOISON;
    if (numPOISON < 0)
        numPOISON = numPOISON * (-1);
}
void input_pos_GAMESPEED(){
    cin >> GAMESPEED;
    if (GAMESPEED < 0)
        GAMESPEED = GAMESPEED * (-1);
}
