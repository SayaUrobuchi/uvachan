#include <stdio.h>
#include <string.h>

int n, len;
int dp[6561], dp2[6561];
int subject[9];
int ability[9];
int price;
char str[10000];

int decode()
{
	int i, j, result;
	for(i=1, j=1, result=0; i<=n; i++, j*=3)
	{
		if(subject[i] > 0)
		{
			result += subject[i] * j;
		}
	}
	return result;
}

void encode(int now)
{
	int i;
	for(i=1; i<=n; i++, now/=3)
	{
		subject[i] = now % 3;
	}
}

int main()
{
	int m, o, i, j, p, total, tmp, optians;
	while(scanf("%d%d%d", &n, &o, &m) == 3)
	{
		if(!n)
		{
			break;
		}
		for(i=1; i<=n; i++)
		{
			subject[i] = 2;
		}
		total = 1;
		while(o--)
		{
			memset(ability, 0, sizeof(ability));
			scanf("%d", &p);
			total += p;
			gets(str);
			for(i=0; str[i]; i++)
			{
				if(str[i] != ' ')
				{
					ability[str[i]-48] = 1;
				}
			}
			for(j=1; j<=n; j++)
			{
				subject[j] -= ability[j];
			}
		}
		memset(dp, 0, sizeof(dp));
		dp[decode()] = total;
		memcpy(dp2, dp, sizeof(dp));
		optians = 2147483640;
		while(m--)
		{
			memset(ability, 0, sizeof(ability));
			scanf("%d", &price);
			gets(str);
			for(j=0; str[j]; j++)
			{
				if(str[j] != ' ')
				{
					ability[str[j]-48] = 1;
				}
			}
			for(j=1; j<6561; j++)
			{
				if(dp[j])
				{
					encode(j);
					for(i=1; i<=n; i++)
					{
						subject[i] -= ability[i];
					}
					tmp = decode();
					if(!dp2[tmp] || dp2[tmp] > dp[j] + price)
					{
						dp2[tmp] = dp[j] + price;
					}
				}
			}
			if(dp2[0])
			{
				if(dp2[0] < optians)
				{
					optians = dp2[0];
				}
			}
			memcpy(dp, dp2, sizeof(dp));
		}
		printf("%d\n", optians-1);
	}
	return 0;
}
