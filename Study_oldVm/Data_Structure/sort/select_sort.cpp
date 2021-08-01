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
 
  int min = a[0];
  int pos = 0;
  int i , j;
  int temp;
  for(i =0 ; i <= size -1;i++)
   {
      //min=a[i];
      pos = i;
    for(j = i ; j <= size-1  ; j++)
     {
       if( a[pos] > a[j])
        {//swap
            pos = j;
        }

     }//end of inner for loop

     //swap
      temp = a[i] ;
      a[i] = a[pos];
      a[pos] = temp;
   
             

    } //end of outer foor loop

 std::cout <<"\n sorted list elelem===";

  for(int i=0 ; i < size ; i++)
   {
    std::cout << a[i];
   }



}          
    
