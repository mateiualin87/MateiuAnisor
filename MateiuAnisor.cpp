#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Automobile {
private:
    string marca;
    string model;
    int nrLocuri;
    int putere;
    string culoare;
    int anFabricatie;
    float pret;
    int kmParcursi;

public:
    Automobile(string marca, string model, int nrLocuri, int putere, string culoare, int anFabricatie, float pret, int kmParcursi) {
        this->nrLocuri = nrLocuri;
        this->putere = putere;
        this->marca = marca;
        this->model = model;
        this->culoare = culoare;
        this->anFabricatie = anFabricatie;
        this->pret = pret;
        this->kmParcursi = kmParcursi;
    }

    ~Automobile() {}

    string getMarca() const {
        return marca;
    }

    void setMarca(const string& nouaMarca) {
        marca = nouaMarca;
    }

    string getModel() const {
        return model;
    }

    void setModel(const string& noulModel) {
        model = noulModel;
    }

    int getNrLocuri() const {
        return nrLocuri;
    }

    void setNrLocuri(int nr) {
        nrLocuri = nr;
    }

    int getPutere() const {
        return putere;
    }

    void setPutere(int kw) {
        putere = kw;
    }

    string getCuloare() const {
        return culoare;
    }

    void setCuloare(const string& nouaCuloare) {
        culoare = nouaCuloare;
    }

    int getAnFabricatie() const {
        return anFabricatie;
    }

    void setAnFabricatie(int an) {
        anFabricatie = an;
    }

    float getPret() const {
        return pret;
    }

    void setPret(float bani) {
        pret = bani;
    }

    int getKmParcursi() const {
        return kmParcursi;
    }

    void setKmParcursi(int km) {
        kmParcursi = km;
    }

    void afisare() const {
        cout << "Marca: " << marca << endl;
        cout << "Model: " << model << endl;
        cout << "Culoare: " << culoare << endl;
        cout << "Numar de locuri: " << nrLocuri << endl;
        cout << "Putere: " << putere << " CP" << endl;
        cout << "An fabricatie: " << anFabricatie << endl;
        cout << "Pret: " << pret << " EUR" << endl;
        cout << "Kilometri parcursi: " << kmParcursi << endl << endl;
    }
};

void afisareDupaPret(vector<Automobile>& automobile) {
    int optiune;
    cout << "Alegeti optiunea de sortare a automobilelor:" << endl;
    cout << "1 - Pret crescator" << endl;
    cout << "2 - Pret descrescator" << endl;
    cout << "Optiunea dvs.: ";
    cin >> optiune;

    if (optiune == 1) {
        sort(automobile.begin(), automobile.end(), [](const Automobile& a, const Automobile& b) {
            return a.getPret() < b.getPret();
            });
    }
    else if (optiune == 2) {
        sort(automobile.begin(), automobile.end(), [](const Automobile& a, const Automobile& b) {
            return a.getPret() > b.getPret();
            });
    }
    else {
        cout << "Optiune invalida!" << endl;
        return;
    }

    cout << "Automobilele sortate dupa pret: " << endl;
    for (const Automobile& automobil : automobile) {
        automobil.afisare();
    }
}

void modificaPret(vector<Automobile>& automobile) {
    string marca, model;
    float pretNou;
    cout << "Introduceti marca masinii: ";
    cin >> marca;
    cout << "Introduceti modelul masinii: ";
    cin >> model;
    cout << "Introduceti noul pret pentru " << marca << " " << model << ": ";
    cin >> pretNou;

    // Cauta masina dupa marca si model
    auto iterator = find_if(automobile.begin(), automobile.end(), [&](const Automobile& autos) {
        return autos.getMarca() == marca && autos.getModel() == model;
        });

    // Daca masina este gasita se modifica pretul
    if (iterator != automobile.end()) {
        iterator->setPret(pretNou);
        cout << "Pretul pentru " << marca << " " << model << " a fost modificat cu succes!" << endl;
        cout << "Noul pret este " << pretNou << " EUR !";
    }
    else {
        cout << "Nu am gasit nicio masina cu aceasta marca si acest model!" << endl;
    }
}


int main() {
    Automobile auto1("BMW", "Seria5", 5, 150, "Albastru", 2015, 25000.0, 120000);
    Automobile auto2("Ford", "Focus", 4, 110, "Rosu", 2018, 18000.0, 50000);
    Automobile auto3("Mercedes-Benz", "Vito", 7, 200, "Negru", 2019, 35000.0, 80000);
    Automobile auto4("Audi", "A4", 5, 190, "Gri", 2017, 13500.0, 180000);

    // Adaugarea obiectelor Automobile intr-un vector
    vector<Automobile> automobile;
    automobile.push_back(auto1);
    automobile.push_back(auto2);
    automobile.push_back(auto3);
    automobile.push_back(auto4);

    // Afisarea tuturor automobilelor
    cout << "Toate automobilele din parc sunt: " << endl;
    for (const Automobile& automobil : automobile) {
        automobil.afisare();
    }

    // Sortarea automobilelor dupa pret si afisarea lor
    afisareDupaPret(automobile);

    // Modifica pretul autmobilului setat
    modificaPret(automobile);

    return 0;
}
