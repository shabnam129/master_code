#include<stdio.h>
#include <iostream>
int fib(int n)
{
   if (n <= 1)
      return n;
   return fib(n-1) + fib(n-2);
}
 
int main ()
{
  int n ;
  std::cout << "\n enter the index of fibnoaci " ;
  std::cin >> n;
  std::cout << fib(n);
  //printf("%d", fib(n));
  //getchar();
  return 0;
}
