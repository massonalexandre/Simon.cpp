/*********************************************************************
 * @file  Touche.cpp
 * @author MASSON Alexandre, MICHEL Hugo
 * @brief Classe Touche de notre Simon
 *********************************************************************/

#include <Arduino.h>
#include "Touche.h"

Touche::Touche(int PinButton, int PinLed, int FreqSong)
{
    Button = PinButton;
    Led = PinLed;
    Song = FreqSong;

    pinMode(Led, OUTPUT);
    pinMode(Button, INPUT);
   
}

void Touche::play() const
{
    digitalWrite(Led, HIGH);
    tone(Buzzer, Song);
    delay(250);
    digitalWrite(Led, LOW);
    noTone(Buzzer);
}

void Touche::playSong() const
{
    tone(Buzzer, Song);
    delay(250);
    noTone(Buzzer);
}

void Touche::light()
{
    digitalWrite(Led, HIGH);
    delay(250);
    digitalWrite(Led, LOW);
}

bool Touche::press()
{
    return (digitalRead(Button) == LOW);
}

bool Touche::operator==(const Touche& AutreTouche) const
{
    return (this->Button == AutreTouche.Button) && (this->Led == AutreTouche.Led);
}
