#include <iostream>
#include <typeinfo>
class  A
{

int i;
virtual void func(){};
};

class  B:public A
{
public:
int j;

//void func();

};


int main()
{

A *a = new A;
A *b = new B;

std::cout << "A=== " << typeid(*a).name();
std::cout << "\n A=== " << typeid(*b).name();


char c = 256;

std::cout << "c===" << c;
//a.i =b.j =1;

}
