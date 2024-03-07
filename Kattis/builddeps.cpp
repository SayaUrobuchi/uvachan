#include <iostream>
#include <vector>
#include <map>
using namespace std;

const int N = 100005;
const int FN = 16;

char buf[1005], fnam[FN];
char nam[N][FN];
bool used[N], recomp[N];
vector<int> v[N];
map<string, int> id_tbl;

int get_id(const char *s)
{
	auto it = id_tbl.find(s);
	if (it == id_tbl.end())
	{
		int nxt_id = id_tbl.size();
		id_tbl[s] = nxt_id;
		sprintf(nam[nxt_id], "%s", s);
		return nxt_id;
	}
	return id_tbl[s];
}

void calc_ord(int id, vector<int> &ord)
{
	if (used[id])
	{
		return;
	}
	used[id] = true;
	int i;
	for (i=0; i<v[id].size(); i++)
	{
		calc_ord(v[id][i], ord);
	}
	ord.emplace_back(id);
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	fgets(buf, sizeof(buf), stdin);
	int p;
	for (i=0; i<n; i++)
	{
		int t;
		fgets(buf, sizeof(buf), stdin);
		sscanf(buf, "%[^:]:%n", fnam, &t);
		int id = get_id(fnam);
		p = t;
		while (sscanf(buf+p, "%s%n", fnam, &t) == 1)
		{
			int did = get_id(fnam);
			v[id].emplace_back(did);
			p += t;
		}
	}
	vector<int> ord;
	for (i=0; i<n; i++)
	{
		calc_ord(i, ord);
	}
	scanf("%s", fnam);
	recomp[get_id(fnam)] = true;
	for (i=0; i<n; i++)
	{
		int id = ord[i];
		for (j=0; !recomp[id]&&j<v[id].size(); j++)
		{
			int did = v[id][j];
			recomp[id] |= recomp[did];
		}
		if (recomp[id])
		{
			puts(nam[id]);
		}
	}
	return 0;
}
