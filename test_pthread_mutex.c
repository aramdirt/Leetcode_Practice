#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

int cnt;
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

void *child(void *arg)
{
    int i;
    int *num = (int *)arg;

    for (i=0; i<3; i++)
    {
        pthread_mutex_lock(&mutex1);
        int tmp = cnt;
        sleep(1);
        cnt = tmp + 1;
        printf("This is thread %d\n", *num);
        printf("cnt = %d\n", cnt);
        pthread_mutex_unlock(&mutex1);
    }
    pthread_exit(NULL);
}

int main()
{
    int pthread1 = 1, pthread_2 = 2;
    pthread_t callThd[2];

    pthread_mutex_init(&mutex1, NULL);
    /* Set attribute of pthread let it can join */
    /* pthread_attr_t attr; */
    /* pthread_attr_init(&attr); */
    /* pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE); */

    pthread_create(&callThd[0], NULL, child, (void*)&pthread1);
    pthread_create(&callThd[1], NULL, child, (void*)&pthread2);

    /* pthread_attr_destroy(&attr); */

    pthread_join(callThd[0], NULL);
    pthread_join(callThd[1], NULL);
    pthread_mutex_destroy(&mutex1);
    return 0;
}