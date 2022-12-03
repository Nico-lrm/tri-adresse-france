#include "../header/common.h"
int main()
{
    bool recherche_dispo, tri_dispo = false;
    int nombreDeLigne, choix, choix_tri, choix_recherche, iteration_recherche, listeTab;
    char *sujet, *nombreDeLigne_Demande;

    sujet = malloc(5*sizeof(char));
    nombreDeLigne_Demande = malloc(8*sizeof(char));

    printf("Programme de chargement, de tri et de recherche - EL GHALI BERRADA & LORMIER NICOLAS\n");
    anchor_selection : printf("\nQue voulez-vous faire ?\n1: Charger des lignes\n2: Trier les lignes actuelles selon le code postal\n3: Melanger les entrees du tableau charge\n4: Rechercher un element du tableau selon le code postal (disponible seulement lorsque le tableau est trie)\n5: Afficher le tableau actuel\n6: Effectuer les mesures (sur 150.000 lignes)\n7: Quitter le programme\nReponse : ");
    scanf("%d", &choix);
    switch (choix)
    {
        case 1:

            anchor_chargement : printf("\nNombre de lignes : ");
            scanf("%s", nombreDeLigne_Demande);
            if(atoi(nombreDeLigne_Demande) == 0)
            {
                printf("\nMauvaise valeur saisie !\n");
                goto anchor_chargement;
            }
            else
            {
                nombreDeLigne = atoi(nombreDeLigne_Demande);
            }
            printf("\nChargement...\n");
            loadData(tabAdresse, nombreDeLigne, false);
            recherche_dispo = false;
            tri_dispo = true;
            printf("\nChargement termine !\n");
            goto anchor_selection;
            break;
        case 2:
            if (tri_dispo)
            {
                anchor_tri : printf("\nQuel algorithme de tri voulez-vous lancer ?\n1: Tri a bulle\n2: Tri a bulle Boustrophedon\n3: Tri Selection\n4: Tri Insertion\n5: Tri Rapide\n6: Tri Breton\n7: Tri Fusion\nChoix du tri : ");
                scanf("%d", &choix_tri);
                switch (choix_tri)
                {
                    case 1:
                        printf("\nTri en cours...\n");
                        triBulle(tabAdresse, nombreDeLigne, false);
                        break;
                    case 2:
                        printf("\nTri en cours...\n");
                        triBulleBoustrophedon(tabAdresse, nombreDeLigne, false);
                        break;
                    case 3:
                        printf("\nTri en cours...\n");
                        triSelection(tabAdresse, nombreDeLigne, false);
                        break;
                    case 4:
                        printf("\nTri en cours...\n");
                        triInsertion(tabAdresse, nombreDeLigne, false);
                        recherche_dispo = true;
                        printf("\nTri termine !\n");
                        break;
                    case 5:
                        printf("\nTri en cours...\n");
                        triRapide(tabAdresse, pile, nombreDeLigne, false);
                        break;
                    case 6 :
                        printf("\nTri en cours...\n");
                        triBreton(tabAdresse, nombreDeLigne, false);
                        break;
                    case 7 :
                        printf("\nTri en cours...\n");
                        triFusion(tabAdresse, nombreDeLigne, false);
                        break;
                    default:
                        printf("\nMauvaise valeur saisie !\n");
                        clear_stdin();
                        goto anchor_tri;
                        break;
                }
                recherche_dispo = true;
                printf("\nTri termine !\n");
            }
            else
            {
                printf("\nIl n'y a pas encore de ligne chargees !\n");
            }
            goto anchor_selection;
            break;
        case 3:
            if (tri_dispo)
            {
                melangeTableau(tabAdresse, nombreDeLigne);
                printf("\nTableau melange !\n");
                recherche_dispo = false;
            }
            else
            {
                printf("\nIl n'y a pas encore de ligne chargees !\n");
            }
            goto anchor_selection;
            break;
        case 4:
            if (tri_dispo)
            {
                if(recherche_dispo)
                {
                    printf("\nEntrez un code postal : ");
                    scanf("%s", sujet);
                    anchor_recherche : printf("\nQuel algorithme de tri voulez-vous lancer ?\n1: Recherche Sequentielle Optimisee\n2: Recherche Sequentielle (nombre d'iteration)\n3: Recherche Dichotomique\nChoix du tri : ");
                    scanf("%d", &choix_recherche);
                    switch(choix_recherche)
                    {
                        case 1:
                            printf("\nRecherche en cours...\n");
                            if (rechercheSequentielle(tabAdresse, nombreDeLigne, sujet, false))
                            {
                                printf("\nLe code postal %s a ete trouve !\n", sujet);
                            }
                            else
                            {
                                printf("\nLe code postal %s n'a pas ete trouve...\n", sujet);
                            }
                            break;
                        case 2:
                            printf("\nRecherche en cours...\n");
                            iteration_recherche = rechercheSequentielleIteration(tabAdresse, nombreDeLigne, sujet, false);
                            if(iteration_recherche > 0)
                            {
                                printf("\nLe code postal %s est present %d fois dans le tableau\n", sujet, iteration_recherche);
                            }
                            else
                            {
                                printf("\nLe code postal %s n'a pas ete trouve...\n", sujet);
                            }
                            break;
                        case 3:
                            printf("\nRecherche en cours...\n");
                            if (rechercheDichotomique(tabAdresse, nombreDeLigne, sujet, false))
                            {
                                printf("\nLe code postal %s a ete trouve !\n", sujet);
                            }
                            else
                            {
                                printf("\nLe code postal %s n'a pas ete trouve...\n", sujet);
                            }
                            break;
                        default:
                            printf("\nMauvaise valeur saisie !\n");
                            clear_stdin();
                            goto anchor_recherche;
                            break;
                    }
                    printf("\nRecherche termine !\n");
                }
                else
                {
                    printf("\nLe tableau n'est pas encore trie.\n");
                }
            }
            else
            {
                printf("\nIl n'y a pas encore de ligne chargees !\n");
            }
            goto anchor_selection;
            break;
        case 5:
            if (tri_dispo)
            {
                for(listeTab=0;listeTab<nombreDeLigne;listeTab++)
                {
                    printf("%s %s %s %s\n", tabAdresse[listeTab].numero, tabAdresse[listeTab].rue, tabAdresse[listeTab].cp, tabAdresse[listeTab].ville);
                }
            }
            else
            {
                printf("\nIl n'y a pas encore de ligne chargees !\n");
            }
            goto anchor_selection;
            break;
        case 6:
            for (listeTab=1; listeTab <= 15; listeTab++)
            {
                nombreDeLigne = 10000*listeTab;
                printf("Chargement des donnees\n");
                loadData(tabAdresse, nombreDeLigne, true);
                printf("Tri a Bulle\n");
                triBulle(tabAdresse, nombreDeLigne, true);
                melangeTableau(tabAdresse, nombreDeLigne);
                printf("Tri a Bulle Boustrophedon\n");
                triBulleBoustrophedon(tabAdresse, nombreDeLigne, true);
                melangeTableau(tabAdresse, nombreDeLigne);
                printf("Tri Selection\n");
                triSelection(tabAdresse, nombreDeLigne, true);
                melangeTableau(tabAdresse, nombreDeLigne);
                printf("Tri Insertion\n");
                triInsertion(tabAdresse, nombreDeLigne, true);
                melangeTableau(tabAdresse, nombreDeLigne);
                printf("Tri Rapide\n");
                triRapide(tabAdresse, pile, nombreDeLigne, true);
                melangeTableau(tabAdresse, nombreDeLigne);
                printf("Tri Breton\n");
                triBreton(tabAdresse, nombreDeLigne, true);
                melangeTableau(tabAdresse, nombreDeLigne);
                printf("Tri Fusion\n");
                triFusion(tabAdresse, nombreDeLigne, true);
                printf("Recherche sequentielle\n");
                rechercheSequentielle(tabAdresse, nombreDeLigne, "60650", true);
                printf("Recherche sequentielle - iterative\n");
                rechercheSequentielleIteration(tabAdresse, nombreDeLigne, "60650", true);
                printf("Recherche dichotomique :\n");
                rechercheDichotomique(tabAdresse, nombreDeLigne, "60650", true);
            }
            free(sujet);
            free(nombreDeLigne_Demande);
            break;
        case 7:
            free(sujet);
            free(nombreDeLigne_Demande);
            break;
        default:
            printf("\nMauvaise valeur saisie !\n");
            clear_stdin();
            goto anchor_selection;
            break;
    }
    return 0;
}
