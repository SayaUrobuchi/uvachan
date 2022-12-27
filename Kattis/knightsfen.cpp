#include <iostream>
#include <bitset>
#include <vector>
#include <map>
using namespace std;

const int N = 5;
const int NN = N*N;
const int FINAL = 0b10000110001111011111;

using pp = pair<int, int>;
using ppp = pair<unsigned long, pp>;
using pppp = pair<int, ppp>;

const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};

inline int cal(int x, int y)
{
	return x*N + y;
}

int main()
{
	int count, i, j, k, x, y, d, sx, sy, tx, ty, ans;
	bool a, b;
	bitset<NN> st, nt;
	string s;
	vector<pppp> qq;
	map<ppp, bool> mp;
	
	getline(cin, s);
	sscanf(s.c_str(), "%d", &count);
	while (count--)
	{
		for (i=0, st=0; i<N; i++)
		{
			getline(cin, s);
			for (j=0; j<N; j++)
			{
				if (s[j] == ' ')
				{
					sx = i;
					sy = j;
				}
				else if (s[j] == '1')
				{
					st |= (1 << cal(i, j));
				}
			}
		}
		qq.clear();
		qq.emplace_back(make_pair(0, make_pair(st.to_ulong(), make_pair(sx, sy))));
		mp.clear();
		mp[qq[0].second] = true;
		ans = 11;
		for (i=0; i<(int)qq.size(); i++)
		{
			forward_as_tuple(d, forward_as_tuple(st, tie(x, y))) = qq[i];
			if (d > 10)
			{
				break;
			}
			if (st == FINAL && x == 2 && y == 2)
			{
				ans = d;
				break;
			}
			for (k=0; k<8; k++)
			{
				tx = x + dx[k];
				ty = y + dy[k];
				if (tx >= 0 && tx < N && ty >= 0 && ty < N)
				{
					nt = st;
					a = nt[cal(x, y)];
					b = nt[cal(tx, ty)];
					nt.set(cal(x, y), b);
					nt.set(cal(tx, ty), a);
					pppp nxt = make_pair(d+1, make_pair(nt.to_ulong(), make_pair(tx, ty)));
					if (!mp.count(nxt.second))
					{
						mp[nxt.second] = true;
						qq.emplace_back(nxt);
					}
				}
			}
		}
		if (ans >= 11)
		{
			puts("Unsolvable in less than 11 move(s).");
		}
		else
		{
			printf("Solvable in %d move(s).\n", ans);
		}
	}
	return 0;
}