#include <iostream>
#include <unordered_map>

int rt[] = {1, 1000, 12, 3, 22, 10, 8, 3};
int rat[16];
const char *full[] = {"thou", "inch", "foot", "yard", "chain", "furlong", "mile", "league"};
const char *simp[] = {"th",   "in",   "ft",   "yd",   "ch",    "fur",     "mi",   "lea"};
std::unordered_map<std::string, int> tbl;
char u0[1024], u1[1024];

int main()
{
	int n, a, b, i;
	for (i=0; i<8; i++)
	{
		tbl[full[i]] = tbl[simp[i]] = i;
		if (i)
		{
			rat[i] = rat[i-1] * rt[i];
		}
		else
		{
			rat[i] = 1;
		}
	}
	//printf("rat[7] = %d\n", rat[7]);
	while (scanf("%d%s%*s%s", &n, u0, u1) == 3)
	{
		a = tbl[u0];
		b = tbl[u1];
		printf("%.10lf\n", (double)n*rat[a]/rat[b]);
	}
	return 0;
}
