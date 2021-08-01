#include<iostream>
#include <typeinfo>
using namespace std;

class base
{
   public:
	base()
         {
              std::cout <<"\n we are in base constructor";
              i=10;
	}
   int i;

   virtual ~base()
   {
   }
 
/*  void virtual fun() 
   {
      std::cout <<"\n we are in base fun";
   }
  */ 

};

class drive: public base
{
   public:
   drive()
     { 
    
       std::cout <<"\n we are in drive constructor";
       j=20;
    }
   int j;

};

int main()
{
 
  base *b ;//= new base();

  b = new drive();
 
 
  drive *d = static_cast <drive *> (b);
  if(typeid(*d)!=typeid(*b))
  {
   std::cout <<"\nthey are diffe";
   std::cout <<"\nclass type of d==" << typeid(d).name() <<" and b="<< typeid(b).name();
  }
  else
  {
   std::cout <<"\n they are same";
   std::cout <<"\nclass type of d==" << typeid(d).name() <<" and b="<< typeid(b).name();
  
  } 
   
  std::cout <<"\n  value of variable" <<d->i;

}

