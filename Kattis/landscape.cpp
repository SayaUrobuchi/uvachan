#include <iostream>
using namespace std;

const int N = 200005;

int fd1[N], fd2[N];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		char cmd;
		int a, b;
		scanf(" %c%d%d", &cmd, &a, &b);
		int v = 1;
		switch (cmd)
		{
			case 'D':
				v = -v;
			case 'R':
				fd1[a] += v;
				fd1[b+1] -= v;
				break;
			case 'V':
				v = -v;
			case 'H':
				fd2[a] += v;
				fd2[b+2] += v;
				if ((b-a) & 1)
				{
					int t = a + ((b-a+1) >> 1);
					fd2[t] -= v;
					fd2[t+1] -= v;
				}
				else
				{
					int t = a + ((b-a) >> 1);
					fd2[t+1] -= v + v;
				}
				break;
		}
	}
	long long ac, h;
	for (i=1, ac=0, h=0; i<=n; i++)
	{
		ac += fd2[i];
		h += ac + fd1[i];
		printf("%lld\n", h);
	}
	return 0;
}
