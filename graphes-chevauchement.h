/** \file graphes-chevauchement.h
* \brief Protoypes des fonctions, macros, constantes et structures.
* \author GILLES Annthomy
* \version 1.0
* \date 16 Février 2017
* \bug Pas de bugs connus.
*/

/*! \def MAX(a,b)
* \brief Une macro qui retourne le maximum de deux valeurs \a a et \a b.
*/
#define MAX(a,b) ((a) > (b) ? a : b)
/*! \def MIN(a,b)
* \brief Une macro qui retourne le minimum de deux valeurs \a a et \a b.
*/
#define MIN(a,b) ((a) < (b) ? a : b)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


/*------------------------------------------------------------------------------------------------*/
/*                                              STRUCTURES                                        */
/*------------------------------------------------------------------------------------------------*/


// definition du type arc
/**
* \struct ELEMENT
* \brief Une structure représentant une liste chainée dont chaque noeud contient
* le poids et la destination.
*/
typedef struct ELEMENT
{
    int poids; /**< poids des arcs  */
    int destination; /**< numero du sommet de destination */
    struct ELEMENT *suivant; /**< pointeur vers une autre structure ELEMENT */
} ELEMENT;

// definition du type LISTE_arc
/**
* \struct LISTE_arc
* \brief Un pointeur vers une struct ELEMENT.
*/
typedef ELEMENT *LISTE_arc ;

//definition du type sommet
/**
* \struct _sommet
* \brief Une structure représentant une liste chainée dont chaque noeud contient un fragment.
*/
struct _sommet
{
    char *fragment;   /**< le fragment attache au sommet*/
    LISTE_arc successeurs; /**< une liste de successeurs */
};

// le type pointeur sur _sommet
/**
* \struct Sommet
* \brief Un pointeur vers une struct _sommet.
*/
typedef struct _sommet *Sommet;


// definition du type graphe pondere
/**
* \struct _GRAPHE
* \brief Une structure représentant un tableau de sommets.
*/
typedef struct _GRAPHE
{
    int nbSommets; /**< nombre de sommets du graphe */
    Sommet *t;    /**< un tableau de sommets indicé de 0 à nbSommets-1 */
} _GRAPHE;

// le type pointeur sur _GRAPHE
/**
* \struct GRAPHE
* \brief Un pointeur vers une struct _GRAPHE.
*/
typedef struct _GRAPHE *GRAPHE;


// definition du type fragment
/**
* \struct fragment
* \brief Une structure représentant une liste chainée de fragments.
*/
typedef struct fragment
{
    char* frag;
    struct fragment *suivant;
} fragment;

// definition du type liste_frag
/**
* \struct LISTE_frag
* \brief Un pointeur vers une struct fragment.
*/
typedef fragment* LISTE_frag;



/*------------------------------------------------------------------------------------------------*/
/*                                PROTOTYPES DES FONCTIONS                                        */
/*------------------------------------------------------------------------------------------------*/

/**
* \fn char* getFragment(Sommet s)
* \brief Retourne le fragment attaché au sommet S.
* \param s Un sommet.
* \return Une chaine de caractère.
*/
char* getFragment(Sommet s);

/**
* \fn LISTE_frag fsd(LISTE_frag S)
* \brief Supprime de la file S toutes les chaines qui sont facteur d'une autre chaine.
* \param S Une \e LISTE_frag.
* \return Un \e LIST_frag correspondant à une file après suppression des facteurs.
*/
LISTE_frag fsd(LISTE_frag S);

/**
* \fn int lplc(char *x, char *y)
* \brief      Compare et calcul la longueur du plus long suffixe d'une chaine qui est un prefixe d'une autre chaine de caractère
* \param x Une chaine de caractères.
* \param y Une chaine de caractères.
* \return Un \e int  correspondant à la longueur du plus long suffixe de x qui est un prefixe de y.
*/
int lplc(char *x, char *y);

/**
* \fn LISTE_frag initListeFragments(LISTE_frag S, char *nomf)
* \brief S est une file initialisé avec les fragments contenus dans le fichier texte passé en argument.
* \param S Une file de chaines de caracteres.
* \param nomf Nom d'un fichier texte contenant des fragments d'ADN.
* \return Un \e LISTE_frag (une file) contenant  l'ensemble des fragments contenus dans le fichier texte nomf.
*/
LISTE_frag initListeFragments(LISTE_frag S, char *nomf);

