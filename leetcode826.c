void sel_sort(int *arr1, int *arr2, int size)
{
    int i, j, min, tmp;

    for (i = 0; i < size - 1; ++i)
    {
        min = i;
        for (j = i + 1; j < size; ++j)
        {
            if (arr1[min] > arr1[j])
                min = j;
        }
        /* swap arr1 */
        tmp = arr1[i];
        arr1[i] = arr1[min];
        arr1[min] = tmp;

        /* swap arr2 */
        tmp = arr2[i];
        arr2[i] = arr2[min];
        arr2[min] = tmp;
    }
    return;
}

int maxProfitAssignment(int* difficulty, int difficultySize, int* profit, int profitSize, int* worker, int workerSize) {
    int result = 0;
    int flag = 0;
    int i, j;

    sel_sort(difficulty, profit, difficultySize);
    for (i = 0; i < workerSize; i++)
    {
        flag = 0;
        for (j = 0; j < difficultySize; j++)
        {
            if (worker[i] == difficulty[j])
            {
                flag = 1;
                result += profit[j];
                break;
            }

            if (worker[i] < difficulty[j])
            {
                if (j == 0)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 1;
                    result += profit[j - 1];
                    break;
                }
            }
        }

        if (!flag)
            result += profit[difficultySize - 1];
    }
    return result;
}