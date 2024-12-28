#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=m; i<n; i++)
	{
		printf("%d ", ary[i]);
	}
	int lim = min(n, m);
	for (i=0; i<lim; i++)
	{
		printf("0%c", " \n"[i+1==lim]);
	}
	return 0;
}
