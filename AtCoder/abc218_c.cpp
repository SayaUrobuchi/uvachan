#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

char s[256];

void read(vector<pp> &va, int n)
{
	int i, j;
	va.clear();
	for (i=0; i<n; i++)
	{
		scanf("%s", s);
		for (j=0; j<n; j++)
		{
			if (s[j] == '#')
			{
				va.emplace_back(i, j);
			}
		}
	}
}

void norm(vector<pp> &va, int n)
{
	int i, mx, my;
	mx = my = n;
	for (i=0; i<va.size(); i++)
	{
		mx = min(mx, va[i].first);
		my = min(my, va[i].second);
	}
	for (i=0; i<va.size(); i++)
	{
		va[i].first -= mx;
		va[i].second -= my;
	}
	sort(va.begin(), va.end());
}

void rot(vector<pp> &va, int n)
{
	int i, x, y;
	for (i=0; i<va.size(); i++)
	{
		x = va[i].first;
		y = va[i].second;
		va[i] = {y, n-x-1};
	}
	norm(va, n);
}

int main()
{
	int n, i;
	bool same;
	vector<pp> va, vb;
	while (scanf("%d", &n) == 1)
	{
		read(va, n);
		read(vb, n);
		same = false;
		if (va.size() == vb.size())
		{
			norm(va, n);
			norm(vb, n);
			for (i=0; i<4; i++)
			{
				rot(va, n);
				if (va == vb)
				{
					same = true;
					break;
				}
			}
		}
		puts(same?"Yes":"No");
	}
	return 0;
}

