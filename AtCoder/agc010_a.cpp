#include <iostream>
using namespace std;

int ary[2];

int main()
{
	int n, i, t;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		++ary[t&1];
	}
	ary[0] += (ary[1] >= 2);
	ary[1] &= 1;
	ary[0] = min(ary[0], 1);
	if (ary[1] ^ ary[0])
	{
		puts("YES");
	}
	else
	{
		puts("NO");
	}
	return 0;
}
