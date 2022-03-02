#ifndef Noeud_H
#define Noeud_H

#include "Element.h"

class Noeud
{

    /*
    #########################
    ----- Classes amies -----
    #########################
    */

    friend class ArbreRN;
    friend class Arbre;

private:

    /*
    ###########################
    ----- Données membres -----
    ###########################
    */

    /**
     * @brief Les données membres privées de la classe Noeud.
     * @param fg Noeud qui correspond au fils gauche.
     * @param fd Noeud qui correspond au fils droit.
     * @param couleur Caractère qui correspond à la couleur du noeud.
     * @param info Element qui correspond à l'information (entier) du noeud.
    **/
    Noeud *fg;
    Noeud *fd;
    char couleur;
    Element info;
    
public:

    /*
    #####################################
    ----- Constructeur/Destructeur -----
    #####################################
    */

    /**
     * @brief Constructeur d'un noeud qui lui attribue l'information e et contenant aucun fils. 
     * @param e Element correspondant à l'information à attribuer au noeud.
    **/
    Noeud(const Element &e);

    /**
     * @brief Destructeur d'un noeud qui met l'information à 0 et les pointeurs à nullptr.
    **/
    ~Noeud();
};

#endif
