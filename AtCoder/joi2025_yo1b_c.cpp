#include <iostream>
using namespace std;

const int N = 128;
const int pt[3][3] = {
	// PSR
	{0, 0, 1}, 
	{1, 0, 0}, 
	{0, 1, 0}
};

int tbl[128];
char s[N], t[N];

int main()
{
	int n, i;
	tbl['P'] = 0;
	tbl['S'] = 1;
	tbl['R'] = 2;
	scanf("%d%s%s", &n, s, t);
	int sc = 0;
	int tc = 0;
	for (i=0; i<n; i++)
	{
		int a = tbl[s[i]];
		int b = tbl[t[i]];
		sc += pt[a][b];
		tc += pt[b][a];
	}
	printf("%d %d\n", sc, tc);
	return 0;
}