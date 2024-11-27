#include <stdio.h>
#include <string.h>

// Définition de la structure pour la date d'échéance
typedef struct {
    int jour, mois, annee;
}echeance;
// Définition de la structure pour une tâche
typedef struct {
    char titre[100];
    char description[200];
    echeance echeance;
    char pr[10];
} taches;

// Tableau de tâches, capacité maximale 100
taches T[100];

// Compteur pour le nombre de tâches ajoutées
int compteurtaches = 0;

// Fonction pour ajouter une nouvelle tâche
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

     // Incrémenter le compteur de tâches
    compteurtaches++;
}
    // Fonction pour afficher toutes les tâches
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
    // Fonction pour modifier une tâche
void modifier() {
    int m;
    printf("Entrer le numero de la tache a modifier (1-%d): ", compteurtaches);
    scanf("%d", &m);
// Vérifier si le numéro de tâche est valide
    if (m > 0 && m <= compteurtaches) {
            m--;// Ajuster l'index car les tâches sont numérotées à partir de 1
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

// Fonction pour supprimer une tâche
void supprimer() {
    int m, i;
    printf("Entrer le numero de la tache a supprimer (1-%d): ", compteurtaches);
    scanf("%d", &m);
    m--; // Ajuster l'index car les tâches sont numérotées à partir de 1

    if (m >= 0 && m < compteurtaches) {
        // Décaler les tâches suivantes pour supprimer l'élément
        for (i = m; i < compteurtaches - 1; i++) {
            T[i] = T[i + 1];
        }
        compteurtaches--;  // Réduire le compteur de tâches

    } else {
        printf("Numero de tache invalide.\n");
    }
}

// Fonction pour filtrer les tâches par priorité
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

// Fonction principale du programme
int main() {
    int choix;

            // Affichage du menu
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
