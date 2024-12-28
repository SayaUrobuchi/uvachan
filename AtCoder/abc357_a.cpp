#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1; i<=n; i++)
	{
		if (m < ary[i])
		{
			break;
		}
		m -= ary[i];
	}
	printf("%d\n", i-1);
	return 0;
}
