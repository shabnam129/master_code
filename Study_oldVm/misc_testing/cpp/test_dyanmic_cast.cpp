#include <iostream>

class Pet{
public:
Pet(){"\n Pet constructor";}

virtual ~Pet(){"\n Pet DEstructor";}

};

class Dog:public Pet
{
public:
Dog (){"\n Dog constructor"; }
~Dog (){"\n Dog Desstructor"; }

};


class Cat:public Pet { //Dog{
public:
Cat (){"\n Cat constructor"; }
~Cat (){"\n Cat Desstructor"; }

};



int main()
{

  Pet *p = new Cat();


  Dog *d = dynamic_cast<Dog*> (p);

// note to call eelse part make cat derived from Dog
  if(d==NULL)
   {
     std::cout << "\n the p is poting to an object which is not of type  of DOgand niether direclty dervice from Dog ";

  }
 
 else
 {
  std::cout <<"\n gothcaa";

 }
   

 


}
