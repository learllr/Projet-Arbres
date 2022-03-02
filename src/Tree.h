
#ifndef Tree_H
#define Tree_H

#include "Element.h"
#include "Noeud.h"

class Tree
{
    
    /*
    #########################
    ----- Classes amies -----
    #########################
    */

    friend class Arbre;
    friend class ArbreRN;
    friend class Collection;

private:

public:

    /*
    #####################################
    ----- Constructeur/Destructeur -----
    #####################################
    */

    /**
     * @brief Constructeur de Tree.
    **/
    Tree() {};

    /**
     * @brief Destructeur de Tree.
    **/
    virtual ~Tree() {};

    /**
     * @fn Insert(const Element &e) -> void
     * @brief Pourra insérer l'élément e dans l'arbre à partir d'un fonction récursive.
     * @param e Element (entier) à insérer.
    **/
    virtual void Insert(const Element &e) =0; 

    /**
     * @fn affichage() -> void
     * @brief Pourra faire l'affichage d'un arbre selon le type que l'utilisateur a choisi.
    **/
    virtual void affichage() =0;

    /**
     * @fn vider() -> void
     * @brief Pourra vider l'intégralité d'un arbre en utilisant une fonction récursive, met le nombre de noeud à 0 et supprime la racine.
    **/
    virtual void vider() =0;

    /**
     * @fn Recherche(const Element &e)
     * @brief Pourra faire la recherche d'un élément e dans un arbre à partir d'une fonction récursive.
     * @param e Element que l'on souhaite rechercher dans un arbre.
     * @return Retourne un pointeur sur un noeud.
    **/
    virtual Noeud *Recherche(const Element &e) =0;
    
};

#endif
