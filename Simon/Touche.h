#ifndef TOUCHE_H_
#define TOUCHE_H_

#include <vector>
#include <Arduino.h>

/**
  * @class Touche
  * @brief Classe Touche 
*/    
class Touche
{
    private :
    
    int Button; 
    int Led; 
    int Song;
    int Buzzer;

    public:
    /**
     * @fn Touche();
     * @brief Constructeur
    */  
    Touche (int PinButton, int PinLed, int FreqSong);
    /**
     * @fn play();
     * @brief  Joue la lumière et le son de la touche
    */  
    void playSong() const;
    /**
     * @fn play();
     * @brief  Joue le son de la touche
    */  
    void play() const;
     /**
     * @fn light();
     * @brief Joue la lumière de la touche
    */  
    void light();
     /**
     * @fn press();
     * @brief Indique si la touche est pressé
    */  
    bool press();

    bool operator==(const Touche& AutreTouche) const;
};

#endif