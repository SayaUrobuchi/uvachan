#include <iostream>
#include <algorithm>
using namespace std;

const int DRAW = 0;
const int WIN = 1;
const int LOSE = -1;

int tbl[128][128];
char str[128][128];
pair<int, int> ary[128];

int main()
{
	int n, n2, m, i, j, a, b;
	tbl['G']['G'] = DRAW;
	tbl['C']['C'] = DRAW;
	tbl['P']['P'] = DRAW;
	tbl['G']['C'] = WIN;
	tbl['C']['P'] = WIN;
	tbl['P']['G'] = WIN;
	tbl['G']['P'] = LOSE;
	tbl['C']['G'] = LOSE;
	tbl['P']['C'] = LOSE;
	while (scanf("%d%d", &n, &m) == 2)
	{
		n2 = (n<<1);
		for (i=0; i<n2; i++)
		{
			scanf("%s", str[i]);
			ary[i].first = 0;
			ary[i].second = i;
		}
		for (i=0; i<m; i++)
		{
			for (j=0; j<n2; j+=2)
			{
				a = str[ary[j].second][i];
				b = str[ary[j+1].second][i];
				if (tbl[a][b] == WIN)
				{
					--ary[j].first;
				}
				else if (tbl[a][b] == LOSE)
				{
					--ary[j+1].first;
				}
			}
			sort(ary, ary+n2);
		}
		for (i=0; i<n2; i++)
		{
			printf("%d\n", ary[i].second+1);
		}
	}
	return 0;
}