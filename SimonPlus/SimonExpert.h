#ifndef SIMONE_H_
#define SIMONE_H_

#include <Arduino.h>
#include "SimonCoo.h"

class SimonExpert : public Simon {
  public:
    void play(int nbTours, int Speed, int ErrorDelay) override;
};

#endif