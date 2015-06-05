#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void * imprimirA() {
	printf("--- A1\n");
	printf("--- A2\n");
}

void * imprimirB() {
	printf("--- B1\n");
	printf("--- B2\n");
}

void main()
{
    pthread_t thread_a;
    pthread_t thread_b;

    sem_init(&sem, 0, 0);

    pthread_create(&thread_b, NULL, imprimirB, NULL);
    pthread_create(&thread_a, NULL, imprimirA, NULL);

    pthread_join(thread_a, NULL);
    pthread_join(thread_b, NULL);
}
