#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using pp = pair<int, int>;

const int N = 505;

int px[N], py[N];

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	while ((a %= b) && (b %= a));
	return a + b;
}

int main()
{
	int n, i, j, k;
	vector<pp> v;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &px[i], &py[i]);
		for (j=0; j<i; j++)
		{
			for (k=0; k<2; k++)
			{
				int dx = px[i] - px[j];
				int dy = py[i] - py[j];
				int g = gcd(abs(dx), abs(dy));
				pp t = make_pair(dx / g, dy / g);
				v.emplace_back(t);
				swap(px[i], px[j]);
				swap(py[i], py[j]);
			}
		}
	}
	sort(v.begin(), v.end());
	int ans = unique(v.begin(), v.end()) - v.begin();
	printf("%d\n", ans);
	return 0;
}
