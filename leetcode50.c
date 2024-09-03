double myPow(double x, int n) {
    double tmp;

    if (n == 0)
        return 1;

    if (n < 0)
    {
        x = 1/x;
        n *= -1;
    }

    tmp = myPow(x, n/2);

    if (n % 2)
        return x * tmp * tmp;
    else
        return tmp * tmp;
}