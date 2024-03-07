#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const string SEP(30, '=');
const int BL = 128;
const int N = 105;

int idx[N];
char nam[N][BL], buf[BL];
vector<int> v[N];

bool comp(const int &a, const int &b)
{
	int i;
	for (i=0; i<v[a].size()||i<v[b].size(); i++)
	{
		int at = 1;
		int bt = 1;
		if (i < v[a].size())
		{
			at = v[a][i];
		}
		if (i < v[b].size())
		{
			bt = v[b][i];
		}
		if (at != bt)
		{
			return at < bt;
		}
	}
	return strcmp(nam[a], nam[b]) < 0;
}

int main()
{
	int count, n, i, j;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf(" %[^:]: %s class", nam[i], buf);
			v[i].clear();
			for (j=0; buf[j]; )
			{
				j += (buf[j] == '-');
				if (buf[j] == 'u')
				{
					v[i].emplace_back(0);
					j += 5;
				}
				else if (buf[j] == 'm')
				{
					v[i].emplace_back(1);
					j += 6;
				}
				else
				{
					v[i].emplace_back(2);
					j += 5;
				}
			}
			reverse(v[i].begin(), v[i].end());
			idx[i] = i;
		}
		sort(idx, idx+n, comp);
		for (i=0; i<n; i++)
		{
			puts(nam[idx[i]]);
		}
		puts(SEP.c_str());
	}
	return 0;
}
