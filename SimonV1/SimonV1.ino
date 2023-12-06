#include <vector> 
#include "TM1637.h"

class Touche {
  private : 
  int Bouton;
  int Led;
  int Song;
  int Buzzer = D9;




  public: 

  Touche(int PinBouton, int PinLed, int FreqSong){
    Bouton = PinBouton;
    Led = PinLed;
    Song = FreqSong;
    

    pinMode(Led, OUTPUT);
    pinMode(Bouton, INPUT);
    pinMode(Buzzer, OUTPUT);
    
  }

  void play() const {
    digitalWrite(Led, HIGH);
    tone(Buzzer, Song);
    delay(250);
    digitalWrite(Led, LOW);
    noTone(Buzzer);
  }

  void light() {
    digitalWrite(Led, HIGH);
    delay(250);
    digitalWrite(Led, LOW);
  }

  bool appuie (){
    return (digitalRead(Bouton)==LOW);
  }

    // Surcharge de l'opérateur == pour comparer des Touches du vecteur et du tableaux ;)
  bool operator==(const Touche& autreTouche) const {
    return (Bouton == autreTouche.Bouton) && (Led == autreTouche.Led);
  }

};


//Instance de Touches :
Touche Bleu(D2,D1,1500 );
Touche Rouge(D5,D3,1000);
Touche Jaune(D4,D8,500);

void disco( Touche* touches, int vitesse, int nbTours){
  for (int j = 0; j < nbTours ; j++) {
  for (int i = 0; i < (sizeof(touches)-1); i++) {
  touches[i].light();
  delay(vitesse);
  }
}
}

Touche touches[] = {
  Bleu,Rouge,Jaune // on peu directement ajouter les instances de touche ici mais pas les nommer 
};

int ToucheAppuie(Touche* touches,int attente) {  // pb ici !!!
  unsigned long startMillis = millis(); // Temps de démarrage
  

  while ((millis() - startMillis) < attente ) { // si le temps d'attente est supperieur à 1s la fonction verifier reponse n'attends pas le retour (-1) et se met en erreur, relance le programme 
    for (int i = 0; i < sizeof(touches); i++) {
      if (touches[i].appuie()) {
        return i; // Renvoie l'indice de la première touche appuyée
      }
    }
  }
  return -1; // Si aucune touche n'est appuyée, renvoie -1
  
}


void genererSequence(std::vector<Touche>& listeTouches, Touche* touches, int vitesse) { //vitesse de 500 = normal
  int randomIndex = random(0, sizeof(touches));
  listeTouches.push_back(touches[randomIndex]);

  for (int i = 0; i < listeTouches.size(); i++) {
    listeTouches[i].play();
    delay(vitesse); // attente entre chaque touche
  }
}

bool verifierSequence(const std::vector<Touche>& listeTouches, Touche* touches, int attente){ //Attention pb attente, voir toucheAppuie{
  for (int i = 0; i < listeTouches.size(); i++) {
    int t = ToucheAppuie(touches, attente) ;
    if (t != -1 && touches[t] == listeTouches[i]){ 

      listeTouches[i].play();

    } else {
      tone(D9, 200);
      delay(2000);
      noTone(D9);
      delay(250);
      listeTouches[i].play();
      delay(250);
      listeTouches[i].play();
      delay(250);
      listeTouches[i].play();
      return false; 
    }
  }
  return true; 
  
}



std::vector<Touche> listeTouches;

TM1637 Segment(D6, D7);
int maximum = 12;
int score;

void setup() {
Segment.init();
Segment.set(BRIGHT_TYPICAL);//BRIGHT_TYPICAL = 2,BRIGHT_DARKEST = 0,BRIGHTEST = 7;
}

void loop() {

disco( touches, 200, 2); // initialisation
Segment.displayStr("Max");
delay(100);
Segment.displayNum(maximum);
delay(1000);

while (1) { //modedejeuclassique(vitesse de 500)
  genererSequence(listeTouches, touches, 500);
  verifierSequence(listeTouches,touches, 1000);
  score = listeTouches.size();
  Segment.displayNum(score);
  delay(2000); // attente entre chaque sequence
}
}
