#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m, i, a, b;
	vector<int> v0, v1, *vp;
	while (scanf("%d%d", &n, &m) == 2)
	{
		v0.clear();
		v1.clear();
		for (i=1; i<=m; i++)
		{
			scanf("%d%d", &a, &b);
			if (a < b)
			{
				v0.emplace_back(i);
			}
			else
			{
				v1.emplace_back(i);
			}
		}
		if (v0.size() < v1.size())
		{
			vp = &v0;
		}
		else
		{
			vp = &v1;
		}
		printf("%d\n", vp->size());
		for (i=0; i<vp->size(); i++)
		{
			printf("%d\n", vp->at(i));
		}
	}
	return 0;
}
