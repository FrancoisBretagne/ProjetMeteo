#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
//                                             FONCTION POUR LES ABR


//création de la structure de l'ABR
typedef struct Tree{
    float data;
    struct Tree* rightnext;
    struct Tree* leftnext;
}Tree;

//fonction pour créer un arbre
Tree* CreateT(float a){
    Tree* head=malloc(sizeof(Tree));// initialisation de mon arbre par rapport aux variables de la structure Tree
    head->data=a;
    head->rightnext=NULL;
    head->leftnext=NULL;
    return head;
}
//fonction permettant d'inserer récursivement un chainon dans l'ABR
Tree* RecinsertABR(Tree* head, float val){


    if (head==NULL){
        return CreateT(val);//création du chainon au moment ou: head->rightnext est null ou head->leftnext est null
    }
    else if (val <= head->data){// si la valeur est plus petite ou égale à la valeur du chainon alors par récursivité on relance la fonction avec head->leftnext
        head->leftnext = RecinsertABR(head->leftnext, val);
    }
    else if(val > head->data){// si la valeur est plus grande à la valeur du chainon alors par récursivité on relance la fonction avec head->rightnext
        head->rightnext = RecinsertABR(head->rightnext, val);
    }
    return head;
}
//fonction permettant de compter le nombre de ligne du fichier mis en argument
int nbrligne(FILE* B){
    //initialisaiton des variables
    int ligne=0,i;
    char Ligne[200];
    
    while (fgets(Ligne,50000000,B)!=NULL) {//tant que la chaine de caractère n'est pas nulle
        ligne++;//ligne va prendre +1 à chaque fois
    }
    return ligne;
}  

//fonction permettant d'écrire les données des chainons par récursivité dans un fichier mise en variable
void PrefixLengthBrowse(Tree* head, FILE* output_file){
    
    if (head->leftnext!=NULL){//si le fil gauche du chainon n'est pas nul
        PrefixLengthBrowse(head->leftnext,output_file);//alors
    }
    fprintf(output_file,"%f\n",head->data);//écrit la donnée du chainon dans le fichier
    if (head->rightnext!=NULL){//si le fil droit du chainon n'est pas nul
        PrefixLengthBrowse(head->rightnext,output_file);
    }

}
//                                  FONCTION POUR LES LISTE CHAINEES


//création de la structure du chainon
typedef struct Node{
    float data;
    struct Node* next;
}Node;
//création du premier chainon
Node* CreateN(float a){
    Node* new=malloc(sizeof(Node));//initialisation du premier chainon
    if(new==NULL){
        exit(1);
    }
    new->data= a;
    new->next= NULL;
    return new;
}
//fonction d'insertion du chainon au début de la chaine
Node* Beinsert(Node* head,float a){

    Node* new=CreateN(a);//création du chainon
    new->next=head;
    head=new;
    return head;
}
//fonction d'insertion du chainon à la fin de la chaine
Node* Endinsert(Node* head, float a){
	Node* new= CreateN(a);//création du chainon
	// si la liste est vide 
	if(head==NULL){
		head= new ;
	}
	else{
		Node* h=head;//création de la variable chainon
		while(h->next != NULL){//tant le fils du chainon n'est pas nul
			h=h->next;//on avance dans l'arbre pour aller jusqu'au bout
		}
		h->next=new;
	}
	return head;
}
//fonction pour écrire la liste chainée dans le fichier par récursivité
Node* PrintN(Node* head,FILE* output_file){
    if (head->next!=NULL){//tant que le fils du chainon n'est pas nulle on avance dans l'arbre pour aller jusqu'au bout
        PrintN(head->next,output_file);//récursivité de la fonction
    }
    fprintf(output_file,"%f\n",head->data);//on écrit la donnée du chainon dans le fichier
}
//fonction permettant d'ajouter un chainon par ordre croissant
Node* ajouterDecroissant(Node* head, float a) {
	Node* new=CreateN(a);
	Node* h =head;
	if(head==NULL){// si la liste est vide
		head=new;
	}
	else if (head->data <= a) { // dans ce cas il faut placer l'element au début
		head=Beinsert(head,a);
	}
	else{
		//on parcours la liste jusqu'à trouver où doit aller le new élément
		while(h->next!= NULL && h->next->data > a){ 
			h=h->next;
		}
		if(h->next==NULL){ // s'il faut placer le nouvel élément en fin de chaîne
			h->next=new;
		}
		else{ // il faut inserer le maillon en millieu de chaîne, après h
			new->next=h->next;
			h->next = new;
		}
	}
	return head;
}

