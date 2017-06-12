#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, dp[305][305], tbl[128];
char *ptr, *pointer[30000], str[30000][305], buf[305], s1[305], s2[305];

int comp(const void *p, const void *q)
{
	return strcmp(*(char**)p, *(char**)q);
}

void backtracking(int p, int q)
{
	int temp;
	char used[4];
	if(dp[p][q] == 0)
	{
		pointer[n] = str[n];
		strcpy(str[n++], buf);
		return;
	}
	temp = q;
	memset(used, 0, sizeof(used));
	if(dp[p-1][q] == dp[p][q])
	{
		backtracking(p-1, q);
	}
	for(; dp[p][q]==dp[p][temp]; q--)
	{
		if(s1[p] == s2[q] && used[tbl[s1[p]]] == 0)
		{
			used[tbl[s1[p]]] = 1;
			*(ptr--) = s1[p];
			backtracking(p-1, q-1);
			ptr++;
		}
	}
}

int main()
{
	int cas, i, j;
	cas = 0;
	tbl['A'] = 0;
	tbl['T'] = 1;
	tbl['G'] = 2;
	tbl['C'] = 3;
	do
	{
		gets(s1+1);
		gets(s2+1);
		for(i=1; s1[i]; i++)
		{
			for(j=1; s2[j]; j++)
			{
				if(s1[i] == s2[j])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
				}
				else
				{
					dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
				}
			}
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		if(dp[i-1][j-1] == 0)
		{
			printf("No common sequence.\n");
		}
		else
		{
			n = 0;
			ptr = buf + dp[i-1][j-1];
			*(ptr--) = 0;
			backtracking(i-1, j-1);
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
