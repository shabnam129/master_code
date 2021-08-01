#include <iostream>
//#include "header.h"

#ifdef HEADER_H
#include "header.h"
#endif


extern int n;
int main()
{
  std::cout <<"\n HI IAM IN MAIN";
 std::cout <<"\n sum=====" <<   sum(5,6);

 n =96;
 std::cout <<"\n value of n===="<< n ;
 return 0;

}
