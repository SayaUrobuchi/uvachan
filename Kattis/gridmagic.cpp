#include <iostream>
#include <vector>

int n, m, ans;
int row[16], col[16];
std::vector<int> v = {1, 2, 3, 5, 7, 9};

bool isp(int t)
{
	int i;
	if (t < 10)
	{
		return t == 2 || t == 3 || t == 5 || t == 7;
	}
	if (!(t&1))
	{
		return false;
	}
	for (i=3; i*i<=t; i+=2)
	{
		if (t % i == 0)
		{
			return false;
		}
	}
	return true;
}

void dfs(int depth)
{
	int p, q, i;
	if (depth == n*m)
	{
		++ans;
		return;
	}
	p = depth / m;
	q = depth % m;
	for (i=0; i<v.size(); i++)
	{
		row[p] = row[p]*10 + v[i];
		col[q] = col[q]*10 + v[i];
		if (isp(row[p]) && isp(col[q]))
		{
			dfs(depth+1);
		}
		row[p] /= 10;
		col[q] /= 10;
	}
}

int main()
{
	while (scanf("%d%d", &n, &m) == 2)
	{
		ans = 0;
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}
