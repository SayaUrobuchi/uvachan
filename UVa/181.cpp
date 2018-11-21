#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int value, suit;
int hand[5][4][13];
int num[5][4];
int score[5];
int tablev[5], tables[5];
char buf[1005];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

void analyze(char *s)
{
	if(s[0] == 'T')
	{
		value = 10;
	}
	else if(s[0] == 'J')
	{
		value = 11;
	}
	else if(s[0] == 'Q')
	{
		value = 12;
	}
	else if(s[0] == 'K')
	{
		value = 13;
	}
	else if(s[0] == 'A')
	{
		value = 14;
	}
	else
	{
		value = s[0] - 48;
	}
	if(s[1] == 'C')
	{
		suit = 0;
	}
	else if(s[1] == 'D')
	{
		suit = 1;
	}
	else if(s[1] == 'H')
	{
		suit = 2;
	}
	else
	{
		suit = 3;
	}
}

int main()
{
	int n, i, j, k, turn, lead, now, maxnum, temp, remainv1, remainv2, remains1, remains2, trump;
	while(scanf("%s", buf) == 1)
	{
		if(!strcmp(buf, "#"))
		{
			break;
		}
		n = 0;
		now = 1;
		memset(num, 0, sizeof(num));
		do
		{
			n++;
			analyze(buf);
			if(n == 51)
			{
				remainv1 = value;
				remains1 = suit;
			}
			else if(n == 52)
			{
				remainv2 = value;
				remains2 = suit;
			}
			else
			{
				hand[now][suit][num[now][suit]++] = value;
				now++;
				if(now >= 5)
				{
					now -= 5;
				}
			}
		}while(n<52 && scanf("%s", buf) == 1);
		if(remainv1 > remainv2)
		{
			trump = remains1;
		}
		else if(remainv1 == remainv1)
		{
			if(remains1 > remains2)
			{
				trump = remains1;
			}
			else
			{
				trump = remains2;
			}
		}
		else
		{
			trump = remains2;
		}
		for(i=0; i<5; i++)
		{
			for(j=0; j<4; j++)
			{
				qsort(hand[i][j], num[i][j], sizeof(int), comp);
				/*printf("PLAYER %d has SUIT %d:", i, j);
				for(k=0; k<num[i][j]; k++)
				{
					printf("%3d", hand[i][j][k]);
				}
				printf("\n");*/
			}
		}
		memset(score, 0, sizeof(score));
		for(turn=0, lead=1; turn<10; turn++)
		{
			for(i=0, maxnum=0; i<4; i++)
			{
				if(i != trump && num[lead][i])
				{
					if(hand[lead][i][num[lead][i]-1] >= maxnum)
					{
						maxnum = hand[lead][i][num[lead][i]-1];
						temp = i;
					}
				}
			}
			if(num[lead][trump] && hand[lead][trump][num[lead][trump]-1] >= maxnum)
			{
				maxnum = hand[lead][trump][num[lead][trump]-1];
				temp = trump;
			}
			tablev[0] = maxnum;
			tables[0] = temp;
			num[lead][temp]--;
			for(i=1, j=lead+1; i<5; i++, j++)
			{
				if(j >= 5)
				{
					j -= 5;
				}
				if(num[j][tables[0]])
				{
					tablev[i] = hand[j][tables[0]][num[j][tables[0]]-1];
					tables[i] = tables[0];
					num[j][tables[0]]--;
				}
				else if(num[j][trump])
				{
					tablev[i] = hand[j][trump][num[j][trump]-1];
					tables[i] = trump;
					num[j][trump]--;
				}
				else
				{
					for(k=0, maxnum=0; k<4; k++)
					{
						if(k != trump && k != tables[0])
						{
							if(num[j][k] && hand[j][k][num[j][k]-1] >= maxnum)
							{
								maxnum = hand[j][k][num[j][k]-1];
								temp = k;
							}
						}
					}
					tablev[i] = maxnum;
					tables[i] = temp;
					num[j][temp]--;
				}
			}
			for(i=0, maxnum=0, suit=-1, value=0; i<5; i++)
			{
				/*printf("PILE %d(PLAYER %d): value %d, suit %d\n", i, (lead+i)%5, tablev[i], tables[i]);*/
				if(tables[i] == 2)
				{
					value += tablev[i];
				}
				if(tables[i] == trump)
				{
					if(suit != trump)
					{
						maxnum = tablev[i];
						suit = tables[i];
						temp = i;
					}
					else if(tablev[i] > maxnum)
					{
						maxnum = tablev[i];
						suit = tables[i];
						temp = i;
					}
				}
				else if(tables[i] == tables[0])
				{
					if(suit != trump && tablev[i] > maxnum)
					{
						maxnum = tablev[i];
						suit = tables[i];
						temp = i;
					}
				}
			}
			lead += temp;
			if(lead >= 5)
			{
				lead -= 5;
			}
			score[lead] += value;
		}
		printf("%3d%3d%3d%3d%3d\n", score[0], score[1], score[2], score[3], score[4]);
	}
	return 0;
}
