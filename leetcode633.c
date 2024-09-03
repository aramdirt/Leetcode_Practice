bool check(double val)
{
    if (val == 0.0)
        return true;

    if (val < 1.0)
        return false;

    int tmp1;
    double tmp2;

    tmp2 = sqrt(val);
    tmp1 = (int) tmp2;

    if (tmp2 - (double)tmp1 != 0.0)
        return false;

    return true;
}

bool judgeSquareSum(int c) {
    if (c == 0)
        return true;

    int cnt;
    int end = sqrt(c);
    double tmp;

    for (cnt = 1; cnt <= end; cnt++)
    {
        tmp = c - (cnt * cnt);
        if (check(tmp))
            return true;
    }
    return false;
}