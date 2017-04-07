#include <stdlib.h>
#include "graphes-chevauchement.h"

/**
* \file          main.c
* \author    GILLES Annthomy
* \version   1.0
* \date       16 Février 2017
* \brief        Algorithme de construction d'un graphe de chevauchement
*
* \details    G est un graphe oriente pondere representé par listes d'adjacence un fragment d'ADN attaché à un sommet.
* Il existe un arc de x vers y si il existe un suffixe non vide du fragment attaché à x qui est un prefixe du fragment attaché à y.
* Entrée : nomf, nom d'un fichier texte contenant des fragments d'ADN
* Sortie : G, le graphe de chevauchement
*/


int main(int argc, char *argv[])
{

// le nom du fichier est un parametre lu sur la ligne de commande
    if(argc == 2)
    {
        LISTE_frag S = NULL;
        char *nomf = argv[1];

        // initialisation de S a partir du contenu de nomf
        S=initListeFragments(S, nomf);
        printf("Le fichier contient les fragments:\n");
        afficheListe(S);
        printf("\n");

        // on enleve de S les fragments internes a d'autres fragments
        S=fsd(S);
        printf("Les fragments generes apres fsd sont: \n");
        afficheListe(S);
        printf("\n");

        // on construit le graphe de chevauchement G a partir de S
         GRAPHE mon_graph=nouveauGraphe(tailleListe(S));
         printf("Il y a %d sommets \n",getNbSommets(mon_graph) );
         construitGrapheChevauchement(mon_graph, S);


        // on parcourt G en profondeur et on affiche sur la sortie l'ordre de parcours
        //  sur les sommets
         parcoursEnProfondeur(mon_graph);
         // parcoursEnProfondeur(mon_graph);

    }

    return EXIT_SUCCESS;
}
