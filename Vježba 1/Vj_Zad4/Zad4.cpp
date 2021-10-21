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

void maxmin(int *niz, int n, int *max1, int *min1)
{
    if (*max1 < niz[n])
        *max1 = niz[n];
    if (*min1 > niz[n])
        *min1 = niz[n];
    if (n == 0)
        return;
    maxmin(niz, n-1, max1, min1);
}

int main()
{
    int max1, min1, n, *niz;
    cout << "Unesite broj clanova niza: ";
    cin >> n;
    //niz = (int*)malloc(n*sizeof(int));

    niz = new int[n];
    input(niz, n);

    max1 = niz[n-1];
    min1 = niz[n-1];

    maxmin(niz, n-1, &max1, &min1);

    cout << "\nNajveci broj: " << max1 << "\nNajmanji broj: " << min1;
    //free(niz);
    delete[] niz;
}
