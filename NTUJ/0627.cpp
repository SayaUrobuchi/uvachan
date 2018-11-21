#include <stdio.h>
#include <stdlib.h>

int ary[35], ans[10000001][6], ptt[10000001];

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

int main()
{
	int n, m, i, j, k, p, q, pp, qq, cc, tt, acnt, sum, tar;
	int *ptr;
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
		for(i=0, acnt=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				for(k=j+1; k<n; k++)
				{
					sum = ary[i]+ary[j]+ary[k];
					for(p=i+1; p<n; p++)
					{
						if(ary[p] * 3 > sum)
						{
							break;
						}
						if(p!=j && p!=k)
						{
							for(q=p+1; q<n; q++)
							{
								if(ary[p] + (ary[q]<<1) > sum)
								{
									break;
								}
								if(q!=j && q!=k)
								{
									tar = sum - ary[p] - ary[q];
									for(pp=q+1, qq=n-1, tt=n; pp<=qq; )
									{
										cc = ((pp+qq)>>1);
										if(ary[cc] >= tar)
										{
											qq = cc-1;
											tt = cc;
										}
										else
										{
											pp = cc+1;
										}
									}
									for(; tt<n; tt++)
									{
										if(ary[tt] > tar)
										{
											break;
										}
										if(tt != j && tt != k)
										{
											if(m)
											{
												ans[acnt][0] = ary[i];
												ans[acnt][1] = ary[j];
												ans[acnt][2] = ary[k];
												ans[acnt][3] = ary[p];
												ans[acnt][4] = ary[q];
												ans[acnt][5] = ary[tt];
												qsort(ans[acnt], 6, sizeof(int), int_comp);
												ptt[acnt] = acnt;
											}
											acnt++;
										}
									}
								}
							}
						}
					}
				}
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
