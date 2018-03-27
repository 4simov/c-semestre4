#include <string>
#include <iostream>
using namespace std;

class IMC {
  private :
	  string* nom;
    int poids;
    float taille;

  public :  
  IMC() {
    *nom = "inconnu";
    poids = 70;
    taille = 1.80;
  }
  IMC( string n, int p, float t ) {
    *nom = n;
    poids = p;
    taille = t;
  }
  IMC( IMC& exemple ) {
    nom = exemple.nom;
    poids = exemple.poids;
    taille = exemple.taille;
  }

  float Indice() {
    return poids/(taille*taille);
  }
  //entrées variables
  void ChangerNom( string n){
    *nom = n;
  }
  void ChangerPoids( int p ) {
    poids = p;
  }
  void ChangerTaille( float t) {
    taille = t;
  }
  void Affichage() {
    cout << " - Identité -" << endl;
    cout << "° Nom : " << *nom << endl;
    cout << "° Taille = " << taille << ", ";
    cout << "Poids = " << poids << endl;
    cout << "° IMC = " << IMC::Indice() << endl;
  }
};

int main() {
  IMC a1;
  IMC a2( "Patate", 67, 1.78 );
  a1.Affichage();
  a2.Affichage();
  a1 = a2;
  a1.ChangerNom("Purée");
  a1.Affichage();
  a2.Affichage();
  IMC a3(a2);
  IMC* b1 = new IMC();
  IMC b2(*b1);
  return 0;
}