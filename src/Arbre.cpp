#include "Arbre.h"
#include <iostream>
#define NC "\e[0m"
using namespace std;

Arbre::Arbre(char aff)
{
    nbnoeud = 0;
    Nracine = nullptr;
    if (aff == 'p')
    {
        Display = &Arbre::affichagefromCCfirst;
    }
    else
    {
        Display = &Arbre::affichagefromPrefix;
    }
}

Arbre::~Arbre()
{
   vider();
}

void Arbre::vider()
{
    Destructfrom(Nracine);
    nbnoeud = 0;
    Nracine = nullptr;
}

void Arbre::Destructfrom(Noeud *&n)
{
    if (n != nullptr)
    {
        Destructfrom(n->fg);
        Destructfrom(n->fd);

        delete n;
    }
}

void Arbre::operator=(Arbre &a2)
{
    if (nbnoeud != 0)
    {
        Destructfrom(Nracine);
    }
    pastefrom(a2.Nracine, Nracine);
}

void Arbre::pastefrom(Noeud *n, Noeud *&current)
{
    if (n != nullptr)
    {
        Inserertfrom(current, n->info);
        pastefrom(n->fg, current->fg);
        pastefrom(n->fd, current->fd);
    }
}

Noeud *Arbre::Recherche(const Element &e)
{
    return (RechercheFrom(Nracine, e));
}

Noeud *Arbre::RechercheFrom(Noeud *n, const Element &e)
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

void Arbre::affichage()
{
    (this->*Display)(Nracine);
}

void Arbre::affichagefromPrefix(Noeud *n)
{
    if (n != nullptr)
    {
        cout << n->info << " || ";
        affichagefromPrefix(n->fg);
        affichagefromPrefix(n->fd);
    }
}

void Arbre::affichagefromCCfirst(Noeud *n)
{
    AffichageFromCC(n, 0);
}

void Arbre::AffichageFromCC(Noeud *n, int decalage)
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
        cout << NC << S << n->info << endl;
        AffichageFromCC(n->fd, decalage2);
    }
}

void Arbre::Insert(const Element &e)
{
    Inserertfrom(Nracine, e);
}

void Arbre::Inserertfrom(Noeud *&n, const Element &e)
{
    if (n == nullptr)
    {
        n = new Noeud(e);
        nbnoeud++;
    }
    else
    {
        if (e < n->info)
        {

            Inserertfrom(n->fg, e);
        }
        if (e >= n->info)
        {

            Inserertfrom(n->fd, e);
        }
    }
}
