#include <iostream>
using namespace std;

int f[16];

int main()
{
	int n, i, ans;
	f[1] = 1;
	for (i=2; i<=10; i++)
	{
		f[i] = f[i-1] * i;
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=10, ans=0; i>=1; i--)
		{
			while (n >= f[i])
			{
				n -= f[i];
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
