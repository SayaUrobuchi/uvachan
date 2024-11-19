#include <iostream>
using namespace std;

const int N = 32;

int ary[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	puts("1");
	ary[1] = 1;
	for (i=2; i<=n; i++)
	{
		ary[i] = 1;
		for (j=i-1; j>1; j--)
		{
			ary[j] += ary[j-1];
		}
		printf("1");
		for (j=2; j<=i; j++)
		{
			printf(" %d", ary[j]);
		}
		puts("");
	}
	return 0;
}