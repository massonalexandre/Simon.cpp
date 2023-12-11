#include "SimonCoo.h"

int Buzzer;
TM1637 Segment(D6, D7);
SimonFacile simonF;
SimonModerate simonM;
SimonExpert simonE;

Simon::Simon() {
  ScoreMaxFacile = 0;
  ScoreMaxModere = 0;
  ScoreMaxExpert = 0;
}

Simon::~Simon() {}
void Simon::init(void)
{

    Touche Bleu(D2,D1,1500 );
    Touche Rouge(D5,D3,1000);
    Touche Jaune(D4,D8,500);
    Buzzer=D9;
    pinMode(Buzzer, OUTPUT);

    ListeTouche.push_back(Bleu);
    ListeTouche.push_back(Rouge);
    ListeTouche.push_back(Jaune);

    Segment.init();
    Segment.set(BRIGHT_TYPICAL);
    Segment.displayStr("LeveL B1-R2-Y3", 500);

}

void Simon::run(){
    Segment.displayStr("PLAY");  
      switch (WhichIsPress(3000))
      {
        case 0:
          simonF.play(1,1000,3000);
          break;
        case 1:
          simonM.play(2,200,1000);
          break;
        case 2:
          simonE.play(3,200,2000);
          break;
        default:
          break;
      }
}

void Simon::Disco(int nbTours, int Speed) {
     for (int i=0;i<nbTours;i++)
    {
        for (int j=0;j<ListeTouche.size();j++)
        {
            ListeTouche[j].light();
            delay(Speed);
        }
    }
}


void Simon::GenerateSequence(int Speed, int Expert) {
      int RandomIndex = random(0, ListeTouche.size());
    Sequence.push_back(ListeTouche[RandomIndex]);

    for (int i=0;i<Sequence.size();i++)
    {
      if (Expert == 0)
      {
        Sequence[i].play();
      }
      else
      {
        Sequence[i].playSong();
      }
        delay(Speed);
    }
}

void Simon::FlushSequence() {
    while (Sequence.size() != 0)
  {
      Sequence.pop_back();
  }
}

int Simon::WhichIsPress(int ErrorDelay) {
    unsigned long StartTime = millis();
    int n=0;
    while(n<2){
    while (millis()-StartTime < (ErrorDelay/2)) //statégie pour retarder la sortie de boucle 
    {
        for (int i=0;i<ListeTouche.size();i++)
        {
            if (ListeTouche[i].press())
            {
                return i;
            }
        }
    }
    n+=1;
    }

    return -1;
}

bool Simon::CheckSequence(int ErrorDelay) {
  for (int i=0;i<Sequence.size();i++)
    {
        int Played = WhichIsPress(ErrorDelay);
        if (Played != -1 && ListeTouche[Played] == Sequence[i])
        {
            Sequence[i].play();
        }
        else
        {
            tone(Buzzer, 200);
            delay(2000);
            noTone(Buzzer);

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