#include <iostream>
#include <unordered_map>
using namespace std;

const int N = 2000000;
const int FORWARD = 1;
const int BACKWARD = 2;

using bits_t = unsigned long long;

bits_t pattern[3], replace[3];
int pat_len[3], rep_len[3];
bits_t qq[N];
int from[N], ql[N], rule[N], pos[N], qs[N], qr[N];
unordered_map<bits_t, int> tbl[16][128];

string bits_to_s(bits_t bits, int len)
{
	int i;
	string res;
	for (i=0; i<len; i++, bits>>=1)
	{
		res += (char)('A'+(bits&1));
	}
	return res;
}

void trace(int idx)
{
	if (from[idx] > 0)
	{
		trace(from[idx]);
	}
	cout << rule[idx] << " " << pos[idx] << " " << bits_to_s(qq[idx], ql[idx]) << '\n';
}

void trace2(int idx)
{
	cout << rule[idx] << " " << pos[idx] << " " << bits_to_s(qq[from[idx]], ql[from[idx]]) << '\n';
	if (from[idx] > 1)
	{
		trace2(from[idx]);
	}
}

bits_t trans_bits(string &s)
{
	int i;
	bits_t res = 0;
	for (i=s.size()-1; i>=0; i--)
	{
		res = (res<<1) | (s[i] == 'A' ? 0 : 1);
	}
	return res;
}

int main()
{
	int i, j, k, l, ns, step, over, meet, self, dir, res, idx, p, q, nl;
	bits_t st, ed, current, nxt, pat, rep;
	string s0, s1;
	for (i=0; i<3; i++)
	{
		cin >> s0 >> s1;
		pat_len[i] = s0.size();
		pattern[i] = trans_bits(s0);
		rep_len[i] = s1.size();
		replace[i] = trans_bits(s1);
		//cout << pattern[i] << " " << replace[i] << '\n';
	}
	cin >> step >> s0 >> s1;
	ql[0] = s0.size();
	st = trans_bits(s0);
	ql[1] = s1.size();
	ed = trans_bits(s1);
	// FORWARD from start state
	qq[0] = st;
	qr[0] = FORWARD;
	tbl[0][ql[0]][st] = 1;
	qs[0] = 0;
	from[0] = -1;
	rule[0] = -1;
	pos[0] = -1;
	// BACKWARD from end state
	qq[1] = ed;
	qr[1] = BACKWARD;
	tbl[step][ql[1]][ed] = 2;
	qs[1] = step;
	from[1] = -1;
	rule[1] = -1;
	pos[1] = -1;
	// if find answer
	over = false;
	meet = -1;
	for (i=0, j=2; i<j&&!over&&j<N; i++)
	{
		current = qq[i];
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
			if (dir == FORWARD)
			{
				pat = pattern[k];
				p = pat_len[k];
				rep = replace[k];
				q = rep_len[k];
			}
			else
			{
				pat = replace[k];
				p = rep_len[k];
				rep = pattern[k];
				q = pat_len[k];
			}
			for (l=0; l+p<=ql[i]; l++)
			{
				if (((current >> l) & ((1<<p)-1)) == pat)
				{
					// before l + replace + after l
					nxt = ( ((current>>(l+p))<<(l+q)) | (rep<<l) | (current & ((1<<l)-1)) );
					nl = ql[i] - p + q;
					// 1. tbl[ns][nxt] not visited
					// 2. tbl[ns][nxt] visited by same direction
					// 3. tbl[ns][nxt] visited by different direction
					res = tbl[ns][nl][nxt];
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
						tbl[ns][nl][nxt] = j+1;
						qq[j] = nxt;
						ql[j] = nl;
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
