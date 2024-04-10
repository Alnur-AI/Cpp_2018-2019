#include <SFML/Graphics.hpp>

typedef struct Block{
    int dir;/// 1 - up, 2 - up + right, 3 - right, 4 - right + down, 5 - down, 6 - down + left, 7 - left, 8 - left + up
    int speed;/// 'speed' blocks per second
    int x;
    int y;
}block;

const int X = 160, Y = 120;
int gravity = 5;/// 1 - up, 2 - up + right, 3 - right, 4 - right + down, 5 - down, 6 - down + left, 7 - left, 8 - left + up
const int num_block = 500;
block b[num_block];

void block_random_place();
void block_collision (block b_feel, block b_do);
void block_fall(int i);
void block_move(int i, int dir);

int main(){
    block_random_place();

    sf::RenderWindow window(sf::VideoMode(X, Y), "SFML works!");

    sf::Texture t_block, t_empty;
    t_block.loadFromFile("images/block.png");
    t_empty.loadFromFile("images/empty.png");


    sf::Sprite s_block, s_empty;
    s_block.setTexture(t_block);
    s_block.setTexture(t_block);


    while (window.isOpen())
    {
        for (int i = 0; i < num_block; i++){
            block_fall(i);
        }
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (int y = 0; y < Y; y++){
            for (int x = 0; x < X; x++){
                for (int i = 0; i < num_block; i++)
                    if (b[i].x == x && b[i].y == y){
                        s_block.setPosition(x, y);
                        window.draw(s_block);
                    }
            }
        }
        window.display();
    }

    return 0;
}

void block_fall(int i){
    if (b[i].y >= Y - 1) return;
    b[i].y++;
}

void block_random_place(){
    for (int i = 0; i < num_block; i++){
        b[i].x = rand() % X;
        b[i].y = rand() % Y;
    }
}
