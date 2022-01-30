# Algoprojetetudiant
Algorithmes pour le probleme d'allocation student project
Ce package contient l'algorithme naïf, l'algorithme récursif et l'algorithme génétique pour le problème d'allocation student project en version R et C++. 
Pour tester notre code:

devtools::install_github("zsr1997/Algoprojetetudiant", force = TRUE) 
library(Algoprojetetudiant)
studentProjectScore(10)
#Matrice score de taille 10*10
studentProjectGenetique(mat5,50,0.001)
#Algorithme Génétique pour une matrice score taille 5*5, itération 50 fois, probabilité de mutation 0.01
studentProjectGenetique(mat6,50,0.001)
#Algorithme Génétique pour une matrice score taille 6*6, itération 50 fois, probabilité de mutation 0.01
studentProjectGenetique(mat20,50,0.001)
#Algorithme Génétique pour une matrice score taille 20*20, itération 50 fois, probabilité de mutation 0.01
studentProjectNaive(5,6)
#Algorithme Naïf pour une matrice score taille 5*5, nombre de fois d'exécution 6
studentProjectNaive(4,6)
#Algorithme Naïf pour une matrice score taille 4*4, nombre de fois d'exécution 6

max_score(ord_mat, ord_mat_copy, pairs, chosen_students,indexes,stud_count, S )
#Algorithme récursif pour une matrice de 5*5

Vous pouvez aussi tester nos algorithmes en version C++ sur les C++ compilers.
