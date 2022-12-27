#include <iostream>
using namespace std;

int main()
{
	int n, i, t, x, y, d, nt, nx, ny;
	bool able;
	scanf("%d", &n);
	able = true;
	for (i=0, t=0, x=y=0; i<n; i++, t=nt, x=nx, y=ny)
	{
		scanf("%d%d%d", &nt, &nx, &ny);
		d = abs(x-nx) + abs(y-ny);
		if (d > nt-t || (d&1) != ((nt-t)&1))
		{
			able = false;
		}
	}
	if (able)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}