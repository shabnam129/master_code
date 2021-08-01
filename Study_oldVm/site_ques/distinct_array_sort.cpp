#include <iostream>
#include  <algorithm>

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


 std::sort(a, a+size);
 std::cout <<" unique numbers are" ;
 
 for( i= 0 ;i<size ;i++)
  {
    
   while(a[i] == a[i+1])
    i++;
   std::cout << " " << a[i] ;

  }  

   

std::cout << "\n distince value===" << count;

}
