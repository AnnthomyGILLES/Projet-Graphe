/** \file graphes-chevauchement.c
* \brief Fonctions.
* \author GILLES Annthomy
* \version 1.0
* \date 16 Février 2017
* \bug Pas de bugs connus.
*/
#include "graphes-chevauchement.h"

/*------------------------------------------------------------------------------------------------*/
/*                                LISTE DE FRAGMENTS LISTE_frag                                   */
/*------------------------------------------------------------------------------------------------*/


/*        Accesseurs          */
LISTE_frag getFragSuivant(LISTE_frag l)
{
    return l->suivant;
}

/*        Affichage          */
void afficheListe(LISTE_frag l)
{
    if(l!=NULL)
    {
        printf("%s,\n",l->frag);
        afficheListe(l->suivant);
    }
}

/*        Manipulation de LISTE_frag           */

LISTE_frag enfiler(LISTE_frag S,char * fragment)
{

    LISTE_frag elem_file=(LISTE_frag)malloc(sizeof(struct fragment));
    elem_file->frag = (char*)malloc((strlen(fragment)+1)*sizeof(char));
    strcpy(elem_file->frag, fragment);
    elem_file->suivant=NULL;

    // Si la file est vide
    if(S==NULL)
    {
        S = elem_file;
        return S;
    }
    else
    { // La file n'est pas vide
        LISTE_frag tete=S;
        // On parcourt entièrement la file.
        while (tete->suivant != NULL)
        {
            tete = tete->suivant;
        }
        //On fait pointer l'élément temporaire vers le nouvel élément créé.
        tete->suivant=elem_file;
        tete=elem_file;
        return S;
    }
}

LISTE_frag recherche(LISTE_frag l,char *data)
{
    //  Cursor pointe vers la tête de liste
    LISTE_frag cursor = l;
    // Parcours la liste
    while(cursor!=NULL)
    {
        // Si la valeur du noeud match avec le fragment recherché
        if(strcmp(cursor->frag,data)==0)
            // Ce noeud est retourné
            return cursor;
        //  Sinon la liste continue d'être parcourue
        cursor = cursor->suivant;
    }
    return NULL;
}


LISTE_frag suppFront(LISTE_frag head)
{
    if(head == NULL)
        return NULL;
    // Stockage de la tête de liste: pointeur vers la tête de la liste.
    LISTE_frag front = head;
    // Noeud suivant devient la tête de liste
    head = head->suivant;

    //Le successeur devient NULL
    front->suivant = NULL;
    //Suppression de la tête de liste
    if(front == head)
        head = NULL;
    free(front);
    return head;
}

LISTE_frag suppBack(LISTE_frag queue)
{
    if(queue == NULL)
        return NULL;

    LISTE_frag curseur = queue;
    LISTE_frag back = NULL;
    while(curseur->suivant != NULL)
    {
        back = curseur;
        curseur = curseur->suivant;
    }
    if(back != NULL)
        back->suivant = NULL;

    if(curseur == queue)
        queue = NULL;

    free(curseur);

    return queue;
}

LISTE_frag supprimer(LISTE_frag file,LISTE_frag noeudASupp)
{

    // Si le noeud est en tête
    if(noeudASupp == file)
    {
        //Suppression de la tête de liste
        file = suppFront(file);
        return file;
    }
    // Si le noeud est en queue
    else if(noeudASupp->suivant == NULL)
    {
        //Suppression de la tête de liste
        file = suppBack(file);
        return file;
    }
    else
    {
        // Stockage de la tête de liste
        LISTE_frag tmp = file;
        // Tant que la valeur du fragment A n'est pas celle du fragment B
        while (strcmp(tmp -> suivant -> frag, noeudASupp->frag) != 0)
        {
            // Passage au noeud suivant
            tmp = tmp->suivant;
        }
        // Stockage du noeud X à supprimer
        LISTE_frag tmp2 = tmp->suivant;
        // Le noeud pointera vers le noeud suivant X
        tmp -> suivant = tmp2 -> suivant;
        tmp2->suivant = NULL;
        free(tmp2);
    }
    return file;
}

int tailleListe(LISTE_frag file)
{
    int i = 0;

    while( (file != NULL) )
    {
        i++;
        file = file->suivant;
    }

    return i;
}


/*------------------------------------------------------------------------------------------------*/
/*                                LISTE D'ARCS LISTE_arc                                          */
/*------------------------------------------------------------------------------------------------*/

/*        Accesseurs          */

int getPoids(LISTE_arc l)
{
    return l->poids;
}

int getDestination(LISTE_arc l)
{
    return l->destination;

}

