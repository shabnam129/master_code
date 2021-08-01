#include <iostream>
#include <vector>


void swap(int *t1,int *t2)
{
   std::cout <<"\n we are in swap";    
   int *temp;
   *temp = *t1;
   *t1= *t2;
   *t2=*temp;
   
}

int main()
 {
   // Do not write main() function.
   // Do not read input, instead use the arguments to the function.
   // Do not print the output, instead return values as specified
   // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   
  std::vector<int > A ={1,2,3,4}; 


  
  int temp, i;
   for(i=0;i<A.size();i++)
   {
       std::cout <<"value of i==" << i;
       //even
       if(  (i==0)  && ( A[i] < A[i+1] ) )
       //swap
       {
           std::swap( A[i]  ,A[i+1]);
           continue;
       }    
       
               //even
       if(  (i%2==0)  && ( A[i] < A[i+1] ) )
       //swap
       std::swap( A[i]  ,A[i+1]);
       
       
       //odd
       if(  ( (i%2)!=0) &&  ( A[i] > A[i+1])  )
       //swap
       std::swap( A[i]  , A[i+1]);
       
       // return A;
       
   }

 std::cout <<"\n Modified array===";
 for(i=0;i<A.size();i++)
  {
    std::cout <<" " << A[i];
  }
}

