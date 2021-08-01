#include <iostream>

/* Logic ::  let  origninal array  be liek a[i ]  {a,b,c,d,e} and  of sum of original array i.e a+b+c+d+e   = z . 
in input /encrypted array  b[0] = z- a eq1
b[1]  = z-b ....eq2
b[2] = z -c ....eq3
 ans so on  .. so adding   equation becomes  after adding above eq 5z - (a+b+c+d+e) = b[0]+ b[1]+b[2] + b[3] +b[4]...Since we know input array ...add thier elemen we can get the input  aaray sum  ...ans 4z = input_arra_su mm....The z =  input_arra_su  / 4 in this case other qwise size -1 in plave of 4 ...now we have fot 

PRoghttp://www.geeksforgeeks.org/find-original-array-encrypted-array-array-sums-elements/
*/
const int size =5;

int main()
{

 int input_array[size] = {10,14  , 12,13,11};

 int orig_array[size] ;

 int i = 0;
 int old_array_sum=0;
 int input_array_sum = 0;

 for(i = 0 ; i <size; i++)
 {

   input_array_sum = input_array_sum + input_array[i];

 }


 old_array_sum = input_array_sum / (size-1);

 
 for(i = 0 ; i < size ; i++)
 {
   orig_array[i] = old_array_sum - input_array[i];

 }

 for(i = 0 ; i < size ; i++)
 {
   std::cout  << "\n orig_array === " << orig_array[i];

 }
  

 
 

 




}
