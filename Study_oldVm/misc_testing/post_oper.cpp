#include <iostream>

class Complex
{
  private :
  int x;
  int y;
  
  public:
  void showdata()
  {
   std::cout <<"\n valuee x====" <<x;
   std::cout <<"\n valuee y====" <<y;
  }

  void setdata()
  {
   x = 10;
   y = 20;
  // std::cout <<"\n valuee y====" <<y;
  }

 friend void fun(Complex &c)
 {
  c.x = 30;
  c.y = 40;
  //showdata();
 
 }  

};   

int  main()
{


 Complex r,s;

 r.setdata();
 
 fun(r);
// s=r++;

 r.showdata();
// s.showdata();
// r.showdata();

} 
 



