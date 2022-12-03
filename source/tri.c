#include "../header/common.h"
void triBulle(Adresse *tabAdresse, int nbLigne, bool auto_save)
{
    //Variable
    int i, j;
    Adresse tempAdresse;

    //Premier compteur de tick CPU
    clock_t debut = clock();

    //Traitement
    for(i=nbLigne-1;i>0;i=i-1)
    {
        for(j=0; j<i;j++)
        {
            if(atoi(tabAdresse[j].cp) > atoi(tabAdresse[j+1].cp))
            {
                //3 oe
                tempAdresse = tabAdresse[j];
                tabAdresse[j] = tabAdresse[j+1];
                tabAdresse[j+1] = tempAdresse;
            }
        }
    }
    //Deuxième compteur de tick CPU
    clock_t fin = clock();



    //Enregistrement
    enregistrementMesureTri(nbLigne, fin-debut, "tri_bulle.csv", auto_save);
}
void triBulleBoustrophedon(Adresse *tabAdresse, int nbLigne, bool auto_save)
{
    //Variables
    int i, j, k;
    bool trie;
    Adresse tempAdresse;

    //Affectation
    trie = false;
    j = nbLigne;
    i = -1;

    //Premier compteur de tick CPU
    clock_t debut = clock();

    //Traitement
    while(!trie && j>i)
    {
        trie = true;
        for(k=i+1;k<j-1;k++)
        {
            if(atoi(tabAdresse[k].cp) > atoi(tabAdresse[k+1].cp))
            {
                tempAdresse = tabAdresse[k];
                tabAdresse[k] = tabAdresse[k+1];
                tabAdresse[k+1]= tempAdresse;
                trie = false;
            }
        }
        j -= 1;
        for(k=j-1;k>i+1;k--)
        {
            if(atoi(tabAdresse[k].cp) < atoi(tabAdresse[k-1].cp))
            {
                tempAdresse = tabAdresse[k];
                tabAdresse[k] = tabAdresse[k-1];
                tabAdresse[k-1]= tempAdresse;
                trie = false;
            }
        }
        i += 1;
    }
    //Deuxième compteur de tick CPU
    clock_t fin = clock();

    //Enregistrement
    enregistrementMesureTri(nbLigne, fin-debut, "tri_bulle_boust.csv", auto_save);
}
void triSelection(Adresse *tabAdresse, int nbLigne, bool auto_save)
{
    //Variables
    int i, j, pg;
    Adresse tempAdresse;

    //Affectation
    i = nbLigne-1;

    //Premier compteur de tick CPU
    clock_t debut = clock();

    //Traitement
    while(i>0)
    {
        pg = 0;
        for(j=0;j<i;j++)
        {
            if(atoi(tabAdresse[j].cp) > atoi(tabAdresse[pg].cp))
            {
                pg = j;
            }
        }
        tempAdresse = tabAdresse[pg];
        tabAdresse[pg] = tabAdresse[i];
        tabAdresse[i] = tempAdresse;
        i -= 1;
    }
    //Deuxième compteur de tick CPU
    clock_t fin = clock();

    //Enregistrement
    enregistrementMesureTri(nbLigne, fin-debut, "tri_selection.csv", auto_save);
}
void triInsertion(Adresse *tabAdresse, int nbLigne, bool auto_save)
{
    //Variables
    int i, j;
    Adresse val;

    //Premier compteur de tick CPU
    clock_t debut = clock();

    //Traitement
    for(i=1;i<nbLigne;i++)
    {
        val = tabAdresse[i];
        j=i;
        while(j>0 && (atoi(tabAdresse[j-1].cp) > atoi(val.cp)))
        {
            tabAdresse[j] = tabAdresse[j-1];
            j -= 1;
        }
        tabAdresse[j] = val;
    }
    //Deuxième compteur de tick CPU
    clock_t fin = clock();

    //Enregistrement
    enregistrementMesureTri(nbLigne, fin-debut, "tri_insertion.csv", auto_save);
}
//Mélangeur de tableau
void melangeTableau(Adresse *tabAdresse, int nbLigne)
{
    srand(time(NULL));
    Adresse tempAdresse;
    int i, nombreAleatoire;
    for(i=0;i<nbLigne;i++)
    {
        nombreAleatoire = rand() % nbLigne;
        tempAdresse = tabAdresse[i];
        tabAdresse[i] = tabAdresse[nombreAleatoire];
        tabAdresse[nombreAleatoire] = tempAdresse;
    }
}

