#include <iostream>
#include <set>

const int N = (1<<22);

int ucnt;
int ary[N], used[N];
std::set<std::set<int> > sss;

int add(int cur, int val)
{
	if (used[cur] != ucnt)
	{
		used[cur] = ucnt;
		ary[cur] = val;
		return cur;
	}
	if (val < ary[cur])
	{
		return add(cur<<1, val);
	}
	return add((cur<<1)|1, val);
}

int main()
{
	int n, m, i, j, t, c;
	while (scanf("%d%d", &n, &m) == 2)
	{
		sss.clear();
		for (i=0; i<n; i++)
		{
			++ucnt;
			std::set<int> c;
			for (j=0; j<m; j++)
			{
				scanf("%d", &t);
				c.insert(add(1, t));
			}
			sss.insert(c);
		}
		printf("%d\n", sss.size());
	}
	return 0;
}
