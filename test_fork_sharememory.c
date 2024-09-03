#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/wait.h>

int main()
{
    pid_t pid = 0;
    int shm_ID = 0;
    int input[2];
    int *pBuf;

    shm_ID = shmget(IPC_PRIVATE, sizeof(int)*2, IPC_CREAT | IPC_EXCL | S_IRUSR | S_IWUSR);
    pBuf = shmat(shm_ID, NULL, 0);

    pid = fork();
    if (pid == 0)
    {
        printf("Enter Child Process\n");
        memcpy(input, pBuf, sizeof(int)*2);
        printf("Child Process get input: {%d, %d}\n", input[0], input[1]);

        result = input[0] + input[1];
        printf("Child Process write result: %d\n", result);

        memcpy(pBuf, &result, sizeof(int));
        shmdt(pBuf);
        printf("Child post\n");
    }
    else if (pid > 0)
    {
        printf("Enter Father Process\n");
        input[0] = 3;
        input[0] = 5;

        printf("Father Process write: {%d, %d}\n", input[0], input[1]);
        memcpy(pBuf, input, sizeof(int)*2);
        shmdt(pBuf);

        printf("Father wait\n");
        wait(NULL);

        pBuf = shmat(shm_ID, NULL, 0);
        memcpy(&result, pBuf, sizeof(int));
        shmctl(shm_ID, IPC_RMID, NULL);
        printf("Father Process get result: %d\n", result);
    }
    else
    {
        printf("Fork error!\n");
        return -1;
    }

    return 0;
}