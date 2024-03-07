#include <iostream>
#include <bitset>
using namespace std;

const int N = 305;

char buf[N];

int main()
{
	int pat, a, b, i, j;
	scanf("%d%d%d", &pat, &a, &b);
	scanf("%s", buf);
	bitset<N> bs;
	for (i=0; buf[i]; i++)
	{
		if (buf[i] == '1')
		{
			bs.set(100+a-i);
		}
	}
	for (i=0; i<b; i++)
	{
		bitset<N> cs;
		for (j=N-2; j>=1; j--)
		{
			int t = ((bs >> (j-1)) & decltype(bs)(0b111)).to_ulong();
			//printf(".. %d %d\n", j, t);
			if (pat & (1 << t))
			{
				cs.set(j);
			}
			if (j >= 101 && j <= 100+a)
			{
				printf("%d", cs.test(j));
			}
		}
		puts("");
		bs = cs;
	}
	return 0;
}
