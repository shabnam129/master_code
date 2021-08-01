#include <iostream>


const int size = 5;

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
  for(i =0 ; i <= size -1;i++)
   {
      //min=a[i];
    for(j =i ; j <= size -1; j++)
     {
       if( a[i]> a[j])
        {//swap
           int temp;
           temp = a[i];
           a[i] = a[j];
           a[j] = temp;

        }

     }//end of inner for loop
             

    }

 std::cout <<"\n sorted list elelem===";

  for(int i=0 ; i < size ; i++)
   {
    std::cout << a[i];
   }



}          
    
