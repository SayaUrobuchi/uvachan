#include <iostream>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int n, i, j, ans;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1, ans=-1; i+i<=n; i++)
	{
		for (j=i+i; j<=n&&ary[j]>ary[j-i]; j+=i);
		if (j > n)
		{
			ans = i;
			break;
		}
	}
	if (ans == -1)
	{
		puts("ABORT!");
	}
	else
	{
		printf("%d\n", ans);
	}
	return 0;
}
