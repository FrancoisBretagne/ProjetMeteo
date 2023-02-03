#!/bin/bash

t=0                         #On entre des variable qu'on initialise à 0
p=0
h=0
m=0
F=0
G=0
S=0
A=0
O=0
Q=0
reg=0
ABR=0
TAB=0
AVL=0
file="file"

while [ $# -ne 0 ]         # Tant que tous les arguments n'ont pas été lu, faire le case
do
	case $1 in          
	"-t1") t=1 k=$((k+1))		#si -t1 est un argument donner la valeur 1 à t et k s'incrémente
	shift;;			# on utilse shift pour analyser l'argument suivant si on rentre dans l'argument -t1
	"-t2") t=2 k=$((k+1))		#si -t2 est un argument donner la valeur 2 à t et k s'incrémente
	shift;;
	"-t3") t=3 k=$((k+1))		#si -t3 est un argument donner la valeur 3 à t et k s'incrémente
	shift;;
	"-p1") p=1 k=$((k+1))		#si -p1 est un argument donner la valeur 1 à p et k s'incrémente
	shift;;
	"-p2") p=2 k=$((k+1))		#si -p2 est un argument donner la valeur 2 à p et k s'incrémente			#Ici on incrémente k pour savoir combien d'arguments sont rentrés dans le programme
	shift;;
	"-p3") p=3 k=$((k+1))		#si -p3 est un argument donner la valeur 3 à p et k s'incrémente
	shift;;
	"-w") w=1 k=$((k+1))		#si -w est un argument donner la valeur 1 à w et k s'incrémente
	shift;;
	"-h") h=1 k=$((k+1))		#si -h est un argument donner la valeur 1 à h et k s'incrémente
	shift;;
	"-m") m=1 k=$((k+1))		#si -m est un argument donner la valeur 1 à m et k s'incrémente
	shift;;
	"-d<*><*>") d=1		#si la date est mise dans les arguments alors donner la valeur 1 à d et k s'incrémente
	shift;;
	-"ABR") ABR=1
	shift;;
	-"Tab") Tab=1
	shift;;
	-"AVL") AVL=1
	shift;;
	"-F") reg=F			#si -F est un argument donner la lettre/valeur F à reg
	shift;;
	"-G") reg=G			#si -G est un argument donner la lettre/valeur G à reg
	shift;;
	"-S") reg=S			#si -S est un argument donner la lettre/valeur S à reg
	shift;;
	"-A") reg=A 			#si -A est un argument donner la lettre/valeur A à reg
	shift;;
	"-O") reg=O			#si -O est un argument donner la lettre/valeur O à reg
	shift;;
	"-Q") reg=Q 			#si -Q est un argument donner la lettre/valeur Q à reg
	shift;;	
	"-f") file=$2			# ici on associe file à l argument derrière l'argument -f grâce à $2. Ici $file sera donc associé au nom du fichier.
	shift 2;;			
	*) echo Vous avez rentré un ou plusieurs mauvais arguments. Veuillez recompiler le programme       #ici * implique que si un autre argument que ceux proposé est rentré alors nous sortons du programme
	   exit 1;;
	esac   #on ferme le case
done	       #on ferme le do et donc le while
	

case $reg in       # si reg comme definie précédement est égale à une des lettres associés plus tôt on fait la commande indiquée
	"F") echo "Files for France downloading" 	#-F à été rentrée, donc reg à été associé à F donc ici on rentre dans la boucle F
	     awk -F ';' '$1 < 8000' $file > FinalWether.csv	#ici on prend la première colone du fichier-->$file et on regarde si la station est inférieur à 8000 donc les données pour la France pour la 									copié dans un fichié FinalWethe	 
	;;
	"G") echo "Files for Guyana downloading"	#-G à été rentrée, donc reg à été associé à G donc ici on rentre dans la boucle G
	     awk -F ';' '$1 < 82000 && $1 >81000' $file > FinalWether.csv	#ici on prend la première colone du fichier-->$file et on regarde si la station est inférieur à 82000 et supérieur à 81000 donc 											des données pour la Guyanne pour la copié dans un fichié FinalWethe
	;;
	"S") echo "Files for Saint Pierre and Miquelon downloading"	#-S à été rentrée, donc reg à été associé à S donc ici on rentre dans la boucle S
	     awk -F ';' '$1 = 71805' $file > FinalWether.csv	    #ici on prend la première colone du fichier-->$file et on regarde si la station est égale à 71805, les données pour Saint Pierre and Miquelon 										pour la copié dans un fichié FinalWethe
	;;
	"A") echo "Files for Antilles downloading"				#-A à été rentrée, donc reg à été associé à A donc ici on rentre dans la boucle A
	     awk -F ';' '$1 < 79000 && $1 > 78000' $file > FinalWether.csv	#ici on prend la première colone du fichier-->$file et on regarde si la station est inférieur à 79000 et supérieur à 78000 donc 											des données pour les Antilles pour la copié dans un fichié FinalWethe
	;;
	"O") echo "Files for Indien ocean downloading"			#-O à été rentrée, donc reg à été associé à O donc ici on rentre dans la boucle O
	     awk -F ';' '$1 < 62000 && $1 >61000' $file > FinalWether.csv	#ici on prend la première colone du fichier-->$file et on regarde si la station est inférieur à 62000 et supérieur à 61000 donc 											des données pour l'océan Indien pour la copié dans un fichié FinalWether
	;;
	"Q") echo "Files for Antarctiques downloading"		#-Q à été rentrée, donc reg à été associé à Q donc ici on rentre dans la boucle Q
	     awk -F ';' '$1 = 89642' $file > FinalWether.csv		#ici on prend la première colone du fichier-->$file et on regarde si la station est égale 89642, les données pour l'Antarctique pour la 										copié dans un fichié FinalWethe
	;;   #on utilise le -F ';' parce que le point virgule marque la séparation des donnés 
