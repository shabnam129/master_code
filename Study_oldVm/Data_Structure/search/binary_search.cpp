#include <iostream>


const int size =5;

int main()
{

 int i ;
 int middle_elem = 0;

 int l , h;
 l = 0;
 h = size -1 ;

 int a[size];
 
 middle_elem = ( (h -l )/ 2) + 1 ;

 std::cout << "\n enter the numbers" ;
 
 for( i = 0; i < size ;i++)
  {
   std::cin >> a[i];
  }
   
  std::cout << "\n enter the  numbers to be search " ;
  int k;
  
  std::cin >> k;
 

 for( i =0 ; l <h; i++)
  {
  
  if(a[l] == k)
  {  std::cout << "element found at index" << l; 
      break;
  
   } 
   middle_elem = ( (h-l )/ 2) + 1;
   if(k == a[middle_elem])
   {  
     std::cout << "element found at index" << middle_elem;
     break;
 
   }
    if( k > a[middle_elem])
     {
           l = middle_elem + 1;

     }

     if( k < a[middle_elem])
     {
           h =  middle_elem -1;

     }
   
   }
  
  if(a[h] == k)
  std::cout << "element found at index" << h;


}
