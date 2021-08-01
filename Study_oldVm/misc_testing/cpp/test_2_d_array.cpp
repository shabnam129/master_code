#include <iostream>

int main()
{
 int a[2][2] = { 1,2,3,4};

 std::cout <<"\na==" <<a;
 std::cout <<"\na[1]==" << a[1];
 std::cout <<"\n(a+1)==  " << a+1;
 std::cout <<"\n*(a+1)==  " <<  *(a+1);
 
 std::cout <<"\n *(*(a+1)+ 0)==  " <<  * ( *(a+1) + 0 );
 
}
