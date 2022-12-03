#include "../header/common.h"

//Fonction de chargement des données
void loadData(Adresse *tabAdresse, int nbDeFois, bool auto_save)
{
    //Variables
    FILE* f = fopen("france.csv", "r");
    int i,j;

    //Saute la première ligne
    fgets(message,180, f);

    //Premier compteur de tick CPU
    clock_t debut = clock();

    //Traitement
    for (i=0;i<nbDeFois;i++)
    {
        //Récupération de la première ligne et déclaration des pointeurs
        fgets(message,180, f);
        char* s = strdup(message);
        char* val = strsep(&s, ",");

        //Saut de longitude - latitude et récupère le numéro
        for(j=0;j<2;j++){val = strsep(&s, ",");}
        tabAdresse[i].numero = val;

        //Récupère le nom de la rue
        val = strsep(&s, ",");
        tabAdresse[i].rue = val;

        //Saut de UNIT et récupères la ville
        for(j=0;j<2;j++){val = strsep(&s, ",");}
        tabAdresse[i].ville = val;

        //Saut des autres colonnes et récupère le code postal
        for(j=0;j<3;j++){val = strsep(&s, ",");}
        tabAdresse[i].cp = val;
    }
    //Deuxième compteur de tick CPU
    clock_t fin = clock();

    //Enregistrement
    enregistrementMesureTri(nbDeFois, fin-debut, "chargement_donnee.csv", auto_save);
    fclose(f);

}
//Fonction de séparation
char *strsep(char **stringp, const char *delim)
{
    char *begin, *end;
    begin = *stringp;
    if (begin == NULL) return NULL;
    end = begin + strcspn (begin, delim);
    if (*end)
    {
        *end++ = '\0';
        *stringp = end;
    }
    else *stringp = NULL;
    return begin;
}
