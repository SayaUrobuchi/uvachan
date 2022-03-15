#include <iostream>
using namespace std;

int main()
{
	int n, m, i, t, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, ans=-(n>>1); i<n; i++)
		{
			scanf("%d", &t);
			ans += t;
		}
		puts(ans<=m?"Yes":"No");
	}
	return 0;
}
