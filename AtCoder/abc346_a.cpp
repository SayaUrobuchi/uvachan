#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1; i<n; i++)
	{
		printf("%d%c", ary[i]*ary[i-1], " \n"[i+1==n]);
	}
	return 0;
}
