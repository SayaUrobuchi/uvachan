#include <iostream>
using namespace std;

const int N = 1024;
const int NN = N*N;
const int ST = 0;
const int ED = 9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int pn[10];
int px[10][NN], py[10][NN];
long long dp[N][N];
string board[N];

int main()
{
	int n, m, i, j, k, t, x, y, tx, ty;
	long long ans;
	while (cin >> n >> m)
	{
		for (i=0; i<=9; i++)
		{
			pn[i] = 0;
		}
		for (i=0; i<n; i++)
		{
			cin >> board[i];
			for (j=0; j<m; j++)
			{
				t = board[i][j] - '0';
				px[t][pn[t]] = i;
				py[t][pn[t]] = j;
				pn[t]++;
			}
		}
		for (i=0; i<pn[ST]; i++)
		{
			dp[px[ST][i]][py[ST][i]] = 1;
		}
		for (i=1; i<=9; i++)
		{
			for (j=0; j<pn[i]; j++)
			{
				x = px[i][j];
				y = py[i][j];
				dp[x][y] = 0;
				for (k=0; k<4; k++)
				{
					tx = x + dx[k];
					ty = y + dy[k];
					if (tx >= 0 && tx < n && ty >= 0 && ty < m)
					{
						if (board[x][y] == board[tx][ty] + 1)
						{
							dp[x][y] += dp[tx][ty];
						}
					}
				}
			}
		}
		for (i=0, ans=0; i<pn[ED]; i++)
		{
			ans += dp[px[ED][i]][py[ED][i]];
		}
		cout << ans << "\n";
	}
	return 0;
}
