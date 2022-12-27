#include <iostream>
using namespace std;

int main()
{
	int n, m, i, j, k, a, b, c;
	scanf("%d%d", &n, &m);
	a = b = c = -1;
	for (i=0; i<=n&&m>=0; i++, m-=10000)
	{
		j = (n-i) * 1000;
		k = j * 5;
		if (m >= j && m <= k && (m-j)%4000 == 0)
		{
			a = i;
			b = (m-j) / 4000;
			c = n-a-b;
		}
	}
	printf("%d %d %d\n", a, b, c);
//	fprintf(stderr, "%d\n", a*10000+b*5000+c*1000);
	return 0;
}