LISTE_arc getSuivant(LISTE_arc l)
{
    return l->suivant;
}

/*        Affichage          */
void afficheListeArc(LISTE_arc l)
{
    if(l!=NULL)
    {
        printf("\tPoids: %d, destination : %d \n",getPoids(l),getDestination(l));
        afficheListeArc(l->suivant);
    }
}


/*        Manipulation de LISTE_arc           */

LISTE_arc ajoutEnTete(LISTE_arc l, int poids, int dest)
{
    LISTE_arc nouveau_graph=(LISTE_arc)malloc(sizeof(struct ELEMENT));
    nouveau_graph->poids=poids;
    nouveau_graph->destination=dest;
    nouveau_graph->suivant=l;
    return nouveau_graph;
}


/*------------------------------------------------------------------------------------------------*/
/*                                                SOMMETS                                         */
/*------------------------------------------------------------------------------------------------*/

int estVideSommet(Sommet s)
{
    return s == NULL;
}

Sommet nouveauSommet(char *etiq)
{
    Sommet s=(Sommet)malloc(sizeof(struct _sommet));
    s->fragment=etiq;
    s->successeurs=NULL;
    return s;

}

int estVideGRAPHE(GRAPHE g)
{
    return g == NULL;
}

Sommet getSommet(GRAPHE g, int k)
{
    if(!estVideGRAPHE(g))
    {
        return g->t[k];
    }
    return NULL;
}

char* getFragment(Sommet s)
{
    if(! estVideSommet(s))
    {
        return s->fragment;
    }
    return NULL;
}

/*------------------------------------------------------------------------------------------------*/
/*                                                GRAPHE                                          */
/*------------------------------------------------------------------------------------------------*/

int getNbSommets(GRAPHE g)
{
    return g->nbSommets;
}


GRAPHE nouveauGraphe(int n)
{
    GRAPHE g=(GRAPHE)malloc(sizeof(GRAPHE));
    g->nbSommets=n;
    g->t=(Sommet*)malloc((size_t)n*sizeof(Sommet*));
    for(int k=0; k<n; k++)
    {
        g->t[k]=nouveauSommet(NULL);
    }
    return g;
}

void nouvelArc(GRAPHE g, int s, int poids,int dest)
{
    g->t[s]->successeurs= ajoutEnTete(g->t[s]->successeurs,poids,dest);
}

void putEtiquette(GRAPHE g, int k, char* e )
{
    g->t[k]->fragment=e;
}

char* getEtiquette(GRAPHE g, int k)
{
    return getSommet(g,k)->fragment;
}


/*------------------------------------------------------------------------------------------------*/
/*                              CONSTRUCTION DU GRAPHE DE CHEVAUCHEMENT                           */
/*------------------------------------------------------------------------------------------------*/


void slice_str(char * str, char * buffer, size_t debut, size_t fin)
{
    size_t j = 0;
    for ( size_t i = debut; i < fin; ++i )
    {
        buffer[j++] = str[i];
    }
    buffer[j] = '\0';
}


int lplc(char *x, char *y)
{
    // Taille des chaines
    int len_x = (int)strlen(x);
    int len_y = (int)strlen(y);
    // Calcul de la chaine la plus courte et la plus longue
    int lmin = MIN(len_x, len_y);
    int lmax = MAX(len_x, len_y);

    char *buffer=(char*)malloc((size_t)lmax * sizeof(char));
    int lplc=0;

    for(int i=len_x-1; i >= lmax-lmin-1; --i)
    {
        size_t fin = strlen(x)-(size_t)i;
        slice_str(y,buffer,0,fin);
        int ret = strcmp(x+i,buffer);
        if (ret==0)
        {
            lplc=(int)strlen(buffer);
        }
    }
    return lplc;
}


LISTE_frag fsd(LISTE_frag S)
{
    LISTE_frag next,frag;
    LISTE_frag current = S;

    // Parcourt la file
    while (current != NULL && current->suivant != NULL)
    {
        next=current;

        while (next->suivant != NULL)
        {
            // Si le noeud suivant est facteur du noeud précédent
            if (strstr(current -> frag,next ->suivant-> frag) != NULL)
            {
                //  Recherche de la chaine dans la file
                frag = recherche(S,next ->suivant-> frag);
                if (frag !=NULL)
                {
                    // Suppression du noeud correspondant
                    S=supprimer(S,frag);
                    current=S;
                    // Si le noeud suivant n'est pas null: utile dans le cas ou la liste ne contiendrait qu'un élément
                    if (current->suivant !=NULL)
                        next=getFragSuivant(current);
                }
            }
            else if (strstr(next ->suivant-> frag,current -> frag) != NULL)
            {
                frag = recherche(S,current -> frag);
                if (frag !=NULL)
                {
                    S=supprimer(S,frag);
                    current=S;
                    // Si le noeud suivant n'est pas null: utile dans le cas ou la liste ne contiendrait qu'un élément
                    if (current->suivant !=NULL)
                        next=current->suivant;
                }
            }
            else
            {   //Sinon passage au noeud suivant
                next=getFragSuivant(next);
            }
        }
        current = getFragSuivant(current);
    }
    return S;
}


