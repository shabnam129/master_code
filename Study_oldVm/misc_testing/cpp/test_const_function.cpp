#include <iostream>


class Base
{
 public:
 virtual void fun() const
 {
  std::cout <<"\n we are in FUN Of BASE";
 }


}; 


class Derived:public Base
{
 public:
 void fun()  
 {
  std::cout <<"\n we are in FUN Of DErvied";
 }


}; 


int main()
{

std::cout <<"\n size of base==" <<sizeof(Base);

std::cout <<"\n size of Derived==" <<sizeof(Derived);


Base * base_ptr = new Derived();
 
 base_ptr->fun();
}

