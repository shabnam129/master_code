#include <iostream>

const int size = 6;

int main()
{
 int i;
 int a[size];
 int data;
 std::cout <<"\n Enter the array eleme";
 for (i = 0; i< size ;i++)
 {
   std::cin>> data;
   a[i] =data;
 }
  
 
 //int arr = { 12,13,1,10,34,1};

 
 int s = a[0];
 int g= a[1];

 if(a[0] > a[1])
 {
   s = a[1];
   g = a[0];
 } 

 for(i=1 ; i <size ; i++)
 {
  if(a[i] > g)
   continue;
  else if (  ( a[i]  < g ) &&  (a[i]  > s)  )
     g = a[i];
  else if (   a[i] < s  )
     s = a[i];

 }

 std::cout <<"\n first smalles elemet =" << s <<"\n second smallest =" << g;


}
 


  
  
  
  
