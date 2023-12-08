/*********************************************************************
 * @file  Simon.cpp
 * @author MASSON Alexandre, MICHEL Hugo
 * @brief Fichier source de notre Simon
 *********************************************************************/

#include <Arduino.h>
#include "SimonFacile.h"
#include "Simon.h"


Simon::Simon()
{
  // Code
  ; 
}
  
Simon::~Simon()
{
  // Code
  ;
}  

void Simon::init(void)
{
    Touche Bleu(D2,D1,1500 );
    Touche Rouge(D5,D3,1000);
    Touche Jaune(D4,D8,500);
    
    ListeTouche.push_back(Bleu);
    ListeTouche.push_back(Rouge);
    ListeTouche.push_back(Jaune);

    SimonFacile JeuBleuFacile;
    SimonFacile JeuRougeFacile;
    SimonFacile JeuJauneFacile;

    ListeMode.push_back(JeuBleuFacile);
}

void Simon::run(void)
{
    int Chosen = -1;
  
    Chosen = WhichIsPress(20000);

    if (Chosen == 0)
    {
      //JeuBleuFacile.Partie();
    }
}

int Simon::WhichIsPress(int ErrorDelay) 
{
    unsigned long StartTime = millis();

    while (millis()-StartTime < ErrorDelay)
    {
        for (int i=0;i<ListeTouche.size();i++)
        {
            if (ListeTouche[i].press())
            {
                return i;
            }
        }
    }

    return -1;
}





