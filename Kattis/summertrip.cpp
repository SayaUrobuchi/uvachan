#include <iostream>
#include <cstring>
#include <vector>

int tbl[200005][32];
std::vector<int> v[32];
char s[1048576];

int main()
{
	int n, i, j, k, p, q, ans;
	while (scanf("%s", s+1) == 1)
	{
		for (i=0; i<26; i++)
		{
			v[i].clear();
		}
		for (i=1; s[i]; i++)
		{
			v[s[i]-'a'].emplace_back(i);
			memcpy(tbl[i], tbl[i-1], sizeof(tbl[i]));
			++tbl[i][s[i]-'a'];
		}
		n = i;
		for (i=0, ans=0; i<26; i++)
		{
			v[i].emplace_back(n);
			for (j=0; j+1<v[i].size(); j++)
			{
				p = v[i][j]+1;
				q = v[i][j+1]-1;
				if (p <= q)
				{
					for (k=0; k<26; k++)
					{
						if (tbl[q][k] - tbl[p-1][k] > 0)
						{
							++ans;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
