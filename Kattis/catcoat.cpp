#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int SS = 0;
const int LS = 1;
const int LR = 2;
const int LL = 3;
const int RR = 4;
const int F = 0;
const int M = 1;
const int RED = 2;

const char *GEN_NAM[] = {
	"Black", 
	"Blue", 
	"Chocolate", 
	"Lilac", 
	"Red", 
	"Cream", 
	"Black-Red Tortie", 
	"Blue-Cream Tortie", 
	"Chocolate-Red Tortie", 
	"Lilac-Cream Tortie"
};
const int CLS = sizeof(GEN_NAM) / sizeof(GEN_NAM[0]);
const int GENE[][3] = {
	{LR, LR, SS}, // B-D-oo
	{LR, SS, SS}, // B-ddoo
	{SS, LR, SS}, // bbD-oo
	{SS, SS, SS}, // bbddoo
	{RR, LR, LL}, // --D-OO
	{RR, SS, LL}, // --ddOO
	{LR, LR, LS}, // B-D-Oo
	{LR, SS, LS}, // B-ddOo
	{SS, LR, LS}, // bbD-Oo
	{SS, SS, LS}, // bbddOo
};
//                 SS LS LR LL RR
const int VAR[] = {1, 1, 2, 1, 3};
const char *BDO[] = {"bB", "dD", "oO"};
const int BDO_VAR[][4] = {
	{0b00}, // SS
	{0b01}, // LS
	{0b01, 0b11}, // LR
	{0b11}, // LL
	{0b00, 0b01, 0b11}, // RR
};
const int NAM_LEN = 32;

int idx[CLS];
char fcat[NAM_LEN], mcat[NAM_LEN];
double cnt[CLS];
vector<string> fcg, mcg;

bool comp(const int &a, const int &b)
{
	if (cnt[a] != cnt[b])
	{
		return cnt[a] > cnt[b];
	}
	//printf(".. %s %s %d\n", GEN_NAM[a], GEN_NAM[b], strcmp(GEN_NAM[a], GEN_NAM[b]));
	return strcmp(GEN_NAM[a], GEN_NAM[b]) < 0;
}

void trunc(char *s)
{
	int i;
	for (i=0; s[i]>=' '; i++);
	s[i] = 0;
}

int find_id(char *s)
{
	trunc(s);
	for (int i=0; i<CLS; i++)
	{
		if (strcmp(GEN_NAM[i], s) == 0)
		{
			return i;
		}
	}
	return -1;
}

int judge_id(const string &s)
{
	int i, j, k;
	for (i=0; i<CLS; i++)
	{
		bool gg = false;
		for (j=0; j<3&&!gg; j++)
		{
			bool fit = false;
			for (k=0; k<VAR[GENE[i][j]]&&!fit; k++)
			{
				if (s[(j<<1)] == BDO[j][BDO_VAR[GENE[i][j]][k]&1]
				 && s[(j<<1)|1] == BDO[j][BDO_VAR[GENE[i][j]][k]>>1])
				{
					fit = true;
				}
			}
			if (!fit)
			{
				gg = true;
			}
		}
		if (!gg)
		{
			//printf(".. %s as %d\n", s.c_str(), i);
			return i;
		}
	}
	return -1;
}

void dfs(int id, int gender, int depth, string &s, vector<string> &res)
{
	if (depth == 3)
	{
		res.emplace_back(s);
		//printf("%d => %s\n", gender, s.c_str());
		return;
	}
	int t = GENE[id][depth];
	if (depth != RED || gender != M)
	{
		for (int i=0; i<VAR[t]; i++)
		{
			s[(depth<<1)] = BDO[depth][BDO_VAR[t][i]&1];
			s[(depth<<1)|1] = BDO[depth][BDO_VAR[t][i]>>1];
			dfs(id, gender, depth+1, s, res);
		}
	}
	else
	{
		s[(depth<<1)] = BDO[depth][BDO_VAR[t][0]&1];
		dfs(id, gender, depth+1, s, res);
	}
}

int calc_var(int id, int gender, vector<string> &v)
{
	string buf;
	buf.resize(6, 'O');
	dfs(id, gender, 0, buf, v);
	return v.size();
}

void calc_kit(const string &fc, const string &mc, int gender)
{
	int i, j, k;
	string ret;
	ret.resize(6, 'X');
	for (i=0; i<4; i++)
	{
		ret[0] = fc[i&1];
		ret[1] = mc[i>>1];
		if (ret[0] > ret[1])
		{
			swap(ret[0], ret[1]);
		}
		for (j=0; j<4; j++)
		{
			ret[2] = fc[2+(j&1)];
			ret[3] = mc[2+(j>>1)];
			if (ret[2] > ret[3])
			{
				swap(ret[2], ret[3]);
			}
			if (gender == F)
			{
				for (k=0; k<2; k++)
				{
					ret[4] = fc[4+(k&1)];
					ret[5] = mc[4];
					if (ret[4] > ret[5])
					{
						swap(ret[4], ret[5]);
					}
					cnt[judge_id(ret)] += 1.0 / 4 / 4 / 2;
				}
			}
			else
			{
				for (k=0; k<2; k++)
				{
					ret[4] = fc[4+(k&1)];
					ret[5] = ret[4];
					cnt[judge_id(ret)] += 1.0 / 4 / 4 / 2;
				}
			}
		}
	}
}

int main()
{
	int i, j;
	int fid, fvar;
	int mid, mvar;
	fgets(fcat, sizeof(fcat), stdin);
	fid = find_id(fcat);
	fvar = calc_var(fid, F, fcg);
	fgets(mcat, sizeof(mcat), stdin);
	mid = find_id(mcat);
	mvar = calc_var(mid, M, mcg);
	//printf("%d %d\n", fvar, mvar);
	for (i=0; i<fvar; i++)
	{
		for (j=0; j<mvar; j++)
		{
			calc_kit(fcg[i], mcg[j], F);
			calc_kit(fcg[i], mcg[j], M);
		}
	}
	for (i=0; i<CLS; i++)
	{
		idx[i] = i;
	}
	sort(idx, idx+CLS, comp);
	for (i=0; i<CLS; i++)
	{
		if (cnt[idx[i]] != 0)
		{
			printf("%s %.9lf\n", GEN_NAM[idx[i]], cnt[idx[i]]/(fvar*mvar*2));
		}
	}
	return 0;
}
