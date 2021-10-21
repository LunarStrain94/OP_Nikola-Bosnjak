#include <iostream>
#include <iomanip>
using namespace std;

struct mat
{
    int m;
    int n;
    float** matrix;
};

void delete_mat(mat* mat1)
{
    int i, j;

    for (int i = 0; i < mat1->m; i++)
        delete [] mat1->matrix[i];
    delete [] mat1->matrix;
}

void input_mat(mat* mat1)
{
    int i, j;

    cout << "\nUnesite m: ";
    cin >> mat1->m;
    cout << "Unesite n: ";
    cin >> mat1->n;

    cout << "\nUnesite brojeve u matrici: \n";
    mat1->matrix = new float*[mat1->m];
    for (int i = 0; i < mat1->m; i++)
        mat1->matrix[i] = new float[mat1->n];
    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            cout << ">>";
            cin >> mat1->matrix[i][j];
        }
    }
}

float rand_num(float a, float b)
{
    cout << fixed << showpoint;
    cout << setprecision(4);

    float x, t;
    if (a > b)
    {
        t = a;
        a = b;
        b = t;
    }
    x = a + (rand()/(RAND_MAX / (b - a)));
    return x;
}

void generate_mat(mat* mat1)
{
    int i, j;
    float a, b;

    cout << fixed << showpoint;
    cout << setprecision(4);

    cout << "\nUnesite m: ";
    cin >> mat1->m;
    cout << "Unesite n: ";
    cin >> mat1->n;

    cout << "\nUnesite raspon brojeva u matrici(a-b):\n-a: ";
    cin >> a;
    cout << "-b: ";
    cin >> b;

    mat1->matrix = new float*[mat1->m];
    for (int i = 0; i < mat1->m; i++)
        mat1->matrix[i] = new float[mat1->n];

    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            mat1->matrix[i][j] = rand_num(a, b);
        }
    }
}

void display_mat(mat* mat1)
{
    int i, j;

    cout << "\n";
    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            cout << mat1->matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

void add_mat(mat* mat1, mat* mat2, mat* mat3)
{
    int i, j;

    if ((mat1->m != mat2->m) || (mat1->n != mat2->n))
    {
        cout << "\nNemoguce zbrajanje!";
        return;
    }

    mat3->m = mat1->m;
    mat3->n = mat1->n;
    mat3->matrix = new float*[mat3->m];

    for (int i = 0; i < mat3->m; i++)
        mat3->matrix[i] = new float[mat3->n];

    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            mat3->matrix[i][j] = mat1->matrix[i][j] + mat2->matrix[i][j];
        }
    }
}

void sub_mat(mat* mat1, mat* mat2, mat* mat3)
{
    int i, j;

    if ((mat1->m != mat2->m) || (mat1->n != mat2->n))
    {
        cout << "\nNemoguce oduzimanje!";
        return;
    }

    mat3->m = mat1->m;
    mat3->n = mat2->n;
    mat3->matrix = new float*[mat3->m];

    for (int i = 0; i < mat3->m; i++)
        mat3->matrix[i] = new float[mat3->n];

    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            mat3->matrix[i][j] = mat1->matrix[i][j] - mat2->matrix[i][j];
        }
    }
}

void mul_mat(mat* mat1, mat* mat2, mat* mat3)
{
    int i, j, k;

    mat3->m = mat2->m;
    mat3->n = mat1->n;
    mat3->matrix = new float*[mat3->m];

    for (int i = 0; i < mat3->m; i++)
        mat3->matrix[i] = new float[mat3->n];

    if (mat1->m != mat2->n)
    {
        cout << "\nNemoguce mnozenje!";
        return;
    }

    for (int i = 0; i < mat1->m; i++)
    {
        for (int j = 0; j < mat1->n; j++)
        {
            mat3->matrix[i][j] = 0;
        }
    }

    for (i = 0; i < mat1->m; ++i)
	{
		for (j = 0; j < mat2->n; ++j)
		{
			for (k = 0; k < mat1->m; ++k)
			{
				mat3->matrix[i][j] += mat1->matrix[i][k] * mat2->matrix[k][j];
			}
		}
	}
}

void tran_mat(mat* mat1, mat* mat3)
{
    int i, j;

    mat3->m = mat1->n;
    mat3->n = mat1->m;
    mat3->matrix = new float*[mat3->m];

    for (int i = 0; i < mat3->m; i++)
        mat3->matrix[i] = new float[mat3->n];

    for (i = 0; i < mat1->m; ++i)
	{
		for (j = 0; j < mat1->n; ++j)
		{
            mat3->matrix[j][i] = mat1->matrix[i][j];
		}
	}
}

int main()
{
    srand(time(NULL));

    char izbor;

    mat mat1;
    mat mat2;
    mat mat3;

    for (;;)
    {
        for (;;)
        {
            cout << "Unijeti matricu 1 rucno ili nasumicno generirati? [1|2]\n";
            cin >> izbor;
            if (izbor == '1')
            {
                input_mat(&mat1);
                break;
            }
            if (izbor == '2')
            {
                generate_mat(&mat1);
                cout << "\n\nMatrica 1:";
                display_mat(&mat1);
                cout << "\n";
                break;
            }
            cout << "\n";
        }
        for (;;)
        {
            cout << "Unijeti matricu 2 rucno ili nasumicno generirati? [1|2]\n";
            cin >> izbor;
            if (izbor == '1')
            {
                input_mat(&mat2);
                break;
            }
            if (izbor == '2')
            {
                generate_mat(&mat2);
                cout << "\n\nMatrica 2:";
                display_mat(&mat2);
                cout << "\n";
                break;
            }
            cout << "\n";
        }

        for (;;)
        {
            cout << "Odaberite operaciju: [+|-|*|t|n]\n";
            cin >> izbor;

            if (izbor == '+')
            {
                cout << "\n\nRezultat:";
                add_mat(&mat1, &mat2, &mat3);
                display_mat(&mat3);
                delete_mat(&mat3);
            }
            if (izbor == '-')
            {
                cout << "\n\nRezultat:";
                sub_mat(&mat1, &mat2, &mat3);
                display_mat(&mat3);
                delete_mat(&mat3);
            }
            if (izbor == '*')
            {
                cout << "\n\nRezultat:";
                mul_mat(&mat1, &mat2, &mat3);
                display_mat(&mat3);
                delete_mat(&mat3);
            }
            if (izbor == 'n')
                break;
            if (izbor == 't')
            {
                for (;;)
                {
                    cout << "\nKoju matricu transponirate? [1|2]\n";
                    cin >> izbor;
                    if (izbor == '1')
                    {
                        cout << "\n\nRezultat:";
                        tran_mat(&mat1, &mat3);
                        display_mat(&mat3);
                        delete_mat(&mat3);
                        break;
                    }
                    if (izbor == '2')
                    {
                        cout << "\n\nRezultat:";
                        tran_mat(&mat2, &mat3);
                        display_mat(&mat3);
                        delete_mat(&mat3);
                        break;
                    }
                }
            }
            cout << "\n";
        }

    }

    delete_mat(&mat1);
    delete_mat(&mat2);
    delete_mat(&mat3);
}
