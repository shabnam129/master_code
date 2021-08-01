#include <iostream>

class A
{
public:

  int i;
 static int b;
 static int set_b()
 {
    b = 20;
   return b;

 }

 static int get_i( A obj)
 {
   return obj.i;


 }


};
int  A::b = 10;
int main()
{

  A obj;
  obj.i = 20;

  std::cout << "\n get calye of i from static function" << A::get_i(obj);

  std::cout << "\n value=====" << A::set_b();
 
}
