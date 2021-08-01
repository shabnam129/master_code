#include <iostream>


const int size = 10;

int main()
{
  int a[size];
  std::cout << "\n enter the " << size << "elements";
  for(int i=0 ; i < size ; i++)
   {
  
    std::cin >> a[i];
   }
  
  std::cout <<"\n entered elelem===";

  for(int i=0 ; i < size ; i++)
   {
    std::cout << a[i];
   }
 
  int i , j;
  for(i =0 ; i < size-1;i++)
   {
      //min=a[i];
    for(j =i+1 ; a[j] < a[j-1] ;  j--)
     {
        if(j==0)
           break;
        if(a[j] < a[j-1])
       { //swap
           int temp;
           temp = a[j];
           a[j] = a[j-1];
           a[j-1] = temp;

      }  

     }//end of inner for loop
             

    }

 std::cout <<"\n sorted list elelem===";

  for(int i=0 ; i < size ; i++)
   {
    std::cout << a[i];
   }



}          
    
