#include<stdio.h>
#include<stdlib.h>
 
void printRepeating(int arr[], int size)
{
  int *count = (int *)calloc(sizeof(int), (size - 2));
  int i;
   
  printf(" Repeating elements are ");
  for(i = 0; i < size; i++)
  { 
    printf("\ni ===%d array_eleme ===%d countt===%d" ,i, arr[i] ,count[arr[i]]);
    if(count[arr[i]] == 1)
      printf(" %d ", arr[i]);
    else
   {
    // printf("\ni ===%d array_eleme ===%d countt===%d" ,i, arr[i] ,count[arr[i]]);
     count[arr[i]]++;
     printf("\ni ===%d array_eleme ===%d countt===%d" ,i, arr[i] ,count[arr[i]]);
   }
  } 

}    
 
int main()
{
  int arr[] = {4, 2, 4, 5, 2, 3, 1};
 int a[1]={7};
  int arr_size = sizeof(arr)/sizeof(arr[0]); 
  printRepeating(arr, arr_size);

 // int a[1]=7;

  a[0]++;
   printf("\n now check a=======%d" ,a[0]);
   
//getchar();
  return 0;
}
