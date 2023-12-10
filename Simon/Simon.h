#ifndef SIMON_H_
#define SIMON_H_

#include <Arduino.h>
#include "Touche.h"
#include "TM1637.h"
#include <vector>

/**
  * @class Simon
  * @brief Classe Simon 
*/    
class Simon
{
  protected :
    std::vector<Touche> Sequence;
    std::vector<Touche> ListeTouche;
    int ScoreMaxFacile;
    int ScoreMaxModere;
    int ScoreMaxExpert;

  public :
    /**
     * @fn Simon();
     * @brief Constructeur par defaut
    */    
    Simon();
    /**
     * @fn Simon();
     * @brief Destructeur
    */    
    ~Simon();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de notre Simon
    */
    void init(void);
    /**
     * @fn void Facile(void)
     * @brief Fonction de lancement de notre Simon en mode Facile
    */
    void Facile(int nbTours, int Speed, int ErrorDelay);
    /**
     * @fn void Modere(void)
     * @brief Fonction de lancement de notre Simon en mode Modéré
    */
    void Modere(int nbTours, int Speed, int ErrorDelay);
    /**
     * @fn void Expert(void)
     * @brief Fonction de lancement de notre Simon en mode Expert sans lumière
    */
    void Expert(int nbTours, int Speed, int ErrorDelay);
     /**
     * @fn void run(void)
     * @brief Fonction de lancement de notre Simon
    */
    void run(void);
    /**
     * @fn Disco();
     * @brief Animation d'attente
    */    
    void Disco(int nbTours, int Speed);
    /**
     * @fn GenerateSequence();
     * @brief Génère et joue la séquence de touches à retenir
    */    
    void GenerateSequence(int Speed, int Expert);
    /**
     * @fn FlushSequence();
     * @brief Supprime la séquence
    */    
    void FlushSequence();
    /**
     * @fn WhichIsPress();
     * @brief Indique quelle touche vient d'être pressée
    */    
    int WhichIsPress(int ErrorDelay);
    /**
     * @fn CheckSequence();
     * @brief Vérifie si la touche jouée est celle de la séquence à retenir
    */    
    bool CheckSequence(int ErrorDelay);
};
#endif