#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void uni(vector<int> &ary)
{
	int i, j;
	for (i=1, j=1; i<ary.size(); i++)
	{
		if (ary[i] != ary[i-1])
		{
			ary[j] = ary[i];
			++j;
		}
	}
	ary.resize(j);
}

int trans(int t, const vector<int> &ary)
{
	return lower_bound(ary.begin(), ary.end(), t) - ary.begin();
}

int strtoint(const char *s)
{
	int a, b, cnt;
	cnt = sscanf(s, "%d.%d", &a, &b);
	if (cnt == 1)
	{
		return a * 100;
	}
	return a * 100 + b;
}

int main()
{
	int n, i, j, t, u, v, w, lx, ly;
	long long ans;
	char a[16], b[16], c[16], d[16];
	vector<int> px, py;
	vector<vector<int>> pre;
	scanf("%d", &n);
	vector<int> x0(n), x1(n), y0(n), y1(n);
	for (i=0; i<n; i++)
	{
		scanf("%s%s%s%s", &a, &b, &c, &d);
		x0[i] = strtoint(a);
		y0[i] = strtoint(b);
		x1[i] = strtoint(c);
		y1[i] = strtoint(d);
		px.emplace_back(x0[i]);
		px.emplace_back(x1[i]);
		py.emplace_back(y0[i]);
		py.emplace_back(y1[i]);
	}
	sort(px.begin(), px.end());
	sort(py.begin(), py.end());
	uni(px);
	uni(py);
	pre.resize(px.size(), vector<int>(py.size()));
	for (i=0; i<n; i++)
	{
		t = trans(x0[i], px);
		u = trans(y0[i], py);
		v = trans(x1[i], px);
		w = trans(y1[i], py);
		++pre[t][u];
		--pre[t][w];
		--pre[v][u];
		++pre[v][w];
	}
	for (i=0; i<px.size(); i++)
	{
		for (j=1; j<py.size(); j++)
		{
			pre[i][j] += pre[i][j-1];
		}
	}
	for (i=1; i<px.size(); i++)
	{
		for (j=0; j<py.size(); j++)
		{
			pre[i][j] += pre[i-1][j];
		}
	}
	for (i=0, ans=0; i+1<px.size(); i++)
	{
		for (j=0; j+1<py.size(); j++)
		{
			if (pre[i][j])
			{
				//printf("area (%d, %d) to (%d, %d)\n", lx, ly, px[i], py[j]);
				ans += (long long)(px[i+1]-px[i])*(py[j+1]-py[j]);
			}
		}
	}
	printf("%lld.%02lld\n", ans/10000, (ans%10000+50)/100);
	return 0;
}
