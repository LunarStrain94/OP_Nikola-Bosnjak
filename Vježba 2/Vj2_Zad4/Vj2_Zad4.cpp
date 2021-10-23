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
