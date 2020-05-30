#include <stdio.h>
#include <vector>

struct coconut
{
	int stat, id;
};

std::vector<coconut> v;

int main()
{
	int n, m, i;
	while (scanf("%d%d", &m, &n) == 2)
	{
		v.clear();
		for (i=0; i<n; i++)
		{
			v.push_back({0, i});
		}
		i = 0;
		while (v.size() > 1)
		{
			i = (i+m-1) % v.size();
			if (v[i].stat == 0)
			{
				v[i].stat = 1;
				v.insert(v.begin()+i, {1, v[i].id});
			}
			else if (v[i].stat == 1)
			{
				v[i].stat = 2;
				++i;
			}
			else if (v[i].stat == 2)
			{
				v.erase(v.begin()+i);
			}
		}
		printf("%d\n", v[0].id+1);
	}
	return 0;
}
