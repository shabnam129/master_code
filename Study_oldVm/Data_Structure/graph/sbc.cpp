#include <iostream>

struct node 
{
  int a;

  int b;


};

//THis prog shows that if pointer is used as an array then it can acess strucuter element using the p[].element and p->element as well
int main()
{

  struct node c;

  struct node *p;
  c.a =10;
  c.b =20;


  p=&c;


/*  a[0].a =10;
  a[0].b =20;

  a[1].a =30;
  a[1].b =40;
 */

//  p = a;

  std::cout <<"\n p[0].a====" << p[1].b  << p->a;




}
