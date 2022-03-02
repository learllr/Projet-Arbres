# ----- make all -----

all: bin/main bin/performances


# ----- Les exécutables -----

bin/main: obj/main.o obj/Collection.o obj/ArbreRN.o obj/Element.o obj/Arbre.o obj/Tree.o obj/Noeud.o
	g++ -g -W -Wall obj/main.o obj/Collection.o obj/ArbreRN.o obj/Element.o obj/Arbre.o obj/Tree.o obj/Noeud.o -o bin/main

bin/performances: obj/mainperformances.o obj/Collection.o obj/ArbreRN.o obj/Element.o obj/Arbre.o obj/Tree.o obj/Noeud.o
	g++ -g -W -Wall obj/mainperformances.o obj/Collection.o obj/ArbreRN.o obj/Element.o obj/Arbre.o obj/Noeud.o obj/Tree.o -o bin/performances


# ----- Les fichiers obj -----

obj/main.o: src/main.cpp src/Collection.h src/Collection.cpp src/ArbreRN.h src/ArbreRN.cpp src/Arbre.h src/Arbre.cpp src/Tree.h src/Tree.cpp
	g++ -g -W -Wall -c src/main.cpp -o obj/main.o
	
obj/mainperformances.o: src/mainperformances.cpp src/ArbreRN.h src/ArbreRN.cpp src/Arbre.h src/Arbre.cpp src/Tree.h src/Tree.cpp src/Noeud.h src/Noeud.cpp
	g++ -g -W -Wall -c src/mainperformances.cpp -o obj/mainperformances.o
	
obj/Collection.o: src/Collection.h src/Collection.cpp src/ArbreRN.h src/ArbreRN.cpp src/Arbre.h src/Arbre.cpp src/Element.h src/Element.cpp src/Tree.h src/Tree.cpp src/Noeud.h src/Noeud.cpp
	g++ -g -W -Wall -c src/Collection.cpp -o obj/Collection.o

obj/ArbreRN.o: src/ArbreRN.h src/ArbreRN.cpp src/Element.h src/Element.cpp src/Tree.h src/Tree.cpp src/Noeud.h src/Noeud.cpp src/Collection.h src/Collection.cpp
	g++ -g -W -Wall -c src/ArbreRN.cpp -o obj/ArbreRN.o
	
obj/Arbre.o: src/Arbre.h src/Arbre.cpp src/Element.h src/Element.cpp src/Tree.h src/Tree.cpp src/Noeud.h src/Noeud.cpp src/Collection.h src/Collection.cpp
	g++ -g -W -Wall -c src/Arbre.cpp -o obj/Arbre.o

obj/Noeud.o: src/Noeud.h src/Noeud.cpp src/Element.h src/Element.cpp
	g++ -g -W -Wall -c src/Noeud.cpp -o obj/Noeud.o

obj/Element.o: src/Element.h src/Element.cpp
	g++ -g -W -Wall -c src/Element.cpp -o obj/Element.o
	
obj/Tree.o: src/Tree.h src/Tree.cpp
	g++ -g -W -Wall -c src/Tree.cpp -o obj/Tree.o


# ----- Nettoyage -----

cleanObj:
	rm obj/*

cleanBin:
	rm bin/*

veryclean: 
	rm obj/*
	rm bin/*
