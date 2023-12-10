#ifndef SIMONF_H_
#define SIMONF_H_

#include <Arduino.h>
#include "SimonCoo.h"

class SimonFacile : public Simon {

  public:
    void play(int nbTours, int Speed, int ErrorDelay) override;
};

#endif