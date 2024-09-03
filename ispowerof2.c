#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_RANGE  100

int ispowerof_2(int num)
{
    return ((num & (num-1)) == 0) ? 1 : 0;
}

int main()
{
    int num, result;

    srand(time(NULL));
    num = rand()%NUM_RANGE;
    printf("Random number: %d\n", num);

    result = ispowerof_2(num);
    if (result)
        printf("%d is power of 2\n", num);
    else
        printf("%d is not power of 2\n", num);

    return 0;
}