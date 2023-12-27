#include <iostream>
#include <set>
#include <vector>
using namespace std;

char buf[32];

int main()
{
	int count, n, i, j, t, stat, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", buf);
		for (i=0, stat=0; buf[i]; i++)
		{
			if (buf[i] == 'o')
			{
				stat |= (1 << i);
			}
		}
		n = i;
		set<int> se;
		vector<int> v;
		se.emplace(stat);
		v.emplace_back(stat);
		for (i=0, ans=n; i<v.size(); i++)
		{
			stat = v[i];
			for (j=stat, t=0; j; j-=(j&-j), ++t);
			ans = min(ans, t);
			for (j=0; (1<<j)<=stat; j++)
			{
				int nxt;
				if (stat & (1 << j))
				{
					if (j >= 2 && (stat & (1 << (j-1)))
						&& !(stat & (1 << (j-2))))
					{
						nxt = (stat | (1 << (j-2)));
						nxt &= ~(1 << (j-1));
						nxt &= ~(1 << j);
						if (!se.count(nxt))
						{
							v.emplace_back(nxt);
							se.insert(nxt);
						}
					}
					if (j+2 < n && (stat & (1 << (j+1)))
						&& !(stat & (1 << (j+2))))
					{
						nxt = (stat | (1 << (j+2)));
						nxt &= ~(1 << (j+1));
						nxt &= ~(1 << j);
						if (!se.count(nxt))
						{
							v.emplace_back(nxt);
							se.insert(nxt);
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
