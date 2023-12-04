#include <iostream>
#include <typeinfo>
using namespace std;
#include "modedejeu.h"



Modedejeu() 
{
    Touche Bleu(D2,D1,1500);
    Touche Rouge(D5,D3,1000);
    Touche Jaune(D4,D8,500);

    listetouche = NULL;

    listetouche.push_back(Bleu);
    listetouche.push_back(Rouge);
    listetouche.push_back(Jaune);

    sequence = NULL;
}

void InitModedejeu(int nbtour); 
{
    for (int i=0;i<nbtour;i++)
    {
        for (int j=0;j<listetouche.size();j++)
        {
            listetouche[i].play();
            delay(500);
        }
    }
}


