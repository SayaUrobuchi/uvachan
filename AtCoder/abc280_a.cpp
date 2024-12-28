#include <iostream>
using namespace std;

const int N = 16;

char buf[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		for (j=0; j<m; j++)
		{
			if (buf[j] == '#')
			{
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
