#include <iostream>
#include <pthread.h>
#include <unistd.h>

void *fun(void *arg)
{

 std::cout <<"\n we  are in fun";

}

 
int main()
{
 std::cout <<"\n we are in main before creating thread";

 int i =10;
 pthread_t tid;
 pthread_create(&tid ,NULL ,fun , (void*)i);
 
// sleep(5);
// pthread_exit(0);  
 std::cout <<"\n we are in main after creating thread";
 
// for(i = 0; i<50000000 ; i++);
  
 

// pthread_exit(0);

}
