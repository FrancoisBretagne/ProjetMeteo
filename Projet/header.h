#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//définition des différentes structures pour les 3 types de tri.
//structure ABR

typedef struct Tree{
    float data;
    struct Tree* rightnext;
    struct Tree* leftnext;
}Tree;
//structure liste chainée
typedef struct Node{
    float data;
    struct Node* next;
}Node;

//structure AVL
typedef struct TreeAVL{
    float data;
    int equilibre; 
    struct TreeAVL *filsD; 
    struct TreeAVL *filsG;
}TreeAVL;


//fonctions pour le tri ABR
Tree* CreateT(float a);
Tree* RecinsertABR(Tree* head, float val);
int nbrligne(FILE* B);
void PrefixLengthBrowse(Tree* head, FILE* output_file);

//fonctions pour le tri de listes chainées
Node* Beinsert(Node* head,float a);
Node* Endinsert(Node* head, float a);
Node* PrintN(Node* head,FILE* output_file);
Node* ajouterDecroissant(Node* head, float a) ;

//fonctions pour le tri AVL
TreeAVL* CreerNoeud(float a);
TreeAVL* InsertionAVL ( TreeAVL* head, int* h, int a);
TreeAVL* rotationGauche(TreeAVL* a);
TreeAVL* rotationDroite(TreeAVL* a);
TreeAVL* doubleRotationGauche(TreeAVL* a);
TreeAVL* doubleRotationDroite(TreeAVL* a);
TreeAVL* equilibrerAVL(TreeAVL* a);


int wind(FILE* fichier, FILE* output_file, int Typedetri);
int humidity(FILE* fichier, FILE* output_file, int Typedetri);
int pression(FILE* fichier, FILE* output_file, int Typedetri);
int temperature(FILE* fichier, FILE* output_file, int Typedetri);
int altitude(FILE* fichier, FILE* output_file, int Typedetri);