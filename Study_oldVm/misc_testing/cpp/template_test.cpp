#include <iostream>

template < class T>
void fun(T a=NULL)
{

 std::cout <<"\n we are in fun and a===" <<a;
}

int main()
{
 int i=10;

// fun(i);

fun();
}
 
