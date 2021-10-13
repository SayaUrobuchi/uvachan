#include <iostream>
using namespace std;

char buf[64];

int main()
{
	int m, i, t;
	long long n, j;
	while (scanf("%llo%d", &n, &m) == 2)
	{
		for (i=0; i<m; i++)
		{
			t = 32;
			buf[t] = 0;
			for (j=n; j; j/=9)
			{
				t--;
				buf[t] = (j%9) + '0';
				if (buf[t] == '8')
				{
					buf[t] = '5';
				}
			}
			sscanf(buf+t, "%llo", &n);
		}
		printf("%llo\n", n);
	}
	return 0;
}
