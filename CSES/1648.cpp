#include <iostream>
using namespace std;
 
const int UPDATE = 1;
const int QUERY = 2;
const int N = 200005;
 
int n;
int ary[N];
long long bit[N];
 
void add(int pos, int d)
{
	for (; pos<=n; pos+=(pos&-pos))
	{
		bit[pos] += d;
	}
}
 
long long sum(int pos)
{
	long long ret = 0;
	for (; pos; pos-=(pos&-pos))
	{
		ret += bit[pos];
	}
	return ret;
}
 
long long query(int a, int b)
{
	return sum(b) - sum(a-1);
}
 
int main()
{
	int m, i, cmd, a, b;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		add(i, ary[i]);
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d", &cmd, &a, &b);
		if (cmd == UPDATE)
		{
			add(a, b-ary[a]);
			ary[a] = b;
		}
		else
		{
			long long ret = query(a, b);
			printf("%lld\n", ret);
		}
	}
	return 0;
}
