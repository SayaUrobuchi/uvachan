#include <stdio.h>
#include <string.h>

int num[60], loc[60][100005], dp[100005];
char str[100005], s2[1005];

int main()
{
	int count, q, len, len2, i, n, sc;
	char *p;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%d", str, &q);
		memset(num, 0, sizeof(num));
		for(p=str; *p; p++)
		{
			if(*p > 90)
			{
				n = *p - 'a' + 26;
			}
			else
			{
				n = *p - 'A';
			}
			dp[p-str+1] = dp[p-str] + n;
			loc[n][num[n]++] = p-str;
		}
		len = p-str;
		while(q--)
		{
			scanf("%s", s2);
			for(p=s2, sc=0; *p; p++)
			{
				if(*p > 90)
				{
					n = *p - 'a' + 26;
				}
				else
				{
					n = *p - 'A';
				}
				sc += n;
			}
			len2 = p - s2;
			if(*s2 > 90)
			{
				n = *s2 - 'a' + 26;
			}
			else
			{
				n = *s2 - 'A';
			}
			for(i=0; i<num[n]; i++)
			{
				if(len - loc[n][i] < len2)
				{
					i = num[n];
					break;
				}
				if(sc == dp[loc[n][i]+len2]-dp[loc[n][i]] && strncmp(str+loc[n][i], s2, len2) == 0)
				{
					break;
				}
			}
			if(i == num[n])
			{
				printf("n\n");
			}
			else
			{
				printf("y\n");
			}
		}
	}
	return 0;
}

