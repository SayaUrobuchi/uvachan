#include <iostream>
#include <vector>
using namespace std;

vector<int> v[128];
int pos[128];
char s[1048576];

int main()
{
	int n, k, i, j, t;
	while (scanf("%d%d", &n, &k) == 2)
	{
		scanf("%s", s);
		for (i='a'; i<='z'; i++)
		{
			v[i].clear();
			pos[i] = 0;
		}
		for (i=0; i<n; i++)
		{
			v[s[i]].emplace_back(i);
		}
		for (i=0, t=-1; i<k; i++)
		{
			for (j='a'; j<='z'; j++)
			{
				for (; pos[j]<v[j].size()&&v[j][pos[j]]<=t; pos[j]++);
				if (pos[j] < v[j].size() && v[j][pos[j]] + (k-i) <= n)
				{
					t = v[j][pos[j]];
					putchar(j);
					break;
				}
			}
		}
		puts("");
	}
	return 0;
}
