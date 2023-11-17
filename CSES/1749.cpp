#include<iostream>
using namespace std;
 
const int N = 200005;
 
int ary[N], bit[N];
 
void add(int n, int pos, int d)
{
	for (; pos<=n; pos+=(pos&-pos))
	{
		bit[pos] += d;
	}
}
 
int main()
{
	int n, i, j, t, u;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		add(n, i, 1);
	}
	for (u=0; (1<<u)<=n; u++);
	--u;
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		int pos = 0;
		for (j=(1<<u); j; j>>=1)
		{
			if (pos+j <= n && bit[pos+j] < t)
			{
				pos += j;
				t -= bit[pos];
			}
		}
		add(n, pos+1, -1);
		printf("%d%c", ary[pos+1], (i==n-1)?'\n':' ');
	}
	return 0;
}
