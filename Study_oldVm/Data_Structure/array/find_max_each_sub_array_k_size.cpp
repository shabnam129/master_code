#include <iostream>
#include<deque>
//Logic::Refer geeks for geeks max elem in sliding window or u can check youtube video of Ideserver:wq

//void printkMax(int * , int  , int );

void printkMax(int *a , int n  , int k)
{

 std::deque<int> queue;

 queue.push_back(0);
 
 int i=0;
 int count =0;
  int index=0;
 //int f = queue.front();
 for(i=1;i<k;i++)
 {
   index = queue.back();
   
  std::cout <<"\n back  index===" << index;  
  
  if(a[index] > a[i])
   {
     queue.push_back(i);
    continue;
   }
    queue.pop_back();
     queue.push_back(i);

 } 
 
 std::cout<< "\n Lets print the greter elements" << a[queue.front()];

 for(i=k;i<n;i++)
 {
   if( (i-k) >=queue.front())
    {
     queue.pop_front();
    }
    
    index=queue.back();

//  std::cout <<"\n back  index===" << index;  
  // queue.pop_back();
  
  while(a[index] < a[i])
   {
      queue.pop_back();
      if(queue.empty())
       break;
      index=queue.back();
   }
   
   queue.push_back(i); 

  std::cout <<" " <<a[queue.front()];
 }


    
 
}
 
int main()
{
//  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
   
  int arr[] = {4, 2, 3, 5, 4, 1, 3, 8, 9, 10};
  int n = sizeof(arr)/sizeof(arr[0]); 
  int k = 3;
  printkMax(arr, n, k);
  return 0;
}


 
