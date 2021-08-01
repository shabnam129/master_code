#include <iostream>
using namespace std;


int  maxSubArraySum(int *a , int len)
{
  int i = 0;
  
  int old_sum =a[0];
  int new_sum = a[0];
  int prev_sum = a[0];
  int update_sum = 0;

  for (i = 1 ; i < len; i++)
  {
    new_sum = old_sum + a[i] ;
     if( new_sum  < old_sum)
     {  
        int  k = prev_sum +  new_sum;
      if( k  > new_sum  )
        {
          prev_sum = k;
          update_sum = k;
        }   
      else
       {
         prev_sum = new_sum;
       }
    
       //prev_sum = new_sum;
       old_sum= 0;
       i++;
       
       continue;
     }
     old_sum = new_sum;

   
  } 

  return update_sum;     
  


}



 /*Driver program to test maxSubArraySum*/
int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
