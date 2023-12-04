#ifndef TOUCHE_H_
#define TOUCHE_H_

#include <iostream>
#include <typeinfo>
using namespace std;

class Touche
{
    private :
    
    int button; //bouton
    int led; 
    int song;
    int buzzer;

    public:

    Touche (int pinbutton, int pinled, int freqsong);

    void play() const;
    void light();
    bool press(); //appuie

    bool operator == (const Touche& autretouche) const;
};

#endif