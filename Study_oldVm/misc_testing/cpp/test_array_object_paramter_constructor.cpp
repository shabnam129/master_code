#include <iostream>
const int size=4;

class A
{
 public:
 int var;
  A (int a){
   var =a;
  }

};


int main()
{
//Array on stack
 //A *obj[size];//(2); 

//Array on heap
  A **obj = new A*[size];
 int i=0;
 
for(i=0;i<size;i++)
 {
     A a(10);
   *(obj+i) = &a ;
  std::cout <<"\n i===" << i <<"and var==" << obj[i]->var;
 }

}
