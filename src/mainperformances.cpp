#include "ArbreRN.h"
#include "Arbre.h"
#include "Element.h"
#include "Collection.h"
#include <iostream>
#include <chrono>  /*chrono::time_point*/
#include <fstream>

using namespace std;

int main()
{
    Collection ArbreGenerator;
    int taille_moyenne = 1000; // Nombre d'arbres.
    int randlimit = 10000; // Valeur maximal pour les nombres aléatoires.
    chrono::time_point<chrono::system_clock> start, end;
    Tree *TabArbre[taille_moyenne]; // Tableau d'arbres.
    float moyenne = 0.0;
    int o = 1; // o : Nombre d'éléments insérés dans chaque arbre.

    /* PARTIE ARBRES ROUGES NOIRES */

    for (int a = 0; a < taille_moyenne; a++)
    {
        // Remplis le tableau de Tree en transformant chaque Tree en arbres rouge et noir.
        TabArbre[a] = ArbreGenerator.Make('r');
    }
    srand(time(0));
    ofstream MyFile("data/PerformanceInsert.txt");
    MyFile << "# "
           << "nb element "
           << "Temps" << endl;

    while (o < 10000)
    {
        srand(rand()); 
        // Pour tous les arbres.
        for (int a = 0; a < taille_moyenne; a++)
        {
            for (int u = o; u < o + 10; u++)
            {
                TabArbre[a]->Insert(rand() % randlimit);
            }
        }
        // Chronomètre la prochaine insertion.
        start = chrono::system_clock::now();
        for (int p = 0; p < taille_moyenne; p++)
        {
            // Insertion d'un élément en plus dans tous les arbres.
            TabArbre[p]->Insert(rand() % randlimit);
        }
        end = chrono::system_clock::now();
        // Temps mis pour insérer un élément en plus dans tous les arbres.
        float elapsed_microseconds = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        moyenne = elapsed_microseconds / taille_moyenne;
        MyFile << o << " " << moyenne << endl;
        cout << "Arbre Rouge et Noir -> Nombre d'éléments : " << o << endl;
        o = o + 10;
    }
    MyFile.close();

    /* PARTIE ARBRE NON ÉQUILIBRÉ */

    for (int a = 0; a < taille_moyenne; a++)
    {
        TabArbre[a] = ArbreGenerator.Make('n');
    }
    ofstream MyFile3("data/PerformanceInsertArbresNormaux.txt");
    MyFile3 << "# "
            << "nb element "
            << "Temps" << endl;
    o = 1;
    while (o < 10000)
    {
        for (int a = 0; a < taille_moyenne; a++)
        {
            for (int u = o; u < o + 10; u++)
            {
                TabArbre[a]->Insert(rand() % randlimit);
            }
        }
        start = chrono::system_clock::now();
        for (int p = 0; p < taille_moyenne; p++)
        {
            TabArbre[p]->Insert(rand() % randlimit);
        }
        end = chrono::system_clock::now();
        float elapsed_microseconds = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        moyenne = elapsed_microseconds / taille_moyenne;
        MyFile3 << o << " " << moyenne << endl;
        cout << "Arbre non équilibré -> Nombre d'éléments : " << o << endl;
        o = o + 10;
    }
    MyFile3.close();
    return 0;
}