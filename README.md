# mini_projet_cours_langage_c
Ce projet nous permet d'implementer un programme qui gere une classe d'etudint afin de mairiser le langage c
# MINI PROJET LANGAGE C
========================
## Objectif
Ce projet a pour objectif l'application directe de notions et concepts vu en  cours et TD/TP
## TRAVAIL DEMANDE
1. Definir un type de donnees **Personne** permettant de memoriser les informations relatives a une personne telles  que  nom et son numero de telephone.
2.  Definir un tableau de personnes, de taille fixe, nomme **Annuaire**.
3.  Ecrire une fonction **Acquisition()** qui permet l'acquisition au clavier du nom de la personne et de son numero de telephone. On verifiera dans cette fonction que :
- - Le nom de la personne ne depasse pas 30 caracteres
- - Le numero de telephone est un nombre positif a 10 chiffres qui commence soit par 08 ou soit par 09
Si ces conditions sont verifies, la valeur de retour de la fonction vaut, et  le nom et le numero de la personne sont renvoye au programme appelant. Dans le cas contraire, un message d'erreur est envoye a l'operateur et la valeur de la fonction vaut 0.
4. / Ecrire une fonction **Ajoute()** qui ajoute a Annuaire un nom et un numero de telephone associe.  Si le nom de la personne ne figurait pas dans Annuaire, un nouvel element est ajoute a la liste, s'il figurait deja,  le numero de telephone existant est remplace par le nouveau numero de telephone. Cette fonction doit egalement permettre de mettre a jour l’ordre des elements en fonction de l’ordre alphabetique. Si le tableau est plein, il faudrait proceder a son agrandissement (strategie a definir).
5. Ecrire une fonction **Affiche()** qui affiche le contenu de l'annuaire dans l’ordre alphabetique.
6. Ecrire une fonction **RechercheTel()** qui, pour un nom de personne donne, affiche :
- - son numéro de téléphone si le nom figure dans l'annuaire
- - le message « pas de personne à ce nom » si le nom ne figure pas dans l'annuaire.
7. Écrire une fonction **RechercheNom()** (recherche inversée) qui, pour un numéro de téléphone donné,recherche dans l’annuaire, à quel nom est associé le numéro , affiche :
- - le nom, si le numéro figure dans l'annuaire
- - le message _pas ce numéro dans l'annuaire!_ sinon. 
8.  Écrire une fonction **Efface()** qui, pour un nom de personne donné supprime l’élément de la liste.Si la personne n'existe pas le message «pas de personne avec ce nom» est affiché.
9.  Écrire un programme principal constitué d'un menu permettant :
    1. d'ajouter une personne à l'annuaire
    2. d'afficher le contenu de l'annuaire dans l'ordre alphabétique
    3. de supprimer une personne de l'annuaire
    4. de consulter le numéro de téléphone d'une personne
    5. de trouver à qui appartient un certain numéro 
    6. de sortir du programme
N.B. :  _On supposera qu'il n'y a pas d'homonymes et que chaque personne n’a qu’un numéro de téléphone.
**CONSIGNES A RESPECTER**
========================
- _Ce mini-projet est a realiser exclusivement en binome_
- _Toutes ressemblance fortuite ou volontaires annulera les travaux rendus sans autre forme de procès !_
- _Protéger jalousement vos sources_
- _Veillez à l’originalité et soignez votre réalisation ainsi que les rendus (affichage de résultats)._
- _D’autre part, toute duplication de code sera sanctionnée sévèrement._
- _Vous avez deux semaines à partir de la fin de TD/TP_
- _Le dossier zippé (contenant vos sources, vos tests et résultats de tests) aux noms du binôme sera envoyé par e-mail à Deoel (qui centralise toutes les réalisations)._ 
- _Notez bien, tout dossier envoyé hors délai ne sera pas considéré, quelque soit la raison invoquée._
- _Vous pouvez utiliser les fonctions de la bibliothèque string.h même si nous ne les avons pas étudiées en cours._
