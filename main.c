#include <stdio.h>
#include <string.h>

typedef struct 
{   
    char nom[50];
    char prenom[50];
    int age;
    double moyenne;
} etudiant ;

int main(){
    etudiant list[1000];
    int choix;
    int i;
    int nbr_etudiant=0;
    do
    {
        printf("\n=== Gestionnaire d'Étudiants ===\n");
        printf("1. Ajouter un étudiant\n");
        printf("2. Afficher les étudiants\n");
        printf("3. Rechercher un étudiant\n");
        printf("4. Supprimer un étudiant\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);
        switch(choix){
            case 1 : 
            ajouter_etudiant(list,&nbr_etudiant);
            break;
            case 2:
            afficher_etudiant(list,&nbr_etudiant);
            break;
            case 3:
            chercher_etudiant(list,&nbr_etudiant);
            break;
            case 4:
            supprimer_etudiant(list,&nbr_etudiant);
            break;
            case 5:
            printf("Au revoir !");
            break;
            default: printf("choix unvalide ");
        }


    }while(choix!=5);
}