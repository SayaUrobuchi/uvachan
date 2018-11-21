#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int en, ecc;
int px1[40005], px2[40005], py1[40005], py2[40005], pp[40005], epx[80005];
int pnum[80005], list[80005][205];
long long flow[40005];

int min(int p, int q)
{
	return p<q ? p : q;
}

int lis_comp(const void *p, const void *q)
{
	double pp, qq;
	pp = py1[*(int*)p] + (double)(py2[*(int*)p]-py1[*(int*)p])*(ecc-px1[*(int*)p])/(px2[*(int*)p]-px1[*(int*)p]);
	qq = py1[*(int*)q] + (double)(py2[*(int*)q]-py1[*(int*)q])*(ecc-px1[*(int*)q])/(px2[*(int*)q]-px1[*(int*)q]);
	if(pp < qq)
	{
		return 1;
	}
	return -1;
}

int epx_comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int pp_comp(const void *p, const void *q)
{
	int y1, y2;
	y1 = min(py1[*(int*)p], py2[*(int*)p]);
	y2 = min(py1[*(int*)q], py2[*(int*)q]);
	return y2 - y1;
}

int main()
{
	int cas, n, i, j, tt, p, q, c, x;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		for(i=0, j=0; i<n; i++)
		{
			scanf("%d%d%d%d", &px1[i], &py1[i], &px2[i], &py2[i]);
			pp[i] = i;
			epx[j++] = px1[i];
			epx[j++] = px2[i];
		}
		qsort(epx, j, sizeof(int), epx_comp);
		for(i=0, en=0, tt=j; i<tt; )
		{
			for(j=i+1; j<tt; j++)
			{
				if(epx[i] != epx[j])
				{
					break;
				}
			}
			epx[en++] = epx[i];
			i = j;
		}
		qsort(pp, n, sizeof(int), pp_comp);
		memset(flow, 0, sizeof(flow));
		memset(pnum, 0, sizeof(pnum));
		for(i=0; i<n; i++)
		{
			p = 0;
			q = en-1;
			for(; p<=q; )
			{
				c = ((p+q)>>1);
				if(epx[c] == px1[pp[i]])
				{
					break;
				}
				else if(epx[c] > px1[pp[i]])
				{
					q = c-1;
				}
				else
				{
					p = c+1;
				}
			}
			for(j=c; j<en; j++)
			{
				if(epx[j] <= px2[pp[i]])
				{
					list[j][pnum[j]++] = pp[i];
				}
				else
				{
					break;
				}
			}
		}
		ecc = epx[0];
		qsort(list[0], pnum[0], sizeof(int), lis_comp);
		for(i=1; i<en; i++)
		{
			ecc = epx[i];
			qsort(list[i], pnum[i], sizeof(int), lis_comp);
			for(j=0; j<pnum[i]; j++)
			{
				tt = list[i][j];
				if(px1[tt] <= epx[i-1] && px2[tt] >= epx[i])
				{
					flow[tt] += epx[i]-epx[i-1];
					break;
				}
			}
		}
		for(i=0; i<n; i++)
		{
			if(py1[pp[i]] < py2[pp[i]])
			{
				x = px1[pp[i]];
			}
			else
			{
				x = px2[pp[i]];
			}
			p = 0;
			q = en-1;
			for(; p<=q; )
			{
				c = ((p+q)>>1);
				if(epx[c] == x)
				{
					break;
				}
				else if(epx[c] > x)
				{
					q = c-1;
				}
				else
				{
					p = c+1;
				}
			}
			for(j=0; j<pnum[c]; j++)
			{
				if(list[c][j] == pp[i])
				{
					for(j++; j<pnum[c]; j++)
					{
						tt = list[c][j];
						if(px1[tt] <= epx[c] && px2[tt] >= epx[c])
						{
							flow[tt] += flow[pp[i]];
							break;
						}
					}
					break;
				}
			}
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		for(i=0; i<n; i++)
		{
			printf("%lld\n", flow[i]);
		}
	}
	return 0;
}