esac

	
for ((i=0;i<$k;i++))   #ici on fait une boucle for avec notre k donc le nombre d'argument rentré préalablement 
do
	if [ $t -eq 1 ]; then # si notre t=1 (arg -t1)
		cut -d ';' -f1,11 FinalWether.csv > Temperature.csv 
		t=0						      #pour réinitialiser le t
							              #on copie la colonne 1 et 11 du fichier FinaleWether ( le fichier découpé par rapport aux régions type france) pour la copié dans un 								      nouveau fichier température. On à donc séparer l'arg -t1 en fonction de la région demandée
		./exe Temperature.csv    			      #On envoie le fichier temperature vers le programme c
	elif [ $t -eq 2 ]; then
	        cut -d ';' -f2,11 FinalWether.csv > Temperature.csv 
	        t=0						        #pour réinitialiser le t
	        							#on copie la colonne 2 et 11 du fichier FinaleWether ( le fichier découpé par rapport aux régions type france) pour la copié dans un 						      				nouveau fichier température. On à donc séparer l'arg -t2 en fonction de la région demandée
		./exe Temperature.csv      				#On envoie le fichier temperature vers le programme c
	elif [ $t -eq 3 ]; then
	        cut -d ';' -f1,2,11, FinalWether.csv > Temperature.csv
	        t=0							 #pour réinitialiser le t
	         							 #on copie la colonne  1, 2 et 11 du fichier FinaleWether ( le fichier découpé par rapport aux régions type france) pour la copié dans un 								         nouveau fichier température. On à donc séparer l'arg -t3 en fonction de la région demandée
	        ./exe Temperature.csv       				 #On envoie le fichier temperature vers le programme c	
	elif [ $p -eq 1 ]; then
	        cut -d ';' -f1,7 FinalWether.csv > Pression.csv 
	        p=0 						  #pour réinitialiser le p
	        						  #on copie la colonne 1 et 7 du fichier FinaleWether ( le fichier découpé par rapport aux régions, type france) pour la copié dans un nouveau 									  fichier température. On à donc séparer l'arg -p1 en fonction de la région demandée
	        ./exe Pression.csv Data_Pression.csv $f $o      #On envoie le fichier Pression vers le programme 	
	elif [ $p -eq 2 ]; then
	        cut -d ';' -f2,7 FinalWether.csv > Pression.csv 
	        p=0						  #pour réinitialiser le p
	        						  #on copie la colonne 2 et 7 du fichier FinaleWether ( le fichier découpé par rapport aux régions type france) pour la copié dans un nouveau 									  fichier température. On à donc séparer l'arg -p2 en fonction de la région demandée
	        ./exe Pression.csv       			  #On envoie le fichier Pression vers le programme c
	elif [ $p -eq 3 ]; then
	        cut -d ';' -f1,2,7 FinalWether.csv > Pression.csv 
	        p=0						    #pour réinitialiser le p
	        						    #on copie la colonne 1, 2 et 11 du fichier FinaleWether ( le fichier découpé par rapport aux régions type france) pour la copié dans un 								            nouveau fichier température. On à donc séparer l'arg -p3 en fonction de la région demandée
	        ./exe Pression.csv 			            #On envoie le fichier Pression vers le programme c
	elif [[ $w -eq 1 ]]; then
	        cut -d ';' -f1,4,5 FinalWether.csv > Wind.csv 
	        w=0						#pour réinitialiser le w
	        						#on copie la colonne 1, 4 et 5 du fichier FinaleWether ( le fichier découpé par rapport aux régions type france) pour la copié dans un nouveau 								        fichier température. On à donc séparer l'arg -w en fonction de la région demandée
	        ./exe Wind.csv 		               #On envoie le fichier Wind vers le programme c
	elif [ $h -eq 1 ]; then
	        cut -d ';' -f1,14 FinalWether.csv > Altitude.csv 
	        h=0						   #pour réinitialiser le h
	        						   #on copie la colonne 1 et 14 du fichier FinaleWether ( le fichier découpé par rapport aux régions type france) pour la copié dans un nouveau  									   fichier température. On à donc séparer l'arg -h en fonction de la région demandée
	       ./exe Altitude.csv 			          #On envoie le fichier Altitude vers le programme c
	elif [ $m -eq 1 ]; then
	        cut -d ';' -f1,6 FinalWether.csv > Humidity.csv 
	        m=0						  #pour réinitialiser le m
	        						  #on copie la colonne 1 et 6 du fichier FinaleWether ( le fichier découpé par rapport aux régions type france) pour la copié dans un nouveau 									  fichier température. On à donc séparer l'arg -m en fonction de la région demandée
	        ./exe Humidity.csv 			         #On envoie le fichier Humidity vers le programme c
	fi
done










