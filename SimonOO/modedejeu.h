#ifndef MODEDEJEU_H_
#define MODEDEJEU_H_

#include <Arduino.h>
using namespace std;
#include "touche.h"

class Modedejeu
{
    private :

    std::vector<Touche> listetouche; //touches
    std::vector<Touche> sequence; //listetouches

    public :

    Modedejeu();
    void InitModedejeu(int nbtour); //disco
    virtual void GenererSuiteSequence(vector<Touche> sequence); //generersequence
    virtual void CheckReponseJoueur(const vector<Touche>& sequence); //verifiersequence
};

#endif