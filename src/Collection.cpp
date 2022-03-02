#include "Collection.h"

using namespace std;

Collection::Collection()
{
}

Collection::~Collection()
{
}

Tree *Collection::Make(char type)
{
    if (type == 'r')
    {
        cout << "[Arbre rouge et noir]" << endl;
        return new ArbreRN('p');
    }
    else
    {
        cout << "[Arbre non équilibré]" << endl;
        return new Arbre('p');
    }
}