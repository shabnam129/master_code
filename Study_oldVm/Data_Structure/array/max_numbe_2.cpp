#include <iostream>
#include <vector>
#include <string>


using namespace std;

string largestNumber(const vector<int> &A)
 {
   // Do not write main() function.
   // Do not read input, instead use the arguments to the function.
   // Do not print the output, instead return values as specified
   // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
   
   vector<int > vec(10);
   
   vec.assign( 10 , 0 );
   int i =0;
   int num = 0;
   int count = 0;
   int digit = 0;
   int j =0;
   for(i = 0; i < A.size();i++)
    {
        num = A[i];
       
        for(j = 0;  num/10 ;j++)
        {
           digit= num%10;
           
          vec[digit] = vec[digit]+1;
          num = num / 10;
        }
       
        vec[num] = vec[num]+ 1;
       
    }
   
    std::string s;
   /* for(i= 0; i<10;i++)
   {
    cout <<"\ni===" << i <<"and vec==" << vec[i];
   }*/
   
   for(i= 9; i>=0;i--)
   {
     if(vec[i]!=0)
      {
       for( j =0 ;  j <vec[i];j++)
       s =s + std::to_string(i);
       cout << "\n s===" <<s;
     }    
   

    //cout <<"\ni===" << i <<"and vec==" << vec[i];
   }





    return "hello";
   
}

int main()
{

  vector<int > input = { 3, 30, 34, 5, 9};// { 1, 3,5};
  //[3, 30, 34, 5, 9]

  
  /*input.push_back(3);
  input.push_back(30);
  input.push_back(34);
  input.push_back(5);
  input.push_back(9);*/
  largestNumber(input);

}
