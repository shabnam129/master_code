#include <iostream>

int main()
{

  int num=0;
  int i , j , k;
  std::cout << "\n function " << __func__;
  std::cout <<"\n enter the number " ;
  std::cin >> k;

  int  count= 0;
  int max_count = 0;
  
  signed int check =0;
   j = 0;
  int limit = (sizeof(int) * 8 ) -1 ;

  for( i=0; i< limit ; ++i)
    {
   std::cout << "\n i===" << i; 
    if( ( (k& 1)   == 0 ) )
     { 
       k = k >> 1;
       continue;
     }
 
    if(  (k&1) == 1) 
    {
      k = k >> 1;
     for( j = i+1; ( (k&1) ==0 && (i < limit) ) ; j++ , i++)
     {
       if(count ==0)
       {count++;
        continue;}

       count++;
       k = k>>1;
     }
    
   if(i== limit )
   { std::cout << "\n all bit scanned";
    break;}
  
   if(max_count < count )
    max_count = count;
   
   std::cout << "\n count ===" << count-1;
   
   count = 0;

   } //end of if check for 1
     
    
  }//end of for loop
 
 std::cout << "\n binary gap count ===" << max_count - 1;

}        
 
  
