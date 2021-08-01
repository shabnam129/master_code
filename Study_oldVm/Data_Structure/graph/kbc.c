#include <stdio.h>
#include <iostream>
#include <cstdlib>

int main()
{

 int u,v;
 int **b;



  
 b =   (int **) malloc(sizeof(int) * (4));  ///If its like  (int*) malloc(4 somehitng) ...then its mean b pointer location which integer itself..but here (int **) means b pointer something wihch itself to pointer int 


 for ( u=0 ; u <4  ; u++)
 {
  b[u] = (int *)   malloc(sizeof(int) * (4));
  for(v=0;v < 4 ;v++)
  {
    b[u][v]=0;
  }
 }



 for ( u=0 ; u <4  ; u++)
 {
   printf("\n value of ==%d row ===" , u);
  for(v=0;v < 4 ;v++)
  {
    printf("  %d", b[u][v]);
  }
 }



}
