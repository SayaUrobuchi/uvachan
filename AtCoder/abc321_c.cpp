#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, i, k;
	scanf("%d", &n);
	vector<long long> que;
	for (i=1; i<=9; i++)
	{
		que.emplace_back(i);
	}
	long long ans;
	for (i=0; i<que.size(); i++)
	{
		if (i+1 == n)
		{
			ans = que[i];
			break;
		}
		int lim = que[i] % 10;
		for (k=0; k<lim; k++)
		{
			que.emplace_back(que[i] * 10 + k);
		}
	}
	printf("%lld\n", ans);
	return 0;
}
