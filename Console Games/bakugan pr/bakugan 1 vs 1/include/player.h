#ifndef PLAYER_H
#define PLAYER_H

#include "bakugan.h"
#include <iostream>


class player
{
    public:
        player();
        virtual ~player();

        void setName(int name){this->name = name;}

        void debugStatOutput(){
            std::cout << "Team :" << team << std::endl;
            std::cout << "Name: " << name << std::endl;
            std::cout << "Player is alive: " << on_the_battle << std::endl << std::endl;

            std::cout << "Bakugan 1: " << std::endl;
            bakugan[0].debugStatOutput();
            std::cout << "Bakugan is alive: " << alive_bakugan[0] << std::endl << std::endl;

            std::cout << "Bakugan 2: " << std::endl;
            bakugan[1].debugStatOutput();
            std::cout << "Bakugan is alive: " << alive_bakugan[1] << std::endl << std::endl;

            std::cout << "Bakugan 3: " << std::endl;
            bakugan[2].debugStatOutput();
            std::cout << "Bakugan is alive: " << alive_bakugan[2] << std::endl << std::endl;

        }

    private:
        int team;
        std::string name;
        bakugan bakugan[3];
        bool alive_bakugan[3];
        bool on_the_battle;
};

#endif // PLAYER_H
