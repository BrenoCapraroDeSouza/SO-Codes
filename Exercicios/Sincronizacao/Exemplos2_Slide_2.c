//para compilar use: gcc program_name.c –lpthread -lrt

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t sem;

void* thread(void* arg) { //function which act like thread
   sem_wait(&sem); //wait state //pthread_mutex_lock(&mutex)
   printf("\nEntered into the Critical Section..\n");
   sleep(3); //critical section
   printf("\nCompleted...\n"); //comming out from Critical section
   sem_post(&sem); // signal do semaforo = pthread_mutex_unlock
}

void main() {
   sem_init(&sem, 0, 5);
   pthread_t th1,th2;
   pthread_create(&th1,NULL,thread,NULL);
   sleep(2);
   pthread_create(&th2,NULL,thread,NULL);
   //Join threads with the main thread
   pthread_join(th1,NULL);
   pthread_join(th2,NULL);
   sem_destroy(&sem);
}