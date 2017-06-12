#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, dp[305][305], tbl[128];
char *ptr, *pointer[30000], str[10000][305], buf[305], s1[305], s2[305];

int comp(const void *p, const void *q)
{
	return strcmp(*(char**)p, *(char**)q);
}

void backtracking(int p, int q)
{
	int tq, tp, c;
	char used[4];
	if(dp[p][q] == 0)
	{
		if(n >= 10000) return;
		pointer[n] = str[n];
		strcpy(str[n++], buf);
		return;
	}
	tp = p;
	tq = q;
	memset(used, 0, sizeof(used));
	for(c=0; dp[tp][tq]==dp[p][tq]&&c<4; p--)
	{
		if(used[tbl[s1[p]]] == 0)
		{
			for(q=tq; dp[p][q]==dp[tp][tq]; q--)
			{
				if(s1[p] == s2[q])
				{
					used[tbl[s1[p]]] = 1;
					*(ptr--) = s1[p];
					backtracking(p-1, q-1);
					ptr++;
					c++;
					break;
				}
			}
		}
	}
}

int main()
{
	int cas, i, j;
	cas = 0;
	tbl['a'] = 0;
	tbl['t'] = 1;
	tbl['g'] = 2;
	tbl['c'] = 3;
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
				/*printf("%d ", dp[i][j]);*/
			}
			/*printf("\n");*/
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		if(s1[1] == 0 || s2[1] == 0 || dp[i-1][j-1] == 0)
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
			/*printf("%s\n", pointer[0]);*/
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
