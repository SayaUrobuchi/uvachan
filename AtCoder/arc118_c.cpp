#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pp = pair<int, int>;

const int RANGE = 10005;

bool appear[RANGE];

struct comp
{
	bool operator()(const pp &a, const pp &b) const
	{
		return a.first * a.second > b.first * b.second;
	}
};

int gcd(int a, int b)
{
	while ((a %= b) && (b %= a));
	return a + b;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	priority_queue<pp, vector<pp>, comp> pq;
	pq.emplace(make_pair(2*3, 2));
	pq.emplace(make_pair(2*5, 2));
	pq.emplace(make_pair(3*5, 2));
	vector<int> v = {2*3, 2*5, 3*5};
	while (v.size() < n)
	{
		pp cur = pq.top();
		pq.pop();
		int t = cur.first * cur.second;
		if (!appear[t])
		{
			v.emplace_back(t);
			appear[t] = true;
		}
		++cur.second;
		pq.emplace(cur);
	}
	// int j;
	// int g = v[0];
	// for (i=1; i<v.size()&&g>1; i++)
	// {
		// g = gcd(g, v[i]);
	// }
	// bool ok = (g == 1);
	// for (i=0; i<v.size()&&ok; i++)
	// {
		// for (j=i+1; j<v.size()&&ok; j++)
		// {
			// if (gcd(v[i], v[j]) == 1 || v[i] == v[j])
			// {
				// ok = false;
			// }
		// }
	// }
	// puts(ok ? "OK" : "NG");
	printf("%d", v[0]);
	for (i=1; i<v.size(); i++)
	{
		printf(" %d", v[i]);
	}
	puts("");
	return 0;
}
