#include <iostream>

using namespace std;
void threeWayPartition( int *, int , int , int);

int main()
{
    int arr[] = {1, 14, 5, 20, 4 };//, 2, 54, 20, 87, 98, 3, 1, 32};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    threeWayPartition(arr, n, 5, 20);
 
    cout << "Modified array \n";
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}


void  threeWayPartition(int *a, int n  , int low, int high)
{

  int i=0;
  int wall = 0;
  int p = 0;
 
   
  for(i=0;i<n;i++)
    {
     if(a[i] >  low  )
      {
       if(a[i] >= a[wall]);
       else 
       wall++;
      }
     else
      if(a[i] <low)
      {
        //swapping 
         int temp = a[wall];
         a[wall] = a[i];
         a[i] =temp;
         wall++;
      }
            

    }

wall=0;
   for(i=0;i<n;i++)
    {
     if(a[i] >  high  )
      {
       if(a[i] >= a[wall]);
       else 
       wall++;
      }
     else
      if(a[i] <high)
      {
        //swapping 
         int temp = a[wall];
         a[wall] = a[i];
         a[i] =temp;
         wall++;
      }
            

    }




}
