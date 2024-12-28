#include <iostream>
using namespace std;

const int N = 64;

int cnt[N][128];
char buf[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		for (j=0; buf[j]; j++)
		{
			++cnt[i][buf[j]];
		}
	}
	for (j='a'; j<='z'; j++)
	{
		int best = N;
		for (i=0; i<n; i++)
		{
			best = min(best, cnt[i][j]);
		}
		for (i=0; i<best; i++)
		{
			putchar(j);
		}
	}
	puts("");
	return 0;
}
