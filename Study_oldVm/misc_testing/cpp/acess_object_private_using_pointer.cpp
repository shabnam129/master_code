#include <iostream>


/*SAR::THIS PROGRAM  Proves that you can access private memeber using pointer 
Private Meber can be acess thorugh folowing

1.Member function
2.Freind dunction
3.Int pointer to object 

*/

class A
{
 public :
 int i;

 private :
 int j;

 public:  
 void setdata( int a ,int  b)
 {
   i =a;
   j =b;
 }
};


int main()
{

   A a;
   a.setdata(1 , 2);
 

   int * p =  (int * )&a;
   p++;
  
  std::cout << "\n value " << *p;
  

 
 
}
