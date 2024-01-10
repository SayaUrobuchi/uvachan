#include <iostream>
using namespace std;

const int N = 1000005;

int n;
int ary[N], bit[N];

void fix(int pos, int v)
{
	for (; pos<=n; pos+=(pos&-pos))
	{
		bit[pos] += v;
	}
}

int rq(int t)
{
	int ret = 0;
	for (; t; t-=(t&-t))
	{
		ret += bit[t];
	}
	return ret;
}

int query(int a, int b)
{
	return rq(b) - rq(a-1);
}

int main()
{
	int m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		char cmd;
		int a, b;
		scanf(" %c", &cmd);
		if (cmd == 'F')
		{
			scanf("%d", &a);
			fix(a, (ary[a]^1)-ary[a]);
			ary[a] ^= 1;
		}
		else
		{
			scanf("%d%d", &a, &b);
			int ret = query(a, b);
			printf("%d\n", ret);
		}
	}
	return 0;
}
