
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
 
int main(void)
{
  int listenfd = 0,connfd = 0;
  
  struct sockaddr_in serv_addr;

  struct sockaddr_in client_addr;

 
  char sendBuff[1025];  
  int numrv;  
 
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  printf("socket retrieve success\n");
  
  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(sendBuff, '0', sizeof(sendBuff));
      
  serv_addr.sin_family = AF_INET;    
  serv_addr.sin_addr.s_addr = inet_addr("10.0.2.15");// htonl("10.0.2.15");
//  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
  serv_addr.sin_port = htons(5000);    
 
  bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
  
  if(listen(listenfd, 10) == -1){
      printf("Failed to listen\n");
      return -1;
  }
     
 
  
  while(1)
    {
       int client_len = sizeof(client_addr);
       printf(" we are waiting from  client \n");
       connfd = accept(listenfd, (struct sockaddr*)&client_addr , &client_len);
       char * clientname = "hello word";

       printf("IP address is: %s\n", inet_ntoa(client_addr.sin_addr));
       printf("port is: %d\n", (int) ntohs(client_addr.sin_port));
     //  printf("Client Adress = %s",inet_ntop(AF_INET,&client_addr.sin_addr, clientname,sizeof(clientname)));      
// printf("\n recievied a connect req from %s===" ,   inet_ntop (client_addr.sin_addr);
      //connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL); // accept awaiting request
  
      strcpy(sendBuff, "Message from server");
      write(connfd, sendBuff, strlen(sendBuff));
 
      close(connfd);    
      sleep(1);
    }
 
 
  return 0;
}
