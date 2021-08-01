#include <iostream>

const int size = 5;
int main()
{
  int i, j;
  j=0; 

  int a[size];
  int queue[size];
  bool   flag ;
  int count = 0;

 std::cout << "\n enter the " << size << "numnerr====" ;
 for(i=0 ; i < size ;i++)
  {
   std::cin >> a[i];
  }

  int temp = 0;
 for(i=0 ; i <3 ;i++)
  {
    for(j= size-1; j >=0; j--)
    {
         if(j == (size-1) )
          {
             temp = a[j];
          }


          else
           {
             a[j+1]=a[j];

           }
    } //end of inside loop      
    
    a[0] = temp; 
  }
//  a[0] = temp;

  std::cout << "\n after roatation array umnerr====" ;
 for(i=0 ; i < size ;i++)
  {
   std::cout  << " " <<  a[i];
  }



}
