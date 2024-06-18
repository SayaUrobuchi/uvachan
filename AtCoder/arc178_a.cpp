#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200005;

int ary[N];

int main()
{
	int n, m, i, j, k;
	scanf("%d%d", &n, &m);
	bool gg = false;
	int best = 0;
	int worst = n;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		if (ary[i] == 1 || ary[i] == n)
		{
			gg = true;
		}
	}
	if (gg)
	{
		puts("-1");
	}
	else
	{
		sort(ary, ary+m);
		int t = 1;
		for (i=0; i<m; i=j)
		{
			for (j=i+1; j<m&&ary[j]==ary[j-1]+1; j++);
			for (; t<ary[i]; t++)
			{
				printf("%d ", t);
			}
			for (k=t+1; k<=ary[j-1]+1; k++)
			{
				printf("%d ", k);
			}
			printf("%d ", t);
			t = k;
		}
		for (; t<=n; t++)
		{
			printf("%d ", t);
		}
		puts("");
	}
	return 0;
}
