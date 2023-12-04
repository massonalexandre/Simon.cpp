#ifndef MODEDEJEUCLASSIQUE_H_
#define MODEDEJEUCLASSIQUE_H_


#include <iostream>
#include <typeinfo>
using namespace std;
#include "modedejeu.h"

class Modedejeuclassique : public Modedejeu
{
    private:

    int speed; //vitesse

    public:

    Modedejeuclassique();
    virtual void GenererSuiteSequence(vector<Touche> sequence)
    virtual void CheckReponseJoueur(vector<Touche> sequence);
};

#endif