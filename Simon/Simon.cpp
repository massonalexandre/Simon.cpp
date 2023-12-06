/*********************************************************************
 * @file  Simon.cpp
 * @author MASSON Alexandre, MICHEL Hugo
 * @brief Fichier source de notre Simon
 *********************************************************************/

#include "Simon.h"
#include "TM1637.h"
#include <Arduino.h>
#include "Touche.h"


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
}


void Simon::run(void)
{
    TM1637 Segment(D6,D7);
    Segment.init();
    Segment.set(BRIGHT_TYPICAL);

    int Test = 1;

    Disco(2, 200);
    delay(1000);

    while(Test)
    {
        GenerateSequence(500);
        Test = CheckSequence(1000);
        Segment.displayNum(Sequence.size());
        delay(2000);
    }
    FlushSequence();
}

void Simon::Disco(int nbTours, int Speed)
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

void Simon::GenerateSequence(int Speed)
{
    int RandomIndex = random(0, ListeTouche.size());
    Sequence.push_back(ListeTouche[RandomIndex]);

    for (int i=0;i<Sequence.size();i++)
    {
        Sequence[i].play();
        delay(Speed);
    }
}

void Simon::FlushSequence()
{
    for (int i=0;i<Sequence.size();i++)
    {
        Sequence.pop_back();
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

bool Simon::CheckSequence(int ErrorDelay)
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