/**
* \fn void construitGrapheChevauchement(GRAPHE G, LISTE_frag S)
* \brief S Construit un graphe de chevauchement à partir d'une file de chaines de caractères.
* \param G Un graphe ponderée.
* \param S Une file de chaines de caracteres.
* \return Void.
*/
void construitGrapheChevauchement(GRAPHE G, LISTE_frag S);

/**
* \fn void parcoursEnProfondeur(GRAPHE G)
* \brief Parcours en profondeur d'un graphe et affichage sur la sortie.
* \param G Un graphe (un pointeur vers une structure Graphe).
* \return Void.
*/
void parcoursEnProfondeur(GRAPHE G);

/**
* \fn LISTE_frag enfiler(LISTE_frag S,char * fragment)
* \brief Ajout d'un élément dans la file.
* \param S Une file de chaines de caracteres.
* \param fragment Une chaine de caractère à enfiler.
* \return Un \e LISTE_frag enfilé d'un nouveau noeud.
*/
LISTE_frag enfiler(LISTE_frag S,char * fragment);

/**
* \fn void afficheListe(LISTE_frag l)
* \brief Affiche la file.
* \return Void.
*/
void afficheListe(LISTE_frag l);

/**
* \fn int tailleListe(LISTE_frag file)
* \brief      Compte le nombre d'élément de la file
* \param file Un \e LISTE_frag
* \return    Un \e int correspondant à la taille de la file.
*/
int tailleListe(LISTE_frag l);

/**
* \fn LISTE_frag getFragSuivant(LISTE_frag l)
* \brief Retourne le noeud suivant de la file.
* \param l Un \e LISTE_frag
* \return Un pointeur vers une  le noeud suivant d'une \e LISTE_frag (une file).
*/
LISTE_frag getFragSuivant(LISTE_frag l);

/**
* \fn LISTE_frag suppFront(LISTE_frag head)
* \brief Suppression de la tête d'une file.
* \param head Un \e LISTE_frag
* \return Un pointeur vers une \e LISTE_frag (une file) après suppression de la tête.
*/
LISTE_frag suppFront(LISTE_frag head);

/**
* \fn LISTE_frag suppBack(LISTE_frag queue)
* \brief Suppression de la queue d'une file.
* \param queue Un \e LISTE_frag
* \return Un pointeur vers une \e LISTE_frag (une file) après suppression de la tête.
*/
LISTE_frag suppBack(LISTE_frag queue);

/**
* \fn LISTE_frag recherche(LISTE_frag l,char *data)
* \brief      Recherche la valeur d'un noeud
* \param    l Pointeur vers une structure file.
* \param    data Une chaine de caractères.
* \return    Un \e LISTE_frag correspondant à la chaine passée en paramètre.
*/
LISTE_frag recherche(LISTE_frag l,char *data);

/**
* \fn LISTE_frag supprimer(LISTE_frag file,LISTE_frag noeudASupp)
* \brief Supprime un noeud de la file
* \param file Pointeur vers une structure file.
* \param noeudASupp Noeud à supprimer.
* \return Un \e LISTE_frag correspondant à la chaine passée en paramètre.
*/
LISTE_frag supprimer(LISTE_frag file,LISTE_frag noeudASupp);

/**
* \fn int estVideSommet(Sommet s)
* \brief Teste si le sommet est vide.
* \param s Un sommet.
* \return    Un \e int retournant un booléen.
*/
int estVideSommet(Sommet s);

/**
* \fn Sommet nouveauSommet(char *etiq)
* \brief Crée un sommet et attribue le fragment passé en paramètre comme étiquette du sommet.
* \param etiq Une chaine de caractères, une étiquette.
* \return    Un \e Sommet avec le fragment ajouté.
*/
Sommet nouveauSommet(char *etiq);

/**
* \fn void slice_str(char * str, char * buffer, size_t debut, size_t fin)
* \brief Permet d'extraire une sous-chaine de taille définie en paramètre d'une chaine de caractère.
* \param str Une chaine de caractère.
* \param buffer Un tampon qui stockera la sous-chaine de sortie
* \param debut Index du début de la sous-chaine
* \param fin Index de la fin de la sous-chaine
* \return Void.
*/
void slice_str(char * str, char * buffer, size_t debut, size_t fin);

