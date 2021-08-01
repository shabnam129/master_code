#include <iostream>


class B{
int a;
virtual showData(){}
}

class D ::public B{ int c}
void main()
{

  base *b;
  base obj_b;
  
  std::cout<< "\n size of obj " << sizeof(b);
  
  
  derive d;
  b = &d;

  std::cout<< "\n size of obj when deriver  " <<  sizeof(b+1);

}

