#include <iostream>




auto f() {
   unsigned x = 0;
   return [x]() {
       return x++;
   };
}

unsigned g() {
   auto a = f();
   a();
   auto b = f();
   b();
   return a() + b();
}
int main()
{

g();

} 
