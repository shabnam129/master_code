#include <iostream>


class Base
{
 public: 
 virtual void fun() { std::cout<<"\n WE are in fun of base class" ; }
 
 void solu( Base *b )
 {
  b->fun();
 
 }

};


class Derive:public Base 
{
 public: 
 virtual void fun() { std::cout<<"\n WE are in fun of Dervie class" ; }

 

};


int main()
{


 Base *b  = new  Derive;
 
 b->solu(b);
 //b->fun();

 return 0;
}

 

