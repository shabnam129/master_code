#include <iostream>

class A
{
 public:
 int i;
 A()
 {
  std::cout <<"\n we are in simple const";
 }

 A(const A  &obj)
 {
   std::cout <<"\n we are in copy const";
 }
 
 ~A()
 {

  std::cout <<"\n Desturator in of A";


 } 


};

A fun()
{
 A a;
 a.i = 20;
 std::cout << "\n address of a====" << (int *)&a; 
 return a;

}



int main()
{

  A obj2 = fun();
  std::cout << "\n address of obj2 ====" << &obj2;
 std::cout <<"\n we are in main  and i ===" << obj2.i;


}

