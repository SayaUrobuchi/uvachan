#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, dp[305][305], ary[305];
char *ptr, *pointer[305], str[305][305], buf[305], s1[305], s2[305];

int comp(const void *p, const void *q)
{
	return strcmp(*(char**)p, *(char**)q);
}

int main()
{
	int cas, i, j, maxlen;
	cas = 0;
	do
	{
		gets(s1+1);
		gets(s2+1);
		for(i=1, maxlen=-1; s1[i]; i++)
		{
			for(j=1; s2[j]; j++)
			{
				if(s1[i] == s2[j])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
					if(dp[i][j] > maxlen)
					{
						maxlen = dp[i][j];
						n = 0;
						ary[n++] = i;
					}
					else if(dp[i][j] == maxlen)
					{
						ary[n++] = i;
					}
				}
				else
				{
					dp[i][j] = 0;
				}
			}
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		if(maxlen == -1)
		{
			printf("No common sequence.\n");
		}
		else
		{
			for(i=0; i<n; i++)
			{
				sprintf(str[i], "%.*s\0", maxlen, s1+ary[i]-maxlen+1);
				pointer[i] = str[i];
			}
			qsort(pointer, n, sizeof(char*), comp);
			printf("%s\n", pointer[0]);
			for(i=1; i<n; i++)
			{
				if(strcmp(pointer[i], pointer[i-1]))
				{
					printf("%s\n", pointer[i]);
				}
			}
		}
	}while(gets(buf));
	return 0;
}
