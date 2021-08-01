/* C program for Merge Sort */


/*LOgic::::Sort the matrix using merge and 2-d aray concept
for sorting :::use the concept of 2-d array.A[0] will give the starting adrress of 2-d array and arr itself  double pointer a[0] will point to 1-d array of int ...arr is pointer of array of pointers... and pointer points to some location where actaully data is soted 

Use link 
2-d array ::https://www.youtube.com/watch?v=0taz_-bdABE

geeks for geeks :: http://www.geeksforgeeks.org/maximum-and-minimum-in-a-square-matrix/
*/

#include <iostream>
#include<stdlib.h>
#include<stdio.h>

#define max 3
 
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



  /* Driver program to test above function */
int main()
{
// int n=3;  
 
 int arr[max][max] = {5, 9, 11, 25, 0, 14, 21, 6, 4};

 int  n = sizeof(arr) /sizeof(arr[0][0] );

  std::cout <<"\n size of arra===" << n << "\n";
  
  int *p = arr[0];
  int i , j;
   i = 0;
   j = 0;
 
   mergeSort(p , 0, n-1);
   
   for(i = 0 ; i< 3;i++)

   { 
     
    for(j=0;j<3;j++)
     std::cout << " " << arr[i][j];
  }
    

 std::cout << "\nmin==" <<arr[0][0]  << "\nmax==" <<arr[2][2]; 

 
 // maxMin(arr, 3); 
  return 0;
}
