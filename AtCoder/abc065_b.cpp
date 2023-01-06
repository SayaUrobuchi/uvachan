#include <iostream>
using namespace std;

int ary[100005];
bool used[100005];

int main()
{
	int n, i, ans;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1, ans=0; i!=2&&!used[i]; used[i]=true, i=ary[i], ans++);
	if (i == 2)
	{
		printf("%d\n", ans);
	}
	else
	{
		puts("-1");
	}
	return 0;
}
