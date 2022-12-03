#include "../header/common.h"

//Recherche séquentielle
bool rechercheSequentielle(Adresse *tabAdresse, int nbLigne,  char* sujet, bool auto_save)
{
    int i;
    bool trouve, possible;
    char* nom_fichier = malloc(sizeof(char));
    sprintf(nom_fichier, "%s", "rech_seq.csv");

    //Premier compteur de tick CPU
    clock_t debut = clock();

    i = 0;
    trouve = false;
    possible = true;

    while(i<nbLigne && !trouve && possible)
    {
        if (atoi(tabAdresse[i].cp) == atoi(sujet))
        {
            trouve = true;
        }
        else
        {
            if (atoi(tabAdresse[i].cp) > atoi(sujet))
            {
                possible = false;
            }
            else
            {
                i++;
            }
        }
    }

    //Deuxième compteur de tick CPU
    clock_t fin = clock();

    //Enregistrement
    enregistrementMesureTri(nbLigne, fin-debut, nom_fichier, auto_save);
    free(nom_fichier);

    return trouve;
}

//Recherche séquentielle - Nombre d'itération
int rechercheSequentielleIteration(Adresse *tabAdresse, int nbLigne, char* sujet, bool auto_save)
{
    int i, iteration;
    char* nom_fichier = malloc(sizeof(char));
    sprintf(nom_fichier, "%s", "rech_seq_it.csv");

    //Premier compteur de tick CPU
    clock_t debut = clock();
    i = 0;
    iteration = 0;
    while (i < nbLigne)
    {
        if (atoi(tabAdresse[i].cp) == atoi(sujet))
        {
            iteration++;
        }
        i++;
    }
    //Deuxième compteur de tick CPU
    clock_t fin = clock();

    //Enregistrement
    enregistrementMesureTri(nbLigne, fin-debut, nom_fichier, auto_save);
    free(nom_fichier);

    return iteration;
}

//Recherche dichotomique
bool rechercheDichotomique(Adresse *tabAdresse, int nbLigne, char* sujet, bool auto_save)
{
    int i, j;
    bool trouve;
    char* nom_fichier = malloc(sizeof(char));
    sprintf(nom_fichier, "%s", "rech_dichotomie.csv");

    //Premier compteur de tick CPU
    clock_t debut = clock();

    trouve = false;
    i = 0;
    j = nbLigne-1;

    while(i <= j && !trouve)
    {
        if (atoi(tabAdresse[(j+i)/2].cp) == atoi(sujet))
        {
            trouve = true;
        }
        else
        {
            if (atoi(tabAdresse[(j+i)/2].cp) > atoi(sujet))
            {
                j = (j+i)/2 - 1;
            }
            else
            {
                i = (j+i)/2 + 1;
            }
        }
    }
    //Deuxième compteur de tick CPU
    clock_t fin = clock();

    //Enregistrement
    enregistrementMesureTri(nbLigne, fin-debut, nom_fichier, auto_save);
    free(nom_fichier);

    return trouve;
}
