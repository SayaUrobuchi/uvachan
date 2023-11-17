#include <iostream>
#include <tuple>
using namespace std;
using cost_t = pair<int, int>;

const int N = 20;
const int NN = (1 << N);

int n, m;
int wei[N];
bool used[NN];
cost_t dp[NN];

cost_t recurs(int stat)
{
	if (used[stat])
	{
		return dp[stat];
	}
	used[stat] = true;
	if (stat == 0)
	{
		return dp[stat] = make_pair(0, 0);
	}
	dp[stat] = make_pair(n+1, 0);
	for (int i=0; i<n; i++)
	{
		if (stat & (1 << i))
		{
			cost_t new_cost = recurs(stat - (1 << i));
			if (new_cost.second + wei[i] <= m)
			{
				new_cost.second += wei[i];
			}
			else
			{
				++new_cost.first;
				new_cost.second = wei[i];
			}
			dp[stat] = min(dp[stat], new_cost);
		}
	}
	return dp[stat];
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=0; i<n; i++)
	{
		scanf("%d", &wei[i]);
	}
	printf("%d\n", recurs((1<<n)-1).first+1);
	return 0;
}
