#include <iostream>

class A{};

int main()
{

A a1, a2;

A &r1 =a1;

r1=a2;
A &r2 = a2;

}

