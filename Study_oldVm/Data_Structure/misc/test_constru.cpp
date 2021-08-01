#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class HowMany
{
 
  
  public:
  HowMany() { cout << "\n hi iam in constructor \n" ; }//objectCount++;}
 
  HowMany ( HowMany const &ref ) {  cout << "\n hi COPY in constructor \n" ;}

 
   int i;
 
};


HowMany f(HowMany x)//Here object is passed by value thts why copy constructor is called
{
  //x.print("x argument inside f()");
  return x;
}


int main()
{
   HowMany h;
   f(h);
   //HowMany::print("\nafter construtnfion of h");
   //HowMany h2 = f(h);
  
  // HowMany::print("After call  to f() in main");
 
} 