LISTE_frag initListeFragments(LISTE_frag S, char *nomf)
{
    FILE* fauto = fopen(nomf, "r");
    LISTE_frag A=S;

    // Initialisation d'une chaine de caractere de taille 100
    char* caracteres = (char*)malloc(100*sizeof(char));

    if (fauto != NULL)
    {
        // Parcourt le fichier ligne par ligne et extraction des fragments
        while(fscanf(fauto, "%s\n", caracteres) != EOF)
        {
            // Allocation memoire selon la taille de fragment
            char* fragment = (char*)malloc((strlen(caracteres)+1)*sizeof(char));
            // Copie de la chaîne
            strcpy(fragment, caracteres);
            // Enfiler
            A=enfiler(A,fragment);
        }
        // Libération de la mémoire
        free(caracteres);
        // Fermeture du fichier;
        fclose(fauto);
        return A;
    }
    else
    {
        printf("Impossible d'ouvrir le fichier");
        return NULL;
    }

}

/*
 * Function: construitGrapheChevauchement
 * ----------------------------
 *  G: Un graphe (un pointeur vers une structure Graphe)
 *  nomf: Nom d'un fichier texte contenant des fragments d'ADN
 */
void construitGrapheChevauchement(GRAPHE G, LISTE_frag S)
{
    if (G==NULL) return;

    printf("Construction du graphe...\n\n");
    int length = tailleListe(S);
    // POur chaque noeud de la file
    for(int i=0; i<length; i++)
    {
        if (S != NULL)
        {
            // Ajout du fragment comme etiquette du sommer
            putEtiquette(G,i,S->frag);
            S=getFragSuivant(S);
        }

    }
    // Pour chaque sommet du graphe G
    for(int i=0; i<getNbSommets(G); i++)
    {


        for(int j=0; j<getNbSommets(G); j++)
        {
            if (j!=i)
            { // Deux mêmes sommets ne sont pas comparés
                // Recherche du sommet correspondant
                Sommet somm_x = getSommet(G,i);
                Sommet somm_y = getSommet(G,j);
                //  Calcul du lplc
                int m = lplc(somm_x->fragment,somm_y->fragment);
                if(m!=0)
                {
                    // Création d'un nouvel Arc
                    nouvelArc(G,i,m,j);
                }
            }

        }

    }
}

/*------------------------------------------------------------------------------------------------*/
/*                                              PARCOURS                                          */
/*------------------------------------------------------------------------------------------------*/

/*
 * Function: visiteEnProfondeur
 * ----------------------------
 *  Visite tous les sommets d'un graphe une fois et une seule
 *  G: Un graphe (un pointeur vers une structure Graphe)
 *  s: index du sommet
 *  marque: marqueur du sommet visité (1) ou non visité (0)
 */
void visiteEnProfondeur(GRAPHE g, int s, int* marque)
{
    // Noeud visité
    marque[s]=1;
    printf("Sommet %d: %s\n",s,getFragment(g->t[s]));
    LISTE_arc successor=g->t[s]->successeurs;
    //  Affiche la liste de successeurs
    afficheListeArc(successor);
    while(successor!=NULL)
    {
        int y = getDestination(successor);
        // Si le noeud n'a pas été visité
        if(marque[y]==0)
        {
            // Visite
            visiteEnProfondeur(g,y,marque);
        }
        successor=getSuivant(successor);
    }
}

/*
 * Function: parcoursEnProfondeur
 * ----------------------------
 *  Parcours en profondeur d'un graphe
 *  G: Un graphe (un pointeur vers une structure Graphe)
 */
void parcoursEnProfondeur(GRAPHE G)
{
    printf("Parcours en profondeur...\n\n");
    int n = getNbSommets(G);
    // Allocation d'un tableau de int à 0;
    int *marque = (int*)calloc((size_t)n,sizeof(int));

    // Pour chaque sommet de G
    for(int k=0; k<n; k++)
    {
        // Si il n'a pas été visité
        if(marque[k]==0)
        {
            visiteEnProfondeur(G,k,marque);
        }
    }

}
