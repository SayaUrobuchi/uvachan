#include <stdio.h>
#include <string.h>

int tbl[201], queuea[1000000], queueb[1000000], queuec[1000000], water[1000000];
char chk[201][201][201];

int main()
{
	int count, a, b, c, d, la, lb, lc, i, j, w;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &la, &lb, &lc, &d);
		memset(tbl, 0, sizeof(tbl));
		memset(chk, 0, sizeof(chk));
		queuea[0] = 0;
		queueb[0] = 0;
		queuec[0] = lc;
		water[0] = 1;
		chk[0][0][lc] = 1;
		for(i=0, j=1; i<j; i++)
		{
			a = queuea[i];
			b = queueb[i];
			c = queuec[i];
			w = water[i];
			if(!tbl[a] || tbl[a] > w)
			{
				tbl[a] = w;
			}
			if(!tbl[b] || tbl[b] > w)
			{
				tbl[b] = w;
			}
			if(!tbl[c] || tbl[c] > w)
			{
				tbl[c] = w;
			}
			if(tbl[d] && w > tbl[d])
			{
				continue;
			}
			if(lb - b > a)
			{
				if(!chk[0][a+b][c])
				{
					chk[0][a+b][c] = 1;
					queuea[j] = 0;
					queueb[j] = a+b;
					queuec[j] = c;
					water[j] = w + a;
					j++;
				}
			}
			else
			{
				if(!chk[a+b-lb][lb][c])
				{
					chk[a+b-lb][lb][c] = 1;
					queuea[j] = a+b-lb;
					queueb[j] = lb;
					queuec[j] = c;
					water[j] = w + lb - b;
					j++;
				}
			}
			if(lb - b > c)
			{
				if(!chk[a][b+c][0])
				{
					chk[a][b+c][0] = 1;
					queuea[j] = a;
					queueb[j] = b+c;
					queuec[j] = 0;
					water[j] = w + c;
					j++;
				}
			}
			else
			{
				if(!chk[a][lb][b+c-lb])
				{
					chk[a][lb][b+c-lb] = 1;
					queuea[j] = a;
					queueb[j] = lb;
					queuec[j] = b+c-lb;
					water[j] = w + lb - b;
					j++;
				}
			}
			if(lc - c > a)
			{
				if(!chk[0][b][a+c])
				{
					chk[0][b][a+c] = 1;
					queuea[j] = 0;
					queueb[j] = b;
					queuec[j] = a+c;
					water[j] = w + a;
					j++;
				}
			}
			else
			{
				if(!chk[a+c-lc][b][lc])
				{
					chk[a+c-lc][b][lc] = 1;
					queuea[j] = a+c-lc;
					queueb[j] = b;
					queuec[j] = lc;
					water[j] = w + lc - c;
					j++;
				}
			}
			if(lc - c > b)
			{
				if(!chk[a][0][b+c])
				{
					chk[a][0][b+c] = 1;
					queuea[j] = a;
					queueb[j] = 0;
					queuec[j] = b+c;
					water[j] = w + b;
					j++;
				}
			}
			else
			{
				if(!chk[a][b+c-lc][lc])
				{
					chk[a][b+c-lc][lc] = 1;
					queuea[j] = a;
					queueb[j] = b+c-lc;
					queuec[j] = lc;
					water[j] = w + lc - c;
					j++;
				}
			}
			if(la - a > b)
			{
				if(!chk[a+b][0][c])
				{
					chk[a+b][0][c] = 1;
					queuea[j] = a+b;
					queueb[j] = 0;
					queuec[j] = c;
					water[j] = w + b;
					j++;
				}
			}
			else
			{
				if(!chk[la][a+b-la][c])
				{
					chk[la][a+b-la][c] = 1;
					queuea[j] = la;
					queueb[j] = a+b-la;
					queuec[j] = c;
					water[j] = w + la - a;
					j++;
				}
			}
			if(la - a > c)
			{
				if(!chk[a+c][b][0])
				{
					chk[a+c][b][0] = 1;
					queuea[j] = a+c;
					queueb[j] = b;
					queuec[j] = 0;
					water[j] = w + c;
					j++;
				}
			}
			else
			{
				if(!chk[la][b][a+c-la])
				{
					chk[la][b][a+c-la] = 1;
					queuea[j] = la;
					queueb[j] = b;
					queuec[j] = a+c-la;
					water[j] = w + la - a;
					j++;
				}
			}
		}
		for(; d>-1; d--)
		{
			if(tbl[d])
			{
				printf("%d %d\n", tbl[d]-1, d);
				break;
			}
		}
	}
	return 0;
}
