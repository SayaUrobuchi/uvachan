#include <iostream>
#include <vector>
using namespace std;

int ary[256];
int dp[256][256], from[256][256];

void trace(vector<int> &buf, int i, int j)
{
	if (i-1 && from[i][j] >= 0)
	{
		trace(buf, i-1, from[i][j]);
	}
	else
	{
		buf.clear();
	}
	if (from[i][j] != j)
	{
		buf.emplace_back(i);
	}
}

void pt(vector<int> &buf)
{
	int i;
	printf("%d", buf.size());
	for (i=0; i<buf.size(); i++)
	{
		printf(" %d", buf[i]);
	}
	puts("");
}

int main()
{
	int n, i, j, t;
	bool ok;
	vector<int> va, vb;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=n; i++)
		{
			scanf("%d", &ary[i]);
			ary[i] %= 200;
		}
		for (i=1, ok=false; i<=n&&!ok; i++)
		{
			for (j=0; j<200; j++)
			{
				t = (j-ary[i]+200) % 200;
				dp[i][j] = 0;
				if (dp[i-1][j])
				{
					++dp[i][j];
					from[i][j] = j;
				}
				if (dp[i-1][t])
				{
					++dp[i][j];
					from[i][j] = t;
				}
				if (dp[i][j] > 1)
				{
					ok = true;
					trace(va, i-1, j);
					trace(vb, i-1, t);
					vb.emplace_back(i);
					break;
				}
				if (j == ary[i])
				{
					++dp[i][j];
					if (dp[i][j] > 1)
					{
						ok = true;
						trace(va, i, j);
						vb.resize(1);
						vb[0] = i;
						break;
					}
					from[i][j] = -1;
				}
			}
		}
		if (ok)
		{
			puts("Yes");
			pt(va);
			pt(vb);
		}
		else
		{
			puts("No");
		}
	}
	return 0;
}

