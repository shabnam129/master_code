#include <iostream>

int main()
{
 const int i =10;


  int *p = const_cast<int *>(&i);

  std::cout << "\n address of i===="<< &i <<  "\n address of p=== " << p;
  *p =7;

  std::cout << "\n value of i===" << i << "\n and value at p ===" << *p;

}
