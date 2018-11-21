#include <stdio.h>
#include <string.h>

int n;
int used[100];
int ary[1000];
double map[100][100];

int getindex(int now)
{
	int i;
	for(i=1; i<=n; i++)
	{
		if(ary[i] == now)
		{
			return i;
		}
	}
	ary[++n] = now;
	return n;
}

double getres(int a, int b)
{
	int i, j, temp;
	double f, p, tmp;
	int queue[100];
	int pp, qq;
	pp = a;
	qq = b;
	/*printf("XDD %d %d\n", a, b);*/
	if(a == b)
	{
		return 0.0;
	}
	for(f=0; ; )
	{
		used[b] = 1;
		/*printf("b: %d\n", b);*/
		for(i=1, j=0; i<=n; i++)
		{
			if(map[b][i] && (!used[i] || i == a))
			{
				temp = i;
				j++;
			}
		}
		/*printf("j: %d\n", j);*/
		if(!j)
		{
			/*printf("FAIL %d %d\n", pp, qq);*/
			return -1.0;
		}
		else if(j == 1)
		{
			if(map[b][temp] > 0)
			{
				f += 1.0 / map[b][temp];
			}
			b = temp;
			if(a == b)
			{
				/*printf("%d %d: %.3lf\n", pp, qq, f);*/
				return f;
			}
		}
		else
		{
			for(; ; )
			{
				/*printf("A: %d\n", a);*/
				used[a] = 1;
				for(i=1, j=0; i<=n; i++)
				{
					if(map[a][i] && (!used[i] || i == b))
					{
						queue[j++] = i;
					}
				}
				/*printf("J: %d\n", j);*/
				if(!j)
				{
					/*printf("FAIL!!! %d %d\n", pp, qq);*/
					return -1.0;
				}
				else if(j == 1)
				{
					if(map[a][queue[0]] > 0)
					{
						f += 1.0 / map[a][queue[0]];
					}
					a = queue[0];
					if(a == b)
					{
						/*printf("%d %d: %.3lf\n", pp, qq, f);*/
						return f;
					}
				}
				else
				{
					for(i=0, p=0; i<j; i++)
					{
						if((tmp=getres(queue[i], b)) >= 0)
						{
							/*printf("%d => %d => %d: %.3lf\n", a, queue[i], b, 1.0/(1.0/map[a][queue[i]]+tmp));*/
							if(map[a][queue[i]] > 0)
							{
								tmp += 1.0 / map[a][queue[i]];
							}
							if(tmp > 0.0)
							{
								p += 1.0 / tmp;
							}
						}
					}
					/*printf("%d %d: %.3lf %.3lf\n", pp, qq, f, 1.0/p);*/
					if(p > 0.0)
					{
						f += 1.0 / p;
					}
					return f;
				}
			}
		}
	}
}

int main()
{
	int cas, m, a, b, p, q;
	double r;
	cas = 0;
	while(scanf("%d%d%d", &m, &a, &b) == 3)
	{
		if(!m && !a && !b)
		{
			break;
		}
		n = 0;
		a = getindex(a);
		b = getindex(b);
		memset(map, 0, sizeof(map));
		memset(used, 0, sizeof(used));
		while(m--)
		{
			scanf("%d%d%lf", &p, &q, &r);
			p = getindex(p);
			q = getindex(q);
			if(r == 0.0)
			{
				map[p][q] = map[q][p] = -1.0;
			}
			else
			{
				map[p][q] += 1.0 / r;
				map[q][p] += 1.0 / r;
				/*map[p][q] = map[q][p] = 1.0;*/
			}
		}
		r = getres(a, b);
		if(r < 0)
		{
			r = 0.0;
		}
		printf("Case %d: %.2lf Ohms\n", ++cas, r);
	}
	return 0;
}
