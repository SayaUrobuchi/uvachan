#include <iostream>
#include <algorithm>
using namespace std;
using ps = pair<int, int>;

const int MN = 128;
const int MN2 = MN*MN;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int mb[MN][MN];
int par[MN2], rnk[MN2];
ps ary[MN2];

bool comp(const ps &a, const ps &b)
{
	return mb[a.first][a.second] < mb[b.first][b.second];
}

int enc(const int a, const int b, const int n)
{
	return a*n+b;
}

int getpar(int t)
{
	if (par[t] < 0)
	{
		return t;
	}
	return par[t] = getpar(par[t]);
}

void merge(int a, int b)
{
	a = getpar(a);
	b = getpar(b);
	if (a != b)
	{
		if (rnk[a] > rnk[b])
		{
			swap(a, b);
		}
		par[a] = b;
		if (rnk[a] == rnk[b])
		{
			++rnk[b];
		}
	}
}

bool same(int a, int b)
{
	return getpar(a) == getpar(b);
}

int main()
{
	int n, n2, i, j, k, x, y, nx, ny, cur, nxt, ans;
	while (cin >> n)
	{
		for (i=0, k=0; i<n; i++)
		{
			for (j=0; j<n; j++, k++)
			{
				cin >> mb[i][j];
				ary[k] = {i, j};
			}
		}
		n2 = n * n;
		sort(ary, ary+n2, comp);
		for (i=0; i<n2; i++)
		{
			par[i] = -1;
			rnk[i] = 1;
		}
		for (i=0; i<n2; i++)
		{
			x = ary[i].first;
			y = ary[i].second;
			cur = enc(x, y, n);
			for (k=0; k<4; k++)
			{
				nx = x + dx[k];
				ny = y + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n && mb[nx][ny] <= mb[x][y])
				{
					nxt = enc(nx, ny, n);
					merge(cur, nxt);
				}
			}
			if (same(0, n2-1))
			{
				ans = mb[x][y];
				break;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}
