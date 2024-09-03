#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int cnt;
sem_t sem;

void *child(void *arg)
{
    int i;
    int *num = (int *)arg;

    for (i=0; i<3; i++)
    {
        sem_wait(&sem);
        int tmp = cnt;
        sleep(1);
        cnt = tmp + 1;
        printf("This is thread %d\n", *num);
        printf("cnt = %d\n", cnt);
        sem_post(&sem);
    }
    pthread_exit(NULL);
}

int main()
{
    int pthread1 = 1, pthread_2 = 2;
    pthread_t callThd[2];

    sem_init(&sem, 0, 1);

    pthread_create(&callThd[0], NULL, child, (void*)&pthread1);
    sleep(2);
    pthread_create(&callThd[1], NULL, child, (void*)&pthread2);

    pthread_join(callThd[0], NULL);
    pthread_join(callThd[1], NULL);
    sem_destroy(&sem);
    return 0;
}