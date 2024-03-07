#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1024;

char buf[N], o[N];

int main()
{
	int n, m, i, j, ans;
	scanf("%d%d%s", &n, &m, &o);
	ans = 1;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		for (j=0; j<m; j++)
		{
			if (buf[j] == '.')
			{
				++ans;
			}
		}
	}
	printf("Your destination will arrive in %d%s meters\n", ans, o+1);
	return 0;
}
