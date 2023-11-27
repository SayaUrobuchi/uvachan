#include <iostream>
using namespace std;

const int N = 1024;

int cnt[N], sum[N];
char s[N];

int main()
{
	int n, i, j, len;
	scanf("%d", &n);
	for (i=0, len=0; i<n; i++)
	{
		scanf("%s", s);
		for (j=0; s[j]; j++)
		{
			++cnt[j];
			sum[j] += s[j];
		}
		len = max(len, j);
	}
	for (i=0; i<len; i++)
	{
		s[i] = sum[i] / cnt[i];
	}
	s[len] = 0;
	puts(s);
	return 0;
}
