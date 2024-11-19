#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 200005;

vector<int> dif[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	int lim = 0;
	for (i=0; i<n; i++)
	{
		int st, ed, need;
		scanf("%d%d%d", &st, &ed, &need);
		dif[st].emplace_back(need);
		dif[ed].emplace_back(-need);
		lim = max(lim, ed);
	}
	bool gg = false;
	long long required = 0;
	for (i=0; i<=lim&&!gg; i++)
	{
		for (j=0; j<dif[i].size(); j++)
		{
			int val = dif[i][j];
			required += val;
		}
		gg = (required > m);
	}
	if (gg)
	{
		puts("No");
	}
	else
	{
		puts("Yes");
	}
	return 0;
}
