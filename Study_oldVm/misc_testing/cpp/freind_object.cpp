#include <iostream>


/*SAR:::
1.You cant call the freind function through object because its nt memeer funrtion "a.fun()" 
2.The function in diffrenet class("Y") can  access member object of other class but not its private member..It can only possbible if that fun is friein to cllas "A" 
*/
class A

{


  private :
  int i;
  public:
  friend void fun () { std::cout << "\n hi iam in freind function"; }

};



class Y
{
   public:
  void fun(A &A) { std::cout << "\n we are in clss Y and i===" << A.i ; }

};


int main()
{
 A a;

// a.fun(); ///Invalid statment

 Y y;
 y.fun(a);

}
