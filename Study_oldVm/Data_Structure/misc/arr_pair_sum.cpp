#include <iostream>


const int size = 5;

int getpair(int * , int);

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
  int i=0; 
  int arr[size];

  int sum = 8;

  std::cout << "\nenter the array" <<size << "elements";
  
  for(i=0;i<size;i++)
   {
    std::cin >> arr[i];

   }
 
  //std::cout << "" <<  
  selectionSort( arr, size); 
  getpair(arr,sum);

}


int getpair(int *arr ,int sum)
{
    int low= 0;
    int hi = size-1;
    
     while(low < hi)
      {  
        
        int low_high_sum = arr[low] + arr[hi]  ;
        if( low_high_sum == sum)
         { std::cout << "\npair found " << arr[low] << ", " << arr[hi];
           low++;
           hi--;
          // return 1;
         }
        
         if(low_high_sum < sum)
            low++;
         if( low_high_sum > sum)
             hi--;

      }
      if(low == hi)       
      {
        std::cout << "\npair not fount " ;
           return 0;
      }  

} 
