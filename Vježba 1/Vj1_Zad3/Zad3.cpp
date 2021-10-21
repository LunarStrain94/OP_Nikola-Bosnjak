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

void maxmin(int *niz, int *max1, int *min1, int n)
{
    int i;
    *max1 = niz[0];
    *min1 = niz[0];
    for (i = 0; i <= n; ++i)
    {
        if (niz[i] > *max1)
            *max1 = niz[i];
        if (niz[i] < *max1)
            *min1 = niz[i];
    }
}

int main()
{
    int max1, min1, n, *niz;
    cout << "Unesite broj clanova niza: ";
    cin >> n;
    //niz = (int*)malloc(n*sizeof(int));
    niz = new int[n];
    input(niz, n);
    maxmin(niz, &max1, &min1, n-1);
    cout << "\nNajveci broj: " << max1 << "\nNajmanji broj: " << min1;
    //free(niz);
    delete[] niz;
}