//                                      FONCTION POUR LES AVL

//création de la structure de l'AVL
typedef struct TreeAVL{
    float data;
    int equilibre; // permet de rééquilibrer l'AVL
    struct TreeAVL *filsD; //fil droit
    struct TreeAVL *filsG; //fil gauche
}TreeAVL;

//fonction pour créér l'AVL
TreeAVL* CreerNoeud(float a){
    TreeAVL* Node = malloc(sizeof(TreeAVL));//initialisation de l'AVL
    Node->data = a;
    Node->equilibre = 0;
    Node->filsD = NULL;
    Node->filsG= NULL;
    return Node;
}

//fonction équilibre



//fonction d'insertion permettant d'inserer les nouveaux chainon de l'AVL
TreeAVL* InsertionAVL ( TreeAVL* head, int* h, int a){
    if ( head==NULL){
        *h=1;
        return CreerNoeud(a);//création d'un chaine de l'AVL
    }
    else if ( a < head->data ){ // si la valeur du nouveau chainon est plus petite que la valeur du chainon ou on se situe
        head->filsG = InsertionAVL (head->filsG, h, a);//alors récursivité de la fonction avec head->filsG
        *h=-*h;
    }
    else if ( a > head->data ){// si la valeur du nouveau chainon est plus grande que la valeur du chainon ou on se situe
        head->filsD = InsertionAVL ( head->filsG, h, a);//alors récursivité de la fonction avec head->filsD
        *h=-*h;
    }
    else{
        *h=0;
        return head;
    }
    if (*h!=0){//rééquilibrage de l'arbre
        head->equilibre = head->equilibre + *h;
        if ( head->equilibre == 0){ 
            *h=0;
        }
        else{
            *h=1;
        }
    }
    return head;
}
//fonction minimum entre 2 entiers
int min(int a, int b)
{
    if (a < b) 
        return a;
    else       
        return b;
}

//fonction maximum entre 2 entiers
int max(int a, int b)
{
    if (a > b) 
        return a;
    else       
        return b;
}

//fonction de rotation 
//si l'arbre n'est pas équilibré alors il faut faire des roations pour le rééquilibrer
TreeAVL* rotationGauche(TreeAVL* a){
    TreeAVL* pivot;
    int eq_a, eq_p;
    pivot = a->filsD;
    a->filsD = pivot->filsG;
    pivot->filsD = a;
    eq_a =  a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - max(eq_p, 0) - 1;
    pivot->equilibre = min( min(eq_a-2, eq_a+eq_p-2), eq_p-1 );
    a = pivot;
    return a;
}
//fonction de rotation 
//si l'arbre n'est pas équilibré alors il faut faire des roations pour le rééquilibrer
TreeAVL* rotationDroite(TreeAVL* a){
    TreeAVL* pivot;
    int eq_a, eq_p;
    pivot = a->filsG;
    a->filsG = pivot->filsD;
    pivot->filsD = a;
    eq_a =  a->equilibre;
    eq_p = pivot->equilibre;
    a->equilibre = eq_a - min(eq_p, 0) + 1;
    pivot->equilibre = max(max(eq_a+2, eq_a+eq_p+2), eq_p+1);
    a = pivot;
    return a;
}
//fonction de double roation gauche pour rééquilibrage
TreeAVL* doubleRotationGauche(TreeAVL* a){
    a->filsD = rotationDroite(a->filsD);
    return rotationGauche(a);
}
//fonction de double roation gauche pour rééquilibrage
TreeAVL* doubleRotationDroite(TreeAVL* a){
    a->filsG = rotationGauche(a->filsG);
    return rotationDroite(a);
}
TreeAVL* equilibrerAVL(TreeAVL* a){//cette fonction permet de rééquilibrer l'arbre avec les fonctions de rotation. La rotation est choisi en fonction de la valeur du nouveau chainon.
    if (a->equilibre >= 2){
        if(a->filsD->equilibre >= 0){
            return rotationGauche(a);
        }
        else{
            return doubleRotationGauche(a);
        }
    }
    if (a->equilibre <= -2){
        if(a->filsG->equilibre <= 0){
            return rotationDroite(a);
        }
        else{
            return doubleRotationDroite(a);
        }
    }
    return a;
}




