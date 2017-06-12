#include <stdio.h>

long long scata[27], cata[26];

int main()
{
	int n, i, j;
	cata[0] = 1;
	cata[1] = 1;
	for(i=2; i<26; i++)
	{
		cata[i] = cata[i-1] * (4*i - 2) / (i+1);
	}
	scata[0] = scata[1] = scata[2] = 1;
	for(i=3; i<27; i++)
	{
		scata[i] = (6*i-9) * scata[i-1] / i - (i-3) * scata[i-2] / i;
	}
	while(scanf("%d", &n) == 1)
	{
		printf("%lld\n", scata[n]-cata[n-1]);
	}
	return 0;
}
