#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int pile[16], card[16];
int ary[52];
int loc[52];
int id[52];
int queue[52];
int hash[14];
char buf[1005];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int trans(char *s)
{
	if(s[0] == 'A')
	{
		return 1;
	}
	else if(s[0] == 'T')
	{
		return 10;
	}
	else if(s[0] == 'J')
	{
		return 11;
	}
	else if(s[0] == 'Q')
	{
		return 12;
	}
	else if(s[0] == 'K')
	{
		return 13;
	}
	return s[0] - 48;
}

int main()
{
	int cas, n, m, i, j, minnum, next, front, rear, now, gameover, used, state, temp, temp2;
	cas = 0;
	while(scanf("%s", buf) == 1)
	{
		if(!strcmp(buf, "#"))
		{
			break;
		}
		n = m = front = rear = 0;
		do
		{
			ary[n++] = trans(buf);
		}while(n < 52 && scanf("%s", buf) == 1);
		memset(pile, 0, sizeof(pile));
		memset(card, 0, sizeof(card));
		for(i=0, gameover=0; i<n&&!gameover; )
		{
			memset(hash, 0, sizeof(hash));
			for(j=0; j<m; j++)
			{
				if(!hash[card[j]])
				{
					hash[card[j]] = j + 1;
				}
			}
			for(j=1, minnum=100; j<=5; j++)
			{
				if(hash[j] && hash[11-j])
				{
					if(hash[j] < minnum)
					{
						minnum = hash[j];
						temp = j;
					}
					if(hash[11-j] < minnum)
					{
						minnum = hash[11-j];
						temp = j;
					}
				}
			}
			if(hash[11] && hash[12] && hash[13])
			{
				if(hash[11] < minnum)
				{
					minnum = hash[11];
					temp = 11;
				}
				if(hash[12] < minnum)
				{
					minnum = hash[12];
					temp = 11;
				}
				if(hash[13] < minnum)
				{
					minnum = hash[13];
					temp = 11;
				}
			}
			if(minnum == 100)
			{
				if(m == 16)
				{
					gameover = i+1;
					break;
				}
				pile[m]++;
				card[m++] = ary[i++];
			}
			else
			{
				if(temp == 11)
				{
					next = 3;
					queue[0] = hash[11]-1;
					queue[1] = hash[12]-1;
					queue[2] = hash[13]-1;
				}
				else
				{
					next = 2;
					queue[0] = hash[temp]-1;
					queue[1] = hash[11-temp]-1;
				}
				qsort(queue, next, sizeof(int), comp);
				/*printf("REPLACE %d: %d %d %d\n", next, queue[0], queue[1], queue[2]);*/
				for(j=0; i<n&&j<next; i++, j++)
				{
					pile[queue[j]]++;
					card[queue[j]] = ary[i];
				}
			}
			/*for(j=0; j<m; j++)
			{
				printf("%3d", card[j]);
			}
			printf("\n\n");*/
		}
		if(gameover)
		{
			printf("%3d: Overflowed on card no %d\n", ++cas, gameover);
		}
		else
		{
			printf("%3d:", ++cas);
			for(i=0; i<16; i++)
			{
				if(pile[i])
				{
					printf("%3d", pile[i]);
				}
				else
				{
					break;
				}
			}
			printf("\n");
		}
	}
	return 0;
}
