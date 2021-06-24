#include <iostream>
#include <vector>
using namespace std;

const int MOD = 998244353;

using mat = vector<vector<int> >;

int n, mstat, msk;
mat trans, idm;
mat tmat, res, temp;

void mul(mat &c, mat &a, mat &b)
{
	int i, j, k;
	for (i=0; i<c.size(); i++)
	{
		for (j=0; j<c[0].size(); j++)
		{
			c[i][j] = 0;
			for (k=0; k<b.size(); k++)
			{
				c[i][j] = (c[i][j]+(long long)a[i][k]*b[k][j]) % MOD;
			}
		}
	}
}

void dfs(int orig, int cur, int b)
{
	if (b >= n)
	{
		++tmat[orig][cur];
		return;
	}
	dfs(orig, cur, b+1);
	if (!(cur & (1<<b)))
	{
		dfs(orig, cur|(1<<b), b+1);
		if (b+1 < n && !(cur & (1<<(b+1))))
		{
			dfs(orig, cur|(1<<b)|(1<<(b+1)), b+2);
		}
	}
}

int main()
{
	int i;
	long long m, t;
	while (scanf("%d%lld", &n, &m) == 2)
	{
		mstat = (1 << n);
		msk = mstat - 1;
		tmat.resize(mstat);
		temp.resize(mstat);
		res.resize(mstat);
		for (i=0; i<mstat; i++)
		{
			tmat[i].resize(0);
			tmat[i].resize(mstat, 0);
			temp[i].resize(mstat);
			res[i].resize(0);
			res[i].resize(mstat);
		}
		for (i=0; i<mstat; i++)
		{
			dfs(i, ~i&msk, 0);
			res[i][i] = 1;
		}
		for (t=m; t; t>>=1)
		{
			if (t & 1)
			{
				mul(temp, res, tmat);
				std::swap(temp, res);
			}
			mul(temp, tmat, tmat);
			std::swap(temp, tmat);
		}
		printf("%d\n", res[mstat-1][mstat-1]);
	}
	return 0;
}
