#include <iostream>
#include <vector>
#include <utility>


int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}


std::pair<int ,int> getMedian(int a1[], int a2[], int len)
{
  std::pair<int ,int > test;
   int m1,mid,m2; 
 
  if (len ==2)
  {
    
   if(a1[0] > a2[0])
     m1 =a1[0];
   else
     m1=a2[0];

   if(a1[1] < a2[1])
     m2 =a1[1];
   else
     m2=a2[1];
  
    std::cout << " pair  m1= " << m1 <<"and m2===" << m2;

   return std::make_pair(m1,m2);
 

 } 	    	  
 
 
   
   m1 =median(a1,len);//a1[len];
   m2 =median(a2,len);//a2[len];
 
  if(m1 < m2)
  
   test = getMedian( a1+(len/2),a2,len);
 
  else
  test =  getMedian( a1,a2+len,len);


  return test;  
  


}

/* Driver program to test above function */ 
int main() 
{
	int ar1[] = {1,5,7,18};//{1, 2, 3, 6}; 
	int ar2[] = {2,3,10,30};//{4, 6, 8, 10};
	int n1 = sizeof(ar1)/sizeof(ar1[0]);
	int n2 = sizeof(ar2)/sizeof(ar2[0]);
	if (n1 == n2) 
	//	std::cout <<"\nMedian is " << 
			std::pair<int ,int> mid_point =  getMedian(ar1, ar2, n1); 
	else 
		std::cout << "Doesn't work for arrays of unequal size";
	return 0;
}

