#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string largestNumber(vector<int> &A)
 {
   // Do not write main() function.
   // Do not read input, instead use the arguments to the function.
   // Do not print the output, instead return values as specified
   // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   int i = 0;
   sort(A.begin() , A.end());


   std::cout <<"\n seet the sorted string";
  // const int k = A.size() -1;

   string  s = std::to_string(A [A.size() -1] );//A[k];
   string s1 ,s2 ;



   for(i = 0; i<A.size();i++)
   {
        std::cout <<"  " << A[i];
   }

   for( i = ( A.size() -2 ) ; i>= 0; i--)
   {
      s1  = s + std::to_string( A[i] )   ;
      s2 =   std::to_string( A[i]) + s;
    
      if( (s1) >  (s2) )
      {
        s = s1;
  
      }
     
     else
      {
        s = s2;

      }
   }

   
  std::cout <<"\n final string ====" <<s;

  
  
   
  
 

  




    return "hello";
   
}

int main()
{

  vector<int > input = { 1,34, 3,98,9,76,45,4} ;// {3, 30, 34, 5, 9};

  
 /* input.push_back(54);
  input.push_back(546);
  input.push_back(548);
  input.push_back(60);*/
 // input.push_back(9);
  largestNumber(input);

}
