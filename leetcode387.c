int firstUniqChar(char* s) {
    int arr[1000][2];
    int cnt, flag;
    int result = 1000;

    for (cnt = 0; cnt < 1000; cnt++)
        arr[cnt][0] = 0;

    for (cnt = 0; cnt < strlen(s); cnt++)
    {
        arr[s[cnt]][0] += 1;

        if (arr[s[cnt]][0] == 1)
            arr[s[cnt]][1] = cnt;
    }

    flag = 0;
    for (cnt = 0; cnt < 1000; cnt++)
    {
        if (arr[cnt][0] == 1)
        {
            flag++;
            result = arr[cnt][1] < result ? arr[cnt][1] : result;
        }
    }

    if (!flag)
        result = -1;

    return result;
}