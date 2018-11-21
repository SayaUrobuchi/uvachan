#include <stdio.h>
#include <string.h>

int timestart[10000][101], timeend[10000][101], forward[10000][101], num[10000], chk[10000];

int main()
{
	int cas, count, i, buf, query, flag;
	cas = 0;
	printf("CALL FORWARDING OUTPUT\n");
	scanf("%d", &count);
	while(count--)
	{
		printf("SYSTEM %d\n", ++cas);
		memset(num, 0, sizeof(num));
		while(scanf("%d", &buf) == 1)
		{
			if(!buf)
			{
				break;
			}
			scanf("%d%d%d", &timestart[buf][num[buf]], &timeend[buf][num[buf]], &forward[buf][num[buf]]);
			timeend[buf][num[buf]] += timestart[buf][num[buf]];
			num[buf]++;
		}
		while(scanf("%d", &buf) == 1)
		{
			if(buf == 9000)
			{
				break;
			}
			scanf("%d", &query);
			memset(chk, 0, sizeof(chk));
			chk[query] = 1;
			printf("AT %04d CALL TO %04d RINGS ", buf, query);
			for(;;)
			{
				flag = 1;
				for(i=0; i<num[query]; i++)
				{
					if(timestart[query][i] <= buf && buf <= timeend[query][i])
					{
						if(chk[forward[query][i]])
						{
							query = 9999;
							break;
						}
						chk[forward[query][i]] = 1;
						query = forward[query][i];
						flag = 0;
						break;
					}
				}
				if(flag)
				{
					printf("%04d\n", query);
					break;
				}
			}
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
