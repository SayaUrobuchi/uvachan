#include <stdio.h>
#include <string.h>

int s, qnum;
int queue[105];
int score[105], length[105];
int dp[25000];
char from[105][25000];
char buf[2008];
char name[105][75];

int main()
{
	int count, n, i, j, l, lim;
	char *ptr;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &lim);
		gets(buf);
		n = 1;
		while(gets(buf))
		{
			if(!buf[0])
			{
				break;
			}
			ptr = strtok(buf, " ");
			sscanf(ptr, "%d", &score[n]);
			ptr = strtok(NULL, " ");
			sscanf(ptr, "%d", &length[n]);
			for(; *ptr; ptr++);
			strcpy(name[n], ++ptr);
			for(i=lim-length[n]; i>=0; i--)
			{
				if(dp[i] + score[n] > dp[i+length[n]])
				{
					dp[i+length[n]] = dp[i] + score[n];
					from[n][i+length[n]] = 1;
				}
			}
			n++;
		}
		if(dp[lim])
		{
			puts("Score  Time  Description");
			puts("-----  ----  -----------");
			for(i=n-1, qnum=0, l=lim; i>0; i--)
			{
				if(from[i][l])
				{
					queue[qnum++] = i;
					l -= length[i];
				}
			}
			for(i=0; i<qnum; i++)
			{
				printf("%3d%7d   %s\n", score[queue[i]], length[queue[i]], name[queue[i]]);
			}
			printf("\n");
			printf("Total score: %d points\n", dp[lim]);
			printf(" Total time: %d hours\n", lim-l);
		}
		else
		{
			puts("There is not enough time to present any evidence. Drop the charges.");
		}
		if(count)
		{
			memset(dp, 0, sizeof(dp));
			memset(from, 0, (n+1)*25000);
			printf("\n");
		}
	}
	return 0;
}
