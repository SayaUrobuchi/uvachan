#include <iostream>
using namespace std;

const int N = 100005;

int ary[N];
bool used[N];

int main()
{
	int n, i, j, ans;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1, ans=0; i<=n; i++)
	{
		if (!used[i] && ary[i] != i)
		{
			for (j=ary[i], ++ans; j!=i; j=ary[j])
			{
				used[j] = true;
				++ans;
			}
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
