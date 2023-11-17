#include <iostream>
using namespace std;

const int N = 1000005;
const int MAX_R = 1005;
const int MAX_C = 1005;

const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};

int x[N], y[N];
int ans[9];
bool board[MAX_R][MAX_C];

int main()
{
	int n, m, o, i, j, t;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<o; i++)
	{
		scanf("%d%d", &x[i], &y[i]);
		board[x[i]][y[i]] = true;
	}
	for (i=0; i<o; i++)
	{
		for (j=0, t=0; j<8; j++)
		{
			t += board[x[i]+dx[j]][y[i]+dy[j]];
		}
		++ans[t];
	}
	for (i=0; i<=8; i++)
	{
		if (i)
		{
			printf(" ");
		}
		printf("%d", ans[i]);
	}
	puts("");
	return 0;
}