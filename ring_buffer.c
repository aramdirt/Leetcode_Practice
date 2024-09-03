#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdint.h>

typedef struct {
    uint8_t *buffer;
    size_t size;
    size_t head;
    size_t tail;

    pthread_cond_t readable, writeable;
    pthread_mutex_t lock;
}queue_t;

void queue_init(queue_t *q, size_t s)
{
    q->buffer = malloc(sizeof(uint8_t) * s);
    q->size = s;
    q->head = q->tail = 0;

    pthread_mutex_init(&q->lock, NULL);
    pthread_cond_init(&q->readable, NULL);
    pthread_cond_init(&q->writeable, NULL);
}

void queue_destroy(queue_t *q)
{
    free(q->buffer);
    if (pthread_mutex_destroy(&q->lock) != 0)
        fprintf(stderr, "Could not destroy mutex\n");

    if (pthread_cond_destroy(&q->readable) != 0)
        fprintf(stderr, "Could not destroy condition variable\n");

    if (pthread_cond_destroy(&q->writeable) != 0)
        fprintf(stderr, "Could not destroy condition variable\n");
}

void queue_put(queue_t *q, uint8_t *buffer, size_t size)
{
    pthread_mutex_lock(&q->lock);

    while ((q->tail + sizeof(size)) % q->size == q->head)
        pthread_cond_wait(&q->writeable, &q->lock);

    memcpy(&q->buffer[q->tail], buffer, sizeof(size_t));
    q->tail += size;
    q->tail %= q->size;

    pthread_cond_signal(&q->writeable);
    pthread_mutex_unlock(&q->lock);
}

void queue_get(queue_t *q, uint8_t *buffer, size_t max)
{
    pthread_mutex_lock(&q->lock);

    while ((q->tail - q->head) == 0)
        pthread_cond_wait(&q->readable, &q->lock);

    memcpy(buffer, &q->buffer[q->head] sizeof(size_t));
    q->head += max;
    q->head %= q->size;

    pthread_cond_signal(&q->readable);
    pthread_mutex_unlock(&q->lock);
}