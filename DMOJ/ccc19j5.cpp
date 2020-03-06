#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 2000000;
const int FORWARD = 1;
const int BACKWARD = 2;

string pattern[3], replace[3];
string qq[N];
int from[N], rule[N], pos[N], qs[N], qr[N];
unordered_map<string, int> tbl[16];

void trace(int idx)
{
	if (from[idx] > 0)
	{
		trace(from[idx]);
	}
	cout << rule[idx] << " " << pos[idx] << " " << qq[idx] << '\n';
}

void trace2(int idx)
{
	cout << rule[idx] << " " << pos[idx] << " " << qq[from[idx]] << '\n';
	if (from[idx] > 1)
	{
		trace2(from[idx]);
	}
}

int main()
{
	int i, j, k, l, ns, step, over, meet, self, dir, res, idx;
	string st, ed, current, nxt, pat, rep;
	for (i=0; i<3; i++)
	{
		cin >> pattern[i] >> replace[i];
	}
	cin >> step >> st >> ed;
	// FORWARD from start state
	qq[0] = st;
	qr[0] = FORWARD;
	tbl[0][st] = 1;
	qs[0] = 0;
	from[0] = -1;
	rule[0] = -1;
	pos[0] = -1;
	// BACKWARD from end state
	qq[1] = ed;
	qr[1] = BACKWARD;
	tbl[step][ed] = 2;
	qs[1] = step;
	from[1] = -1;
	rule[1] = -1;
	pos[1] = -1;
	// if find answer
	over = false;
	meet = -1;
	for (i=0, j=2; i<j&&!over; i++)
	{
		current = qq[i];
		//cout << "start" << i << " " << j << ": " << current << '\n';
		dir = qr[i];
		if (dir == FORWARD)
		{
			ns = qs[i] + 1;
		}
		else
		{
			ns = qs[i] - 1;
		}
		for (k=0; k<3; k++)
		{
			for (l=0; l<current.size(); l++)
			{
				// 012345.substr(1, 3)
				if (dir == FORWARD)
				{
					pat = pattern[k];
					rep = replace[k];
				}
				else
				{
					pat = replace[k];
					rep = pattern[k];
				}
				if (current.substr(l, pat.size()) == pat)
				{
					// before l + replace + after l
					nxt = current.substr(0, l) + rep + current.substr(l+pat.size());
					// 1. tbl[ns][nxt] not visited
					// 2. tbl[ns][nxt] visited by same direction
					// 3. tbl[ns][nxt] visited by different direction
					res = tbl[ns][nxt];
					idx = res - 1;
					if (res != 0 && qr[idx] != dir)
					{
						// meets
						over = true;
						self = j;
						meet = idx;
						res = 0;
					}
					if (res == 0)
					{
						tbl[ns][nxt] = j+1;
						qq[j] = nxt;
						qs[j] = ns;
						qr[j] = dir;
						from[j] = i;
						rule[j] = k+1;
						pos[j] = l+1;
						j++;
					}
				}
			}
		}
		if (over)
		{
			break;
		}
	}
	dir = qr[self];
	if (dir == FORWARD)
	{
		trace(self);
		trace2(meet);
	}
	else
	{
		trace(meet);
		trace2(self);
	}
	return 0;
}
