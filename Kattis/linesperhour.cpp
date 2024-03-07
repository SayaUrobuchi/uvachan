#include <iostream>
#include <algorithm>
using namespace std;

const int N = 64;

int ary[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	m *= 5;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	int sum = 0;
	for (i=0; i<n; i++)
	{
		if (sum + ary[i] > m)
		{
			break;
		}
		sum += ary[i];
	}
	printf("%d\n", i);
	return 0;
}
