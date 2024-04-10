#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

const int M = 80, N = 40;
int size = 8;//size of blocks in pixels

int field[M][N],// 0 - nothing, 1 - food, 2 - poison, 3 - bacteria
    bacteria_alive,
    ENERGY_NEWGEN,
    numFOOD,
    numPOISON,
    GAMESPEED;

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
typedef struct life_form{
    int sight;// sight - chance that bacteria will eat this
    int moving;// direction
    int eating;// what it will eat: 1 - grass, 2 - grass + meat
    int energy;// if this parameter will equal 20 (number of eaten meal) then will created two childs with same statements
    int lifespan;// how much times it will lives: MAX = 99
    int pointX;
    int pointY;
}lifeform;
lifeform bacteria[M*N];//Bacterias
bool register_bacteria[M*N];// tells what bacterias are alive

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
void initialize_field();
void eat_food_poison_cond(int id);
void input_pos_bacteria_alive();
void input_pos_ENERGY_NEWGEN();
void input_pos_numFOOD();
void input_pos_numPOISON();
void input_pos_GAMESPEED();

int main(){

    std::cout << "Welcome to bacteria life simulation!"<< std::endl << std::endl;
    std::cout << "HOW MUCH BACTERIAS IN FIELD:(MAX " << M*N << " ONLY!)";
    input_pos_bacteria_alive();
    std::cout << "ENERGY FOR NEW GENERATION:";
    input_pos_ENERGY_NEWGEN();
    std::cout << "HOW MUCH FOOD IN FIELD:";
    input_pos_numFOOD();
    std::cout << "HOW MUCH POISON IN FIELD:";
    input_pos_numPOISON();
    std::cout << "GAMESPEED(in ms):";
    input_pos_GAMESPEED();

    sf::RenderWindow window(sf::VideoMode(M*size, N*size), "SFML LIFE");

    Texture t_white,t_red,t_green,t_blue, t_purple;
	t_white.loadFromFile("images/white.png");
	t_red.loadFromFile("images/red.png");
    t_green.loadFromFile("images/green.png");
    t_blue.loadFromFile("images/blue.png");
    t_purple.loadFromFile("images/purple.png");

	Sprite s_white(t_white);
	Sprite s_red(t_red);
	Sprite s_green(t_green);
	Sprite s_blue(t_blue);
	Sprite s_purple(t_purple);

	Clock clock;
    float timer = 0.0, delay = GAMESPEED/1000.0;

    for (int id = 0; id < bacteria_alive; id++)
        initialize_bacteria(id, M/2, N/2, 0, 1);
    initialize_field();

    while (window.isOpen() && bacteria_alive != 0){
        float time = clock.getElapsedTime().asSeconds();
		clock.restart();
        timer+=time;

        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        if (Keyboard::isKeyPressed(Keyboard::Escape))  return 0;
        if (timer > delay){
            timer = 0;
            for (int id = 0; id < M*N; id++)
                if (register_bacteria[id] == true){
                    move_bacteria(id);
                    mutation(id);
                }
        }

        window.clear();
        for (int i = 0; i < M; i++){
            for (int j = 0; j < N; j++){
                 if (field[i][j] == EMPTY){
                    s_white.setPosition(i*size, j*size);
                    window.draw(s_white);
                 }
                 if (field[i][j] == FOOD){
                    s_green.setPosition(i*size, j*size);
                    window.draw(s_green);
                 }
                 if (field[i][j] == POISON){
                    s_red.setPosition(i*size, j*size);
                    window.draw(s_red);
                 }
                 if (field[i][j] == BACTERIA){
                    s_blue.setPosition(i*size, j*size);
                    window.draw(s_blue);
                 }
                 if (field[i][j] == MEAT){
                    s_purple.setPosition(i*size, j*size);
                    window.draw(s_purple);
                 }
            }
        }
        window.display();
        std::cout << "Bacteria alive: " << bacteria_alive << std::endl;
    }

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
void initialize_field(){
    srand(time(0));
    for (int y = 0; y < N; y++){
        for (int x = 0; x < M; x++){
            field[x][y] = EMPTY;
        }
    }
    for (int i = 0; i < numPOISON; i++){
        int x = rand()%M;
        int y = rand()%N;
        field[x][y] = POISON;
    }
    for (int i = 0; i < numFOOD; i++){
        int x = rand()%M;
        int y = rand()%N;
        field[x][y] = FOOD;
    }
}
int random_moving(){
    int a = rand()%8;
    return a;
}
void inc_bacteria_x(int id){
    bacteria[id].pointX++;
    if (bacteria[id].pointX >= M)
        bacteria[id].pointX = 0;
}
void dec_bacteria_x(int id){
    bacteria[id].pointX--;
    if (bacteria[id].pointX < 0)
        bacteria[id].pointX = M - 1;
}
void inc_bacteria_y(int id){
    bacteria[id].pointY++;
    if (bacteria[id].pointY >= N)
        bacteria[id].pointY = 0;
}
void dec_bacteria_y(int id){
    bacteria[id].pointY--;
    if (bacteria[id].pointY < 0)
        bacteria[id].pointY = N - 1;
}
void move_bacteria(int id){
    field[bacteria[id].pointX][bacteria[id].pointY] = EMPTY;
    if (bacteria[id].sight > 0){
        if (bacteria[id].eating == 1){
            if(field[bacteria[id].pointX - 1][bacteria[id].pointY] == FOOD && bacteria[id].pointX - 1 >= 0){
                dec_bacteria_x(id);
                eat_food_poison_cond(id);
                return;
            }
            if(field[bacteria[id].pointX + 1][bacteria[id].pointY] == FOOD && bacteria[id].pointX + 1 < M){
                inc_bacteria_x(id);
                eat_food_poison_cond(id);
                return;
            }
            if(field[bacteria[id].pointX][bacteria[id].pointY - 1] == FOOD && bacteria[id].pointY - 1 >= 0){
                dec_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
            if(field[bacteria[id].pointX][bacteria[id].pointY + 1] == FOOD && bacteria[id].pointY + 1 < N){
                inc_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
            if(field[bacteria[id].pointX - 1][bacteria[id].pointY + 1] == FOOD && bacteria[id].pointX - 1 >= 0 && bacteria[id].pointY + 1 < N){
                dec_bacteria_x(id);
                inc_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
            if(field[bacteria[id].pointX + 1][bacteria[id].pointY + 1] == FOOD && bacteria[id].pointX + 1 < M && bacteria[id].pointY + 1 < N){
                inc_bacteria_x(id);
                inc_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
            if(field[bacteria[id].pointX - 1][bacteria[id].pointY - 1] == FOOD && bacteria[id].pointX - 1 >= 0 && bacteria[id].pointY - 1 >= 0){
                dec_bacteria_x(id);
                dec_bacteria_y(id);
                eat_food_poison_cond(id);
                return;
            }
            if(field[bacteria[id].pointX + 1][bacteria[id].pointY - 1] == FOOD && bacteria[id].pointX + 1 < M && bacteria[id].pointY - 1 >= 0){
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
void mutation(int id){
    int chance_of_mutation = rand()%100;
    if (chance_of_mutation < 6)
        bacteria[id].sight++;
    if (chance_of_mutation == 4){
        bacteria[id].sight--;
        if (bacteria[id].sight < 0) bacteria[id].sight = 0;
    }
}
int find_free_id(){
    for (int i = 0; i < M*N; i++)
        if (register_bacteria[i] == false)
            return i;
    return -1;
}
void eat_food_poison_cond(int id){
    int x,y;
    if (field[bacteria[id].pointX][bacteria[id].pointY] == FOOD){
        bacteria[id].energy++;
        do{
            x = rand()%M;
            y = rand()%N;
        }while(field[x][y] == BACTERIA);
        field[x][y] = FOOD;
    }
    if (field[bacteria[id].pointX][bacteria[id].pointY] == POISON)
        bacteria[id].lifespan = 1;
    bacteria[id].lifespan--;
    field[bacteria[id].pointX][bacteria[id].pointY] = BACTERIA;
    if (bacteria[id].lifespan == 0){
        field[bacteria[id].pointX][bacteria[id].pointY] = MEAT;
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
    std::cin >> bacteria_alive;
    if (bacteria_alive == 0)
        bacteria_alive = 1;
    if (bacteria_alive > M*N)
        bacteria_alive = M*N;
    if (bacteria_alive < 0)
        bacteria_alive = bacteria_alive * (-1);
}
void input_pos_ENERGY_NEWGEN(){
    std::cin >> ENERGY_NEWGEN;
    if (ENERGY_NEWGEN == 0)
        ENERGY_NEWGEN = 1;
    if (ENERGY_NEWGEN < 0)
        ENERGY_NEWGEN = ENERGY_NEWGEN * (-1);
}
void input_pos_numFOOD(){
    std::cin >> numFOOD;
    if (numFOOD < 0)
        numFOOD = numFOOD * (-1);
}
void input_pos_numPOISON(){
    std::cin >> numPOISON;
    if (numPOISON < 0)
        numPOISON = numPOISON * (-1);
}
void input_pos_GAMESPEED(){
    std::cin >> GAMESPEED;
    if (GAMESPEED < 0)
        GAMESPEED = GAMESPEED * (-1);
}
