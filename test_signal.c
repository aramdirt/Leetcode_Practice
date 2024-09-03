#include <stdio.h>
#include <signal.h>

typedef void (*signal_handler)(int);

void signal_handler_func(int signal_num)
{
    printf("Catch signal number: %d\n", signal_num);
}

int main()
{
    signal_handler p_signal = signal_handler_func;
    signal(SIGINT, p_signal);
    for(;;);
    return 0;
}