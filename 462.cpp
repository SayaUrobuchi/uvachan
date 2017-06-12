#include <stdio.h>
#include <string.h>

#define ACE 4
#define KING 3
#define QUEEN 2
#define JACK 1

int value, suit;
int ary[4];
int ace[4];
int king[4];
int queen[4];
int jack[4];
int stop[4];
char suitname[4] = {'S', 'H', 'D', 'C'};
char buf[1005];

void analyze(char *s)
{
	int i;
	if(s[0] == 'A')
	{
		value = ACE;
	}
	else if(s[0] == 'K')
	{
		value = KING;
	}
	else if(s[0] == 'Q')
	{
		value = QUEEN;
	}
	else if(s[0] == 'J')
	{
		value = JACK;
	}
	else
	{
		value = 0;
	}
	for(i=0; i<4; i++)
	{
		if(s[1] == suitname[i])
		{
			suit = i;
			return;
		}
	}
}

int main()
{
	int n, i, score, extra;
	while(scanf("%s", buf) == 1)
	{
		memset(ary, 0, sizeof(ary));
		memset(ace, 0, sizeof(ace));
		memset(king, 0, sizeof(king));
		memset(queen, 0, sizeof(queen));
		memset(jack, 0, sizeof(jack));
		memset(stop, 0, sizeof(stop));
		score = 0;
		n = 0;
		do
		{
			n++;
			analyze(buf);
			ary[suit]++;
			if(value == ACE)
			{
				score += ACE;
				ace[suit] = 1;
			}
			else if(value == KING)
			{
				score += KING;
				king[suit] = 1;
			}
			else if(value == QUEEN)
			{
				score += QUEEN;
				queen[suit] = 1;
			}
			else if(value == JACK)
			{
				score += JACK;
				jack[suit] = 1;
			}
		}while(n<13 && scanf("%s", buf) == 1);
		for(i=0, extra=0; i<4; i++)
		{
			if(king[i] && ary[i] == 1)
			{
				score--;
			}
			if(queen[i] && ary[i] <= 2)
			{
				score--;
			}
			if(jack[i] && ary[i] <= 3)
			{
				score--;
			}
			if(ary[i] == 2)
			{
				extra++;
			}
			else if(ary[i] == 1)
			{
				extra += 2;
			}
			else if(!ary[i])
			{
				extra += 2;
			}
			if(ace[i] || (king[i] && ary[i] >= 2) || (queen[i] && ary[i] >= 3))
			{
				stop[i] = 1;
			}
		}
		if(score + extra < 14)
		{
			printf("PASS\n");
		}
		else
		{
			if(score >= 16 && stop[0] && stop[1] && stop[2] && stop[3])
			{
				printf("BID NO-TRUMP\n");
			}
			else
			{
				for(i=0, value=0; i<4; i++)
				{
					if(ary[i] > value)
					{
						value = ary[i];
						suit = i;
					}
				}
				printf("BID %c\n", suitname[suit]);
			}
		}
	}
	return 0;
}
