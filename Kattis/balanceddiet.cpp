#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	int n, i;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		bitset<10*600+5> bs;
		bs.set(0);
		int sum = 0;
		for (i=0; i<n; i++)
		{
			int t;
			scanf("%d", &t);
			sum += t;
			bs |= (bs << t);
		}
		for (i=sum>>1; !bs.test(i); --i);
		printf("%d %d\n", sum-i, i);
	}
	return 0;
}
