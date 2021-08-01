#include <iostream>



// A iterative binary search function. It returns location of x in
// given array arr[l..r] if present, otherwise -1
int BinarySearch(int arr[], int l, int r, int x)
{
  while (l <= r)
  {
    int m = l + (r-l)/2;
 
    // Check if x is present at mid 
    if(arr[l] <= arr[m] )
   {
    if (arr[m] == x)
        return m; 
 
    // If x greater, ignore left half 
    if (arr[m] >  x  && x > arr[l]  )// like if search  "6" in 5, 6, 7, 8, 9, 10, 1, 2, 3:w

        r = m - 1;
 
    // If x is smaller, ignore right half
    else
         l = m + 1;
   }

   if(arr[m] <= arr[r])
   {

    if (arr[m] == x)
        return m; 

    // If x greater, ignore left half 
    if (arr[m] <  x  && x < arr[r]  )
        l = m + 1;

    // If x is smaller, ignore right half
    else
         r = m - 1;
   }

  

  }
 
  // if we reach here, then element was not present
  return -1;
}


/* Driver program to check above functions */
int main()
{
   // Let us search 3 in below array
  // int arr1[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};

   int arr1[] = {50,10,20,30,40};
   int n = sizeof(arr1)/sizeof(arr1[0]);
   int key = 10;
   std::cout <<"Index: %d\n" <<  BinarySearch(arr1,0,  n-1, key);
   return 0;
}
