#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/*int hashfun(char *a)
{
  int  i = 0 ;
  int sum = 0;
  for(i = 0 ;a[i] !='\0';i++)
   {
       sum = (int) a[i] + sum;
       
   }
 
  return sum;
}*/


int main() {
  int a ;
  vector<string > string_value;
  vector<int > count;
  int N =4;
  string str;
  int i=0;
  int  p = 0 ;
  for(i = 0  , p = 0;  p < N;p++ )
      {
         std::cin >> str;
     
         vector<string >::iterator it;
             
           it =  find(string_value.begin(), string_value.end(), str) ;

        if( it!=string_value.end())
         {
            for( i = 0 ;  string_value[i] != *it; i++);
                 
             ++count[i];
              continue ;
             //elem exists in the vector
           
         }    
       
     
         string_value.push_back(str);
          std::cout << " str queueu==="  << string_value.back();
        //count[i] = 1;
         count.push_back(1);
     
  }
 
  for ( i= 0 ; i<count.size();i ++)
      {
        cout << count[i];
      }
 


  /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
  return 0;
}
