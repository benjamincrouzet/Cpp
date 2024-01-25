#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;  // Déclaration pour éviter d'utiliser explicitement std::

// Classe abstraite représentant un véhicule de Formule 1
class VehiculeF1 {
public:
    // Constructeur par défaut
    VehiculeF1() {
        cout << "Constructeur par defaut de VehiculeF1" << endl;
    }

    // Constructeur paramétrique avec un nom
    VehiculeF1(const string& nom) : nom_(nom) {
        cout << "Voici le nom de l'ecurie F1 : " << nom_ << endl;
    }

    // Méthode virtuelle pure (rend la classe abstraite)
    virtual void accelerer() const = 0;

    // Destructeur virtuel
    virtual ~VehiculeF1() {
        cout << "Destructeur de VehiculeF1" << endl;
    }

private:
    string nom_;
};

// Classe dérivée de VehiculeF1 représentant une voiture de Formule 1
class VoitureF1 : public VehiculeF1 {
public:
    // Constructeur par défaut
    VoitureF1() : VehiculeF1("VoitureF1") {
        cout << "Constructeur par defaut de VoitureF1" << endl;
    }

    // Constructeur paramétrique avec un nom et un numéro
    VoitureF1(const string& nom, int numero) : VehiculeF1(nom), numero_(numero) {
        cout << "Voici le numero de cette voiture F1 : " << numero_ << endl;
    }

    // Destructeur
    ~VoitureF1() {
        cout << "Destructeur de VoitureF1" << endl;
    }

    // Implémentation de la méthode virtuelle pure
    void accelerer() const override {
        cout << "La voiture F1 accelere sur la piste !" << endl;
    }

private:
    int numero_;
};

// Classe représentant une équipe de Formule 1
class EquipeF1 {
public:
    // Constructeur par défaut
    EquipeF1() {
        cout << "Constructeur par defaut d'EquipeF1" << endl;
    }

    // Constructeur paramétrique avec un nom et une voiture
    EquipeF1(const string& nom, const VoitureF1& voiture) : nom_(nom), voiture_(voiture) {
        cout << "Voici le nom de cette equipe F1 : " << nom_ << endl;
    }

    // Destructeur
    ~EquipeF1() {
        cout << "Destructeur d'EquipeF1" << endl;
    }

    // Méthode utilisant la voiture de l'équipe
    void faireCourse() const {
        cout << "L'equipe " << nom_ << " participe a une course !" << endl;
        voiture_.accelerer();
    }

private:
    string nom_;
    VoitureF1 voiture_;
};

int main() {
    // Création d'une voiture de Formule 1
    VoitureF1 maVoiture("Red Bull Racing", 33);

    // Création d'une équipe de Formule 1 avec la voiture précédemment créée
    EquipeF1 monEquipe("Red Bull", maVoiture);

    // La méthode faireCourse() simule la participation de l'équipe à une course
    monEquipe.faireCourse();

    return 0;
}
