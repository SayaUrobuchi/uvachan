#include <iostream>
using namespace std;

int main()
{
	int n, i, j, t, least;
	scanf("%d", &n);
	for (i=0, least=1000; i<n; i++)
	{
		scanf("%d", &t);
		for (j=0; !(t&1); j++, t>>=1);
		least = min(least, j);
	}
	printf("%d\n", least);
	return 0;
}