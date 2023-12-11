#include "SimonModerate.h"
#include <Arduino.h>

void SimonModerate::play(int nbTours, int Speed, int ErrorDelay){
  int Test = 1;
    Segment.displayStr("LVL2");
    Disco(nbTours, 0.5*Speed);
    delay(1000);

    while(Test)
    {
        GenerateSequence(Speed,0);
        Test = CheckSequence(ErrorDelay);
        if (Test == 1)
        {
          Segment.displayNum(this->ScoreMaxModere+Sequence.size());
        }
        delay(1000);
    }
    if (this->ScoreMaxModere < 100*(Sequence.size()-1))
    {
      this->ScoreMaxModere = 100*(Sequence.size()-1);
    }
    FlushSequence();
} 