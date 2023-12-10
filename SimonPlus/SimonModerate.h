#ifndef SIMONM_H_
#define SIMONM_H_

#include <Arduino.h>
#include "SimonCoo.h"

class SimonModerate : public Simon {
  public:
    void play(int nbTours, int Speed, int ErrorDelay) override;
};

#endif