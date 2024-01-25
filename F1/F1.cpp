#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;  // D�claration pour �viter d'utiliser explicitement std::

// Classe abstraite repr�sentant un v�hicule de Formule 1
class VehiculeF1 {
public:
    // Constructeur par d�faut
    VehiculeF1() {
        cout << "Constructeur par defaut de VehiculeF1" << endl;
    }

    // Constructeur param�trique avec un nom
    VehiculeF1(const string& nom) : nom_(nom) {
        cout << "Voici le nom de l'ecurie F1 : " << nom_ << endl;
    }

    // M�thode virtuelle pure (rend la classe abstraite)
    virtual void accelerer() const = 0;

    // Destructeur virtuel
    virtual ~VehiculeF1() {
        cout << "Destructeur de VehiculeF1" << endl;
    }

private:
    string nom_;
};

// Classe d�riv�e de VehiculeF1 repr�sentant une voiture de Formule 1
class VoitureF1 : public VehiculeF1 {
public:
    // Constructeur par d�faut
    VoitureF1() : VehiculeF1("VoitureF1") {
        cout << "Constructeur par defaut de VoitureF1" << endl;
    }

    // Constructeur param�trique avec un nom et un num�ro
    VoitureF1(const string& nom, int numero) : VehiculeF1(nom), numero_(numero) {
        cout << "Voici le numero de cette voiture F1 : " << numero_ << endl;
    }

    // Destructeur
    ~VoitureF1() {
        cout << "Destructeur de VoitureF1" << endl;
    }

    // Impl�mentation de la m�thode virtuelle pure
    void accelerer() const override {
        cout << "La voiture F1 accelere sur la piste !" << endl;
    }

private:
    int numero_;
};

// Classe repr�sentant une �quipe de Formule 1
class EquipeF1 {
public:
    // Constructeur par d�faut
    EquipeF1() {
        cout << "Constructeur par defaut d'EquipeF1" << endl;
    }

    // Constructeur param�trique avec un nom et une voiture
    EquipeF1(const string& nom, const VoitureF1& voiture) : nom_(nom), voiture_(voiture) {
        cout << "Voici le nom de cette equipe F1 : " << nom_ << endl;
    }

    // Destructeur
    ~EquipeF1() {
        cout << "Destructeur d'EquipeF1" << endl;
    }

    // M�thode utilisant la voiture de l'�quipe
    void faireCourse() const {
        cout << "L'equipe " << nom_ << " participe a une course !" << endl;
        voiture_.accelerer();
    }

private:
    string nom_;
    VoitureF1 voiture_;
};

int main() {
    // Cr�ation d'une voiture de Formule 1
    VoitureF1 maVoiture("Red Bull Racing", 33);

    // Cr�ation d'une �quipe de Formule 1 avec la voiture pr�c�demment cr��e
    EquipeF1 monEquipe("Red Bull", maVoiture);

    // La m�thode faireCourse() simule la participation de l'�quipe � une course
    monEquipe.faireCourse();

    return 0;
}
