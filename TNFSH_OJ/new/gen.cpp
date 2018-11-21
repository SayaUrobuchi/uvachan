#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

char s[64];

int main(int argc, char *argv[])
{
	int n, i, j, seed;
	long long m, o;
	if (argc < 2 || sscanf(argv[1], "%d", &n) != 1)
	{
		fprintf(stderr, "no number in argv, please input: ");
		if (scanf("%d", &n) != 1)
		{
			fprintf(stderr, "format error.\n");
			return -1;
		}
	}
	if (argc < 3 || sscanf(argv[2], "%lld", &m) != 1)
	{
		fprintf(stderr, "no number limit in argv, please input: ");
		if (scanf("%lld", &m) != 1)
		{
			fprintf(stderr, "format error.\n");
			return -1;
		}
	}
	if (argc < 4 || sscanf(argv[3], "%d", &seed) != 1)
	{
		seed = time(NULL);
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<18; j++)
		{
			s[j] = '0' + rand()%10;
		}
		s[j] = 0;
		std::random_shuffle(s, s+j);
		sscanf(s, "%lld", &o);
		o %= m;
		if (!o)
		{
			o = 1;
		}
		printf("%lld\n", o%m);
	}
	return 0;
}
