#include <iostream>



int ** fun()
{

int a=9;
int *p = &a;

std::cout << "\n address a=====" << p;

std::cout << "\n address p=====" << &p;
return &p;

}

int main()
{

std::cout <<"\nIAM IN MAIN data===" << **fun();

}
