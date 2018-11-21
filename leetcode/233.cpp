int countDigitOne(int n) {
	if (n <= 0)
	{
		return 0;
	}
	long long i, res;
	int j, k, ex;
	res = 0;
    for (i=1; i<=n; i*=10)
    {
    	j = n/i;
    	k = j%10;
    	ex = 0;
    	if (k > 1)
    	{
    		ex = i;
    	}
    	else if (k == 1)
    	{
    		ex = n%i + 1;
    	}
    	res += ex + (j/10) * i;
    }
    return res;
}
