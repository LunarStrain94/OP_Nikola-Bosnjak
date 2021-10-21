/*#include "vector.hpp"
using namespace std;
int main()
{
    MyVector mv;
    mv.vector_new();

    int m;
    cout << "Unesi element, Ctrl+d (linux) ili Ctrl+z (win) za kraj unosa" << endl;
    while(cin >> m)
        mv.vector_push_back(m);

    cout << "first element " << mv.vector_front() << endl;
    cout << "last element " << mv.vector_back() << endl;
    mv.print_vector();

    cout << "removing last element" << endl;
    mv.vector_pop_back();
    mv.print_vector();

    cout << "size " << mv.vector_size() << endl;
    cout << "capacity " << mv.capacity << endl;

    mv.vector_delete();
}*/

#include "vector.hpp"
#include <iostream>
using namespace std;
int main()
{
    myVector mv;
    mv.vector_new(4);

    int m;
    cout << "Enter elements. For exit, enter 0;" << endl;
    cin >> m;
    while (m != 0)
    {
        mv.vector_push_back(m);
        cin >> m;
    }

    mv.print_vector();
    cout << "First element: " << mv.vector_front() << endl;
    cout << "Last element " << mv.vector_back() << endl;

    cout << "Size " << mv.vector_size() << endl;
    cout << "Capacity " << mv.capacity << endl;

    cout << "Last element removed: " << endl;

    mv.vector_pop_back();
    mv.print_vector();
    mv.vector_delete();
}
