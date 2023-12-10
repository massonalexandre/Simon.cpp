#include "SimonExpert.h"
#include <Arduino.h>

void SimonExpert::play(int nbTours, int Speed, int ErrorDelay){
  int Test = 1;
  Segment.displayStr("LVL3");

    Disco(nbTours, 0.5*Speed);
    delay(500);

    for (int i=0;i<ListeTouche.size();i++) //sequance d'ecoute pour pouvoir reconnaitre les touches
    {
      ListeTouche[i].play();
      delay(500);
    }

    delay(500);
  
    while(Test)
    {
        GenerateSequence(Speed,1);
        Test = CheckSequence(ErrorDelay);
        if (Test == 1)
        {
          Segment.displayNum(this->ScoreMaxExpert+Sequence.size());
        }
        delay(1000);
    }

    if (this->ScoreMaxExpert < 100*(Sequence.size()-1))
    {
      this->ScoreMaxExpert = 100*(Sequence.size()-1);
    }
    FlushSequence();
} 