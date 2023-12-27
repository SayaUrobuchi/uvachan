#include <iostream>
#include <vector>
using namespace std;

const int N = 1005;

int score[N][N];
int sum[N][2];

int main()
{
	int n, n2, i, j;
	vector<int> v[2];
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			scanf("%d", &score[i][j]);
		}
		v[i&1].emplace_back(i);
	}
	n2 = (n >> 1);
	for (i=0; i<n2; i++)
	{
		for (j=0; j<n2; j++)
		{
			sum[v[0][i]][0] += score[v[0][i]][v[0][j]];
			sum[v[0][i]][1] += score[v[0][i]][v[1][j]];
			sum[v[1][i]][0] += score[v[1][i]][v[0][j]];
			sum[v[1][i]][1] += score[v[1][i]][v[1][j]];
		}
	}
	while (true)
	{
		int best, ba, bb;
		for (i=0, best=0; i<n2; i++)
		{
			for (j=0; j<n2; j++)
			{
				int dif = -sum[v[0][i]][0] - (sum[v[0][i]][1] - score[v[0][i]][v[1][j]]);
				dif += (sum[v[1][j]][0] - score[v[1][j]][v[0][i]]) + sum[v[1][j]][1];
				if (dif > best)
				{
					best = dif;
					ba = i;
					bb = j;
				}
			}
		}
		if (best == 0)
		{
			break;
		}
		for (i=0; i<n2; i++)
		{
			sum[v[0][i]][0] += score[v[0][i]][v[1][bb]] - score[v[0][i]][v[0][ba]];
			sum[v[0][i]][1] += -score[v[0][i]][v[1][bb]] + score[v[0][i]][v[0][ba]];
			sum[v[1][i]][0] += score[v[1][i]][v[1][bb]] - score[v[1][i]][v[0][ba]];
			sum[v[1][i]][1] += -score[v[1][i]][v[1][bb]] + score[v[1][i]][v[0][ba]];
		}
		swap(v[0][ba], v[1][bb]);
	}
	long long ans;
	for (i=0, ans=0; i<n2; i++)
	{
		ans += sum[v[0][i]][0];
		ans -= sum[v[1][i]][1];
	}
	printf("%lld\n", ans>>1);
	return 0;
}
