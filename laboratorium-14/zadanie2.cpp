#include <iostream>
using namespace std;

int sumujWartosci(int *wartosci, int n)
{
    int suma = 0; // było 'int suma;'
    for (int i = 0; i < n; i++)  // było 'for (int i = 0; i <= n; i++)'
    {
        suma += wartosci[i];
    }
    return suma;
}

int main()
{
    int rozmiar;
    cout << "Podaj rozmiar: ";
    cin >> rozmiar;
    int *wartosci = new int[rozmiar];
    int i = 0;  // było 'int i;' 
    while (i < rozmiar)
    {
        cout << "Podaj wartosc do dodania: ";
        cin >> wartosci[i++]; // było 'cin >> wartosci[++i];'
    }
    cout << "Laczna suma wynosi: " << sumujWartosci(wartosci, rozmiar) << endl;

    delete [] wartosci; // nie było dealokacji pamięci
}