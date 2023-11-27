#include <iostream>
using namespace std;

int main()
{
	int n, m, i, sum;
	scanf("%d%d", &n, &m);
	for (i=0, sum=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		sum += t;
	}
	puts(sum <= m ? "Jebb" : "Neibb");
	return 0;
}
