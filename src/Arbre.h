#ifndef Arbre_H
#define Arbre_H

#include "Element.h"
#include "Tree.h"
#include "Noeud.h"

class Arbre : public Tree
{
private:

    /*
    ###########################
    ----- Données membres -----
    ###########################
    */

    /**
     * @brief Les données membres privées de la classe Arbre.
     * @param Nracine Pointeur sur Noeud qui correspond à la racine.
     * @param nbnoeud Entier qui contient le nombre de noeuds de notre arbre.
    **/
    Noeud *Nracine;
    int nbnoeud;


    /*
    ################################
    ----- Fonctions récursives -----
    ################################
    */

    /**
     * @fn Inserertfrom(Noeud *&n, const Element &e) -> void
     * @brief Insère l'élément e dans un sous-arbre.
     * @param n Noeud à partir duquel on souhaite insérer l'élément e.
     * @param e Element (entier) à insérer.
    **/
    void Inserertfrom(Noeud *&n, const Element &e);

    /**
     * @fn AffichageFromCC(Noeud *n, int decalage) -> void
     * @brief Affichage de manière graphique d'un sous-arbre à partir du noeud n.
     * @param n Noeud à partir duquel on va afficher ses sous-arbres de manière graphique.
     * @param decalage Entier qui correspond au nombre d'espaces entre les éléments de notre arbre.
    **/
    void AffichageFromCC(Noeud *n, int decalage);

    /**
     * @fn RechercheFrom(Noeud *n, const Element &e)
     * @brief Recherche un élément e dans les sous-arbres de n.
     * @param n Noeud à partir duquel on souhaite rechercher l'élément e.
     * @param e Element (entier) à rechercher.
     * @return Retourne un pointeur sur un noeud.
    **/
    Noeud* RechercheFrom(Noeud *n, const Element &e);

    /**
     * @fn affichagefromPrefix(Noeud *n) -> void
     * @brief Affichage de manière préfixe d'un sous-arbre.
     * @param n Noeud à partir duquel on va afficher ses sous-arbres.
    **/
    void affichagefromPrefix(Noeud *n);

    /**
     * @fn Destructfrom(Noeud *&n) -> void
     * @brief Vide un sous-arbre à partir du noeud n.
     * @param n Noeud à partir duquel on vide ses sous-arbres.
    **/
    void Destructfrom(Noeud * &n);

    /**
     * @fn pastefrom(Noeud *n, Noeud *&current) -> void
     * @brief Fait la copie profonde d'un autre arbre dans notre arbre.
     * @param n Noeud à partir duquel on veut copier l'autre arbre. 
     * @param current Noeud de notre arbre à partir duquel on veut coller l'autre arbre. 
    **/
    void pastefrom(Noeud *n,Noeud * & current);

    /**
     * @fn affichagefromCCfirst(Noeud *n) -> void
     * @brief Affichage d'un arbre de manière graphique.
     * @param n Noeud à partir duquel on va afficher ses sous-arbres en utilisant une fonction récursive.
    **/
    void affichagefromCCfirst(Noeud *n);

public:

    /*
    #####################################
    ----- Constructeur/Destructeur -----
    #####################################
    */
    
    /**
     * @brief Constructeur d'un arbre qui selon le type d'affichage que choisit l'utilisateur, affiche l'arbre graphiquement ou textuellement (préfixe).
     * @param aff Caractère qui contient la lettre que l'utilisateur a choisit pour l'affichage de l'arbre (p -> affichage graphique, autre -> préfixe).
    **/
    Arbre(char aff);

    /**
     * @brief Destructeur d'un arbre qui vide l'arbre.
    **/
    ~Arbre();


    /*
    ##################################
    ----- Surcharge d'opérateurs -----
    ##################################
    */ 

    /**
     * @fn operator=(Arbre &a2)
     * @brief Surcharge d'opérateur d'affectation d'un arbre.
     * @param a2 Arbre que l'on souhaite copier et mettre dans notre arbre.
    **/
    void operator=(Arbre &a2);

    /*
    #####################
    ----- Fonctions -----
    #####################
    */ 

    /**
     * @fn Insert(const Element &e) -> void
     * @brief Insère l'élément e dans l'arbre à partir d'un fonction récursive.
     * @param e Element (entier) à insérer.
    **/
    void Insert(const Element &e);

    /**
     * @fn affichage() -> void
     * @brief Affichage d'un arbre selon le type que l'utilisateur a choisi.
    **/
    void affichage();

    /**
     * @fn (Arbre::*Display)(Noeud *n) -> void
     * @brief Pointeur de fonction qui suivant le type d'affichage choisit par l'utilisateur pourra permettre d'être redirigé dans la fonction adéquate.
     * @param n Noeud à partir duquel on va afficher ses sous-arbres.
    **/
    void (Arbre::*Display)(Noeud *n);

    /**
     * @fn Recherche(const Element &e)
     * @brief Recherche d'un élément e dans un arbre à partir d'une fonction récursive.
     * @param e Element que l'on souhaite rechercher dans un arbre.
     * @return Retourne un pointeur sur un noeud.
    **/
    Noeud* Recherche(const Element &e);
    
    /**
     * @fn vider() -> void
     * @brief Vide l'intégralité d'un arbre en utilisant une fonction récursive, met le nombre de noeud à 0 et supprime la racine.
    **/
    void vider();
};

#endif
