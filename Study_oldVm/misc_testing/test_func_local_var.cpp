#include <iostream>


int * fun()
{
  int i=10;
  int m=40;
  int j=20;
  std::cout << "\n fun &i =====" << &i;
  return &i;  
}


void gun()
{
  int g=70;
   std::cout << "\n gun &g =====" << &g;

}


int main()
{

 int a;
 
 int *p =  fun();
 std::cout <<"\n vale ====" << *p;
 
  gun();

 std::cout <<"\n vali of p after g() ====" << *p;
  

}
