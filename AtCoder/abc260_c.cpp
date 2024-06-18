#include <iostream>
using namespace std;

const int N = 15;

long long red[N], blue[N];

int main()
{
	int n, x, y, i;
	scanf("%d%d%d", &n, &x, &y);
	red[n] = 1;
	for (i=n; i>1; i--)
	{
		red[i-1] += red[i];
		blue[i] += red[i] * x;
		red[i-1] += blue[i];
		blue[i-1] += blue[i] * y;
	}
	printf("%lld\n", blue[1]);
	return 0;
}
