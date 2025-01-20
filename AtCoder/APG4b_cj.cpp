#include <iostream>
using namespace std;

const int N = 1024;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	int sum = 0;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		sum += ary[i];
	}
	int avg = sum / n;
	for (i=0; i<n; i++)
	{
		int dif = abs(avg - ary[i]);
		printf("%d\n", dif);
	}
	return 0;
}
