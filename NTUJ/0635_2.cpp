#include <stdio.h>
#include <string.h>

int pre_calc(int a, int m, int *tbl, int *list)
{
	int i, t;
	static int f=0, res;
	if(f)
	{
		return res;
	}
	for(i=0, t=a%m; ; i++)
	{
		if(tbl[t])
		{
			break;
		}
		tbl[t] = 1;
		list[i] = t;
		t *= a;
		t %= m;
	}
	f = 1;
	return res=i;
}

int calc(int a, int b, int n)
{
	int i, t;
	static int tbl[10001], list[10001];
	if(b == 0)
	{
		return a%n;
	}
	t = pre_calc(a, n, tbl, list);
	return list[calc(a, b-1, t)];
}

int main()
{
	int a, b, n;
	while(scanf("%d%d%d", &a, &b, &n) == 3)
	{
		printf("%d\n", calc(a, b, n));
	}
	return 0;
}
