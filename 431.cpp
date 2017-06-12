#include <stdio.h>
#include <string.h>

int s;
int score[105], length[105];
int from[105][25000];
int dp[25000];
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
		memset(dp, 0, sizeof(dp));
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
		for(i=lim; i>0; i--)
		{
			if(dp[i])
			{
				puts("Score  Time  Description");
				puts("-----  ----  -----------");
				for(j=n-1, l=i; j>0; j--)
				{
					if(from[j][l])
					{
						printf("%3d%7d   %s\n", score[j], length[j], name[j]);
						l -= length[j];
					}
				}
				printf("Total score: %d points\n", dp[i]);
				printf(" Total time: %d hours\n", i);
				break;
			}
		}
		if(i == 0)
		{
			puts("There is not enough time to present any evidence. Drop the charges.");
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
