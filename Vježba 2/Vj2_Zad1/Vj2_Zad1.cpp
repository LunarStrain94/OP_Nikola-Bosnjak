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

void maxmin(int *niz, int& rmax, int& rmin, int n)
{
    int i;
    rmax = niz[0];
    rmin = niz[0];
    for (i = 0; i <= n; ++i)
    {
        if (niz[i] > rmax)
            rmax = niz[i];
        if (niz[i] < rmax)
            rmin = niz[i];
    }
}

int main()
{
    int max1, min1, n, *niz;
    int& rmax = max1;
    int& rmin = min1;

    cout << "Unesite broj clanova niza: ";
    cin >> n;

    niz = new int[n];
    input(niz, n);

    maxmin(niz, rmax, rmin, n-1);
    cout << "\nNajveci broj: " << max1 << "\nNajmanji broj: " << min1;

    delete[] niz;
    return 0;
}

