int tbl[205][205];

int uniquePaths(int m, int n) {
	int i, j;
    if (!tbl[0][0])
    {
    	tbl[0][0] = 1;
        for (i=1; i<=200; i++)
        {
        	tbl[i][0] = 1;
        	for (j=1; j<=i; j++)
        	{
        		tbl[i][j] = tbl[i-1][j] + tbl[i-1][j-1];
        	}
        }
    }
    return tbl[m+n-2][n-1];
}
