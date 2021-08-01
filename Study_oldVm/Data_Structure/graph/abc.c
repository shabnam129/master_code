
#include<stdio.h>

int main()
{

 int a[2][2]  = { {1,2,} , {7,4}};

 int *p;
 int **d;
 
 d = a[0];  
/* p=a;
 d=&p;
 printf("\n value in array address =%p and  add of it own array ===%p and next valuee ===%p",a, &a,&a+1);

 printf("\n value in array address =%p and  add of it own array ===%p and next valuee ===%p and d===%p" ,a ,p, &p,d);
 */printf("\n value in array ===%d\n",d[0][1]);//*(*d + 2));

// printf("\n value in array ===%d\n",*(*d[2]));


}
