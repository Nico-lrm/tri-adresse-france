#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

//Type "Adresse"
typedef struct
{
    char *rue, *ville, *cp, *numero;
} Adresse;

//Type bool
typedef int bool;
#define false 0
#define true 1
//Variables Globales
extern Adresse tabAdresse[27381996];
extern char message[200];
extern int pile[27381996];
extern Adresse tabFusionAdresse[27381996];


//-----------------NETTOYAGE------------------------
//Prototype : Nettoyage de buffer d'entrée
void clear_stdin();
//----------------ENREGISTREMENT--------------------
//Prototype : Enregistrement des données relatives au tri
void enregistrementMesureTri(int nbLigne, clock_t temps, char* nom_fichier, bool auto_save);

//------------------CHARGEMENT----------------------
//Prototype : Fonction de chargement des données
void loadData(Adresse *tabAdresse, int nbDeFois, bool auto_save);

//Prototype : Fonction de séparation
char *strsep(char **stringp, const char *delim);
//---------------------TRI--------------------------
//Prototype : Tri à bulle
void triBulle(Adresse *tabAdresse, int nbLigne, bool auto_save);

//Prototype : Tri à bulle Boustrophédon
void triBulleBoustrophedon(Adresse *tabAdresse, int nbLigne, bool auto_save);

//Prototype : Tri par sélection
void triSelection(Adresse *tabAdresse, int nbLigne, bool auto_save);

//Prototype : Tri par insertion
void triInsertion(Adresse *tabAdresse, int nbLigne, bool auto_save);

//Prototype : Mélange le tableau
void melangeTableau(Adresse *tabAdresse, int nbLigne);

//---------------------TRI RAPIDE--------------------------
//Prototype : Tri Rapide
void triRapide(Adresse *tabAdresse, int *pile, int nbLigne, bool auto_save);

//Prototype : Fonction de partition du tri rapide
int partitionTriRapide(Adresse *tabAdresse, int a, int b);
//---------------------TRI BRETON--------------------------
//Prototype : Inverseur du tri Breton
void inverse(Adresse *tabAdresse, int nbLigne,  int indiceMax);

void inverse2(Adresse *tabAdresse,int nbLigne, int indiceMax);

//Prototype : Recherche le plus grand dans le tableau
int maximum(Adresse *tabAdresse, int nbLigne);

//Prototype : Algorithme du tri Breton
void triBreton(Adresse *tabAdresse, int nbLigne, bool auto_save);
//---------------------TRI FUSION--------------------------
//Prototype : Fusion de tableau
void fusion(Adresse *tabAdresse, int nbLigne, int start, int middle, int endt, Adresse *tabFusionAdresse);

//Prototype : Fonction de tri fusion
void triFusion(Adresse *tabAdresse, int nbLigne, bool auto_save);
//---------------------RECHERCHE---------------------------
//Recherche séquentielle - Nombre d'itération
int rechercheSequentielle(Adresse *tabAdresse, int nbLigne, char* sujet, bool auto_save);

//Recherche séquentielle - Nombre d'itération
int rechercheSequentielleIteration(Adresse *tabAdresse, int nbLigne, char* sujet, bool auto_save);

//Recherche dichotomique
bool rechercheDichotomique(Adresse *tabAdresse, int nbLigne, char* sujet, bool auto_save);

#endif
