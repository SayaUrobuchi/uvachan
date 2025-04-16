#include <iostream>
using namespace std;

const int N = 2048;

int ary[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (j=n-1; j>0; j--)
	{
		for (i=0; i<j; i++)
		{
			ary[i] = abs(ary[i] - ary[i+1]);
		}
	}
	printf("%d\n", ary[0]);
	return 0;
}
