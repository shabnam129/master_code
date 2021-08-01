#include <iostream>
using namespace std;

int countRotations(int a[], int size)
{

 int i =0;

 int min =a[0];

 for( i = 0 ; i <size ; i++)
 {
   if(a[i+1] < a[i])
   return ++i;
 }


}
   
 

 // Driver code
int main()
{
    int arr[] = {15, 18, 2, 3, 6, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << countRotations(arr, n);
    return 0;
}
