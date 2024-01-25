#include <stdio.h>

// D�finition de la classe Voiture
class Voiture {
private:
    char modele[50]; // Attribut pour stocker le mod�le de la voiture

    int annee; // Attribut pour stocker l'ann�e de la voiture

public:
    // Constructeur par d�faut
    Voiture() {
        modele[0] = '\0'; // Initialisation de la cha�ne de caract�res � une cha�ne vide
        annee = 0; // Initialisation de l'ann�e � z�ro
    }

    // Constructeur avec des param�tres
    Voiture(const char* mode, int year) {
        // Copie de la cha�ne de caract�res `mode` dans l'attribut `modele`
        // en s'assurant de ne pas d�passer la taille maximale du tampon (49 caract�res + le caract�re nul)
        snprintf(modele, sizeof(modele), "%s", mode);

        annee = year; // Initialisation de l'ann�e avec la valeur fournie
    }

    // M�thode pour afficher les d�tails de la voiture
    void afficherDetails() {
        printf("Mod�le : %s, Ann�e : %d\n", modele, annee);
    }
};

int main() {
    // Cr�ation d'objets de la classe Voiture
    Voiture voiture1; // Utilisation du constructeur par d�faut
    Voiture voiture2("Toyota", 2022); // Utilisation du constructeur avec param�tres

    // Affichage des d�tails des voitures
    printf("D�tails de la voiture 1 : ");
    voiture1.afficherDetails();

    printf("D�tails de la voiture 2 : ");
    voiture2.afficherDetails();

    return 0;
}

