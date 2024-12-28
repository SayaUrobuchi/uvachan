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
	int st = n - m;
	for (i=0; i<n; i++)
	{
		printf("%d%c", ary[(i+st)%n], " \n"[i+1==n]);
	}
	return 0;
}
