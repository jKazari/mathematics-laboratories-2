#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct Transakcja {
    string produkt;
    double wartosc;
};

bool wczytajTransakcje(const string& nazwaPliku, vector<Transakcja>& transakcje) {
    ifstream plik(nazwaPliku);
    if (!plik.is_open()) {
        cerr << "Blad otwierania pliku: " << nazwaPliku << endl;
        return false;
    }

    string produkt;
    double wartosc;
    while (plik >> produkt >> wartosc) {
        if (plik.fail()) {
            cerr << "Blad odczytu wiersza" << endl;
            return false;
        }
        transakcje.push_back({produkt, wartosc});
    }
    plik.close();
    return true;
}

void generujRaport(const vector<Transakcja>& transakcje, const string& nazwaPlikuRaportu) {
    int liczbaTransakcji = transakcje.size();
    double calkowitaSprzedaz = 0;
    double najwyzszaSprzedaz = transakcje.size() > 0 ? transakcje[0].wartosc : 0;
    double najnizszaSprzedaz = transakcje.size() > 0 ? transakcje[0].wartosc : 0;
    vector<string> produkty;
    vector<int> liczby;

    for (const auto& t : transakcje) {
        calkowitaSprzedaz += t.wartosc;
        if (t.wartosc > najwyzszaSprzedaz) najwyzszaSprzedaz = t.wartosc;
        if (t.wartosc < najnizszaSprzedaz) najnizszaSprzedaz = t.wartosc;

        bool znaleziono = false;
        for (size_t i = 0; i < produkty.size(); ++i) {
            if (produkty[i] == t.produkt) {
                liczby[i]++;
                znaleziono = true;
                break;
            }
        }
        if (!znaleziono) {
            produkty.push_back(t.produkt);
            liczby.push_back(1);
        }
    }

    double sredniaSprzedaz = liczbaTransakcji > 0 ? calkowitaSprzedaz / liczbaTransakcji : 0;

    ofstream plikRaportu(nazwaPlikuRaportu);
    if (!plikRaportu.is_open()) {
        cerr << "Blad otwierania pliku raportu: " << nazwaPlikuRaportu << endl;
        return;
    }

    plikRaportu << "Raport Sprzedazy\n";
    plikRaportu << "================\n";
    plikRaportu << "Laczna liczba transakcji: " << liczbaTransakcji << "\n";
    plikRaportu << "Laczna sprzedaz: " << fixed << setprecision(2) << calkowitaSprzedaz << " zl\n";
    plikRaportu << "Srednia wartosc transakcji: " << fixed << setprecision(2) << sredniaSprzedaz << " zl\n";
    plikRaportu << "Najwyzsza sprzedaz: " << fixed << setprecision(2) << najwyzszaSprzedaz << " zl\n";
    plikRaportu << "Najnizsza sprzedaz: " << fixed << setprecision(2) << najnizszaSprzedaz << " zl\n";
    plikRaportu << "Liczba transakcji dla kazdego produktu:\n";
    for (size_t i = 0; i < produkty.size(); ++i) {
        plikRaportu << "  " << produkty[i] << ": " << liczby[i] << "\n";
    }
    plikRaportu.close();
}

int main() {
    string nazwaPlikuWejsciowego = "sprzedaz.txt";
    string nazwaPlikuRaportu = "raport.txt";
    vector<Transakcja> transakcje;

    if (!wczytajTransakcje(nazwaPlikuWejsciowego, transakcje)) {
        cerr << "Nie udalo sie wczytac transakcji." << endl;
        return 1;
    }

    generujRaport(transakcje, nazwaPlikuRaportu);
    cout << "Raport wygenerowany pomyslnie: " << nazwaPlikuRaportu << endl;

    return 0;
}
