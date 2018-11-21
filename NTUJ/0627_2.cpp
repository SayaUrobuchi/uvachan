#include <stdio.h>
#include <stdlib.h>

int ary[35], ans[10000001][6], ptt[10000001];
int list[5000][4], lpp[5000];

int int_comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int lex_comp(const void *p, const void *q)
{
	int i, *pp, *qq;
	pp = ans[*(int*)p];
	qq = ans[*(int*)q];
	for(i=0; i<6; i++)
	{
		if(pp[i] != qq[i])
		{
			return pp[i]-qq[i];
		}
	}
	return 0;
}

int lis_comp(const void *p, const void *q)
{
	return *list[*(int*)p] - *list[*(int*)q];
}

int main()
{
	int n, m, i, j, k, pp, qq, cc, tt, acnt, sum, tar, lcnt;
	int *ptr, *p, *q;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		qsort(ary, n, sizeof(int), int_comp);
		for(i=0, acnt=0, lcnt=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				for(k=j+1; k<n; k++)
				{
					sum = ary[i]+ary[j]+ary[k];
					list[lcnt][0] = sum;
					list[lcnt][1] = i;
					list[lcnt][2] = j;
					list[lcnt][3] = k;
					lpp[lcnt] = lcnt;
					lcnt++;
				}
			}
		}
		qsort(lpp, lcnt, sizeof(int), lis_comp);
		for(i=0; i<lcnt; i++)
		{
			for(j=i+1; j<lcnt; j++)
			{
				if(list[lpp[i]][0] != list[lpp[j]][0])
				{
					break;
				}
				p = list[lpp[i]] + 1;
				q = list[lpp[j]] + 1;
				for(pp=0, qq=0, k=0; pp<3||qq<3; )
				{
					if(pp < 3 && qq < 3 && p[pp] == q[qq])
					{
						break;
					}
					if(qq >= 3 || (pp<3 && p[pp] < q[qq]))
					{
						ans[acnt][k] = ary[p[pp]];
						pp++;
					}
					else
					{
						ans[acnt][k] = ary[q[qq]];
						qq++;
					}
					k++;
				}
				if(pp<3||qq<3)
				{
					continue;
				}
				ptt[acnt] = acnt;
				acnt++;
			}
		}
		printf("%d\n", acnt);
		if(m)
		{
			qsort(ptt, acnt, sizeof(int), lex_comp);
			for(i=0; i<acnt; i++)
			{
				ptr = ans[ptt[i]];
				printf("%d %d %d %d %d %d\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4], ptr[5]);
			}
		}
	}
	return 0;
}
