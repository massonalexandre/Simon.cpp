#include "SimonCOO.h"
class SimonFacile;
class SimonModerate;
class SimonExpert;


SimonFacile simonF;
SimonModerate simonM;
SimonExpert simonE;


void setup() 
{
  simonF.init();
}

void loop() 
{
  simonF.run();
}