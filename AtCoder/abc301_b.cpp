#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	printf("%d", ary[0]);
	int cur = ary[0];
	for (i=1; i<n; i++)
	{
		int step = 1;
		if (cur > ary[i])
		{
			step = -1;
		}
		for (j=cur+step; j!=ary[i]; j+=step)
		{
			printf(" %d", j);
		}
		printf(" %d", ary[i]);
		cur = ary[i];
	}
	puts("");
	return 0;
}
