#include <iostream>
using namespace std;

int ary[105];

bool judge(int a, int b, int c)
{
	if (a == b || a == c || b == c)
	{
		return false;
	}
	int x = max(a, max(b, c));
	int y = min(a, min(b, c));
	int z = a+b+c - x - y;
	return x < y+z;
}

int main()
{
	int n, i, j, k, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=0, ans=0; i<n; i++)
	{
		for (j=i+1; j<n; j++)
		{
			for (k=j+1; k<n; k++)
			{
				ans += judge(ary[i], ary[j], ary[k]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}