#include <iostream>


int main()
{

 int i=10;
 

 int *p = &i;
 std::cout  << "\n value  i====" << *p;

  
 int *&r = p;

 *r =20;
 std::cout <<"\n r==== " << &r  << "   and p=====" << &p;
 std::cout  << "\n value  i====" << *p;


}
