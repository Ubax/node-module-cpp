unsigned fibonacciSequence(unsigned index)
{
    unsigned prev1 = 1, prev2 = 1;
    for (int i = 1; i <= index; i++)
    {
        int b = prev2;
        prev2 = prev2 + prev1;
        prev1 = b;
    }
    return prev2;
}