#include <iostream>
using namespace std;

const int N = 8;

int ans, msk;
int tbl[N+8];

void set_board(string &s, int row)
{
	int i, t;
	for (i=0, t=0; i<s.size(); i++)
	{
		if (s[i] == '*')
		{
			t |= (1<<i);
		}
	}
	tbl[row] = t;
}

void dfs(int depth, int col, int ldia, int rdia)
{
	if (depth == N)
	{
		++ans;
		return;
	}
	int avail = (~(col | ldia | rdia | tbl[depth]) & msk);
	while (avail)
	{
		int t = (avail & -avail);
		avail &= ~t;
		dfs(depth+1, col|t, (ldia|t)<<1, (rdia|t)>>1);
	}
}

int main()
{
	int i;
	string board;
	while (cin >> board)
	{
		set_board(board, 0);
		for (i=1; i<N; i++)
		{
			cin >> board;
			set_board(board, i);
		}
		msk = (1<<N)-1;
		ans = 0;
		dfs(0, 0, 0, 0);
		cout << ans << "\n";
	}
	return 0;
}

