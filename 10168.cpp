#include <stdio.h>
#include <string.h>

int prime[664579];
char tbl[10000001];

int main()
{
	int n, i, j, k, tmpi, tmpj, tmpk, limi, limj, limk, len;
	char ans;
	prime[0] = 2;
	prime[1] = 3;
	memset(tbl, 1, sizeof(tbl));
	tbl[1] = 0;
	tbl[4] = 0;
	for(k=4; k<10000001; k+=2)
	{
		tbl[k] = 0;
	}
	for(k=9; k<10000001; k+=3)
	{
		tbl[k] = 0;
	}
	for(i=5, j=2; i<4000; i+=2)
	{
		if(tbl[i])
		{
			prime[j++] = i;
			for(k=i*i; k<10000001; k+=i)
			{
				tbl[k] = 0;
			}
		}
	}
	for(i; i<10000001; i+=2)
	{
		if(tbl[i])
		{
			prime[j++] = i;
		}
	}
	len = j;
	while(scanf("%d", &n) == 1)
	{
		limi = n / 4 + 1;
		for(i=0, ans=0; prime[i]<limi; i++)
		{
			tmpi = prime[i];
			if(tmpi < n)
			{
				limj = (n - tmpi) / 3 + 1;
				for(j=i; prime[j]<limj; j++)
				{
					tmpj = tmpi + prime[j];
					if(tmpj < n)
					{
						limk = (n-tmpi) / 2 + 1;
						for(k=j; prime[k]<limk; k++)
						{
							tmpk = tmpj + prime[k];
							if(tmpk < n)
							{
								if(tbl[n - tmpk])
								{
									printf("%d %d %d %d\n", prime[i], prime[j], prime[k], n-tmpk);
									ans = 1;
									break;
								}
							}
							else
							{
								break;
							}
						}
						if(ans)
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
				if(ans)
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
		if(!ans)
		{
			printf("Impossible.\n");
		}
	}
	return 0;
}
