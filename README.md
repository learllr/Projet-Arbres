  
  

Voici le site pour visualiser le langage md du read me : https://stackedit.io/app#

  

# Arbre (rouge et noir / non équilibré)

  

Notre projet porte sur les arbres non équilibrés et rouge et noir. Il a été réalisé dans le cadre de l'unité d'enseignement LIFAP6 de 2021-2022.

  

## Organisation de l'archive

  

**./ :** Contient le Makefile permettant de compiler le projet en créant les 2 exécutables qui sont contenu dans le dossier bin.

  

**bin/ :** Contient les executables main et performances.

  

**data/ :** Toutes les données nécessaires pour le fonctionnement graphique.

  

**doc/ :** Un fichier de configuration doxygen image.doxy, un dossier htlm contenant le résultat de la génération de la documentation doxygen ainsi que ce readme.

  

**obj/ :** Les fichiers objets (.o) : main.o, mainperformances.o, Collection.o, ArbreRN.o, Arbre.o, Noeud.o, Element.o, Tree.o.

  

**src/ :** Les fichiers sources .cpp et header .h : Arbre.cpp, Arbre.h, ArbreRN.cpp, ArbreRN.h, Collection.cpp, Collection.h, main.cpp, mainperformances.cpp, Noeud.cpp, Noeud.h, Tree.cpp, Tree.h, Element.cpp, Element.h.

  

## Utilisation et Exécutables

  

Pour compiler et créer les exécutables, on utilise la commande make dans le terminal Linux suivi de ./bin/nomExecutable depuis le dossier.

  

Notre projet contient deux exécutables :

  

- main : exécutable permettant de générer deux arbres partir d'une collection : l'un non équilibré l'autre rouge et noir. On teste les quatre fonctions qui sont demandées dans l'implémentation de la collection : insertion, recherche, affichage et vider.

  

- performances : exécutable permettant de tester les performances de recherche et d'insertion de chaque type d'arbre.

## Modules

 - Element : type des éléments qui seront insérés dans les arbres.
 - Noeud : classe qui correspond au noeud d'un arbre.
 - Arbre : classe qui correspond à un arbre binaire de recherche non équilibré.
 - ArbreRN : classe qui correspond à un arbre binaire de recherche rouge et noir.
 - Collection : classe qui génèrera des Tree (Arbre et ArbreRN).
 - Tree : classe qui correspond à un arbre en général qui pourra être un Arbre ou un ArbreRN.

## Installation
  Pour faire générer les performances, il faut installer gnuplot :
```
brew install gnuplot
```
## Performances

Pour accéder à gnuplot :
```
gnuplot
```

Pour voir les performances d'insertion d'un arbre rouge et noir, il faut écrire les commandes suivantes :

 
```
set terminal pngcairo size 2000,2000 enhanced font 'Verdana,10'  
set output 'data/PerformancesInsertRN.png' 
plot "data/PerformanceInsert.txt" w l
```

Pour voir les performances d'insertion d'un arbre non équilibré, il faut écrire les commandes suivantes :

```
set terminal pngcairo size 2000,2000 enhanced font 'Verdana,10'
set output 'data/PerformancesInsertBR.png'
plot "data/PerformanceInsertArbresNormaux.txt" w l
```
  
Pour voir la comparaison des performances du temps d'insertion pour les deux types d'arbres, il faut écrire les commandes suivantes :

```
set terminal pngcairo size 2000,2000 enhanced font 'Verdana,10'  
set output 'data/PerformancesInsert.png' 
plot "data/PerformanceInsert.txt" w l , "data/PerformanceInsertArbresNormaux.txt" w l
```
  

![alt text](https://zupimages.net/up/21/47/i2uz.png)

  
  
## Créateurs

  

BEN JEMIA Boran (p1924945)

  

ROULLIER LEA (p1911736)
