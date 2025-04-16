#include <iostream>
using namespace std;

const int N = 128;
const int SLEN = 32;

char buf[SLEN];
int p[N];
string s[N], s2[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		s[i] = buf;
	}
	for (i=0; i<m; i++)
	{
		scanf("%s", buf);
		s2[i] = buf;
	}
	scanf("%d", &p[m]);
	for (i=0; i<m; i++)
	{
		scanf("%d", &p[i]);
	}
	int ans = 0;
	for (i=0; i<n; i++)
	{
		for (j=0; j<m&&s2[j]!=s[i]; j++);
		ans += p[j];
	}
	printf("%d\n", ans);
	return 0;
}
