#include <iostream>
#include <typeinfo>
using namespace std;
#include "modedejeuclassique.h"
#include "touche.h"

Modedejeuclassique::Modedejeuclassique() : Modedejeu()
{
    speed = 500;
}

virtual void GenererSuiteSequence(vector<Touche> sequence)
{
    int randomindex = random(0,listetouche.size());
    sequence.push_back(listetouche[randomindex]);

    for (int i=0;i<sequence.size();i++)
    {
        sequence[i].play();cd
        delay(speed);
    }
}

virtual void CheckReponseJoueur(vector<Touche> sequence);
{
    int cmp = 0;
    while (cmp != sequence.size())
    {
        for (int i=0;i<listetouche.size();i++)
        {
            if (listetouche[i].press)
            {
                if listetouche[i] != sequence[cmp] throw MonException();
            }
            else
            {
                sequence[cmp].play();
                cmp++;
            }
        }
    }
}