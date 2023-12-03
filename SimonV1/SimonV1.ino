#include <vector> 

class Touche {
  private : 
  int Bouton;
  int Led;
  int Song;
  int Buzzer = D6;



  public: 

  Touche(int PinBouton, int PinLed, int FreqSong){
    Bouton = PinBouton;
    Led = PinLed;
    Song = FreqSong;
    

    pinMode(Led, OUTPUT);
    pinMode(Bouton, INPUT);
    pinMode(Buzzer, OUTPUT);
    
  }

  void play(){
    digitalWrite(Led, HIGH);
    tone(Buzzer, Song);
    delay(250);
    digitalWrite(Led, LOW);
    noTone(Buzzer);
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

Touche touches[] = {
  Bleu,Rouge,Jaune // on peu directement ajouter les instances de touche ici mais pas les nommer 
};

int ToucheAppuie(Touche* touches, int numTouches) {
    unsigned long startMillis = millis(); // Temps de démarrage
    bool sortie = 1;
  while (((millis() - startMillis )< 3000) && sortie) { // Attendre 3 secondes
  for (int i = 0; i < numTouches; i++) {
    if (touches[i].appuie()) {
      sortie = 0;
      return i; // Renvoie l'indice de la première touche appuyée
    }
  }
  }
  return -1; // Si aucune touche n'est appuyée, renvoie -1
}

void genererSequence(std::vector<Touche>& listeTouches, Touche* touches, int nbTouches, int vitesse) { //vitesse de 500 = normal
  int randomIndex = random(0, nbTouches);
  listeTouches.push_back(touches[randomIndex]);

  for (int i = 0; i < listeTouches.size(); i++) {
    listeTouches[i].play();
    delay(vitesse); // attente entre chaque touche
  }
}


std::vector<Touche> listeTouches;

void setup() {}

void loop() {


genererSequence(listeTouches, touches, 3, 500);




  delay(2000); // attente entre chaque sequence


  // if (Bleu.appuie()) {
  //   Bleu.play();
  // }
  // if (Rouge.appuie()) {
  //   Rouge.play();
  // }
  // if (Jaune.appuie()) {
  //   Jaune.play();
  // }

}
