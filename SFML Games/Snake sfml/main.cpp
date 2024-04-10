#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

const int M = 40, N = 40;
const int size = 16;//size of blocks in pixels
const int w = size * M;
const int h = size * N;

int dir, num = 1;//dir - direction, num - size of snake
int score = 0;

struct Block {int x, y;} s[M * N],f;

void randomize_f_pos(){
    f.x = rand() % M;
    f.y = rand() % N;
}

void Tick(){
    // move snake parts
    for (int i = num; i > 0; --i){
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    // move head
    if (dir == 0) s[0].y+=1;
    if (dir == 1) s[0].x-=1;
    if (dir == 2) s[0].x+=1;
    if (dir == 3) s[0].y-=1;

    // if eat food
	if (s[0].x == f.x && s[0].y == f.y)
    {   num++;
        randomize_f_pos();
        score++;
    }

    // if you go thought the wall
    if (s[0].x >= M) s[0].x = 0;  if (s[0].x < 0) s[0].x = M - 1;
    if (s[0].y >= N) s[0].y = 0;  if (s[0].y < 0) s[0].y = N - 1;

    // if you eat yourself
    for (int i = 1; i < num; i++)
        if (s[0].x == s[i].x && s[0].y == s[i].y)
            exit(0);

 }

int main()
{
	srand(time(0));

    RenderWindow window(VideoMode(w, h), "Snake Game!");

	Texture t1,t2,t3;
	t1.loadFromFile("images/white.png");
	t2.loadFromFile("images/red.png");
    t3.loadFromFile("images/green.png");

	Sprite sprite1(t1);
	Sprite sprite2(t2);
	Sprite sprite3(t3);

	Clock clock;
    float timer = 0.0, delay = 0.2;

	f.x = M / 2;
    f.y = N / 2;

    while ( window.isOpen() ){
		float time = clock.getElapsedTime().asSeconds();
		clock.restart();
        timer+=time;

        Event e;
        while (window.pollEvent(e)){
            if (e.type == Event::Closed)
                window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Left))    dir = 1;
		if (Keyboard::isKeyPressed(Keyboard::A))    dir = 1;
	    if (Keyboard::isKeyPressed(Keyboard::Right))   dir = 2;
	    if (Keyboard::isKeyPressed(Keyboard::D))   dir = 2;
	    if (Keyboard::isKeyPressed(Keyboard::Up))      dir = 3;
	    if (Keyboard::isKeyPressed(Keyboard::W))      dir = 3;
		if (Keyboard::isKeyPressed(Keyboard::Down))    dir = 0;
		if (Keyboard::isKeyPressed(Keyboard::S))    dir = 0;
		if (Keyboard::isKeyPressed(Keyboard::E))       delay = delay + 0.001;
        if (Keyboard::isKeyPressed(Keyboard::Q))       delay = delay - 0.001;
        if (Keyboard::isKeyPressed(Keyboard::Escape))  return 0;


		if (timer > delay){
            timer = 0;
            Tick();
        }

       ////// draw  ///////
        window.clear();

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                {sprite1.setPosition(i*size, j*size);  window.draw(sprite1); }

        for (int i = 0; i < num; i++)
            {sprite2.setPosition(s[i].x*size, s[i].y*size);  window.draw(sprite2); }

        sprite3.setPosition(f.x*size, f.y*size);  window.draw(sprite3);

        window.display();
	}

    return 0;
}
/*
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
*/
