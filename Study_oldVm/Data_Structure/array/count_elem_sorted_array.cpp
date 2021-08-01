#include <iostream>
/*logic:::find the number is occuring in arrat using binary search...each time u encounter the number incrment the counter...u need to move in left annd right...
left movement will happpen in two cases...if the element on mid-1 has key data...it means that some key data is present on left...2nd time will happen when first serching for data element than also u wanr left movment...like in below exampel when we searching 9 ...so it may happen than in first search we dont find 9 at mid postio..currenltu it has but it due to input i have set...in that condiotn u have to move righ5 or left depepending on mid element value.if its greater thsn  key data than move to left else right
*/

int Binary_search_count( int *a , int l , int r , int x)
{
  static int count = 0;
  int mid  = 0;
  if(l <= r)
  {

   mid = l + (r-l) /2;
   
   if(a[mid] == x)
    count ++;
   
   if( ( a[mid] == x && a[mid-1] ==x ) || a[mid] > x)
   {
     Binary_search_count( a , l ,  mid-1 ,  x);

   }
  
  if( ( a[mid] == x && a[mid + 1] ==x ) || a[mid]  < x)
   {
     Binary_search_count( a ,mid + 1  , r  ,  x);

   }
   
     
 }
 return count;  
   


}


  /* driver program to test above functions */
int main()
{
  int arr[] = {1, 2, 4, 5, 9, 9, 9,9,9,10,11,12,13};
  int x =  9;  // Element to be counted in arr[]
  int n = sizeof(arr)/sizeof(arr[0]);
  int c = Binary_search_count(arr,  0 , n-1 ,x) ;
  std::cout << "occurs  times " << c ;
  return 0;
}

