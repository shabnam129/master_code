#include <iostream>//#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
 typedef struct
 {
 int *a; int length; int sum;
 }
 MyData;
#define N 5 
#define L 20 

MyData mData; 
pthread_t myThread[N]; 
pthread_mutex_t mutex;

int sum = 0;


void *threadWork(void *arg)
{ 
 int start_index = 1;
 int thread_number = * ( (int * )arg );

std::cout << "\n the thread number ===" <<  thread_number;
 switch (thread_number)
 {
  case 0: start_index = 1;
         break;
 case 1: start_index = 21;
         break;
   
 case 2: start_index = 41;
         break;
 case 3: start_index = 61;
         break;
 case 4: start_index = 81;

 }

std::cout << "\n the thread number ===" <<  thread_number << " and start _index === " << start_index;

//pthread_mutex_lock(&mutex);
 for (int i = start_index; i < start_index +20  ; i++) 

//  mutex lock/unlock 
 { pthread_mutex_lock(&mutex); 
   sum = sum + i;
   pthread_mutex_unlock(&mutex);
 }
// pthread_mutex_unlock(&mutex);
 
pthread_exit((void*) 0);

}  
// Define and use local variables for convenience
/* long offset = (long)arg; int sum = 0; 
 int start = offset * mData.length; 
 int end = start + mData.length; 

// each thread calculates its sum *
 for (int i = start; i < end ; i++) sum += mData.a[i]; 
//  mutex lock/unlock 
   pthread_mutex_lock(&mutex); 
   mData.sum += sum; pthread_mutex_unlock(&mutex); 
   pthread_exit((void*) 0); 
  */
//} 

/*void *threadWork(void *arg)
{  Define and use local variables for convenience
 long offset = (long)arg; int sum = 0;
 int start = offset * mData.length;
 int end = start + mData.length; 

// each thread calculates its sum *
 for (int i = start; i < end ; i++) sum += mData.a[i]; 
//  mutex lock/unlock 
   pthread_mutex_lock(&mutex;);
   mData.sum += sum; pthread_mutex_unlock(&mutex;);
   pthread_exit((void*) 0); 

} */



int main () 
{
  void *status;
 /* fill the structure */
/* int *a = (int*) malloc (N*L*sizeof(int));
 for (int i = 0; i < N*L;i++) 
  a[i] = i + 1; 
  mData.length = L;
  mData.a = a;
  mData.sum = 0; */
  pthread_mutex_init(&mutex, NULL);
 
  /* Each thread has its own set of data to work on. */ 
   for(int i=0; i < N; i++)
   {
     pthread_create(&myThread[i], NULL, threadWork, (void *)&i); 
     usleep(1);

   }

 /* Wait on child threads */ 
  for(int i=0; i < N; i++) 
 pthread_join(myThread[i], &status);

 /* Results and cleanup i*/

   std::cout <<"\nweareinmain and sum" << sum; 
// std::cout <<"\nweareinmain and sum === " <<  mData.sum;
// printf ("Sum = %d \n", mData.sum); 
// free (a);
 pthread_mutex_destroy(&mutex); 
 pthread_exit(NULL); }
