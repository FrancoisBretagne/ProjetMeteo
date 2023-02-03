#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"header.h"


FILE* main(int argc, char* argv[]) {
    char* t,*m,*h,*p,*w;
    int retour;
    int Typedetri=1;
    FILE* fichier;
    FILE* output_file;
    //printf("argv[3]=%s",argv[3]);
    // regarde si le nombre d'arguments est bien correct.
    if (argc == 6) {
        printf("Format: <chemin du fichier> <nom du fichier> <tableau> <donnee> <date> <lieu>\n");
    }
     retour=wind(fichier,output_file,  Typedetri);
    //Pour choisir entre tab abr et avl
        /*if(argv[4]=='w'){
                 wind(fichier,output_file,  Typedetri);
        }
        else if(argv[4]=='h'){
                 humidity(fichier,output_file,  Typedetri);
        }
        else if(argv[4]=='t'){
                 temperature(fichier,output_file,  Typedetri);
        }
        else if(argv[4]=='p'){
                 pression(fichier,output_file,  Typedetri);
        }
        else if(argv[4]=='m'){
                 altitude(fichier,output_file,  Typedetri);
        }*/
   /* switch( argv[3] ){//en fonction de l'argument 3, alors
            case abr://si l'argument est abr alors type de tri egale 1
                Typedetri=1;
                    break;
            case tab://si l'argument est tab alors type de tri egale 2
                Typedetri=2;
                    break;
            case avl://si l'argument est avl alors type de tri egale 3
                Typedetri=3;
                    break;
            default:
                    Typedetri=1;
                    break;
    }*/
    // pour ouvrir la fonction par rapport au type de donnes demandees
    /*switch( argv[4] ){
        case t:
                temperature(fichier,output_file,  Typedetri);
                break;
        case p:
                pression(fichier,output_file, Typedetri);
                break;
        case w:
                wind(fichier,output_file,  Typedetri);
                break;
        case m:
                altitude( fichier,  output_file,  Typedetri);
                break;
        case h:
                humidity( fichier,  output_file,Typedetri);
                break;
        default:
                    wind(fichier,output_file,Typedetri);
                    break;
                
    }*/
    return 0;
}

