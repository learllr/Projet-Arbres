#ifndef ArbreRN_H
#define ArbreRN_H

#include "Element.h"
#include "Tree.h"
#include "Noeud.h"

/**
 * @class ArbreRN
**/

class ArbreRN : public Tree
{
private:

    /*
    ###########################
    ----- Données membres -----
    ###########################
    */

    /**
     * @brief Les données membres privées de la classe ArbreRN.
     * @param Nracine Pointeur sur Noeud qui correspond à la racine.
     * @param nbnoeud Entier qui contient le nombre de noeud de notre arbre.
     * @param changenoeuddroite Booléen qui demande de changer le noeud pointé lors de l'équilibrage droite.
     * @param changenoeudgauche Booléen qui demande de changer le noeud pointé lors de l'équilibrage gauche.
    **/
    Noeud *Nracine;
    int nbnoeud;
    bool changenoeuddroite;
    bool changenoeudgauche;

    /*
    ################################
    ----- Fonctions récursives -----
    ################################
    */

    /**
     * @fn Inserertfrom(Noeud *&n, const Element &e) -> void
     * @brief Insère l'élément e dans un sous-arbre rouge et noir.
     * @param n Noeud à partir duquel on souhaite insérer l'élément e.
     * @param e Element (entier) à insérer.
    **/
    void Inserertfrom(Noeud *&n, const Element &e);

    /**
     * @fn AffichageFromCC(Noeud *n, int decalage) -> void
     * @brief Affichage de manière graphique un sous-arbre rouge et noir à partir du noeud n.
     * @param n Noeud à partir duquel on va afficher ses sous-arbres de manière graphique.
     * @param decalage Entier qui correspond au nombre de décalage entre les valeurs de notre arbre.
    **/
    void AffichageFromCC(Noeud *n, int decalage);

    /**
     * @fn RechercheFrom(Noeud *n, const Element &e)
     * @brief Recherche un élément e dans les sous-arbres rouge et noir de n.
     * @param n Noeud à partir duquel on souhaite rechercher l'élément e.
     * @param e Element (entier) à rechercher.
     * @return Retourne un pointeur sur un noeud.
    **/
    Noeud *RechercheFrom(Noeud *n, const Element &e);

    /**
     * @fn Destructfrom(Noeud *&n) -> void
     * @brief Vide un sous-arbre rouge et noir à partir du noeud n.
     * @param n Noeud à partir duquel on vide ses sous-arbres.
    **/
    void Destructfrom(Noeud *&n);

    /**
     * @fn affichagefromCCfirst(Noeud *n) -> void
     * @brief Affichage d'un arbre rouge et noir de manière graphique.
     * @param n Noeud à partir duquel on va afficher ses sous-arbres en utilisant une fonction récursive.
    **/
    void affichagefromCCfirst(Noeud *n);

    /**
     * @fn affichagefromPrefix(Noeud *n) -> void
     * @brief Affichage de manière préfixe d'un sous-arbre rouge et noir.
     * @param n Noeud à partir duquel on va afficher ses sous-arbres.
    **/
    void affichagefromPrefix(Noeud *n);

    /**
     * @fn Equilibrage(Noeud *&n, Noeud *&follow, Noeud *&Changement)
     * @brief Fait l'équilibrage après chaque insertion d'un noeud.
     * @param n Element à partir duquel on souhaite faire l'équilibrage.
     * @param follow L'endroit où l'élément a été inséré.
     * @param Changement Pointeur qui indique le lien avant le noeud n.
     * @return Retourne un entier.
    **/
    int Equilibrage(Noeud *&n, Noeud *&follow, Noeud *&Changement);

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
    ArbreRN(char aff);

    /**
     * @brief Destructeur d'un arbre qui vide l'arbre rouge et noir.
    **/
    ~ArbreRN();

    /*
    #####################
    ----- Fonctions -----
    #####################
    */ 

    /**
     * @fn Insert(const Element &e) -> void
     * @brief Insère l'élément e dans l'arbre rouge et noir à partir d'un fonction récursive.
     * @param e Element (entier) à insérer.
    **/
    void Insert(const Element &e);

    /**
     * @fn affichage() -> void
     * @brief Affichage d'un arbre rouge et noir selon le type que l'utilisateur a choisi.
    **/
    void affichage();

    /**
     * @fn (Arbre::*Display)(Noeud *n) -> void
     * @brief Pointeur de fonction qui suivant le type d'affichage choisit par l'utilisateur pourra permettre d'être redirigé dans la fonction adéquate.
     * @param n Noeud à partir duquel on va afficher ses sous-arbres.
    **/
    void (ArbreRN::*Display)(Noeud *n);

    /**
     * @fn *Recherche(const Element &e)
     * @brief Recherche d'un élément e dans un arbre rouge et noir à partir d'une fonction récursive.
     * @param e Element que l'on souhaite rechercher dans un arbre.
     * @return Retourne un pointeur sur un noeud.
    **/
    Noeud *Recherche(const Element &e);

    /**
     * @fn vider() -> void
     * @brief Vide l'intégralité d'un arbre rouge et noir en utilisant une fonction récursive, met le nombre de noeud à 0 et supprime la racine.
    **/
    void vider();
};

#endif
