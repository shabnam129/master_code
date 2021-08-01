#include <iostream>
/*To Prove:: if there is parent class A and two class B and C derived from it . If use the above two class to inherited in other class D .Than class D will have two copy of grandparent that is A.As a result ambiuity will happen//TO resolve this use virutal keyword while inherting such that only one copy of grandparent is copied to the child  



*/

class A
{
 public:
 int i;
 void fun () {
 std::cout <<"\n we are in Class A";
 }
};

class B:virtual  public A

{
public:
int i;
/* void fun () {
  std::cout <<"\n we are in Class B";
 }*/
};


class C:virtual public A
{
 public:
 int i;
 /*void fun () {
  std::cout <<"\n we are in Class B";
 }*/
};



class D: public B , public C 
{
 public:
 int i;
 /*void fun () {
  std::cout <<"\n we are in Class B";
 }*/
};



int main()
{
 std::cout <<"\n hi iam in main";
 D obj;
 //c.ii10;

 std::cout <<"\n check func of C" ;
 obj.fun();

}
 

