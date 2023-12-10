#include "SimonFacile.h"
#include "SimonCoo.h"
#include <Arduino.h>


void SimonFacile::play(int nbTours, int Speed, int ErrorDelay){
  int Test = 1;
    Segment.displayStr("LVL1");
    Disco(nbTours, 0.5*Speed);
    delay(1000);

    while(Test)
    {
        GenerateSequence(Speed,0);
        Test = CheckSequence(ErrorDelay);
        if (Test == 1)
        {
          Segment.displayNum(this->ScoreMaxFacile+Sequence.size());
        }
        delay(1000);
    }
    if (this->ScoreMaxFacile < 100*(Sequence.size()-1))
    {
      this->ScoreMaxFacile = 100*(Sequence.size()-1);
    }
    FlushSequence();
} 