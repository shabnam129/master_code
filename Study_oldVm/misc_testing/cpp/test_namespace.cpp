#include<iostream>

/*AIM ::This prog porves that namepace are not like header file once use variable inside a namespace  using key word  using than it will reflect there untill  newnamsepave is not derclared*/

namespace x
{

 int z =10;;

}


namespace y
{

 int z=20;

}


int main()
{

using namespace x;

std::cout << "\n hello jiiivalue of x ===" << x::z;

using namespace y;
std::cout << "\n value of x ===" << y::z;

} 
  


