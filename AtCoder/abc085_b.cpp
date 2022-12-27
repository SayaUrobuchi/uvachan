#include <iostream>
using namespace std;

int used[128];

int main()
{
	int n, i, t, ans;
	scanf("%d", &n);
	for (i=0, ans=0; i<n; i++)
	{
		scanf("%d", &t);
		ans += !used[t];
		used[t] = true;
	}
	printf("%d\n", ans);
	return 0;
}