#include <iostream>
#include <vector>
using namespace std;

const int MD = 8;
const int N = (1 << MD);
const int FILL_X = 0;
const int FILL_Y = 1;
const int TRANS_X = 2;
const int TRANS_Y = 3;
const int DISCARD_X = 4;
const int DISCARD_Y = 5;

int ucnt;
int used[1<<(MD<<1)];
int ary[N], dp[N], able[N], from[N];
vector<int> qq, ff, cmd;

int gcd(int a, int b)
{
	while ((a %= b) && (b %= a));
	return a + b;
}

void decode(int t, int &a, int &b)
{
	a = t >> MD;
	b = t & ((1<<MD) - 1);
}

int encode(int a, int b)
{
	return (a << MD) + b;
}

void push(int x, int y, int last, int typ)
{
	int t = encode(x, y);
	if (used[t] != ucnt)
	{
		used[t] = ucnt;
		qq.emplace_back(t);
		ff.emplace_back(last);
		cmd.emplace_back(typ);
	}
}

void backtrace(int cur, vector<int> &res)
{
	res.emplace_back(cmd[cur]);
	if (ff[cur])
	{
		backtrace(ff[cur], res);
	}
}

void output_single(int c, int x, int y)
{
	if (c == FILL_X)
	{
		printf("fill %d\n", x);
	}
	else if (c == FILL_Y)
	{
		printf("fill %d\n", y);
	}
	else if (c == TRANS_X)
	{
		printf("transfer %d %d\n", x, y);
	}
	else if (c == TRANS_Y)
	{
		printf("transfer %d %d\n", y, x);
	}
	else if (c == DISCARD_X)
	{
		printf("discard %d\n", x);
	}
	else if (c == DISCARD_Y)
	{
		printf("discard %d\n", y);
	}
}

void bfs(int a, int b, int tar)
{
	int i;
	qq.clear();
	ff.clear();
	cmd.clear();
	qq.emplace_back(encode(0, 0));
	ff.emplace_back(0);
	cmd.emplace_back(0);
	++ucnt;
	used[qq[0]] = ucnt;
	int x, y;
	for (i=0; i<qq.size(); i++)
	{
		decode(qq[i], x, y);
		if ((x == tar && !y) || (y == tar && !x))
		{
			break;
		}
		int tx, ty, d;
		// fill x
		tx = ary[a];
		ty = y;
		push(tx, ty, i, FILL_X);
		// fill y
		tx = x;
		ty = ary[b];
		push(tx, ty, i, FILL_Y);
		// trans x to y
		d = min(ary[b]-y, x);
		tx = x - d;
		ty = y + d;
		push(tx, ty, i, TRANS_X);
		// trans y to x
		d = min(ary[a]-x, y);
		tx = x + d;
		ty = y - d;
		push(tx, ty, i, TRANS_Y);
		// discard x
		tx = 0;
		ty = y;
		push(tx, ty, i, DISCARD_X);
		// discard y
		tx = x;
		ty = 0;
		push(tx, ty, i, DISCARD_Y);
	}
	vector<int> res;
	backtrace(i, res);
	while (res.size())
	{
		output_single(res.back(), a, b);
		res.pop_back();
	}
	decode(qq[i], x, y);
	if (x)
	{
		output_single(TRANS_X, a, 0);
	}
	else
	{
		output_single(TRANS_X, b, 0);
	}
}

void output(const int t)
{
	int i, j;
	decode(able[t], i, j);
	if (j == 0)
	{
		output_single(FILL_X, i, 0);
		output_single(TRANS_X, i, 0);
	}
	else
	{
		bfs(i, j, t);
	}
}

int main()
{
	int n, i, j, t;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		able[ary[i]] = encode(i, 0);
		for (j=1; j<i; j++)
		{
			int res = gcd(ary[i], ary[j]);
			able[res] = encode(j, i);
		}
	}
	scanf("%d", &t);
	dp[0] = true;
	from[0] = -1;
	for (i=1; i<=t; i++)
	{
		for (j=1; j<=i&&!dp[i]; j++)
		{
			if (able[j] && dp[i-j])
			{
				dp[i] = true;
				from[i] = j;
			}
		}
	}
	if (!dp[t])
	{
		puts("impossible");
	}
	else
	{
		for (; t; t-=from[t])
		{
			output(from[t]);
		}
	}
	return 0;
}
