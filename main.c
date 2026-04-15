#include <stdio.h>
#include <string.h>

typedef struct 
{   
    char nom[50];
    char prenom[50];
    int age;
    double moyenne;
} etudiant ;

void  ajouter_etudiant(etudiant list[], int *nbr_etudiant);
void ajouter_etudiant(etudiant list[],int *nbr_etudiant ){
    printf("ajouter un etudiant !");
    int i;
    printf("\nNom     : ");
    scanf("%s",list[*nbr_etudiant].nom);
    printf("\nPrenom  : ");
    scanf("%s",list[*nbr_etudiant].prenom);
    printf("\nage     : ");
    scanf("%d",&list[*nbr_etudiant].age);
    printf("\nmoyenne : ");
    scanf("%lf",&list[*nbr_etudiant].moyenne);
    (*nbr_etudiant)++;
    printf("\etudiant ajoutee !");}


void afficher_etudiant(etudiant list[],int *nbr_etudiant){
    printf(" ===Liste etudiant=== ");
    int i;
    if(*nbr_etudiant==0){
        printf("aucun etudiant dans la liste !");
    }
    for(i=0;i<*nbr_etudiant;i++){
        printf("etudiant %d ",i+1);
        printf("\nNom\t%s ",list[i].nom);
        printf("\nPrenom\t%s ",list[i].prenom);
        printf("\nAge\t%d ",list[i].age);
        printf("\nMoyenne\t%.2lf ",list[i].moyenne);
        printf("\n");
        }
}

void chercher_etudiant(etudiant list[],int *nbr_etudiant ){
    char nom[50];
    int trouve=0;
    int i;
    printf("Entrer le nom d etudiant :");
    scanf("%s",nom);
    for(i=0;i<*nbr_etudiant;i++){
    if(strcmp(nom, list[i].nom)==0){
     printf("etudiant %d ",i+1);
        printf("\nNom\t%s ",list[i].nom);
        printf("\nPrenom\t%s ",list[i].prenom);
        printf("\nAge\t%d ",list[i].age);
        printf("\nMoyenne\t%.2lf ",list[i].moyenne);
        printf("\n");
        trouve=1;
        break;}
    }
    if(!trouve){
        printf("aucun etudiant touve !");
    }
}

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