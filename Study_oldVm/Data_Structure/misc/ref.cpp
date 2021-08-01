#include <iostream>

int main()
{

 int i=10;
 int &j = i;
  int k =  12;


 std::cout << "\nj===== " << j;

 j = &k;

 std::cout << "\nj===== " << j;

}
