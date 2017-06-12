#include <stdio.h>
#include <string.h>

int ary[1005][11];
int num[1005];
int next[1005];

int getgcd(int p, int q)
{
	if(p % q)
	{
		return getgcd(q, p%q);
	}
	return q;
}

int main()
{
	int count, n, i, j, k, lcm, c, d, last, min, temp, worst, record;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=1, lcm=0; i<=n; i++)
		{
			scanf("%d", &num[i]);
			for(j=0; j<num[i]; j++)
			{
				scanf("%d", &ary[i][j]);
			}
			if(lcm)
			{
				lcm *= num[i] / getgcd(num[i], lcm);
			}
			else
			{
				lcm = num[i];
			}
			next[i-1] = i;
		}
		next[i-1] = 0;
		for(last=0, c=n, d=0; ; d+=lcm)
		{
			record = c;
			for(i=0; i<lcm; i++)
			{
				for(j=0, min=2147483640, worst=-1; k=next[j]; j=k)
				{
					if((temp=ary[k][i%num[k]]) < min)
					{
						min = temp;
						worst = j;
					}
					else if(temp == min)
					{
						worst = -1;
					}
				}
				if(worst != -1)
				{
					next[worst] = next[next[worst]];
					last = i + 1 + d;
					c--;
				}
			}
			if(record == c)
			{
				break;
			}
		}
		printf("%d %d\n", c, last);
	}
	return 0;
}
