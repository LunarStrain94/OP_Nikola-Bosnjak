#include <iostream>
#include <iomanip>
using namespace std;

struct tocka
{
    int x;
    int y;
};

struct pravokutnik
{
    tocka A;
    tocka C;
};

struct kruznica
{
    //(x-xs)^2 + (y-ys)^2 = r^2
    tocka S;
    int r;
};

void unosPravokutnika(pravokutnik *niz, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        cout << "\nUnesite pravokutnik[" << i + 1 << "]:\n";
        cout << "Ax: ";
        cin >> niz[i].A.x;
        cout << "Ay: ";
        cin >> niz[i].A.y;
        cout << "Cx: ";
        cin >> niz[i].C.x;
        cout << "Cy: ";
        cin >> niz[i].C.y;
    }
}

void unosKruznice(kruznica *kr)
{
    cout << "\nUnesite kruznicu: \n";
    cout << "r: ";
    cin >> kr->r;
    cout << "Sx: ";
    cin >> kr->S.x;
    cout << "Sy: ";
    cin >> kr->S.y;
}

int presjecanje(const kruznica& kr, const pravokutnik *niz, int n)
{
    tocka T;
    int br = 0;

    for(int i = 0; i < n; i++)
    {
        T.x = kr.S.x - max(niz[i].A.x, min(kr.S.x, niz[i].A.x + (niz[i].C.x - niz[i].A.x)));
        T.y = kr.S.y - max(niz[i].A.y, min(kr.S.y, niz[i].A.y + (niz[i].C.y - niz[i].A.y)));

        if((T.x * T.x + T.y * T.y) <= kr.r * kr.r)
        {
            br++;
        }
    }
    return br;
}


int main()
{
    int n, br;

    cout << "Unesite broj pravokutnika: ";
    cin >> n;

    pravokutnik* niz;
    kruznica kr;

    niz = new pravokutnik[n];

    unosPravokutnika(niz, n);
    unosKruznice(&kr);

    br = presjecanje(kr, niz, n);

    cout << "\n" << br << " pravokutnika presjeca kruznicu.";

    delete[] niz;

    return 0;
}
