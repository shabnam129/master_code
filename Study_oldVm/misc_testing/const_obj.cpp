#include <iostream>

class Test
{
 public:
 int i;
 
 int  fun() const {return i;}
 int non_const_fun() {return 1;}
 
 Test(int x=10 ):i(x){}

};

int main()
{

 Test t1;
 const Test t2;
 
 t1.fun();
 t2.fun();
 t1.non_const_fun(); 
}
