#include<stdio.h>

#define MAX_ACS_VNF 2
#define IPADDR_ADDRSTRLEN 2

void  main()
{
 int i ;

 char acsip[MAX_ACS_VNF][IPADDR_ADDRSTRLEN] = {{0}};
 
/* for(i=0 ; i< MAX_ACS_VNF ; i++)
  {
    acsip[i] = {NULL};

  }
 */
char (* acs2ipAddr)[2] =  acsip[0] ;
 
if (NULL != acs2ipAddr)
{   printf("yipppee its cooorec");
 //acsip[0]
}

 printf("data====%d" , -1*-1);

}
