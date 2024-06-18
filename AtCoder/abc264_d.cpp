#include <iostream>
using namespace std;

const int N = 7;
const char *key = "atcoder";

int tbl[128];
char s[N+1];

int main()
{
	int i, j;
	for (i=0; i<N; i++)
	{
		tbl[key[i]] = i;
	}
	scanf("%s", s);
	int ans = 0;
	for (i=0; i<N; i++)
	{
		for (j=0; j+1<N-i; j++)
		{
			if (tbl[s[j]] > tbl[s[j+1]])
			{
				swap(s[j], s[j+1]);
				++ans;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
