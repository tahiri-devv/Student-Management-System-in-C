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
    printf("Ajouter un etudiant !");
    int i;
    printf("\nNom     : ");
    scanf("%s",list[*nbr_etudiant].nom);
    printf("\nPrenom  : ");
    scanf("%s",list[*nbr_etudiant].prenom);
    printf("\nAge     : ");
    scanf("%d",&list[*nbr_etudiant].age);
    printf("\nMoyenne : ");
    scanf("%lf",&list[*nbr_etudiant].moyenne);
    (*nbr_etudiant)++;
    printf("\nEtudiant ajoute !");
}

void afficher_etudiant(etudiant list[],int *nbr_etudiant){
    printf(" === Liste des etudiants === ");
    int i;
    if(*nbr_etudiant==0){
        printf("Aucun etudiant dans la liste !");
    }
    for(i=0;i<*nbr_etudiant;i++){
        printf("\nEtudiant %d ",i+1);
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
    printf("Entrer le nom de l'etudiant : ");
    scanf("%s",nom);
    for(i=0;i<*nbr_etudiant;i++){
        if(strcmp(nom, list[i].nom)==0){
            printf("\nEtudiant %d ",i+1);
            printf("\nNom\t%s ",list[i].nom);
            printf("\nPrenom\t%s ",list[i].prenom);
            printf("\nAge\t%d ",list[i].age);
            printf("\nMoyenne\t%.2lf ",list[i].moyenne);
            printf("\n");
            trouve=1;
            break;
        }
    }
    if(!trouve){
        printf("Aucun etudiant trouve !");
    }
}

void supprimer_etudiant(etudiant list[],int *nbr_etudiant){
    char etudiant_supp[50];
    int trouve =0;
    printf("Entrer le nom de l'etudiant a supprimer : ");
    scanf("%s",etudiant_supp);
    int i;
    for(i=0;i<*nbr_etudiant;i++){
        if(strcmp(list[i].nom,etudiant_supp)==0){
            for(int j=i;j<*nbr_etudiant-1;j++){
                list[j]=list[j+1];
            }
            (*nbr_etudiant)--;
            trouve=1;
            printf("Etudiant supprime avec succes !");
            return;
        }
    }
    if(!trouve){
        printf("Etudiant introuvable !");
    }
}

int main(){
    etudiant list[1000];
    int choix;
    int i;
    int nbr_etudiant=0;
    do
    {
        printf("\n=== Gestionnaire d'Etudiants ===\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Rechercher un etudiant\n");
        printf("4. Supprimer un etudiant\n");
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
            default: 
                printf("Choix invalide !");
        }

    }while(choix!=5);
}