#ifndef SIMON_H_
#define SIMON_H_

#include <Arduino.h>
#include "Touche.h"
class SimonFacile;
class SimonModerate;
class SimonExpert;
#include "TM1637.h"
#include <vector>

class Simon {
  protected:
    std::vector<Touche> Sequence;
    std::vector<Touche> ListeTouche;
    int ScoreMaxFacile;
    int ScoreMaxModere;
    int ScoreMaxExpert;

  public:
    Simon();
    virtual ~Simon();

    void init();
    void run();
    virtual void play(int nbTours, int Speed, int ErrorDelay ) =0;
    void Disco(int nbTours, int Speed);
    void GenerateSequence(int Speed, int Expert);
    void FlushSequence();
    int WhichIsPress(int ErrorDelay);
    bool CheckSequence(int ErrorDelay);
};

#endif