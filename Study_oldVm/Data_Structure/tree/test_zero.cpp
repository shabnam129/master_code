#include <iostream>
#include <cstdlib>

#include <typeinfo>

using namespace std;
class Poly{

virtual void fun() {}
};



int main()
{

   try{
    Poly  *p =0;


   typeid(*p);
   }
  

   catch(exception& e)
   {
      cerr << "exceptio " << e.what();
   }

}



