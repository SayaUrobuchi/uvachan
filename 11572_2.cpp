#include <stdio.h>
#include <stdlib.h>
#include <map>

int ary[1048576];
std::map<int, int> tbl;

int main()
{
	int count, n, m, i, j, res, cnt;
	scanf("%d", &count);
	while (count--)
	{
		++cnt;
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		res = 0;
		tbl.clear();
		for (i=0, j=0; i<n; i++)
		{
			if (tbl.find(ary[i]) != tbl.end())
			{
				while (ary[j] != ary[i])
				{
					tbl.erase(ary[j++]);
				}
				++j;
			}
			else
			{
				tbl[ary[i]] = cnt;
			}
			if (i-j+1 > res)
			{
				res = i-j+1;
			}
		}
		printf("%d\n", res);
	}
	return 0;
}
