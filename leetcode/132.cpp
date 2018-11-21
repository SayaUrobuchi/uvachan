char *ss;
int isp[2005][2005], used[2005][2005], cnt;
int dp[2005];

int is_p(int p, int q)
{
	if (p >= q)
	{
		return 1;
	}
	if (used[p][q] == cnt)
	{
		return isp[p][q];
	}
	used[p][q] = cnt;
	if (ss[p] != ss[q])
	{
		return isp[p][q] = 0;
	}
	return isp[p][q] = is_p(p+1, q-1);
}

int minCut(char* s) {
    int len = strlen(s);
    int i, j, t;
    ss = s;
    ++cnt;
    for (i=0; i<len; i++)
    {
    	dp[i] = i+1;
    	for (j=0; j<=i; j++)
    	{
    		if (is_p(j, i))
    		{
    			t = 0;
    			if (j > 0)
    			{
    				t += dp[j-1]+1;
    			}
    			if (t < dp[i])
    			{
    				dp[i] = t;
    			}
    		}
    	}
    }
    return dp[len-1];
}
