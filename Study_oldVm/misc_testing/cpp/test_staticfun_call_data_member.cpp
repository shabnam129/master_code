#include <iostream>

class A
{
 public :
 int i;
 static int j;
 static void fun( class A * this_ptr)
 {
  j = this_ptr->i;
 }

};

  
 int A::j = 0;  


int main()
{

 A obj;
 obj.i =10;
 

 std::cout << "\n value of j ==="<< A::j;

 obj.fun(&obj);

 std::cout << "now \n value of j ==="<< A::j;

} 
