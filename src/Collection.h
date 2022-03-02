#ifndef Collection_H
#define Collection_H
#include <iostream>
#include "Arbre.h"
#include "ArbreRN.h"
using namespace std;

/**
 * @class Collection
**/

class Collection
{
private:

public:

    /*
    #####################################
    ----- Constructeur/Destructeur -----
    #####################################
    */

    /**
     * @brief Constructeur d'une collection.
    **/
    Collection();
    
    /**
     * @fn Make(char type)
     * @brief Fonction qui selon le type que l'utisateur choisit, créée un arbre non équilibré ou rouge et noir.
     * @param type Caractère qui permet de choisir quel type d'arbre renvoyé.
     * @return Retourne la classe Tree.
    **/
    virtual Tree *Make(char type);
    
    /**
     * @brief Destructeur d'une collection.
    **/
    ~Collection();
};

#endif
