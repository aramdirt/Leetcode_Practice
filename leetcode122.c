int maxProfit(int* prices, int pricesSize) {
    int cnt;
    int sum = 0;
    int buy = prices[0];

    for (cnt = 1; cnt < pricesSize; cnt++)
    {
        if (buy < prices[cnt])
        {
            sum += (prices[cnt] - buy);
            buy = prices[cnt];
        }
        else
            buy = prices[cnt];
    }

    return sum;
}