// LISTE_ARC
/**
* \fn int getPoids(LISTE_arc l)
* \brief  Retourne le poids du premier maillon d'une liste non vide
* \param l Une \e LISTE_arc qui représente les successeurs.
* \return Un \e int qui est le poids .
*/
int getPoids(LISTE_arc l);

/**
* \fn int getDestination(LISTE_arc l)
* \brief Retourne la destination du premier maillon d'une liste non vide.
* \param l Une \e LISTE_arc qui représente les successeurs.
* \return Un \e int qui est la destination.
*/
int getDestination(LISTE_arc l);

/**
* \fn LISTE_arc getSuivant(LISTE_arc l)
* \brief Retourne le successeur suivant.
* \param l Une \e LISTE_arc qui représente les successeurs.
* \return Un \e LISTE_arc qui est le noeud suivant.
*/
LISTE_arc getSuivant(LISTE_arc l);

/**
* \fn LISTE_arc ajoutEnTete(LISTE_arc l, int poids, int dest)
* \brief Retourne la liste avec un nouveau maillon en tete de poids p et de destination d
* \param l Une \e LISTE_arc qui représente les successeurs.
* \param poids Le poids.
* \param dest La destination.
* \return Un \e LISTE_arc avec le nouveau maillon ajouté.
*/
LISTE_arc ajoutEnTete(LISTE_arc l, int poids, int dest);

/**
* \fn void afficheListeArc(LISTE_arc l)
* \brief Affiche la liste de successeurs.
* \param l Une \e LISTE_arc qui représente les successeurs.
* \return Void.
*/
void afficheListeArc(LISTE_arc l);

//  GRAPHE
/**
* \fn int estVideGraphe(GRAPHE g)
* \brief Teste si un GRAPHE est vide.
* \param g Un \e GRAPHE.
* \return Un \e booléen.
*/
int estVideGraphe(GRAPHE g);

/**
* \fn GRAPHE nouveauGraphe(int n)
* \brief Crée un graphe a n sommets.
* \param n Nombre de sommet à initialiser.
* \return Un \e GRAPHE avec n sommets.
*/
GRAPHE nouveauGraphe(int n);

/**
* \fn int getNbSommets(GRAPHE g)
* \brief Retourne le nombre de sommets d'un graphe non vide.
* \param g Un \e GRAPHE avec n sommets.
* \return Un \e int du nombre de sommets.
*/
int getNbSommets(GRAPHE g);

/**
* \fn Sommet getSommet(GRAPHE g, int k)
* \brief  Retourne le k-ieme sommet d'un graphe non vide.
* \param g Un \e GRAPHE avec n sommets.
* \param k Un \e int de l'index du sommet à retourner.
* \return Un \e Sommet.
*/
Sommet getSommet(GRAPHE g, int k);

/**
* \fn void nouvelArc(GRAPHE g, int s, int poids,int dest)
* \brief  Ajoute un arc au graphe non vide g.
* \param g Un \e GRAPHE.
* \param s Un \e int de l'index du sommet à retourner.
* \param poids Un \e int du poids de la relation.
* \param dest Un \e int du sommet de destination.
* \return Void.
*/
void nouvelArc(GRAPHE g, int s, int poids,int dest);

/**
* \fn void putEtiquette(GRAPHE g, int k, char* e )
* \brief  Change l'etiquette du k-ieme sommet de g.
* \param g Un \e GRAPHE avec n sommets.
* \param k Un \e int de l'index du sommet à modifier.
* \param e Une chaine de caractères à insérer.
* \return Void.
*/
void putEtiquette(GRAPHE g, int k, char* e );

/**
* \fn char* getEtiquette(GRAPHE g, int k)
* \brief  Retourne l'etiquette du k-ieme sommet de g.
* \param g Un \e GRAPHE avec n sommets.
* \param k Un \e int de l'index du sommet.
* \return Une chaine de caractères.
*/
char* getEtiquette(GRAPHE g, int k);

/**
* \fn void visiteEnProfondeur(GRAPHE g, int s, int* marque)
* \brief  Retourne le k-ieme sommet d'un graphe non vide.
* \param g Un \e GRAPHE avec n sommets.
* \param s Un \e int de l'index du sommet.
* \param marque Un tableau de int.
* \return Void.
*/
void visiteEnProfondeur(GRAPHE g, int s, int* marque);


