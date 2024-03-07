#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	int k = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		while (!(t & 1))
		{
			++k;
			t >>= 1;
		}
	}
	printf("%d\n", m<=k);
	return 0;
}
