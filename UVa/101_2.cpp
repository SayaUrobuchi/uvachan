#include <iostream>
using namespace std;

int len[32], ary[32][32];
int px[32], py[32];

void mov(int id, int tar)
{
	len[px[id]]--;
	ary[tar][len[tar]] = id;
	px[id] = tar;
	py[id] = len[tar];
	len[tar]++;
}

void recover(int id)
{
	int i, x, cur;
	x = px[id];
	for (i=len[x]-1; i>py[id]; i--)
	{
		cur = ary[x][i];
		mov(cur, cur);
	}
}

int main()
{
	int n, i, j, a, b, st, ed, h;
	string cmd, cmd2;
	while (cin >> n)
	{
		for (i=0; i<n; i++)
		{
			len[i] = 1;
			ary[i][0] = i;
			px[i] = i;
			py[i] = 0;
		}
		while (cin >> cmd)
		{
			if (cmd == "quit")
			{
				break;
			}
			cin >> a >> cmd2 >> b;
			if (a == b || px[a] == px[b])
			{
				continue;
			}
			if (cmd == "move")
			{
				recover(a);
				if (cmd2 == "onto")
				{
					recover(b);
				}
				mov(a, px[b]);
			}
			else
			{
				if (cmd2 == "onto")
				{
					recover(b);
				}
				st = px[a];
				ed = px[b];
				h = len[st];
				for (i=py[a]; i<h; i++)
				{
					mov(ary[st][i], ed);
				}
			}
		}
		for (i=0; i<n; i++)
		{
			cout << i << ":";
			for (j=0; j<len[i]; j++)
			{
				cout << " " << ary[i][j];
			}
			cout << "\n";
		}
	}
	return 0;
}
