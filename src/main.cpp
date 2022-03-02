#include "ArbreRN.h"
#include "Arbre.h"
#include "Element.h"
#include "Collection.h"
#define NC "\e[0m"
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  cout << endl;
  Collection GenerateurArbre;
  Tree *testArbreBR;
  Tree *testArbreRN;

  testArbreBR = GenerateurArbre.Make('n');

  cout << endl;
  testArbreBR->Insert(90);
  testArbreBR->Insert(98);
  testArbreBR->Insert(198);
  testArbreBR->affichage();
  cout << endl;

  Noeud *Search = testArbreBR->Recherche(90);
  cout << "Adresse du noeud dans un arbre binaire non equilibré contenant 90 : " << Search << endl;
  Search = testArbreBR->Recherche(198);
  cout << "Adresse du noeud dans un arbre binaire non equilibré contenant 198 : " << Search << endl;
  Search = testArbreBR->Recherche(205);
  cout << "Adresse du noeud dans un arbre binaire non equilibré contenant 205 : " << Search << endl;
  cout << endl;

  testArbreRN = GenerateurArbre.Make('r');

  cout << endl;
  testArbreRN->Insert(16);
  testArbreRN->Insert(18);
  testArbreRN->Insert(20);
  testArbreRN->affichage();
  cout << endl;

  Search = testArbreRN->Recherche(16);
  cout << "Adresse du noeud dans un arbre rouge et noir contenant 16 : " << Search << endl;
  Search = testArbreRN->Recherche(18);
  cout << "Adresse du noeud dans un arbre rouge et noir contenant 18 : " << Search << endl;
  Search = testArbreBR->Recherche(300);
  cout << "Adresse du noeud dans un arbre rouge et noir contenant 300 : " << Search << endl;
  cout << endl;

  testArbreBR->vider();
  cout << "Vérification de l'état de l'arbre" << endl;

  testArbreBR->affichage();
  cout << "Arbre binaire non équilibré vidé" << endl;

  testArbreRN->vider();
  cout << endl;
  cout << "Vérification de l'état de l'arbre" << endl;
  
  testArbreRN->affichage();
  cout << "Arbre rouge noir vidé" << endl;
  cout << endl;

  return 0;
}