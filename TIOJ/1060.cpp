#include <stdio.h>

int hused[1000000], hdp[1000000], fused[1000000], fdp[1000000];

int f(int);
int g(int);
int h(int);

int g(int z)
{
	if(z <= 2)
	{
		return z*z - 1;
	}
	return 2;
}

int h(int y)
{
	if(hused[y+200000])
	{
		return hdp[y+200000];
	}
	hused[y+200000] = 1;
	if(y < 2)
	{
		return hdp[y+200000] = -1;
	}
	return hdp[y+200000] = 2 + h(y-1) - h(y-2);
}

int f(int x)
{
	if(fused[x+200000])
	{
		return fdp[x+200000];
	}
	fused[x+200000] = 1;
	if(x > h(x))
	{
		return fdp[x+200000] = f(x-1) - h(x);
	}
	else if(x < h(x))
	{
		return fdp[x+200000] = f(g(x)) - g(x);
	}
	return fdp[x+200000] = 1;
}

int main()
{
	int n;
	f(100);
	f(-100);
	f(200);
	f(-200);
	while(scanf("%d", &n) == 1)
	{
		printf("%d\n", f(n));
	}
	return 0;
}
