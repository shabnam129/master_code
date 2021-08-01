//: C12:ExplicitKeyword.cpp
// Using the "explicit" keyword
#include <iostream>


class Number;
void g(Number );

class Number{
   public : 
   int i ;
   Number(int x = 0):i(x) {std::cout << "\ndefault  constructor of class Number";}

   int operator + (const Number & n)
   {
     return (i+n.i);
    
   }

  friend void g(Number n  ) {std::cout <<"\n hello g is freind of Number";}
};


class One;

class Two {
  public:
 
  //here destination or actual arugments will be called and work for automatic conversation using copy consturctor 
    Two(const One&) { std::cout << "\n source getting coverted using copy construstor";}
};


class One {
public:
  One() { std::cout <<"\n defualt const for ONe";}
  //Here scource class will work and  automatic conversation will  be done by operator overloading 
  //Source class is working get the object of two type by calling its member function  operator Two() const  which return two bje
  operator Two() const { std::cout <<"\n source has converted itself into obj two " ; return Two();}
};




void f(Two) {}

//void g(Number x){ std::cout <<"\niam in g";}

int main() {
One one;

//in below call source is one and destionation in two.WE need to convert One into two either using copy consturtor of dest or operator func of source 
 f(one);
//! f(one); // No auto conversion allowed
//f(Two(one)); // OK -- user performs conversion
Number n(7);//craeting a object of number tyoe with deaukt falue 7

int k;

std::cout <<"\nnow see that Number class constructor  will be called for 8, as auto matic converstsation will be called for 8";

 k = n + 8;


 std::cout << "\n value of k==="<< k ;

 g(1);//Here g expect Number type object but we are passing int ...So since Number class  has consturcotor of this type ..so object for 1 will be creating and that will be passed to g 
} 
