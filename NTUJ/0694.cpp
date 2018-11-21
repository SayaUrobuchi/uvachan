#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fa[5], fb[5], a[5], b[5], stt[8000], cntt[8000];
double rate[32], brat[32];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int calc(int *ary)
{
	int i;
	int ta[5];
	for(i=0; i<5; i++)
	{
		ta[i] = ary[i];
	}
	qsort(ta, 5, sizeof(int), comp);
	if(ta[0] == ta[4])
	{
		return 90000000 + ta[0];
	}
	else if(ta[0] == ta[3] || ta[1] == ta[4])
	{
		return 80000000 + (ta[0]==ta[3] ? ta[0]*10 + ta[4] : ta[4] * 10 + ta[0]);
	}
	else if((ta[0] == ta[2] && ta[3] == ta[4]) || (ta[0] == ta[1] && ta[2] == ta[4]))
	{
		return 70000000 + (ta[0] == ta[2] ? ta[0]*10+ta[3] : ta[2]*10+ta[0]);
	}
	else if(ta[0]+1 == ta[1] && ta[1]+1 == ta[2] && ta[2]+1 == ta[3] && ta[3]+1 == ta[4])
	{
		return 60000000 + ta[4];
	}
	else if(ta[0] == ta[2] || ta[2] == ta[4])
	{
		return 50000000 + (ta[0] == ta[2] ? ta[0]*100+ta[4]*10+ta[3] : ta[2]*100+ta[1]+ta[0]);
	}
	else if((ta[0] == ta[1] && ta[2] == ta[3]) || (ta[0] == ta[1] && ta[3] == ta[4]) || (ta[1] == ta[2] && ta[3] == ta[4]))
	{
		return 40000000 + (ta[0] == ta[1] && ta[2] == ta[3] ? ta[2]*100+ta[1]*10+ta[4] : 
			(ta[0] == ta[1] && ta[3] == ta[4] ? ta[4]*100+ta[1]*10+ta[2] : 
				ta[4]*100+ta[2]*10+ta[0]));
	}
	else if(ta[0] == ta[1] || ta[1] == ta[2] || ta[2] == ta[3] || ta[3] == ta[4])
	{
		return 30000000 + (ta[0] == ta[1] ? ta[1]*10000 + ta[4]*1000 + ta[3]*100 + ta[2] : 
			(ta[1] == ta[2] ? ta[1]*10000+ta[4]*1000+ta[3]*100+ta[0] : 
				(ta[2] == ta[3] ? ta[2]*10000+ta[4]*1000+ta[1]*100+ta[0] : 
					(ta[3]*10000+ta[2]*1000+ta[1]*100+ta[0]))));
	}
	else
	{
		return ta[4]*10000+ta[3]*1000+ta[2]*100+ta[1]*10+ta[0];
	}
}

int winn(int* aa, int* bb)
{
	return calc(aa) > calc(bb);
}

void check_brat(int dep, int st, double r)
{
	int i;
	if(dep == 5)
	{
		if(winn(fa, fb))
		{
			brat[st] += 1 * r;
		}
		return;
	}
	if(st & (1<<dep))
	{
		for(i=1; i<=6; i++)
		{
			fb[dep] = i;
			check_brat(dep+1, st, r/6.0);
		}
	}
	else
	{
		fb[dep] = b[dep];
		check_brat(dep+1, st, r);
	}
}

void dfsb(int dep, int st)
{
	if(dep == 5)
	{
		brat[st] = 0.0;
		check_brat(0, st, 1.0);
		return;
	}
	dfsb(dep+1, st);
	dfsb(dep+1, st+(1<<dep));
}

void check_rate(int dep, int st, double r)
{
	int i;
	double mx;
	if(dep == 5)
	{
		if(winn(b, fa))
		{
			return;
		}
		dfsb(0, 0);
		for(i=0, mx=-1.0; i<32; i++)
		{
			if(brat[i] > mx)
			{
				mx = brat[i];
			}
		}
		rate[st] += mx * r;
		return;
	}
	if(st & (1<<dep))
	{
		for(i=1; i<=6; i++)
		{
			fa[dep] = i;
			check_rate(dep+1, st, r/6.0);
		}
	}
	else
	{
		fa[dep] = a[dep];
		check_rate(dep+1, st, r);
	}
}

void dfs(int dep, int st)
{
	if(dep == 5)
	{
		rate[st] = 0.0;
		check_rate(0, st, 1.0);
		return;
	}
	dfs(dep+1, st);
	dfs(dep+1, st+(1<<dep));
}

int main()
{
	int count, i;
	double j;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0; i<5; i++)
		{
			scanf("%d", &a[i]);
		}
		for(i=0; i<5; i++)
		{
			scanf("%d", &b[i]);
		}
		memset(stt, -1, sizeof(stt));
		dfs(0, 0);
		for(i=0, j=-1.0; i<32; i++)
		{
			if(rate[i] > j)
			{
				j = rate[i];
			}
		}
		printf("%.6lf\n", j*100.0);
	}
	return 0;
}
