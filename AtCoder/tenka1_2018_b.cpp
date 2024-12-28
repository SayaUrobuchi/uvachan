#include <iostream>
using namespace std;

int ary[2];

int main()
{
	int c, i;
	scanf("%d%d%d", &ary[0], &ary[1], &c);
	for (i=0; i<c; i++)
	{
		int a, b;
		a = (i & 1);
		b = !a;
		if (ary[a] & 1)
		{
			--ary[a];
		}
		int t = (ary[a] >> 1);
		ary[a] -= t;
		ary[b] += t;
	}
	printf("%d %d\n", ary[0], ary[1]);
	return 0;
}