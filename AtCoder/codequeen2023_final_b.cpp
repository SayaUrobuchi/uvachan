#include <iostream>
using namespace std;

const int N = 5050;
const int N2 = (N << 1);

bool row[N], col[N], d1[N2], d2[N2];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i<n; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		row[x] = true;
		col[y] = true;
		d1[x+y] = true;
		d2[x-y+n] = true;
	}
	int r, c;
	for (r=1; r<=n&&row[r]; r++);
	for (c=1; c<=n&&col[c]; c++);
	if (!d1[r+c] && !d2[r-c+n])
	{
		printf("%d %d\n", r, c);
	}
	else
	{
		puts("-1");
	}
	return 0;
}