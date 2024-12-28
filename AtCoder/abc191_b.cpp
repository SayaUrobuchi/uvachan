#include <iostream>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	int nn = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t != m)
		{
			ary[nn] = t;
			++nn;
		}
	}
	for (i=0; i<nn; i++)
	{
		printf("%d%c", ary[i], " \n"[i+1==nn]);
	}
	return 0;
}
