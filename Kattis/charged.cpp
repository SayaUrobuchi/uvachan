#include <iostream>
#include <cmath>
using namespace std;

const int N = 15;
const int BN = 55;
const double PI = acos(-1);
const char *negtbl = "%Xx.";
const char *postbl = "0Oo.";

int px[N], py[N], pz[N];
char buf[15], board[BN][BN];

double dis(int x0, int y0, int x1, int y1)
{
	return sqrt((x0-x1)*(x0-x1) + (y0-y1)*(y0-y1));
}

int main()
{
	int n, m, o, i, j, k, t;
	double f, line;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<o; i++)
	{
		scanf("%d%d%s", &py[i], &px[i], buf);
		board[px[i]][py[i]] = *buf;
		pz[i] = (*buf == '+' ? 1 : -1);
	}
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=m; j++)
		{
			if (board[i][j])
			{
				putchar(board[i][j]);
				continue;
			}
			for (k=0, f=0; k<o; k++)
			{
				double d = dis(i, j, px[k], py[k]);
				f += pz[k]/d;
			}
			for (t=0, line=1/PI; t<3&&abs(f)<=line; t++, line/=PI);
			if (f < 0)
			{
				putchar(negtbl[t]);
			}
			else
			{
				putchar(postbl[t]);
			}
		}
		puts("");
	}
	return 0;
}
