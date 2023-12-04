#include <Arduino.h>
using namespace std;
#include "touche.h"

Touche (int pinbutton, int pinled, int freqsong)
{
    buzzer = D6;
    button = pinbutton;
    led = pinled;
    song = freqsong;

    pinMode(led, OUTPUT);
    pinMode(button, INPUT);
    pinMode(buzzer, OUTPUT);
}

void play() const
{
    digitalWrite(led, HIGH);
    tone(buzzer, song);
    delay(250);
    digitalWrite(led, LOW);
    noTone(buzzer);
}

void light()
{
    digitalWrite(led, HIGH);
    delay(250);
    degitalWrite(led, LOW);
}

bool press()
{
    return (digitalRead(button) == LOW)
}

bool operator == (const Touche& autretouche) const
{
    return (button == autretouche.button) && (led == autretouche.led);
}