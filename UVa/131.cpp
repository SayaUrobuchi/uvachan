#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int best;
char hand[5][3], deck[5][3], buf[5][3], ans[100];

int transc(char now)
{
	if(now == 'C')
	{
		return 0;
	}
	if(now == 'D')
	{
		return 1;
	}
	if(now == 'H')
	{
		return 2;
	}
	return 3;
}

int transn(char now)
{
	if(now < 58)
	{
		return now - 48;
	}
	if(now == 'T')
	{
		return 10;
	}
	if(now == 'J')
	{
		return 11;
	}
	if(now == 'Q')
	{
		return 12;
	}
	if(now == 'K')
	{
		return 13;
	}
	return 1;
}

int ncomp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int ccomp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

void chkans()
{
	int i, s, f, color[4], num[5];
	memset(color, 0, sizeof(color));
	for(i=0; i<5; i++)
	{
		num[i] = transn(buf[i][0]);
		color[transc(buf[i][1])]++;
	}
	qsort(num, 5, sizeof(int), ncomp);
	qsort(color, 4, sizeof(int), ccomp);
	s = f = 0;
	if(num[1] + 1 == num[2] && num[2] + 1 == num[3] && num[3] + 1 == num[4])
	{
		if(num[0] + 1 == num[1] || (num[0] == 1 && num[4] == 13))
		{
			s = 1;
		}
	}
	if(color[0] == 5)
	{
		f = 1;
	}
	if(s && f)
	{
		strcpy(ans, "straight-flush");
		best = 8;
		return;
	}
	if(best < 5 && f)
	{
		strcpy(ans, "flush");
		best = 5;
		return;
	}
	if(best < 4 && s)
	{
		strcpy(ans, "straight");
		best = 4;
		return;
	}
	if(best < 7 && ((num[0] == num[1] && num[1] == num[2] && num[2] == num[3]) || (num[1] == num[2] && num[2] == num[3] && num[3] == num[4])))
	{
		strcpy(ans, "four-of-a-kind");
		best = 7;
		return;
	}
	if(best < 6 && ((num[0] == num[1] && num[1] == num[2] && num[3] == num[4]) || (num[0] == num[1] && num[2] == num[3] && num[3] == num[4])))
	{
		strcpy(ans, "full-house");
		best = 6;
		return;
	}
	if(best < 3 && ((num[0] == num[1] && num[1] == num[2]) || (num[1] == num[2] && num[2] == num[3]) || (num[2] == num[3] && num[3] == num[4])))
	{
		strcpy(ans, "three-of-a-kind");
		best = 3;
		return;
	}
	if(best < 2 && ((num[0] == num[1] && num[2] == num[3]) || (num[0] == num[1] && num[3] == num[4]) || (num[1] == num[2] && num[3] == num[4])))
	{
		strcpy(ans, "two-pairs");
		best = 2;
		return;
	}
	if(best < 1 && ((num[0] == num[1]) || (num[1] == num[2]) || (num[2] == num[3]) || (num[3] == num[4])))
	{
		strcpy(ans, "one-pair");
		best = 1;
		return;
	}
}

void dfs(int now, int depth, int limit)
{
	int i;
	char temp[3];
	if(depth == limit)
	{
		for(i=0; i<5; i++)
		{
			strcpy(buf[i], hand[i]);
		}
		chkans();
		return;
	}
	for(i=now; i<5; i++)
	{
		strcpy(temp, hand[i]);
		strcpy(hand[i], deck[depth]);
		dfs(i+1, depth+1, limit);
		strcpy(hand[i], temp);
	}
}

int main()
{
	int i;
	while(scanf("%s", hand[0]) == 1)
	{
		printf("Hand: %s ", hand[0]);
		for(i=1; i<5; i++)
		{
			scanf("%s", hand[i]);
			printf("%s ", hand[i]);
		}
		printf("Deck: ");
		for(i=0; i<5; i++)
		{
			scanf("%s", deck[i]);
			printf("%s ", deck[i]);
		}
		strcpy(ans, "highest-card");
		for(i=0, best=0; i<=5; i++)
		{
			dfs(0, 0, i);
		}
		printf("Best hand: %s\n", ans);
	}
	return 0;
}
