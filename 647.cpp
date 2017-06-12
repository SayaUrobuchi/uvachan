#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define EXTRA 1
#define MISS 2

int dice[1050];
int conn[101];
int extra[101];
int loc[8];
int stop[8];

int main()
{
	int n, i, j, p, q;
	n = 0;
	while(scanf("%d", &dice[n]) == 1)
	{
		if(!dice[n])
		{
			break;
		}
		n++;
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(conn, 0, sizeof(conn));
		while(scanf("%d%d", &p, &q) == 2)
		{
			if(!p && !q)
			{
				break;
			}
			conn[p] = q;
		}
		memset(extra, 0, sizeof(extra));
		while(scanf("%d", &p) == 1)
		{
			if(!p)
			{
				break;
			}
			if(p < 0)
			{
				extra[-p] = MISS;
			}
			else
			{
				extra[p] = EXTRA;
			}
		}
		memset(loc, 0, sizeof(loc));
		memset(stop, 0, sizeof(stop));
		for(i=0, j=0; ; i++)
		{
			if(i == n)
			{
				i = 0;
			}
			/*printf("player %d, loc %d\n", i+1, loc[i]);*/
			if(stop[i])
			{
				stop[i] = 0;
			}
			else
			{
				for(; ; )
				{
					if(loc[i] + dice[j] > 100)
					{
						/*printf("player %d IGNORE dice.\n", i+1);*/
						break;
					}
					/*printf("player %d from %d GO TO %d.\n", i+1, loc[i], loc[i]+dice[j]);*/
					loc[i] += dice[j++];
					if(conn[loc[i]])
					{
						/*printf("player %d THROUGH EVENT to %d\n", i+1, conn[loc[i]]);*/
						loc[i] = conn[loc[i]];
						break;
					}
					else if(extra[loc[i]] == MISS)
					{
						/*printf("player %d STOP 1 turn.\n", i+1);*/
						stop[i] = 1;
						break;
					}
					else if(extra[loc[i]] != EXTRA)
					{
						break;
					}
					/*printf("player %d get a EXTRA TURN.\n", i+1);*/
				}
				if(loc[i] == 100)
				{
					printf("%d\n", i+1);
					break;
				}
			}
			/*system("pause");*/
		}
	}
	return 0;
}
