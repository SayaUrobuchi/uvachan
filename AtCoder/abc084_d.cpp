#include <iostream>
#include <vector>
using namespace std;

const int N = 100005;

int tbl[N], pre[N];

int main()
{
	int i, j;
	vector<int> pri;
	for (i=2; i<N; i++)
	{
		if (!tbl[i])
		{
			pri.emplace_back(i);
			if (i & 1)
			{
				if (!tbl[(i+1) >> 1])
				{
					pre[i] = 1;
				}
			}
		}
		pre[i] += pre[i-1];
		for (j=0; j<pri.size()&&i*pri[j]<N; j++)
		{
			tbl[i * pri[j]] = true;
			if (i % pri[j] == 0)
			{
				break;
			}
		}
	}
	int n;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		printf("%d\n", pre[b]-pre[a-1]);
	}
	return 0;
}