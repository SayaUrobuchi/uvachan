#include <iostream>
using namespace std;

long long ary[25];

int main()
{
	int i;
	ary[0] = 100;
	ary[1] = 100;
	ary[2] = 200;
	for (i=3; i<20; i++)
	{
		ary[i] = ary[i-1] + ary[i-2] + ary[i-3];
	}
	printf("%lld\n", ary[19]);
	return 0;
}
