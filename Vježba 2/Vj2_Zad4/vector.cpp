#include "vector.hpp"
using namespace std;
void myVector::vector_new(size_t sz)
{
    arr = new int[sz];
    size = 0;
    capacity = 1;
}
void myVector::vector_delete()
{
    delete[] arr;
}
void myVector::vector_push_back(int n)
{
    if (size == capacity)
    {
        capacity *= 2;
        int* arrN = new int[capacity];
        for (int i = 0; i < (capacity - 1); i++)
        {
            arrN[i] = arr[i];
        }

        delete[] arr;

        arr = arrN;
    }

    arr[size] = n;
    size++;
}
void myVector::vector_pop_back()
{
    size -= 1;
}
int& myVector::vector_front()
{
    return arr[0];
}
int& myVector::vector_back()
{
    return arr[size - 1];
}
size_t myVector::vector_size()
{
    return size;
}
void myVector::print_vector()
{
    for (size_t i = 0; i < vector_size(); i++)
        cout << arr[i] << " ";
    cout << endl;
}