//fonction pour trier les données de vents
int wind(FILE* fichier, FILE* output_file, int Typedetri){//on prend en arguments le fichier d'entrée, le fichire de sortie et le type de tri qui vaut 1,2 ou 3 en fonction du choix du tri si c'est en tri ABR, liste chainée ou AVL
    int ligne=0,i=1;
    float key,val=0;
    struct Tree *head = NULL;
    struct Node *first = NULL;
    Typedetri=1;


    fichier = fopen("zTest.csv", "r");//on ouvre le fichier qui contient les données
    if (fichier== NULL) {//si le fichier n'existe pas alors 
        printf("Erreur lors de l'ouverture du fichier\n");//
        return 1;
    }
    if(Typedetri!=1&&Typedetri!=2&&Typedetri!=3){// si le type de tri n'est pas, 1,2 ou 3 alors l'argument dans le main n'a pas été pris en compte.
        printf(" erreur, aucun type de tri défini\n");
        return 0;
    }
    else if(Typedetri==1){ //si le type de tri égale à 1 alors on tri avec un ABR
        printf("utilisation d'un ABR\n");
        head=CreateT(val);//création de l'arbre ABR
        while (fscanf(fichier, "%f", &key) != EOF) {// tant que toute les lignes du fichier n'ont pas été traité, on va scanner chaque ligne et rentrer les données dans l'arbre
            ligne++;
            head = RecinsertABR(head, key);//on rentre les données dans l'arbre
        }
        printf("ligne=%d\n",ligne);
        fclose(fichier); // on referme le fichier d'entrée

        output_file = fopen("zretourtest.csv", "w");//on ouvre le fichier de sortie dans lequel non va 
        if (output_file == NULL) {
            printf("Erreur lors de l'ouverture du fichier\n");
            return 1;
        }
        //inorder(head, output_file);
        PrefixLengthBrowse(head,output_file);
    }
    else if(Typedetri==2){//si le type de tri égale à 2 alors on tri avec une liste chainées
        printf("tri par tableau\n");
        first=CreateN(val);//création de la liste chainée
        while(fscanf(fichier, "%f", &key) != EOF) {// tant que toute les lignes du fichier n'ont pas été traité, on va scanner chaque ligne et rentrer les données dans la liste chainées
            ligne++;
            first=Beinsert(first, key);//on rentre les données dans la liste chainées
        }
        printf("ligne=%d\n",ligne);
        fclose(fichier);// on referme le fichier d'entrée

        output_file = fopen("zretourtest.csv", "w");//on ouvre le fichier de sortie
        if (output_file == NULL) {
            printf("Erreur lors de l'ouverture du fichier\n");
            return 1;
        }
        PrintN(first,output_file);//fonction permettant d'écrire les données de la liste chainées dans le fichier csv
        return 0;
    }
    else{
        printf("tri avl\n");printf("utilisation d'un AVL\n");//si le type de tri égale à 3 alors on tri avec un AVL
        head=CreateT(val);
        while (fscanf(fichier, "%f", &key) != EOF) {// tant que toute les lignes du fichier n'ont pas été traité, on va scanner chaque ligne et rentrer les données dans l'AVL
            ligne++;
            head = RecinsertABR(head, key);
        }
        printf("ligne=%d\n",ligne);
        fclose(fichier);// on referme le fichier d'entrée
        output_file = fopen("zretourtest.csv", "w");//on ouvre le fichier de sortie
        if (output_file == NULL) {
            printf("Erreur lors de l'ouverture du fichier\n");
            return 1;
        }
        PrefixLengthBrowse(head,output_file);//fonction permettant d'écrire les données de la liste chainées dans le fichier csv
        return 0;
    }
}

int main(){
    FILE* fichier;
    FILE* output_file;
    int a;
    a=wind(fichier,output_file,1);
}