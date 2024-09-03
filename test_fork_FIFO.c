#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    pid_t pid = 0;
    int fd = 0;
    int input[2];
    int result = 0;

    mkfifo("file_father", 666);
    mkfifo("file_child", 666);

    pid = fork();
    if (pid == 0)
    {
        printf("Enter Child Process\n");

        fd = open("file_father", O_RDONLY);
        read(fd, input, sizeof(int)*2);
        close(fd);

        printf("Child Process get input: {%d, %d}\n", input[0], input[1]);

        result = input[0] + input[1];

        printf("Child Process write result: %d\n", result);

        fd = open("file_child", O_WRONLY);
        write(fd, &result, sizeof(int));
        close(fd);
    }
    else if (pid > 0)
    {
        printf("Enter Father Process\n");
        input[0] = 3;
        input[0] = 5;

        printf("Father Process write: {%d, %d}\n", input[0], input[1]);

        fd = open("file_father", O_WRONLY);
        write(fd, input, sizeof(int)*2);
        close(fd);

        fd = open("file_child", O_RDONLY);
        read(fd, &result, sizeof(int));
        close(fd);

        printf("Father Process get result: %d\n", result);

        unlink("file_child");
        unlink("file_father");
    }
    else
    {
        printf("Fork error!\n");
        return -1;
    }

    return 0;
}