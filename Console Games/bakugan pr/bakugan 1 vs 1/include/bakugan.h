#ifndef BAKUGAN_H
#define BAKUGAN_H

#include <iostream>

#include "Acard.h"
#include "Gcard.h"

class bakugan
{
    public:
        bakugan();
        virtual ~bakugan();

        //GET
        int getElement(){ return element;}
        int getGpower() { return Gpower; }
        int getID() {return id; }

        //SET
        void setElement(int element){this->element = element;}
        void setGpower(int Gpower){this->Gpower = Gpower;}
        void setID (int id){this->id = id;}

        //ABILITY CARDS

        //GATE CARDS

        //DEBUG
        void debugStatOutput(){
            std::cout << "Element :" << element << std::endl;
            std::cout << "G power: " << Gpower << std::endl;
            std::cout << "ID: " << id << std::endl;
        }


    private:
        int element;
        int Gpower;
        int id;
        std::string name;

        Acard Acard[6];
        Gcard Gcard[6];
};

#endif // BAKUGAN_H
