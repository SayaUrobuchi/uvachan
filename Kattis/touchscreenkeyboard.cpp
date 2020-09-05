#include <iostream>
#include <algorithm>
using namespace std;

int dis[1048576], idx[1048576], px[128], py[128];
string str[1048576];
string key[] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};

bool comp(int p, int q)
{
	if (dis[p] != dis[q])
	{
		return dis[p] < dis[q];
	}
	return str[p] < str[q];
}

int main()
{
	int count, n, i, j;
	for (i=0; i<3; i++)
	{
		for (j=0; j<key[i].size(); j++)
		{
			px[key[i][j]] = i;
			py[key[i][j]] = j;
		}
	}
	string s;
	cin >> count;
	while (count--)
	{
		cin >> s >> n;
		for (i=0; i<n; i++)
		{
			cin >> str[i];
			idx[i] = i;
			for (j=0, dis[i]=0; j<s.size(); j++)
			{
				dis[i] += abs(px[s[j]] - px[str[i][j]]) + abs(py[s[j]] - py[str[i][j]]);
			}
		}
		sort(idx, idx+n, comp);
		for (i=0; i<n; i++)
		{
			cout << str[idx[i]] << " " << dis[idx[i]] << "\n";
		}
	}
	return 0;
}
