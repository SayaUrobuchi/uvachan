#include <stdio.h>
#include <vector>
#include <algorithm>

const int N = 6000000;

std::vector<int> v[N];
int hn;
int from[N], qci[N], heap[N];
char qstep[N], qtar[N], qst[N];
short qused[N];
int dp[32];

bool comp(int p, int q)
{
	int pp, qq;
	pp = qstep[p] + qtar[p];
	qq = qstep[q] + qtar[q];
	return pp>qq;
}

void trace(int cur)
{
	if (from[cur] > 0)
	{
		trace(from[cur]);
	}
	printf("%d %d\n", (qci[cur]>>4)+1, (qci[cur]&15)+1);
}

int lis(std::vector<int> &v)
{
	int i, j, res;
	dp[0] = 1;
	for (i=1, res=1; i<v.size(); i++)
	{
		dp[i] = 1;
		for (j=0; j<i; j++)
		{
			if (v[j] < v[i] && dp[j]+1 > dp[i])
			{
				dp[i] = dp[j]+1;
			}
		}
		if (dp[i] > res)
		{
			res = dp[i];
		}
	}
	return (v.size() - res+1)/2;
}

int main()
{
	int count, n, i, j, k, l, p, q, nused;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		v[0].resize(n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &v[0][i]);
		}
		from[0] = -1;
		qst[0] = 0;
		qused[0] = 0;
		qstep[0] = 0;
		qtar[0] = lis(v[0]);
		heap[0] = 0;
		hn = 1;
		for (j=1; hn>0; )
		{
			i = heap[0];
			std::pop_heap(heap, heap+hn, comp);
			hn--;
			for (k=1; k<v[i].size(); k++)
			{
				if (v[i][k] <= v[i][k-1])
				{
					break;
				}
			}
			q = k-1;
			if (k >= v[i].size())
			{
				break;
			}
			for (k=qst[i]; k<v[i].size(); k++)
			{
				if (!(qused[i] & (1<<k)))
				{
					for (l=q; l<v[i].size(); l++)
					{
						if (l != k)
						{
							v[j] = v[i];
							v[j][l] += v[j][k];
							nused = (qused[i] | (1 << l));
							for (p=k; p+1<v[j].size(); p++)
							{
								v[j][p] = v[j][p+1];
							}
							v[j].resize(v[j].size()-1);
							nused = ((nused & ((1<<k)-1)) | ((nused >> (k+1)) << k));
							from[j] = i;
							qst[j] = k;
							qused[j] = nused;
							qstep[j] = qstep[i]+1;
							qci[j] = (k<<4) + l;
							qtar[j] = lis(v[j]);
							if (qstep[j] + qtar[j] > n-1)
							{
								continue;
							}
							heap[hn] = j;
							hn++;
							std::push_heap(heap, heap+hn, comp);
							j++;
						}
					}
				}
			}
			v[i].resize(0);
			v[i].shrink_to_fit();
		}
		printf("%d\n", qstep[i]);
		if (qstep[i])
		{
			trace(i);
		}
	}
	return 0;
}
