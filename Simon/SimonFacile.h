#ifndef SIMONFACILE_H_
#define SIMONFACILE_H_

#include <Arduino.h>
#include "Simon.h"
#include "Touche.h"
#include "TM1637.h"
#include <vector>

/**
  * @class SimonFacile
  * @brief Classe SimonFacile : mode de jeu Facile de notre Simon 
*/    
class SimonFacile : public Simon
{
  private :
    int Speed;
    int ScoreMax;

  public :
    /**
     * @fn SimonFacile();
     * @brief Constructeur mode facile
    */    
    SimonFacile();
    /**
     * @fn SimonFacile();
     * @brief Destructeur
    */    
    ~SimonFacile();    
        /**
     * @fn void Partie(void)
     * @brief Fonction de lancement de notre Simon en mode Facile
    */
    void Partie(void);
    /**
     * @fn Disco();
     * @brief Animation d'attente
    */    
    virtual void Disco(int nbTours, int Speed);
    /**
     * @fn GenerateSequence();
     * @brief Génère et joue la séquence de touches à retenir
    */    
    virtual void GenerateSequence(int Speed);
    /**
     * @fn FlushSequence();
     * @brief Supprime la séquence
    */    
    virtual void FlushSequence();
        /**
     * @fn WhichIsPress();
     * @brief Indique quelle touche vient d'être pressée
    */    
    virtual int WhichIsPress(int ErrorDelay);
    /**
     * @fn CheckSequence();
     * @brief Vérifie si la touche jouée est celle de la séquence à retenir
    */    
    virtual bool CheckSequence(int ErrorDelay);
};
#endif