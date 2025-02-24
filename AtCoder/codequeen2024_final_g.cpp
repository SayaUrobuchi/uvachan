#include <iostream>
#include <queue>
#include <tuple>
#include <array>
using namespace std;
using pp = pair<int, int>;
using pq_t = priority_queue<pp>;

const int N = 200005;

int ary[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	long long sum = 0;
	int most = -1;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		sum += ary[i];
		most = max(most, ary[i]);
	}
	int other = sum - most;
	int total = other + min(most, other/2*3);
	int ans = total / 5;
	printf("%d\n", ans);
	pq_t pq;
	for (i=0; i<n; i++)
	{
		pq.emplace(ary[i], i+1);
	}
	for (i=0; i<ans; i++)
	{
		array<int, 5> list;
		for (j=0; j<5; j+=2)
		{
			int a, ai;
			tie(a, ai) = pq.top();
			pq.pop();
			list[j] = ai;
			int b, bi;
			if (j+1 < 5)
			{
				tie(b, bi) = pq.top();
				pq.pop();
				list[j+1] = bi;
				pq.emplace(b-1, bi);
			}
			pq.emplace(a-1, ai);
		}
		for (j=0; j<5; j++)
		{
			printf("%d%c", list[j], " \n"[j+1==5]);
		}
	}
	return 0;
}
