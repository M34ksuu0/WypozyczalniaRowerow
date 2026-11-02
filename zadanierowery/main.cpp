
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// Struktura roweru
struct Rower {
    int id;
    string opis;
    string rodzaj;
    double cena;
    bool wypozyczony;
};

// Struktura wyjatku
struct Except {
    string komunikat;
};

// Lista rowerow
vector<Rower> rowery;

// Szukanie roweru po ID
int znajdzRower(int id) {
    for (int i = 0; i < rowery.size(); i++) {
        if (rowery[i].id == id) {
            return i;
        }
    }

    return -1;
}

// Dodawanie roweru
void dodajRower() {
    Rower r;

    cout << "Podaj ID: ";
    cin >> r.id;

    if (znajdzRower(r.id) != -1) {
        cout << "Rower o takim ID juz istnieje!\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Podaj opis: ";
    getline(cin, r.opis);

    cout << "Podaj rodzaj: ";
    getline(cin, r.rodzaj);

    cout << "Podaj cene za godzine: ";
    cin >> r.cena;

    if (r.cena <= 0) {
        cout << "Cena musi byc wieksza od 0!\n";
        return;
    }

    r.wypozyczony = false;

    rowery.push_back(r);

    cout << "Dodano rower!\n";
}

// Wypozyczanie roweru
void wypozyczRower() {
    int id;

    cout << "Podaj ID roweru: ";
    cin >> id;

    try {
        int indeks = znajdzRower(id);

        if (indeks == -1) {
            throw Except{"Nie znaleziono roweru!"};
        }

        if (rowery[indeks].wypozyczony == true) {
            throw Except{"Rower jest juz wypozyczony!"};
        }

        rowery[indeks].wypozyczony = true;

        cout << "Rower zostal wypozyczony!\n";
    }
    catch (Except e) {
        cout << "Blad: " << e.komunikat << endl;
    }
}

// Zwracanie roweru
void zwrocRower() {
    int id;
    double godziny;

    cout << "Podaj ID roweru: ";
    cin >> id;

    try {
        int indeks = znajdzRower(id);

        if (indeks == -1) {
            throw Except{"Nie znaleziono roweru!"};
        }

        if (rowery[indeks].wypozyczony == false) {
            throw Except{"Ten rower nie jest wypozyczony!"};
        }

        cout << "Podaj liczbe godzin: ";
        cin >> godziny;

        if (godziny <= 0) {
            throw Except{"Liczba godzin musi byc wieksza od 0!"};
        }

        double koszt = godziny * rowery[indeks].cena;

        rowery[indeks].wypozyczony = false;

        cout << fixed << setprecision(2);
        cout << "Rower zostal zwrocony!\n";
        cout << "Do zaplaty: " << koszt << " zl\n";
    }
    catch (Except e) {
        cout << "Blad: " << e.komunikat << endl;
    }
}

// Wyswietlanie rowerow
void wyswietlRowery() {
    if (rowery.empty()) {
        cout << "Brak rowerow w wypozyczalni!\n";
        return;
    }

    cout << endl;
    cout << "=======================================================================\n";
    cout << "                    LISTA ROWEROW"<<endl;
    cout << "=======================================================================\n";

    cout << left
         << setw(6) << "ID"
         << setw(20) << "Opis"
         << setw(15) << "Rodzaj"
         << setw(12) << "Cena/h"
         << setw(12) << "Status" << endl;

    cout << "-----------------------------------------------------------------------\n";

    for (int i = 0; i < rowery.size(); i++) {
        cout << left
             << setw(6) << rowery[i].id
             << setw(20) << rowery[i].opis
             << setw(15) << rowery[i].rodzaj
             << fixed << setprecision(2)
             << setw(12) << rowery[i].cena
             << setw(12) << (rowery[i].wypozyczony ? "Wypozyczony" : "Dostepny")
             << endl;
    }

    cout << "=======================================================================\n";
}

// Menu glowne
int main() {
    int wybor;

    do {
        cout << "\n=========== WYPOZYCZALNIA ROWEROW =====================================\n";
        cout << "1. Dodaj rower\n";
        cout << "2. Wypozycz rower\n";
        cout << "3. Zwroc rower\n";
        cout << "4. Wyswietl rowery\n";
        cout << "0. Wyjscie\n";
        cout << "=======================================================================\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                dodajRower();
                break;

            case 2:
                wypozyczRower();
                break;

            case 3:
                zwrocRower();
                break;

            case 4:
                wyswietlRowery();
                break;

            case 0:
                break;

            default:
                cout << "Nieprawidlowa opcja!\n";
        }

    } while (wybor != 0);

    return 0;
}
