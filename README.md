# Présentation

Ce code fait partie du projet d'identification d'auteurs, partie feature engineering.

Cette partie a été réalisée par Arnaud Stiegler, Basile Confavreux, Luca Ganassali, Paul Vardon et Clément Jumel


# Fonctionnement

Ce code prend en entrée des textes issus d'une base de donnée (ici la base de donnée Gutenberg), et écrit dans un fichier csv "results.txt" situé à la racine du projet, les vecteurs de features de chaque test, ce qui servira par la suite de données d'entraînement pour le projet.

Il peut aussi écrire dans un fichier "testResult.txt" les features associés à un texte d'intérêt, typiquement un texte dont on voudrait déterminer l'auteur.


# Structure du code

Ce code contient 3 classes et 2 fichiers .cpp indépendants :

## La classe text
La classe text gère les textes récupérés dans la base de donnée. Chaque texte est caractérisé notamment par un titre et un auteur (chacun étant caractérisé à la fois par un string et un id), et une liste de blocs, blockList, représentant le contenu du texte sous forme de liste de blocs.

Cette classe contient différentes fonctions (constructeurs,...), et notamment :
- la fonction parseTextToBlock, qui fractionne le texte en blocs et crée la liste de blocs
- la fonction agregate qui rassemble les features de chaque bloc pour créer les features de chaque texte

## La classe block
La classe block représente les blocs, c'est-à-dire les fragments de textes issus de la classe text. Chaque bloc est caractéristé par un id et sont contenu, textUnit, sous forme de vecteur de charactères, et par des champs correspondant aux features du bloc (int, float, vecteurs).

Cette classe contient différentes fonctions : des constructeurs et des fonctions update, qui sont chargées de calculer la valeur d'une feature (nombre de mots, de phrases dans le bloc par exemple), et de mettre à jour le champ du bloc correspondant.

Les features utilisées sont :
- wordCount : nombre de mots
- sentenceCount : nombre de phrases
- charFrequency : nombre d'apparition de chaque charactère individuel
- differentWordsCount : nombre de mots différents utilisés
- unicWordsCount : nombre de mots utilisés une et une seule fois
- wordFrequency : nombre d'apparition de chacun des 100 mots les plus courants en Anglais
- subordinationsCount : nombre d'apparition de conjonctions de subordination
- wordLengthDeviation : écart type de la longueur des mots
- sentenceLengthDeviation : écart type de la longueur des phrases

## La classe feature
La classe features, qui contient les features de chaque texte et des fonctions createcsv permettant d'écrire ces features dans des fichiers csv qui servent de résultats pour cette partie du projet.

## Le fichier buildtext.cpp
Ce fichier contient les 2 fonctions qui vont écrire les résultats et qui seront appelées par le main :

- La fonction createtxtFile : elle lance le calcule des features pour chaque texte (sur un total de nbiterations textes, qui peut aller jusqu'à 594 pour l'entraînement complet), puis écrit les vecteurs de features obtenus pour dans un fichier csv.

- La fonction preprocessingTest : elle lance le calcule des features d'un texte de test, puis écrit le vecteur de features obtenu dans un fichier csv.

## Le fichier main.cpp
Ce fichier appelle d'abord la fonction createtxtFile pour créer les données d'entraînement à partir des textes de la base de donnée, dans le fichier csv "results.txt" situé à la racine du projet. L'entraînement se fait sur nbiteration textes (594 pour l'entraînement complet).

Ce fichier peut aussi appeler preprocessingTest qui sert à déterminer les features d'un texte dont on voudrait connaître l'auteur ; ces features sont écrites dans le fichier csv "testResult.txt" situé à la racine du projet.
