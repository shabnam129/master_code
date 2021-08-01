#include <iostream>

#define  size 5

//Logic behind theis...first sort the elements...then use the same logic as in pair array sum used but with some extensiotn ...Keep take the sum of leftmost and right most numbers .If sum is greter than 0 ..then decemeent right/higher index..Bcoz it means that the sum can be produced from tight most...If  this tempsum is less than actual or qual to 0...then do binary search check the third element which on addtion with this tempsum  can make it equal to zero...If its found than than means the sum can increment lower index...If low== higher




//Note:: for testing pupose iam expecting sorted input


// A recursive binary search function. It returns location of x in
// given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)  return mid;
 
        // If element is smaller than mid, then it can only be present
        // in left subarray
        if (arr[mid] > x) return binarySearch(arr, l, mid-1, x);
 
        // Else the element can only be present in right subarray
        return binarySearch(arr, mid+1, r, x);
   }
 
   // We reach here when element is not present in array
   return -1;
}


int main()
{
  int i=0;
  int arr[size] ;
  int sum;
  std::cout << "\nenter the array";
  
  for(i = 0 ; i < size ;i++)
  {  std::cin >> arr[i];

  }

  std::cout << "\nenter the sum  ";
  std::cin >> sum;
 
  int j = size-1;
  int temp_sum = 0 ;
   i = 0;

  
   while ( i<= j )
   {
    temp_sum= arr[i] + arr[j];
    if(temp_sum  > sum )
    {
     j--;
     continue;
     
    }

    if(temp_sum <= sum)
    {
    std::cout << "\nsum less  i ====" << i << " andd j=== " << j;

    int result =   binarySearch( arr , i+1 , j-1 , -temp_sum);
      (result == -1)? std::cout << "Element is not present in array\n" 
                 : std::cout << "Element is present  an are === " <<arr[i] << arr[j] <<-temp_sum << "\n";

    } 
    i++;
   // j--;

  }//end of while  
  

}  




// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
} 
