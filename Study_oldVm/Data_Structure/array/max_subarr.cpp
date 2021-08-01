#include <iostream>
#include <vector>
using namespace std;




vector <int> maxSubArraySum(int *arr , int len)
{
  vector<int> res_vec;
   
  int i = 0;
  int small_index = 0;
  int large_index = 0;

  int sum = 0; 
  res_vec.push_back(small_index); 
  res_vec.push_back(large_index);
  res_vec.push_back(sum); 


  vector<int > pre_res;
   for(i = 0 ; i< len;i++)
   {
  
    if(arr[i]  <  0)
     {
       if(res_vec[2] <  pre_res [2] )
        {
          res_vec.clear();
          res_vec = pre_res;
        }
      pre_res.clear();
      sum = 0;
      small_index = arr[i+1];
      continue;
     }
  
    if(arr[i] > 0)
     {
         sum = arr[i]+sum;
     }
                
    if(arr[i+1] < 0 || (i+1) == len)
     {
       large_index =i;
       pre_res.push_back(small_index);
       pre_res.push_back( large_index);
       pre_res.push_back( sum);
       
     
     }

    }  
     
   if(res_vec[2] <  pre_res [2] )
     {
           std::cout <<"\n we are ib outside sum test";
          res_vec = pre_res;
     }
   
  small_index = res_vec[0];
  large_index = res_vec[1];
  sum = res_vec[2];

  res_vec.clear();

  std::cout << "\n small_index =="  << small_index ;

std::cout << "\n large_index =="  << large_index;

std::cout << "\n sum =="  << sum ;
    
  for(i = small_index ; i < large_index; i++ )
   {
    std::cout << "\n i===" << i << "\n ararry data====" << arr[i];
     res_vec.push_back(arr[i]); 
     std::cout << "\n valuee== " << res_vec[i];
   }

  return res_vec;
   
} 
 
  
  

/* Driver program to test maxSubArraySum */
int main()
{
   int  a[] = {1, 2, 5, -7, 2, 5};//, -9 ,4,5,10,80,80};
  // int a[] =  {-2, -3, 4, -1, -2, 1, 5, -3};
   int n = sizeof(a)/sizeof(a[0]);
   maxSubArraySum(a, n);
   //vector < int> subarray =  maxSubArraySum(a, n);
   int  i = 0;
  
/*   for(i = 0 ; i<subarray.size(); i++)
    {
     std::cout << " "  << subarra[i];

    }
*/   
   
  int max_sum = 0; 
   cout << "\n Maximum contiguous sum is " << max_sum;
   return 0;
}


