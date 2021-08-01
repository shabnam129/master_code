#include <iostream>


int main()
{
 int n =0;
  int num=0;
 std::cout <<"\n enter the total number";
 std::cin >> n;

 std:::vector vec;
 std::cout <<"\n enter the element";
 for(i=0;i<n;i++)
 {
  std::cin>> num;
  vec.push_back(num);
 }
 
 
 int low,mid,max;

 low = vec[0];
 max = vec[2];

 for(i = 1 ;i<3;i++)
  {
   if(low > vec[i])
    {
      mid = low;
     
       
 
 
   
