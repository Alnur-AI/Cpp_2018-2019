#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

const int X = 50, Y = 40, size = 16;
const int coeff = 5;//from 1% to 70%
bool field_reg[X][Y];//false - close, true - open
bool field_flag[X][Y];//false - no flag, true - have a flag;
int field[X][Y];//-1 - bomb; 1,2,3,...,8 - num of bombs around; 9 - flag; 10 - pressed button
const int BOMB = -1, FLAG = 9, PRESSED = 10;

void clean_field_and_field_reg();
void initfield_place_mines ();
void initfield_place_numbers ();
bool bool_inc (bool a);

int main(){
    srand(time(0));
	RenderWindow window(sf::VideoMode(X*size, Y*size), "SAPER"); //увеличили для удобства размер окна

	Texture t_empty, t_flag, t_zero, t_one, t_two, t_three, t_four, t_five, t_six, t_seven, t_eight, t_bomb;//создаем объект Texture (текстура)
	t_empty.loadFromFile("images/empty.png");
	t_flag.loadFromFile("images/flag.png");
	t_zero.loadFromFile("images/zero.png");
	t_one.loadFromFile("images/one.png");
	t_two.loadFromFile("images/two.png");
	t_three.loadFromFile("images/three.png");
	t_four.loadFromFile("images/four.png");
	t_five.loadFromFile("images/five.png");
	t_six.loadFromFile("images/six.png");
	t_seven.loadFromFile("images/seven.png");
	t_eight.loadFromFile("images/eight.png");
	t_bomb.loadFromFile("images/bomb.png");


    Sprite s_empty, s_flag, s_zero, s_one, s_two, s_three, s_four, s_five, s_six, s_seven, s_eight, s_bomb;
    s_empty.setTexture(t_empty);
    s_flag.setTexture(t_flag);
    s_zero.setTexture(t_zero);
    s_one.setTexture(t_one);
    s_two.setTexture(t_two);
    s_three.setTexture(t_three);
    s_four.setTexture(t_four);
    s_five.setTexture(t_five);
    s_six.setTexture(t_six);
    s_seven.setTexture(t_seven);
    s_eight.setTexture(t_eight);
    s_bomb.setTexture(t_bomb);

    clean_field_and_field_reg();
    initfield_place_mines();
    initfield_place_numbers();

    int mouseX, mouseY;

	while (window.isOpen())
	{
        mouseX = sf::Mouse::getPosition(window).x;
        mouseY = sf::Mouse::getPosition(window).y;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && field[mouseX / size][mouseY / size] == BOMB &&
        X*size > mouseX && mouseX >= 0 &&
        Y*size > mouseY && mouseY >= 0)
        {
            field_reg [mouseX / size][mouseY / size] = true;
            return 0;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && field[mouseX / size][mouseY / size] != BOMB && field[mouseX / size][mouseY / size] != 0 &&
        X*size > mouseX && mouseX >= 0 &&
        Y*size > mouseY && mouseY >= 0)
        {
            field_reg [mouseX / size][mouseY / size] = true;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && field[mouseX / size][mouseY / size] == 0 && field_reg[mouseX / size][mouseY / size] == false &&
        X*size > mouseX && mouseX >= 0 &&
        Y*size > mouseY && mouseY >= 0)
        {
            field_reg [mouseX / size][mouseY / size] = true;
            for (int i = (-1)*X/2; i <= X/2; i++){
                for (int j = (-1)*Y/2; j <= Y/2; j++){
                    if (field[mouseX / size + i][mouseY / size + j] == 0 && i*i + j*j <= X*X &&
                    X > mouseX / size + i && mouseX / size + i >= 0 &&
                    Y > mouseY / size + j && mouseY / size + j >= 0)
                    {
                        field_reg [mouseX / size + i][mouseY / size + j] = true;;
                    }
                }
            }

        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Right) &&
        X*size >= mouseX && mouseX >= 0 &&
        Y*size >= mouseY && mouseY >= 0)
        {
            field_flag [mouseX / size][mouseY / size] = bool_inc(field_flag [mouseX / size][mouseY / size]);
        }

		window.clear();
        for (int y = 0; y < Y; y++){
            for (int x = 0; x < X; x++){
                if (field_flag[x][y] == true){
                    s_flag.setPosition(x*size, y*size);
                    window.draw(s_flag);
                    continue;
                }
                if (field_reg[x][y] == false){
                    s_empty.setPosition(x*size, y*size);
                    window.draw(s_empty);
                    continue;
                }
                if (field[x][y] == BOMB){
                    s_bomb.setPosition(x*size, y*size);
                    window.draw(s_bomb);
                    continue;
                }
                if (field[x][y] == FLAG){
                    s_flag.setPosition(x*size, y*size);
                    window.draw(s_flag);
                    continue;
                }
                if (field[x][y] == 0){
                    s_zero.setPosition(x*size, y*size);
                    window.draw(s_zero);
                    continue;
                }
                if (field[x][y] == 1){
                    s_one.setPosition(x*size, y*size);
                    window.draw(s_one);
                    continue;
                }
                if (field[x][y] == 2){
                    s_two.setPosition(x*size, y*size);
                    window.draw(s_two);
                    continue;
                }
                if (field[x][y] == 3){
                    s_three.setPosition(x*size, y*size);
                    window.draw(s_three);
                    continue;
                }
                if (field[x][y] == 4){
                    s_four.setPosition(x*size, y*size);
                    window.draw(s_four);
                    continue;
                }
                if (field[x][y] == 5){
                    s_five.setPosition(x*size, y*size);
                    window.draw(s_five);
                    continue;
                }
                if (field[x][y] == 6){
                    s_six.setPosition(x*size, y*size);
                    window.draw(s_six);
                    continue;
                }
                if (field[x][y] == 7){
                    s_seven.setPosition(x*size, y*size);
                    window.draw(s_seven);
                    continue;
                }
                if (field[x][y] == 8){
                    s_eight.setPosition(x*size, y*size);
                    window.draw(s_eight);
                    continue;
                }
            }
        }
		window.display();
	}

	return 0;
}
void clean_field_and_field_reg(){
    for (int y = 0; y  < Y; y++)
        for (int x = 0; x < X; x++){
            field[x][y] = 0;
            field_reg[x][y] = false;
        }
}
void initfield_place_mines(){
    int left_mines = X * Y * coeff / 100;
    int randX, randY;
    do{
        randX = rand() % X;
        randY = rand() % Y;
        if (field[randX][randY] != BOMB){
            field[randX][randY] = BOMB;
            left_mines--;
        }
    }while(left_mines > 0);
}
void initfield_place_numbers (){
    int mines_val;
    for (int y = 0; y < Y; y++){
        for (int x = 0; x < X; x++){
            if (field[x][y] == BOMB) continue;
            mines_val = 0;
            if (field[x - 1][y] == BOMB && (0 <= (x - 1) && (x - 1) < X)) mines_val++;
            if (field[x + 1][y] == BOMB && (0 <= (x + 1) && (x + 1) < X)) mines_val++;
            if (field[x][y + 1] == BOMB && (0 <= (y + 1) && (y + 1) < Y)) mines_val++;
            if (field[x][y - 1] == BOMB && (0 <= (y - 1) && (y - 1) < Y)) mines_val++;
            if (field[x - 1][y - 1] == BOMB && (0 <= (x - 1) && (x - 1) < X) && (0 <= (y - 1) && (y - 1) < Y)) mines_val++;
            if (field[x - 1][y + 1] == BOMB && (0 <= (x - 1) && (x - 1) < X) && (0 <= (y + 1) && (y + 1) < Y)) mines_val++;
            if (field[x + 1][y - 1] == BOMB && (0 <= (x + 1) && (x + 1) < X) && (0 <= (y - 1) && (y - 1) < Y)) mines_val++;
            if (field[x + 1][y + 1] == BOMB && (0 <= (x + 1) && (x + 1) < X) && (0 <= (y + 1) && (y + 1) < Y)) mines_val++;
            field[x][y] = mines_val;
        }
    }
}
bool bool_inc (bool a){
    if (a == false) a = true;
    if (a == true) a = false;
}
