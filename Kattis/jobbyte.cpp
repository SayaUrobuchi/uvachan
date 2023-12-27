#include <iostream>
using namespace std;

const int N = 300005;

int ary[N];

int main()
{
	int n, i, ans;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1, ans=0; i<=n; i++)
	{
		if (ary[i] != i)
		{
			while (ary[i] != i)
			{
				swap(ary[i], ary[ary[i]]);
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
