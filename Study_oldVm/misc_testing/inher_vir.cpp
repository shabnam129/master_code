#include <iostream>

class A
{
 public:
 virtual   void  Test1() {std::cout << "\n HI aim TEST1 in A\n" ; }
 void  Test2()
  {
    Test1();
  }

};

class B:public A
{
 public:
  void  Test1() {std::cout << "\n HI iam TEST1 in B\n" ; }
 /*void  Test2() 
  {
    Test1();
  }*/

};


int main()
{

 B obj_b;

 obj_b.Test2();

}

