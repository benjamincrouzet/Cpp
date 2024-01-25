#include <stdio.h>

// D�finition de la classe abstraite Moto
class Moto {
public:
    // M�thode virtuelle pure pour afficher les d�tails de la moto
    virtual void afficherDetails() = 0;
    // L'utilisation de 'virtual void' indique une m�thode virtuelle
    // '= 0' signifie que cette m�thode est virtuelle pure et doit �tre impl�ment�e dans les classes d�riv�es.
};

// D�finition de la classe concr�te Vehicule
class Vehicule : public Moto {
protected:
    char modele[50];
    int annee;
    const char* type = "V�hicule";

public:
    // Constructeur avec param�tres pour Vehicule
    Vehicule(const char* mode, int year) {
        snprintf(modele, sizeof(modele), "%s", mode);
        annee = year;
    }

    // Impl�mentation de la m�thode afficherDetails() pour Vehicule
    void afficherDetails() override {
        printf("Type : %s, Mod�le : %s, Ann�e : %d\n", type, modele, annee);
    }
};

// D�finition de la classe Voiture, d�riv�e de Vehicule
class Voiture : public Vehicule {
public:
    // Constructeur avec param�tres pour Voiture
    Voiture(const char* mode, int year) : Vehicule(mode, year) {
        // Appel du constructeur de Vehicule pour initialiser les attributs
    }
    // Voiture h�rite de la m�thode afficherDetails() de Vehicule
    // Pas besoin de la red�finir ici, car la classe Vehicule a d�j� fourni une impl�mentation.
};

int main() {
    // Cr�ation d'objets de la classe Voiture et Vehicule
    Voiture maVoiture("Toyota", 2022);
    Vehicule monVehicule("Moto", 2021);

    // Appel de la m�thode afficherDetails() pour chaque objet
    printf("D�tails de ma voiture : \n");
    maVoiture.afficherDetails();

    printf("\nD�tails de mon v�hicule : \n");
    monVehicule.afficherDetails();

    return 0;
}
