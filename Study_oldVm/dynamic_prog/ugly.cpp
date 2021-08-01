#include <iostream>

int arr[20];


/*This function divides a by greatest divisible
  power of b*/
int maxDivide(int a, int b)
{
   int rem = a%b;
   int quo = a/b;
  if(rem!=0)
   return a;

  if( (rem == 0) &&  (arr[quo] == 1 ) ) 
   {
     // arr[a] = 1;
      return 1;
   }
  
  else if ( (rem == 0) &&  (arr[quo] == -1 ) && ( quo%a ==0 ))
   {
      arr[quo] =1;
   }
   return quo;
}  
 
/* Function to check if a number is ugly or not */
int isUgly(int no)
{
     
  no = maxDivide(no, 2);
  no = maxDivide(no, 3);
  no = maxDivide(no, 5);
   
  return (no == 1)? 1 : 0;
}    


int main()
{

  int n, i , count , j;
  
  n=  i =count =0;
 
  std::cout <<"\n enter the nth number";
  std::cin >> n;
  int flag=0;


  for( i = 0 ; i <20 ;i++)
   {
     arr[i] = -1;
   }

    arr[2]  =1 ;
  arr[3] =1;
  arr[5] =1; 

 
  for(i = 1 ; count < n ;i++)
   {

     if(isUgly(i) ) 
      { 
       std::cout << "\n ugly ===" << i;
       count++;
      }
   } 
   

    


 return 0;
}
        
