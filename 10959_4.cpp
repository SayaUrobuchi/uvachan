#include <stdio.h>
#include <string.h>
#include <stdlib.h>

short dis[1000], dp[1000], map[1000][21], heap[10000], n;

int main()
{
	int in, in2;
	short i, j, tmp, ctmp, ptmp, stmp, pnow, htmp, p, d, now, count, *ptr;
	scanf("%d", &in);
	count = in;
	while(count--)
	{
		scanf("%d%d", &in, &in2);
		p = in;
		d = in2;
		for(i=0; i<p; i++)
		{
			map[i][0] = 1;
		}
		while(d--)
		{
			scanf("%d%d", &in, &in2);
			map[in][map[in][0]++] = in2;
			map[in2][map[in2][0]++] = in;
		}
		memset(dis, 0, p * 2);
		dis[0] = -1;
		n = 0;
		for(i=1, ctmp=map[0][0]; i<ctmp; i++)
		{
			dis[map[0][i]] = 1;
			heap[++n] = map[0][i];
		}
		ptmp = p - 1;
		while(ptmp)
		{
			now = heap[1];
			heap[1] = heap[n--];
			pnow = 1;
			stmp = heap[1];
			while(1)
			{
				htmp = pnow * 2;
				ptr = &heap[htmp];
				if(htmp > n) break;
				if(htmp < n && dis[*ptr] > dis[*(ptr + 1)])
				{
					htmp++;
					ptr++;
				}
				if(dis[stmp] > dis[*ptr])
				{
					heap[pnow] = *ptr;
				}
				else
				{
					break;
				}
				pnow = htmp;
			}
			heap[pnow] = stmp;
			if(dis[now] != -1)
			{
				ptmp--;
				ctmp = dis[now];
				dp[now] = ctmp;
				dis[now] = -1;
				ctmp++;
				for(i=1, tmp=map[now][0], ptr=map[now] + 1; i<tmp; i++, ptr++)
				{
					if(!dis[*ptr] || dis[*ptr] > ctmp)
					{
						dis[*ptr] = ctmp;
						heap[++n] = *ptr;
						pnow = n;
						stmp = heap[n];
						while(1)
						{
							if(pnow == 1) break;
							htmp = pnow / 2;
							if(dis[stmp] < dis[heap[htmp]])
							{
								heap[pnow] = heap[htmp];
							}
							else
							{
								break;
							}
							pnow = htmp;
						}
						heap[pnow] = stmp;
     			}
				}
			}
		}
		for(i=1; i<p; i++)
		{
			printf("%d\n", dp[i]);
		}
		if(count) printf("\n");
	}
	return 0;
}
