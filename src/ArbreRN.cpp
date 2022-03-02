#include "ArbreRN.h"
#include <iostream>
#include <type_traits>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define JN "\e[0;33m"
#define CYN "\e[0;36m"
#define REDB "\e[41m"
using namespace std;

ArbreRN::ArbreRN(char aff)
{
    nbnoeud = 0;
    Nracine = nullptr;
    changenoeudgauche = false;
    changenoeuddroite = false;
    if (aff == 'p')
    {
        Display = &ArbreRN::affichagefromCCfirst;
    }
    else
    {
        Display = &ArbreRN::affichagefromPrefix;
    }
}

ArbreRN::~ArbreRN()
{
    vider();
}

void ArbreRN::vider()
{
    Destructfrom(Nracine);
    nbnoeud = 0;
    Nracine = nullptr;
}

void ArbreRN::Destructfrom(Noeud *&n)
{
    if (n != nullptr)
    {
        Destructfrom(n->fg);
        Destructfrom(n->fd);
        delete n;
    }
}

Noeud *ArbreRN::Recherche(const Element &e)
{
    return (RechercheFrom(Nracine, e));
}

Noeud *ArbreRN::RechercheFrom(Noeud *n, const Element &e)
{
    if (n == nullptr)
    {
        return nullptr;
    }
    else
    {
        if (n->info == e)
        {
            return n;
        }
        else
        {
            if (e < n->info)
            {
                return RechercheFrom(n->fg, e);
            }
            else
            {
                return RechercheFrom(n->fd, e);
            }
        }
    }
}

void ArbreRN::affichage()
{
    (this->*Display)(Nracine);
}

void ArbreRN::affichagefromPrefix(Noeud *n)
{
    if (n != nullptr)
    {
        cout << n->info << " || ";
        affichagefromPrefix(n->fg);
        affichagefromPrefix(n->fd);
    }
}

void ArbreRN::affichagefromCCfirst(Noeud *n)
{
    AffichageFromCC(n, 0);
}

void ArbreRN::AffichageFromCC(Noeud *n, int decalage)
{
    string S = "";
    if (n != nullptr)
    {
        int decalage2 = decalage + 1;
        AffichageFromCC(n->fg, decalage2);
        for (int i = 0; i < decalage; i++)
        {
            S = S + " . ";
        }
        if (n->couleur == 'r')
        {
            cout << NC << S << RED << n->info << NC << endl;
        }
        if (n->couleur == 'n')
        {
            cout << NC << S << CYN << n->info << NC << endl;
        }

        AffichageFromCC(n->fd, decalage2);
    }
}

void ArbreRN::Insert(const Element &e)
{
    Inserertfrom(Nracine, e);
}

void ArbreRN::Inserertfrom(Noeud *&n, const Element &e)
{
    Noeud *Changement;
    if (n == nullptr)
    {
        n = new Noeud(e);
        n->couleur = 'r';
        if (nbnoeud == 0)
        {
            n->couleur = 'n';
        }
        nbnoeud++;
    }
    else
    {
        if (e < n->info)
        {
            Inserertfrom(n->fg, e);
            Equilibrage(n, n->fg, Changement);
            if (changenoeudgauche)
            {
                n = Changement;
                changenoeudgauche = false;
            }
            Equilibrage(n, n->fg, Changement);
            if (changenoeudgauche)
            {
                n = Changement;
                changenoeudgauche = false;
            }
        }
        else if (e >= n->info)
        {
            Inserertfrom(n->fd, e);
            Equilibrage(n, n->fd, Changement);
            if (changenoeuddroite)
            {
                n = Changement;
                changenoeuddroite = false;
            }
            Equilibrage(n, n->fd, Changement);
            if (changenoeuddroite)
            {
                n = Changement;
                changenoeuddroite = false;
            }
        }
    }
}

int ArbreRN::Equilibrage(Noeud *&n, Noeud *&follow, Noeud *&Changement)
{
    Noeud *temp;
    if (follow == n->fg)
    {
        if (n->fg->fg != NULL)
        {
            if ((n->fg->couleur == 'r') && (n->fg->fg->couleur == 'r'))
            {
                if ((n->fd != NULL) && (n->fd->couleur == 'r'))
                {
                    n->couleur = 'r';
                    n->fg->couleur = 'n';
                    n->fd->couleur = 'n';
                    return 0;
                }
                else
                {
                    temp = n->fg;
                    n->fg = n->fg->fd;
                    temp->fd = n;
                    temp->fd->couleur = 'r';
                    temp->couleur = 'n';
                    Changement = temp;
                    changenoeudgauche = true;
                    return 1;
                }
            }
        }
        if (n->fg->fd != NULL)
        {
            if ((n->fg->couleur == 'r') && (n->fg->fd->couleur == 'r'))
            {
                if ((n->fd != NULL) && (n->fd->couleur == 'r'))
                {
                    n->couleur = 'r';
                    n->fg->couleur = 'n';
                    n->fd->couleur = 'n';
                    return 0;
                }
                else
                {
                    temp = n->fg;
                    n->fg = n->fg->fd;
                    temp->fd = n->fg->fg;
                    n->fg->fg = temp;
                    return 0;
                }
            }
        }
    }

    else if (follow == n->fd)
    {
        if (n->fd->fd != NULL)
        {
            if ((n->fd->couleur == 'r') && (n->fd->fd->couleur == 'r'))
            {
                if ((n->fg != NULL) && (n->fg->couleur == 'r'))
                {
                    n->couleur = 'r';
                    n->fg->couleur = 'n';
                    n->fd->couleur = 'n';
                    return 0;
                }
                else
                {
                    temp = n->fd;
                    n->fd = n->fd->fg;
                    temp->fg = n;
                    temp->fg->couleur = 'r';
                    temp->couleur = 'n';
                    Changement = temp;
                    changenoeuddroite = true;
                    return 2;
                }
            }
        }
        if (n->fd->fg != nullptr)
        {
            if ((n->fd->couleur == 'r') && (n->fd->fg->couleur == 'r'))
            {
                if ((n->fg != NULL) && (n->fg->couleur == 'r'))
                {
                    n->couleur = 'r';
                    n->fg->couleur = 'n';
                    n->fd->couleur = 'n';
                    return 0;
                }
                else
                {
                    temp = n->fd;
                    n->fd = n->fd->fg;
                    temp->fg = n->fd->fd;
                    n->fd->fd = temp;
                    return 0;
                }
            }
        }
    }
    Nracine->couleur = 'n';
    return 0;
}