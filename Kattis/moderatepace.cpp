#include <iostream>
using namespace std;

const int N = 1024;

int ary[N], bry[N], cry[N];

void read(int ary[], int n)
{
	for (int i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
}

int main()
{
	int n, i, high, low, ans;
	scanf("%d", &n);
	read(ary, n);
	read(bry, n);
	read(cry, n);
	for (i=0; i<n; i++)
	{
		high = max(ary[i], max(bry[i], cry[i]));
		low = min(ary[i], min(bry[i], cry[i]));
		ans = ary[i] + bry[i] + cry[i] - high - low;
		if (i)
		{
			putchar(' ');
		}
		printf("%d", ans);
	}
	puts("");
	return 0;
}
