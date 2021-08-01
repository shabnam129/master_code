#include <iostream>
#include <cstdlib>

int main()
{

 int *p = (int *)  malloc(8);

 std::cout <<"\n addreess return ====" << p;


 
 int*q =p;// so that starting address can bee kept and work with q
 *q=10;
 q++;
 *q=11;

 free(p);
 p=NULL;
 std::cout <<"\n addreess return ====" << p;
 
}


 
