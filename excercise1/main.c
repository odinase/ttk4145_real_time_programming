#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int i = 0;
void *increment( void *ptr ) {
    for (int j = 0; j < 1000000; j++)
        i++;
}
void *decrement( void *ptr ) {
    for (int j = 0; j < 1000000; j++)
        i--;
}


int main()
{
     pthread_t thread1, thread2;
     int  iret1, iret2;

    /* Create independent threads each of which will execute function */

     iret1 = pthread_create( &thread1, NULL, increment, NULL);
     iret2 = pthread_create( &thread2, NULL, decrement, NULL);

     /* Wait till threads are complete before main continues. Unless we  */
     /* wait we run the risk of executing an exit which will terminate   */
     /* the process and all threads before the threads have completed.   */

     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 

     printf("i is now: %d\n",i);
     exit(0);
}
