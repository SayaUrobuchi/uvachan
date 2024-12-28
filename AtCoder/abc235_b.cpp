#include <iostream>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	int ans = ary[1];
	for (i=2; i<=n; i++)
	{
		if (ary[i] <= ans)
		{
			break;
		}
		ans = ary[i];
	}
	printf("%d\n", ans);
	return 0;
}
