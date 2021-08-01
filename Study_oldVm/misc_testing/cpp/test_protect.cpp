#include <iostream>

class A{

 protected :
  int i;
 void set(){std::cout << "\n CLASS A";}

  public :
   int j;


  private:
   int  k;


};



class B:public A
{
 public:
 void change (){ std::cout<< "\n CLASS B" ;set();}
 
};

int main()
{


  A a;
//  a.i =10;
  a.j=20;

  B b;

  b.change();
  
 // a.k=30;


}




