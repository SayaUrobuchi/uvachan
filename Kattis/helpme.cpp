#include <stdio.h>
#include <algorithm>
using namespace std;

int bt[128], bx[128], by[128], bi[128], bn;
int wt[128], wx[128], wy[128], wi[128], wn;
int tbl[128];
const char *key = "KQRBNP";
char nam[16][8];
char buf[1024];

bool wcomp(int p, int q)
{
	if (wt[p] != wt[q])
	{
		return wt[p] < wt[q];
	}
	if (wx[p] != wx[q])
	{
		return wx[p] > wx[q];
	}
	return wy[p] < wy[q];
}

bool bcomp(int p, int q)
{
	if (bt[p] != bt[q])
	{
		return bt[p] < bt[q];
	}
	if (bx[p] != bx[q])
	{
		return bx[p] < bx[q];
	}
	return by[p] < by[q];
}

int main()
{
	int i, j;
	for (i=0; i<6; i++)
	{
		tbl[key[i]] = tbl[key[i]^32] = i;
		nam[i][0] = key[i];
		nam[i][1] = 0;
	}
	nam[5][0] = 0;
	while (scanf("%s", buf) == 1)
	{
		wn = 0;
		bn = 0;
		for (i=0; i<8; i++)
		{
			scanf("%s%*s", buf);
			for (j=2; j<=2+4*7; j+=4)
			{
				if (buf[j] >= 'a' && buf[j] <= 'z')
				{
					bt[bn] = tbl[buf[j]];
					bx[bn] = i;
					by[bn] = (j>>2);
					bi[bn] = bn;
					++bn;
				}
				else if (buf[j] >= 'A' && buf[j] <= 'Z')
				{
					wt[wn] = tbl[buf[j]];
					wx[wn] = i;
					wy[wn] = (j>>2);
					wi[wn] = wn;
					++wn;
				}
			}
		}
		sort(wi, wi+wn, wcomp);
		printf("White:");
		for (i=0; i<wn; i++)
		{
			printf("%c%s%c%d", i?',':' ', nam[wt[wi[i]]], 'a'+wy[wi[i]], 8-wx[wi[i]]);
		}
		puts("");
		sort(bi, bi+bn, bcomp);
		printf("Black:");
		for (i=0; i<bn; i++)
		{
			printf("%c%s%c%d", i?',':' ', nam[bt[bi[i]]], 'a'+by[bi[i]], 8-bx[bi[i]]);
		}
		puts("");
	}
	return 0;
}
