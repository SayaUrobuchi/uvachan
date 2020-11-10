#include <iostream>
#include <algorithm>

int god[1048576], mech[1048576];

int main()
{
	int count, n, m, i, j;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		for (i=0; i<n; i++)
		{
			scanf("%d", &god[i]);
		}
		std::sort(god, god+n);
		for (i=0; i<m; i++)
		{
			scanf("%d", &mech[i]);
		}
		std::sort(mech, mech+m);
		for (i=0, j=0; i<n&&j<m; )
		{
			if (mech[j] <= god[i])
			{
				++j;
			}
			else
			{
				++i;
			}
		}
		puts(i<n?"Godzilla":"MechaGodzilla");
	}
	return 0;
}
