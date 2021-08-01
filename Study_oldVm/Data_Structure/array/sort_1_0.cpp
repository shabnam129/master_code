#include <iostream>

//Logic::Use left and right pointers..if left pointer has one and right pointer has zero then do swapping...If  l=1 and r=1 then save left position and move giht t i.edec right pointer ..if right pointer has zero then save this position and incremnt left and check things again ..Please refer geeks for geeks also and its my verison of promagg..ue input like 1,0,1,0,1,1 ...rsult 0,0,1,1,1,1.


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
  
 int *l = &  a[0 ];
 int *r = &  a[size-1];

 for( i = 0 ; l<=r ; i++)
 {


    

  if( *l < *r)
   {
      l++;
      r--;
      continue;
   }

  if( *l > *r)
  {
   //swapp
   int temp = *l;
   *l = *r;
   *r = temp;
  
   l++;
   r--;
   continue;  

  }
//save position ...if l =1 then save this poistion(left and decrement right) ,, so that it can be used for swapping and if r=0 then save right and increment left
  if( (*l) == *r )
   {
      if(*r == 1) 
      r--;
      else 
   l++;

   }

 }

 
 //print array
 std::cout <<"\n modified array\n";

  for (i = 0; i< size ;i++)
 {
   std::cout <<  a[i];
 }
 
 



}
 


  
  
  
  
