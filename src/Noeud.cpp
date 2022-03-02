#include "Noeud.h"

/*
class nullptr_t  // A DECOMMENTER S'IL Y A UNE ERREUR PENDANT L'EXECUTION SUR UN MAC 
{
  public:
    template<class T>
    inline operator T*() const 
    { return 0; }

    template<class C, class T>
    inline operator T C::*() const   
    { return 0; }

  private:
    void operator&() const; 

} nullptr = {}; */

Noeud::Noeud(const Element &e)
{
  info = e;
  fg = nullptr;
  fd = nullptr;
}

Noeud::~Noeud()
{
  info = 0;
  fg = nullptr;
  fd = nullptr;
}