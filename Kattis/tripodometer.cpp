#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int n, i, j, k, sum;
	scanf("%d", &n);
	for (i=0, sum=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		sum += ary[i];
	}
	sort(ary, ary+n);
	for (i=0, k=0; i<n; i=j)
	{
		for (j=i+1; j<n&&ary[j]==ary[i]; j++);
		ary[k++] = ary[i];
	}
	printf("%d\n", k);
	for (i=k-1; i>=0; i--)
	{
		printf("%d%c", sum-ary[i], i?' ':'\n');
	}
	return 0;
}
