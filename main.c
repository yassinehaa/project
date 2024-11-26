#include <stdio.h>
#include <string.h>

typedef struct {
    int jour, mois, annee;
}echeance;
typedef struct {
    char titre[100];
    char description[200];
    echeance echeance;
    char pr[10];
} taches;

taches T[100];
int compteurtaches = 0;

void ajouter() {
    printf("Entrer la tache a ajouter\n");

    printf("Titre: ");
    scanf(" %[^\n]", T[compteurtaches].titre);

    printf("Description: ");
    scanf(" %[^\n]", T[compteurtaches].description);

    printf("Echeance: ");
        printf("\n jour: ");
    scanf("%d", &T[compteurtaches].echeance.jour);
        printf("\n mois: ");
    scanf("%d", &T[compteurtaches].echeance.mois);
        printf("\n annee: ");
    scanf("%d", &T[compteurtaches].echeance.annee);

    printf("Priorite (high ou low): ");
    scanf("%s", T[compteurtaches].pr);
    compteurtaches++;
}

void afficher() {
    int i;
        if (compteurtaches == 0) {
        printf("Pas de taches, ajoutez une nouvelle tache.\n");
        return;}
    for (i = 0; i < compteurtaches; i++) {
        printf("--------------------------\n");
        printf("Nom de la tache: %s\n", T[i].titre);
        printf("Description de la tache: %s\n", T[i].description);
        printf("Echeance: %02d-%02d-%04d\n", T[i].echeance.jour,T[i].echeance.mois,T[i].echeance.annee);
        printf("Priorite: %s\n", T[i].pr);
        printf("--------------------------\n");
    }
}

void modifier() {
    int m;
    printf("Entrer le numero de la tache a modifier (1-%d): ", compteurtaches);
    scanf("%d", &m);

    if (m > 0 && m <= compteurtaches) {
            m--;
        printf("Entrer nouveau titre: ");
        scanf(" %[^\n]", T[m].titre);

        printf("Entrer nouvelle description: ");
        scanf(" %[^\n]", T[m].description);

        printf("Entrer nouvelle echeance: ");
        printf("\n jour: ");
    scanf("%d", &T[m].echeance.jour);
        printf("\n mois: ");
    scanf("%d", &T[m].echeance.mois);
        printf("\n annee: ");
    scanf("%d", &T[m].echeance.annee);

        printf("Entrer nouvelle priorite 'high' ou 'low': ");
        scanf("%s", T[m].pr);
    } else {
        printf("Numero de tache invalide.\n");
    }
}

void supprimer() {
    int m, i;
    printf("Entrer le numero de la tache a supprimer (1-%d): ", compteurtaches);
    scanf("%d", &m);
    m--;

    if (m >= 0 && m < compteurtaches) {
        for (i = m; i < compteurtaches - 1; i++) {
            T[i] = T[i + 1];
        }
        compteurtaches--;
    } else {
        printf("Numero de tache invalide.\n");
    }
}

void filtrer() {
    int i;
    char f[20];

    printf("Entrer 'high' ou 'low': ");
    scanf("%s", f);
    for (i = 0; i < compteurtaches; i++) {
        if (strcmp(T[i].pr, f) == 0) {
            printf("Tache: %s\n", T[i].titre);
            printf("Description: %s\n", T[i].description);
            printf("Echeance: %d\n", T[i].echeance);
            printf("Priorite: %s\n", T[i].pr);
        }
    }
}

int main() {
    int choix;

    do {
        printf("\n==============MENU================");
        printf("\n1. Ajouter une tache\n");
        printf("==================================\n");
        printf("2. Afficher la liste des taches\n");
        printf("==================================\n");
        printf("3. Modifier une tache\n");
        printf("==================================\n");
        printf("4. Supprimer une tache\n");
        printf("==================================\n");
        printf("5. Filtrer les taches\n");
        printf("==================================\n");
        printf("6. Quitter\n");
        printf("==================================\n");

        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: ajouter(); break;
            case 2: afficher(); break;
            case 3: modifier(); break;
            case 4: supprimer(); break;
            case 5: filtrer(); break;
            case 6: printf("Programme termine.\n"); break;
            default: printf("Choix invalide\n");
        }
    } while (choix != 6);

    return 0;
}
