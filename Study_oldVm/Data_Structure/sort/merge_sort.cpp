#include <iostream>
#include <cstdlib>


/*
lOGIC::Divide the array into half ...left array contains the element from 0 to middle and right array middle+1 to last.
like in 54321 ..in first iterration left 543  and right 21 ...do this untill l<r.  As soon last elemt s reached array like 5 ..the return should return back the array pointer..  in this way left will have 5 and right would have 4 ..Now merge them into new array  which will return the sorted aaray..THe processcing will be in hang state for orignal left which contained 54. so Left of this would be 45 and next stataemnt would right=3 ..Now merege them two and return ..this way sorting is completed


*/

const int size = 10;

int * merge_sort(int *arr, int , int);
int *sort_and_merge(int *arr,int [],int ,int );

int main()
{
  int a[size];
  std::cout << "\n enter the " << size << "elements";
  for(int i=0 ; i < size ; i++)
   {
    std::cin >> a[i];
   }
  
  std::cout <<"\n entered elelem===";

  for(int i=0 ; i < size ; i++)
   {
    std::cout << a[i];
   }
  
  int l=0;
  int r= size-1;

  int *p = merge_sort(a, l , r); 
  //array after sorting

  std::cout << "\n after sorting";
  for(int i=0 ; i < size ; i++)
   {
    std::cout << p[i];
   }



}         

int* merge_sort(int *arr ,int l ,int r)
{
  int *left;
  int *right;
  
  int i , j , k, t;
  if(l < r)
  {
 
  int m= l+ (r-l)/2;
  i=j=k=0;
  int count_l = 0;
  int count_r = 0;
  left = (int *) malloc(sizeof(int) *(m-l) ) ;
  right = (int *) malloc( sizeof(int) *(r-(m+1)) ) ;

  for(i = l , t =0 ; i<=m ; i++, t++)
  { 
    
   left[k]=arr[t];
    
    count_l++;
    k++;
  }
  
  k=0;
  int s =0 ;
  for(j = m+1, s=t; j<=r ; j++,s++)
  {
  right[k]=arr[s]; 
  count_r++;
  k++;
  }
  
  left = merge_sort(left, l ,m);
  right = merge_sort(right, m+1,r);

  arr = sort_and_merge(left,right,count_l,count_r);
 
  free(left);
  left=NULL;
  free(right); 
  right=NULL;

  }
  
  return arr;

}

//like sort and mege ( 54 and 3 ---->345)
int *sort_and_merge(int left[],int right[],int count_l,int count_r)
{
  int i , j , k;
  i = j = k = 0;
  int *p;//Pointer which wil hold the sorted array

  //create new pointer as size of largest aaray from left,right 
  if( count_l >= count_r)
  p = (int *) malloc(sizeof(int) * count_l);
  else
  p = (int *) malloc(sizeof(int) * count_r); 

 //fill the array with by comapring left and right array  
  for(i=0, j=0 , k=0; i< count_l && j< count_r ; k++) 
   {
    if(left[i] < right[j])
    {
     p[k] = left[i];
     i++;
    // k++;

    }

    else
     {
       p[k] = right[j];
        j++;
     }   
 
    }

  //if right is exahusted than fill with reamining left half into resulatant array
  if( i <count_l)
   {
     while( i <count_l)
     {
       p[k] = left[i];
       i++;  
       k++;
    }
      
   }
  //if left is exahusted than fill with reamining right half into resulatant array
  if( j <count_r)
   { 
     while( j <count_r)
     {
       p[k] = right[j];
       k++;
       j++;
    }

   }

  return p;



}

   
    
 

   



    
