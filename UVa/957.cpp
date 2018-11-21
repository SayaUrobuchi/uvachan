#include <stdio.h>

int tbl[1000001];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, m, i, j, k, temp, temp2, maxnum, left, right;
	while(scanf("%d%d", &n, &m) == 2)
	{
		tbl[0] = 0;
		for(i=1, j=1, maxnum=0; i<=m; i++)
		{
			scanf("%d", &temp);
			for(; j<=temp; j++)
			{
				tbl[j] = tbl[j-1];
			}
			tbl[temp]++;
			if(tbl[temp] - tbl[temp2=max(temp-n, 0)] > maxnum)
			{
				for(k=temp2+1; k<=temp; k++)
				{
					if(tbl[k] > tbl[k-1])
					{
						break;
					}
				}
				maxnum = tbl[temp] - tbl[temp2];
				left = k;
				right = temp;
			}
		}
		printf("%d %d %d\n", maxnum, left, right);
	}
	return 0;
}
