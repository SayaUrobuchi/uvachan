#include <stdio.h>
#include <string.h>

int tbl[10], vote[110][10], ptr[110], deathnote[10];

int main()
{
	int cas, c, n, i, j, k, bad, chk, maximum, minimum, temp;
	cas = 0;
	while(scanf("%d%d", &c, &n) == 2)
	{
		if(!c && !n)
		{
			break;
		}
		for(i=0, k=0, bad=0; i<n; i++)
		{
			memset(tbl, 0, sizeof(tbl));
			for(j=0, chk=0; j<c; j++)
			{
				scanf("%d", &vote[k][j]);
				if(vote[k][j] < 1 || vote[k][j] > c)
				{
					chk = 1;
				}
				else if(tbl[vote[k][j]])
				{
					chk = 1;
				}
				tbl[vote[k][j]] = 1;
			}
			ptr[k] = 0;
			bad += chk;
			k += 1 - chk;
		}
		n = k;
		memset(deathnote, 0, sizeof(deathnote));
		for(;;)
		{
			memset(tbl, 0, sizeof(tbl));
			for(i=0; i<n; i++)
			{
				if(deathnote[vote[i][ptr[i]]])
				{
					ptr[i]++;
				}
				tbl[vote[i][ptr[i]]]++;
			}
			for(i=1, maximum=0, minimum=200; i<=c; i++)
			{
				if(tbl[i] > n/2)
				{
					break;
				}
				if(tbl[i] > maximum)
				{
					maximum = tbl[i];
				}
				if(!deathnote[i] && tbl[i] < minimum)
				{
					minimum = tbl[i];
					temp = i;
				}
			}
			if(i <= c)
			{
				break;
			}
			if(maximum == minimum)
			{
				i = c + 1;
				break;
			}
			deathnote[temp] = 1;
		}
		printf("Election #%d\n   %d bad ballot(s)\n", ++cas, bad);
		if(i <= c)
		{
			printf("   Candidate %d is elected.\n", i);
		}
		else
		{
			printf("   The following candidates are tied:");
			for(i=1; i<=c; i++)
			{
				if(!deathnote[i])
				{
					printf(" %d", i);
				}
			}
			printf("\n");
		}
	}
	return 0;
}
