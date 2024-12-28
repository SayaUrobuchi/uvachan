#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int sum = 0;
		for (j=0; j<7; j++)
		{
			int t;
			scanf("%d", &t);
			sum += t;
		}
		printf("%d%c", sum, " \n"[i+1==n]);
	}
	return 0;
}
