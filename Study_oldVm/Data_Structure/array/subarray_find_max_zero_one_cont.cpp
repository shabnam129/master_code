#include <iostream>
#include <map>
#include <unordered_map>
#include <utility>
using namespace std;

/*Logic::This progamm is equal to check subarray with equal  of sum=0 ...for this logic is go on  summation of each element and set each sum in put in  hash with index ..and any point the same sum is visited again it means the this the  point when the sum is repeated ...difference of current index with previous index sum gives the answer..This apporach can be further used in this progmm by converting zero to -1 and then  the count and indexes with sum   where the Check if the sum is already been set .subarray with same sum ..then check index difference and i

https://www.youtube.com/watch?v=hLcYp67wCcM
http://www.geeksforgeeks.org/find-if-there-is-a-subarray-with-0-sum/

4 ,-2,-1,-1, 0
4,2,1,0,0
Condition check::Either loop or sum=0 where sum is zero at index 3..So when whole thing is added it sum to zero so anqer wil be 0,3

 */
void changeArr( int *, int);
void findSubArray(int * , int);
int main()
{

    int arr[] = { 0,0,0,1,1,1,1,0,1};// { 1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0, 0,1,1,1, 0,0,0,0,0}; // {0,0,0,1,1,1,1,0,1};
    

   // int arr[] = { -1,-1,-1,1,1,1 , 1 , -1 ,1};//   {4, 2, -3, 1, 6};
    int size = sizeof(arr)/sizeof(arr[0]);

    std::cout <<"\n size of arr=" <<size;
     changeArr(arr,size);
 
    findSubArray(arr, size);
    return 0;
}
void changeArr(int * a ,  int len)
{
 int i =0;
 for(i=0;i<len;i++)
  {
    if(a[i]==0)
       a[i] = -1;
  }
}


void findSubArray(int *a ,int n)

{
 
 
 int i =0;

 unordered_map<int , int> sum_occr;
 sum_occr.reserve(n);

 unordered_map<int , std::pair <int , int >> max_count_index;
 max_count_index.reserve(1);

 int sum = a[0];
 sum_occr[sum] = 0;

 
  int max_count = 0;
 for(i=1;i< n ; i++)
  {
      
     sum = sum +a[i];
     if(sum_occr.find(sum) == sum_occr.end() )
    { 
     //not found
    // int sum = sum+a[i];

       sum_occr[sum]=i; 

    }
    else
    {

     //found
       
     std::cout <<"\n sum isfound  i==" << (sum_occr[sum] + 1)  <<" j===" <<  i;
     if(  ( i - ( sum_occr[sum] + 1) ) > max_count )
     {
        max_count =  i - ( sum_occr[sum] + 1) ;
        max_count_index[0] = make_pair(sum_occr[sum] + 1 , i);


     } 
        
   
 
    }
    if(sum==0)
     {
       std::cout <<"\n sum isfound  i==" << 0  <<" j===" <<  i;
   // if(  ( i - ( sum_occr[sum] + 1) ) > max_count )
       max_count =  i - 1; 
       max_count_index[0] = make_pair(0 , i);
 

     }
    
  } //end of for loop 

  std::cout <<"\nmax_count ===" <<max_count;

  std::cout <<"\nmax_count_index==" << max_count_index[0].first <<" " << max_count_index[0].second;


}


