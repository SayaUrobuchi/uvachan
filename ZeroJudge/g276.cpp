#include <iostream>
#include <cstring>
using namespace std;

int px[512], py[512], dx[512], dy[512], bx[512], by[512];
bool bomb[128][128];

void del(int &i, int &o)
{
	px[i] = px[o-1];
	py[i] = py[o-1];
	dx[i] = dx[o-1];
	dy[i] = dy[o-1];
	o--;
	i--;
}

int main()
{
	int n, m, o, i, k, b;
	while (cin >> n >> m >> o)
	{
		memset(bomb, 0, sizeof(bomb));
		for (i=0; i<o; i++)
		{
			scanf("%d%d%d%d", &px[i], &py[i], &dx[i], &dy[i]);
		}
		b = 0;
		while (o)
		{
			for (i=0; i<o; i++)
			{
				if (!bomb[px[i]][py[i]])
				{
					++b;
					++bomb[px[i]][py[i]];
				}
				px[i] += dx[i];
				py[i] += dy[i];
				if (px[i] < 0 || px[i] >= n || py[i] < 0 || py[i] >= m)
				{
					del(i, o);
				}
			}
			for (i=0, k=0; i<o; i++)
			{
				if (bomb[px[i]][py[i]])
				{
					bx[k] = px[i];
					by[k] = py[i];
					k++;
					del(i, o);
				}
			}
			for (i=0; i<k; i++)
			{
				b -= bomb[bx[i]][by[i]];
				bomb[bx[i]][by[i]] = 0;
			}
		}
		cout << b << "\n";
	}
	return 0;
}