//---------------------TRI RAPIDE--------------------------
//Fonction
void triRapide(Adresse *tabAdresse, int pile[], int nbLigne, bool auto_save)
{
    int top=1, a, b, p;
    pile[0] = 0;
    pile[1] = nbLigne-1;

    //Premier compteur de tick CPU
    clock_t debut = clock();

    while(top>=0)
    {
        a = pile[top-1];
        b = pile[top];
        top -= 2;
        p = partitionTriRapide(tabAdresse, a, b);
        if (p-1 > a)
        {
            pile[top+1] = a;
            pile[top+2] = p-1;
            top += 2;
        }
        if (p+1<b)
        {
            pile[top+1] = p+1;
            pile[top+2] = b;
            top += 2;
        }
    }
    //Deuxième compteur de tick CPU
    clock_t fin = clock();

    //Enregistrement
    enregistrementMesureTri(nbLigne, fin-debut, "tri_rapide.csv", auto_save);
}
//Partition
int partitionTriRapide(Adresse *tabAdresse, int a, int b)
{
    //Variables
    int pivot, j;
    Adresse tempAdresse;

    //Affectation & Traitement
    pivot = a;
    for(j=a+1;j<=b;j++)
    {
        if(atoi(tabAdresse[j].cp) < atoi(tabAdresse[pivot].cp))
        {
            tempAdresse = tabAdresse[j];
            tabAdresse[j] = tabAdresse[pivot+1];
            tabAdresse[pivot+1] = tabAdresse[pivot];
            tabAdresse[pivot] = tempAdresse;
            pivot += 1;
        }
    }
    return pivot;
}

//---------------------TRI BRETON--------------------------
void inverse(Adresse *tabAdresse,int nbLigne, int indiceMax)
{
    Adresse tempAdresse;
    int j=0;
    while (j < indiceMax)
    {
        tempAdresse = tabAdresse[j];
        tabAdresse[j] = tabAdresse[indiceMax];
        tabAdresse[indiceMax] = tempAdresse;
        j++;
        indiceMax--;
    }
}
void inverse2(Adresse *tabAdresse,int nbLigne, int indiceMax)
{
    Adresse tempAdresse;
    int j;
    for(j=0;j<=indiceMax/2;j++)
    {
        if( atoi(tabAdresse[j].cp) != atoi(tabAdresse[indiceMax-j].cp))
        {
            tempAdresse = tabAdresse[j];
            tabAdresse[j] = tabAdresse[indiceMax-j];
            tabAdresse[indiceMax-j] = tempAdresse;
        }
    }
}
int maximum(Adresse *tabAdresse, int nbLigne)
{
    int max = 0, k;
    for(k=0;k<nbLigne;k++)
    {
        if(atoi(tabAdresse[k].cp) > atoi(tabAdresse[max].cp))
        {
            max = k;
        }
    }
    return max;
}

void triBreton(Adresse *tabAdresse, int nbLigne, bool auto_save)
{
    int i, max;

    //Premier compteur de tick CPU
    clock_t debut = clock();

    for(i=nbLigne-1;i>0;i--)
    {
        max = maximum(tabAdresse, i+1);
        inverse2(tabAdresse, nbLigne, max);
        inverse2(tabAdresse, nbLigne, i);
    }

    //Deuxième compteur de tick CPU
    clock_t fin = clock();

    //Enregistrement
    enregistrementMesureTri(nbLigne, fin-debut, "tri_breton.csv", auto_save);

}
//---------------------TRI FUSION--------------------------
void fusion(Adresse *tabAdresse, int nbLigne, int start, int middle, int endt, Adresse *tabFusionAdresse)
{
    int i, j, k;

    for(i=0;i<=nbLigne-1;i++)
    {
        tabFusionAdresse[i] = tabAdresse[start+i];
    }
    i = 0;
    j = middle-start+1;
    k = start;

    while (k<=endt)
    {
        if(i<=middle-start && (j == endt-start+1 || atoi(tabFusionAdresse[i].cp) <= atoi(tabFusionAdresse[j].cp)))
        {
            tabAdresse[k] = tabFusionAdresse[i];
            i++;
        }
        else
        {
            tabAdresse[k] = tabFusionAdresse[j];
            j++;
        }
        k++;
    }
}

void triFusion(Adresse *tabAdresse, int nbLigne, bool auto_save)
{
    int i, m=1;

    //Premier compteur de tick CPU
    clock_t debut = clock();

    while (m <= nbLigne)
    {
        for (i=0; i<nbLigne;i=i+2*m)
        {
            if(i+2*m-1 < nbLigne)
            {
                fusion(tabAdresse, nbLigne, i, i+m-1, i+2*m-1, tabFusionAdresse);
            }
            else
            {
                if(i+m <= nbLigne-1)
                {
                    fusion(tabAdresse, nbLigne,i,i+m-1,nbLigne-1, tabFusionAdresse);
                }
            }
        }
        m = 2*m;
    }
    //Deuxième compteur de tick CPU
    clock_t fin = clock();

    //Enregistrement
    enregistrementMesureTri(nbLigne, fin-debut, "tri_fusion.csv", auto_save);
}
