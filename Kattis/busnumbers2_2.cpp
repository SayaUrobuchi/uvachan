#include <iostream>
using namespace std;

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	int ans = 0;
	for (i=n; i>0&&!ans; i--)
	{
		int cnt = 0;
		for (j=1; j*j*j<i&&cnt<2; j++)
		{
			for (k=j; j*j*j+k*k*k<i; k++);
			if (j*j*j + k*k*k == i)
			{
				++cnt;
			}
		}
		if (cnt >= 2)
		{
			ans = i;
		}
	}
	if (ans)
	{
		printf("%d\n", ans);
	}
	else
	{
		puts("none");
	}
	return 0;
}
