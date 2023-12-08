/*********************************************************************
 * @file  SimonFacile.cpp
 * @author MASSON Alexandre, MICHEL Hugo
 * @brief Fichier source de notre Simon, mode jeu Facile
 *********************************************************************/

#include "SimonFacile.h"
#include <Arduino.h>


SimonFacile::SimonFacile() : Simon()
{
  this->Speed = 500;
  this->ScoreMax = 0;
}
  
SimonFacile::~SimonFacile()
{
  // Code
  ;
}  

void SimonFacile::Partie(void)
{
    TM1637 Segment(D6,D7);
    Segment.init();
    Segment.set(BRIGHT_TYPICAL);

    int Test = 1;

    Disco(3, 200);
    delay(1000);

    while(Test)
    {
        GenerateSequence(Speed);
        Test = CheckSequence(2000);
        if (Test == 1)
        {
          Segment.displayNum(Sequence.size());
        }
        delay(2000);
    }
    FlushSequence();
}

void SimonFacile::Disco(int nbTours, int Speed)
{
    for (int i=0;i<nbTours;i++)
    {
        for (int j=0;j<ListeTouche.size();j++)
        {
            ListeTouche[j].light();
            delay(Speed);
        }
    }
}

void SimonFacile::GenerateSequence(int Speed)
{
    int RandomIndex = random(0, ListeTouche.size());
    Sequence.push_back(ListeTouche[RandomIndex]);

    for (int i=0;i<Sequence.size();i++)
    {
        Sequence[i].play();
        delay(Speed);
    }
}

void SimonFacile::FlushSequence()
{
    while (Sequence.size() != 0)
    {
        Sequence.pop_back();
    }
}

int Simon::WhichIsPress(int ErrorDelay) 
{
  return Simon::WhichIsPress(ErrorDelay);
}

bool SimonFacile::CheckSequence(int ErrorDelay)
{
    for (int i=0;i<Sequence.size();i++)
    {
        int Played = WhichIsPress(ErrorDelay);
        if (Played != -1 && ListeTouche[Played] == Sequence[i])
        {
            Sequence[i].play();
        }
        else
        {
            tone(D9, 200);
            delay(2000);
            noTone(D9);

            delay(250);
            Sequence[i].play();
            delay(250);
            Sequence[i].play();
            delay(250);
            Sequence[i].play();

            return false;
        }
    }

    return true;
}