#include <iostream>
#include <iomanip>
using namespace std;

void input(int *niz, int n)
{
    int i;
    for (i = 0; i < n; ++i)
    {
        cout << "\n>>";
        cin >> niz[i];
    }
}

int& nizref(int *niz, int i)
{
    return niz[i];
}

int main()
{
    int n, *niz, i;

    cout << "Unesite broj clanova niza: ";
    cin >> n;

    niz = new int[n];
    input(niz, n);

    cout << "\nKoji clan niza referencirati?\n>>";
    cin >> i;

    nizref(niz, i) += 1;

    cout << niz[i];

    delete[] niz;
    return 0;
}
