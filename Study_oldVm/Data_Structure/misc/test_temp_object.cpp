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
  // const int *p = obj;
   std::cout <<"\n value of this pointer ===" <<this;
   std::cout <<"\n value of object ====%p" << (int *)&obj;

  this->i = obj.i;
 }

 ~A()
 {

   std::cout <<"\n we are in disrucotr consit and this pointer ====" <<this;
 
 }

};



A fun()
{
 A a;
 int *p = (int * )&a;
 std::cout <<"\n we are in fun and adress of obj " <<p;

 a.i = 20; 
 return a;

}



/*A fun(A a)
{
  int *p = (int * )&a;
  std::cout <<"\n we are in fun and adress of obj " <<p;

  a.i = 20; 
  return a;

}*/


int main()
{

 A obj;
 obj.i =10;
 
 std::cout << "\n we are in amain  and adress of obj ====" << (int *)&obj;

//  A obj2 = fun(obj);
  A obj2 = fun();
   
 std::cout << "\n object2 address  ===" << (int *) &obj2; 
 //  std::cout << "\n object2.i===" << obj2.i;
 std::cout <<"\n we are in main  and i ===" << obj2.i;


}

