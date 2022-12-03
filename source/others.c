#include "../header/common.h"
void clear_stdin()
{
    int chaine;
    while (chaine != '\n' && chaine != EOF)
    {
        chaine = getchar();
    }
}

void enregistrementMesureTri(int nbLigne, clock_t temps, char* nom_fichier, bool auto_save)
{
    char *temporaire, *chemin;
    int reponse;
    FILE* fichier;

    temporaire = malloc(sizeof(char));
    chemin = malloc(40*sizeof(char));

    sprintf(chemin, "mesure/%s", nom_fichier);
    fichier = fopen(chemin, "a");

    free(chemin);

    //Affichage des résultats
    printf("Nombre de ligne : %d\n", nbLigne);
    printf("Temps de traitement : %ld\n\n", temps);

    if(auto_save == false)
    {
        anchor_enregistrement : printf("Voulez-vous enregistrer les mesures de tri dans le fichier '%s' ?\n1: Oui\n2: Non\n", nom_fichier);
        scanf("%d", &reponse);
        switch(reponse)
        {
            case 1:
                sprintf(temporaire, "%d,", nbLigne);
                fputs(temporaire, fichier);

                sprintf(temporaire, "%ld,", temps);
                fputs(temporaire, fichier);

                //Retour à la ligne
                fputc('\n',fichier);
                break;
            case 2:
                break;
            default:
                printf("\nMauvaise valeur saisie !\n");
                clear_stdin();
                goto anchor_enregistrement;
                break;
        }
    }
    else
    {
        sprintf(temporaire, "%d,", nbLigne);
        fputs(temporaire, fichier);

        sprintf(temporaire, "%ld,", temps);
        fputs(temporaire, fichier);

        //Retour à la ligne
        fputc('\n',fichier);
    }

    //Libère la case mémoire
    free(temporaire);
    fclose(fichier);
}
