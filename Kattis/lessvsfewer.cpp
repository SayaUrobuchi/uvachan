#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
using pp = pair<string, int>;

const int TN = 12;
const int C = 1;
const int M = 2;
const int N = 1005;
const int BN = 32;

const char *ans[] = {"Not on my watch!", "Correct!"};
pp tbl[] = {
	{"amount of", M}, 
	{"few", C}, 
	{"fewer", C}, 
	{"fewest", C},
	{"least", M}, 
	{"less", M}, 
	{"little", M}, 
	{"many", C}, 
	{"more", C|M}, 
	{"most", C|M}, 
	{"much", M}, 
	{"number of", C}
};
int typ[128];

int n;
pp ary[N];
char buf[BN], buf2[BN];

bool comp(const pp &a, const pp &b)
{
	return a.first < b.first;
}

bool judge(const char *a, const char *b)
{
	int need = lower_bound(tbl, tbl+TN, make_pair(a, 0), comp)->second;
	int val = lower_bound(ary, ary+n, make_pair(b, 0), comp)->second;
	return need & val;
}

int main()
{
	int m, i;
	sort(tbl, tbl+TN);
	typ['c'] = C;
	typ['m'] = M;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s%s", buf, buf2);
		ary[i].first = buf;
		ary[i].second = typ[*buf2];
	}
	sort(ary, ary+n);
	for (i=0; i<m; i++)
	{
		scanf("%s", buf);
		if (strcmp(buf, "number") == 0 || strcmp(buf, "amount") == 0)
		{
			scanf("%*s");
			strcat(buf, " of");
		}
		scanf("%s", buf2);
		puts(ans[judge(buf, buf2)]);
	}
	return 0;
}
