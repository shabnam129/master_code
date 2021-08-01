#include<stdio.h>
#include <iostream>
#include <cstring>
void main()
{

       /*char acsMgmtNtwkValue[64];
       strcpy(acsMgmtNtwkValue, "cidr='10.1.0.0/16', gw='10.1.0.1,");
       printf("string====%s", acsMgmtNtwkValue);
        // acs-mgmt:network value: cidr='10.1.0.0/16', gw='10.1.0.1'.
        // 104
       // char *temp_str;
        //temp_str =//
        char *    temp_str = strtok(acsMgmtNtwkValue, ",");
       // temp_str[15]='\0';
        printf("string2====%p", temp_str);
        /i/

      */


       char from[] = "12.34.56.78.100.101";
       char * ch = ".";
                       char * token = strtok(from, ch);
        //printf("%s\n",token);
         while(token != NULL)
              {
               std::cout << "tokee===" <<token;
             //printf("%s\n", token);
               token = strtok(NULL,    ch);
              }
}
