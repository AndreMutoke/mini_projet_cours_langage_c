// Creer utype des donnees Personnes;
// ON va utiliser une structure ou nous ceer un nouveau type

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
// Creation de la structure Personne

// 1 ere question
struct Personne
{
    char nom[30];
    char num_telephone[10];
};
//Creation d'un nouveau type de donnes Personne
typedef struct Personne Personne;

 // 2eme Question : Creation d'un tableau des personnes nome Annuaire
 // Avec une fixe prede finie.
 Personne Annuaire[300];// L'annuaire est global et on acces de partout
 // Faire une fonction qui nous permet d'inserer un nom et num dans la structure personne
 // Accesseur

 Personne setNumberAndNom(char *nom, int tailleNom, char *num, int tailleNum)
 {
     Personne P;
     // Tout les caractere dans Nom on lss mets dans P.nom
     for(int i=0; i<tailleNom; i++)
     {
         P.nom[i] = nom[i];
     }
     // Tout les caractere dans Num on lss mets dans P.num_telephone
     for(int i=0; i<tailleNum; i++)
     {
         P.num_telephone[i] = num[i];
     }
    return P;
 }
 // Initiliser le tableau
 void initialiserAnnuaire(Personne *annuaire, int tailleAnnuaire)
 {
     Personne A;
     for(int i=0; i<tailleAnnuaire; i++)
     {
         /*[i].nom = '\0';
         annuaire[i].num_telephone = '\0';*/

         A = annuaire[i];
         A = setNumberAndNom("0", 1, "0", 1);//[maman][lulu][andre][0][0]......
         annuaire[i] = A;
     }
 }


 // Creation d'une fonction minisculeToMajiscule
 char minisculeToMajisculeofChar(char c)
 {
     if(c>='a' && c<='z')
     {//c c'est une miniscule

         return (c-32);//la majiscule de c c'est de faire c-32
     }
     return c;
 }
void minisculeToMajisculeOfString(char *chaine, int tailleChaine)
{
    char l;
    for(int i=0; i<tailleChaine; i++)
    {
        l = chaine[i];
        chaine[i] = minisculeToMajisculeofChar(l);
    }
}
 //bool n'est pas dans le header <stdio.h>
 // bool se trouve dans le header <stdbool.h> et on va l'inclure
 bool compareCaracteres(char c1, char c2)
 {
     return (c1 == c2) ? true : false;
 }

 bool compareNomDansAnnuaire(Personne *annuaire, int tailleAnnuaire, char *nom, int tailleNom, char *num, int tailleNum)
 {
     bool comparaison = false;
     //On transforme le nom en majiscule par mesure de prudence
     Personne P;
     minisculeToMajisculeOfString(nom, tailleNom);
     for(int i=0; i<tailleAnnuaire; i++)
     {
         P = annuaire[i];
         // On va verifier si les deux chaines de caracteres on la meme taille
         int taillePersonneAnnuaire = strlen(P.nom);
         if(taillePersonneAnnuaire == tailleNom)
         {
             // Le nom est probable d'etre a cette position
             //char l[taillePersonneAnnuaire];
             //strcpy(l, P.nom[i])
             int compteur=0;
             for(int j=0; j<tailleNom; j++)
             {
                 if(compareCaracteres(P.nom[j], nom[j]))
                     compteur++;
             }
             if(compteur==tailleNom)
             {
                 // On va changer le numero de telephone;
                 // On va utiliser la fonction strcpy() de string.h
                 strcpy(P.num_telephone, num);
                 annuaire[i] = P;
                 goto sortie;

             }

         }
         // On passe a la position suivante
     }
     sortie:
         comparaison = true;
         return comparaison;
         //break;

     return comparaison;
 }
 void Ajoute(Personne *annuaire, int tailleAnnuaire, char *nom, int tailleNom, char *num, int tailleNum)
 //           ------La ou on veut ajouter-------- ; -------------Ce qu'on veut ajouter----------------
 {
     // Verifions si le nom de la personne est dans l'annuaire
     //Personne P;
     if(!(compareNomDansAnnuaire(annuaire, tailleAnnuaire, nom, tailleNom, num, tailleNum)))
     {
        // Ajout d'un nouvel element
        Personne Q, P;
        Q = setNumberAndNom("0", 1, "0", 1);
        for(int i=0; i<tailleAnnuaire; i++)
        {
            P = annuaire[i];
            if(P.nom == Q.nom)
            {
                P = setNumberAndNom(nom, tailleNom, num, tailleNum);
                annuaire[i] = P;
                break;
            }
        }

     }
 }

 int Acquisition(Personne *annuaire, int tailleAnnuaire)// Doit prendre en parametre l'annuaire et sa taille
 {

     char nom[31], num[11];// Le numero c'est une chaine de caractere pour pouvoir prendre en compte le Zero du but
     // 0828643788---> 828643788 si c'est un entier
     // 0828643788  ----> '0', '8' , '2', '8','6', '4', '3', '7', '8', '8' si c'est un char[];
     int tailleNom, tailleNum;

     printf("ENtrez votre nom : ");
     scanf("%s", nom);
     printf("Entrez votre numero de telephone : ");
     scanf("%s", num);
     tailleNom = strlen(nom);
     tailleNum = strlen(num);
     // -34, -23, +3547

     if((tailleNom<=30) && (tailleNum == 10))
     {
         // On verifie si le premier caractere du numero de telephon  est different "-"
         // On verifie si le premier caractere du numero de telephon  est comparable a 0
         if(num[0] == '0')
         {
             // On va executer et verifier une autre condition
             //et on retourne 1
             if(num[1] == '8' || num[1]== '9')
             {
                 // Onverifie si le reste des caracteres sont des chiffres compris entre 0 et 9
                 for(int i=2; i<tailleNum; i++)
                 {
                     //_________________________________________
                     // Normalement num[i]>= '0' && num[i]<= '9' ==> num[i] < '0' || num[i] > '9'
                     if(num[i] < '0' || num[i] > '9')
                     {
                         goto sortie;
                     }
                     // Tout les caracteres respectent les normes
                     // Une fonction f(nom, tailleNom, num, tailleNum, ....)
                     // Ici il y aura la fontion ajouter
                 }
                 return 1;
             }
             sortie :
                 printf("Desole, le numero ne respecte pas les regles\n");
                return 0;
         }

         //Oublier tout
         //return 0;
     }
     printf("Desole vous ne pouvez inserer un nom de plus de 30 caractere ou un numero ayant un nombre inferieur  ou superieur a 10\n");
    return 0;
 }


 int main()
 {

     return 0;
 }

