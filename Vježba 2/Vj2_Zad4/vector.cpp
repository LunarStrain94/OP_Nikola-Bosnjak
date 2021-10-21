#include "vector.hpp"

void MyVector::vector_new (size_t sz)
{
    /* TODO */
}
void MyVector::vector_delete()
{
    /* TODO */
}
void MyVector::vector_push_back(int n)
{
    /* TODO */
}
void MyVector::vector_pop_back()
{
    /* TODO */
}
int& MyVector::vector_front()
{
    /* TODO */
}
int& MyVector::vector_back()
{
    /* TODO */
}
size_t MyVector::vector_size()
{
    /* TODO */
}


void MyVector::print_vector()
{
    for (size_t i = 0; i < vector_size(); ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}
