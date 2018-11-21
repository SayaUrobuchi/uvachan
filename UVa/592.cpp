#include <stdio.h>
#include <string.h>

int tbl[128], map[10][10][4], res[10], idd[10];
unsigned int able[10];
char arg[5][1024], buf[1024];

int main()
{
	int cas, n, i, j, p, q, r, gg, cnt, neg, temp, succ;
	unsigned int rel;
	char *adj;
	cas = 0;
	for(i='A'; i<='E'; i++)
	{
		tbl[i] = i-'A';
	}
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(map, 0, sizeof(map));
		gets(buf);
		gg = 0;
		for(i=0; i<n; i++)
		{
			gets(buf);
			cnt = sscanf(buf, "%s%s%s%s%s", arg[0], arg[1], arg[2], arg[3], arg[4]);
			p = tbl[*arg[0]];
			if(*arg[1] == 'I')
			{
				if(arg[1][1])
				{
					q = 5;
				}
				else
				{
					q = p;
				}
			}
			else
			{
				q = tbl[*arg[1]];
			}
			neg = 1;
			adj = arg[3];
			if(strcmp(arg[3], "not") == 0)
			{
				neg = -1;
				adj = arg[4];
			}
			adj[strlen(adj)-1] = 0;
			if(strcmp(adj, "day") == 0)
			{
				rel = 0;
			}
			else if(strcmp(adj, "night") == 0)
			{
				rel = 1;
			}
			else if(strcmp(adj, "divine") == 0)
			{
				rel = 0;
			}
			else if(strcmp(adj, "evil") == 0)
			{
				rel = 1;
			}
			else if(strcmp(adj, "human") == 0)
			{
				rel = 2;
			}
			else if(strcmp(adj, "lying") == 0)
			{
				rel = 3;
			}
			else
			{
				while(1);
			}
			if(map[p][q][rel] && map[p][q][rel] != neg)
			{
				gg = 1;
			}
			map[p][q][rel] = neg;
		}
		printf("Conversation #%d\n", ++cas);
		if(gg)
		{
			printf("This is impossible.\n\n");
			continue;
		}
		memset(res, 0, sizeof(res));
		for(i=0; i<486; i++)
		{
			temp = i;
			idd[5] = temp%2;
			temp >>= 1;
			for(j=0; j<5; j++, temp/=3)
			{
				idd[j] = temp % 3;
			}
			memset(able, -1, sizeof(able));
			for(p=0; p<5; p++)
			{
				for(q=0; q<6; q++)
				{
					for(r=0; r<4; r++)
					{
						if(map[p][q][r])
						{
							/*printf("%d %d %d\n", p, q, r);*/
							neg = map[p][q][r];
							if(idd[p] == 1 || (idd[p] == 2 && idd[5]))
							{
								neg = -neg;
							}
							if(r < 3)
							{
								rel = (1<<r);
							}
							else
							{
								if(idd[5])
								{
									rel = ((1<<1) | (1<<2));
								}
								else
								{
									rel = (1<<1);
								}
							}
							if(neg < 0)
							{
								rel = ~rel;
							}
							able[q] &= rel;
						}
					}
				}
			}
			for(j=0, succ=-1; j<6&&succ; j++)
			{
				/*if(i<100&&j==0)printf("%u %u %u\n", able[j], idd[j], able[j]&(1<<idd[j]));*/
				succ &= (able[j] & (1<<idd[j])) ? 1 : 0;
			}
			if(succ)
			{
				for(j=0; j<6; j++)
				{
					res[j] |= (1<<idd[j]);
				}
			}
		}
		for(i=0; i<6; i++)
		{
			if(!res[i])
			{
				break;
			}
		}
		if(i < 6)
		{
			printf("This is impossible.\n");
		}
		else
		{
			for(i=0, succ=0; i<6; i++)
			{
				for(j=0, cnt=-1; j<3; j++)
				{
					if(res[i] & (1<<j))
					{
						if(cnt == -1)
						{
							cnt = j;
						}
						else
						{
							break;
						}
					}
				}
				if(j >= 3)
				{
					succ = 1;
					if(i < 5)
					{
						if(cnt == 0)
						{
							printf("%c is divine.\n", i+'A');
						}
						else if(cnt == 1)
						{
							printf("%c is evil.\n", i+'A');
						}
						else if(cnt == 2)
						{
							printf("%c is human.\n", i+'A');
						}
					}
					else
					{
						if(cnt == 0)
						{
							printf("It is day.\n");
						}
						else
						{
							printf("It is night.\n");
						}
					}
				}
			}
			if(succ == 0)
			{
				printf("No facts are deducible.\n");
			}
		}
		printf("\n");
	}
	return 0;
}
