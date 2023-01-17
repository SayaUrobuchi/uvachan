#include <iostream>
using namespace std;

bool seat[1005];

int main()
{
	int n, m, i, t, ans;
	scanf("%d%d", &m, &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		seat[t-1] = true;
	}
	for (t=0; t<m&&!seat[t]; t++);
	for (i=0, ans=0; i<m; i++, t++)
	{
		if (!seat[t%m] && !seat[(t+1)%m] && !seat[(t+m-1)%m])
		{
			seat[t%m] = true;
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
