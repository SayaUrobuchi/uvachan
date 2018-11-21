#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

#define M 10005

char s0[10005], s1[10005];
std::vector<int> v[140];
std::map<int, int> tbl;
std::map<int, int>::iterator it;

int main()
{
	int i, j, k, l, p, q, n, m, t, len0, len1;
	while (scanf("%s%s", s0, s1) == 2)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<=m; i++)
		{
			v[i].clear();
		}
		tbl.clear();
		len0 = strlen(s0);
		len1 = strlen(s1);
		v[0].push_back((len0)*M+(len1));
		for (i=0; i<=m; i++)
		{
			for (j=0; j<v[i].size(); j++)
			{
				it = tbl.find(v[i][j]);
				if (it->second > i)
				{
					continue;
				}
				p = v[i][j]/M-1;
				q = v[i][j]%M-1;
				while (p>=0 && q>=0 && s0[p]==s1[q])
				{
					--p;
					--q;
				}
				if (p<0 && q<0)
				{
					break;
				}
				if (p<0 || q<0)
				{
					l = i + ((p>=0?p:q))/n+1;
					if (l <= m)
					{
						t = 0;
						it = tbl.find(t);
						if (it == tbl.end() || it->second > l)
						{
							tbl[t] = l;
							v[l].push_back(t);
						}
					}
					continue;
				}
				l = i+1;
				if (l <= m)
				{
					for (k=q-1; k>=q-n&&k>=0; k--)
					{
						if (s1[k] == s0[p] || k == q-n)
						{
							t = (p+1)*M+k+1;
							it = tbl.find(t);
							if (it == tbl.end() || it->second > l)
							{
								tbl[t] = l;
								v[l].push_back(t);
							}
						}
					}
					for (k=p-1; k>=p-n&&k>=0; k--)
					{
						if (s1[q] == s0[k] || k == p-n)
						{
							t = (k+1)*M+q+1;
							it = tbl.find(t);
							if (it == tbl.end() || it->second > l)
							{
								tbl[t] = l;
								v[l].push_back(t);
							}
						}
					}
				}
			}
			if (j < v[i].size())
			{
				break;
			}
		}
		if (i <= m)
		{
			printf("%d\n", i);
		}
		else
		{
			puts("Impossible");
		}
	}
	return 0;
}
