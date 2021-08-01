#include <iostream>
using namespace std;

class Solution
{

  public:
 int reverse(int);
};


int main()
{

  Solution sol;
  int num;
  std::cout <<"\nenter the number to be revse";
  std::cin>> num;
  int k = sol.reverse(num);
  std::cout<<"\n Reverse num===" <<k;

}

int Solution::reverse(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
 
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    int count = 1;
    int i=0;
    int ten=1;
    int neg_flag=0;
    int ten_high_flag=0;
     std::cout <<"A===" <<A;
     if(A<0)
     {
         A = -A;
         neg_flag=1;
     }
     
    for( i =1 ;ten< A;i++)
    {
        ten  = ten*10;
        count++;
        if(ten == 1000000000 )
         {
         // break;
          ten_high_flag=1;
           break;
         }
    }
   if (ten_high_flag ==0)
    ten = ten/10;
   // std::cout <<" max digit==" << ten << "and count===" <<count <<std::endl;
    
    int rem =1;
    int place =1;
    int sum = 0;
    for (i= 0; i<count ;i++)
    {
        
     //   std::cout <<" A===" <<A;
         if(ten==0)
           continue;
        rem = A/ten;
        
        A = A%ten;
        sum = sum + rem*place;
        place =place*10;
        ten =ten/10;
        
        
    }
    if(neg_flag==1)
    return -sum;
    else
    
    return sum;
    
}



