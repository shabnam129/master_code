#include <iostream>

const int size = 10;
int main()
{
  int i;

  int a[size];
  int queue[size];
  bool   flag ;
  int count = 0;

 std::cout << "\n enter the " << size << "numnerr====" ;
 for(i=0 ; i < size ;i++)
  {
   std::cin >> a[i];
  }


for(i=0 ; i < size ;i++)
  {
   queue[i] =-1;
  }

 for(i=0 ; i < size ;i++)
  {
    if(queue[ a[i] ] ==-1 ) 
     {
      count++;
      queue[a[i]] = 0;

     }   
  }

std::cout << "\n distince value===" << count;

}
