#include <iostream>

const int N = 12;
const char *key = "C#D#EF#G#A#B";

int tbl[128];
int ary[128], bry[128];

int parse(const char *s)
{
	if (s[1])
	{
		return tbl[*s]+1;
	}
	return tbl[*s];
}

bool is_t(int n, int *a, int *b)
{
	int t = (*b+N-*a) % N;
	int i;
	for (i=1; i<n; i++)
	{
		if ((b[i]+N-a[i])%N != t)
		{
			return false;
		}
	}
	return true;
}

bool is_r(int n, int *a, int *b)
{
	int i, j;
	for (i=0, j=n-1; i<n; i++, j--)
	{
		if (a[i] != b[j])
		{
			return false;
		}
	}
	return true;
}

bool is_i(int n, int *a, int *b)
{
	int i;
	if (a[0] != b[0])
	{
		return false;
	}
	for (i=1; i<n; i++)
	{
		if (((a[i]+N-a[0])%N + (b[i]+N-b[0])%N)%N)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n, i;
	char s[16];
	for (i=0; key[i]; i++)
	{
		tbl[key[i]] = i;
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			ary[i] = parse(s);
		}
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			bry[i] = parse(s);
		}
		if (is_t(n, ary, bry))
		{
			puts("Transposition");
		}
		else if (is_r(n, ary, bry))
		{
			puts("Retrograde");
		}
		else if (is_i(n, ary, bry))
		{
			puts("Inversion");
		}
		else
		{
			puts("Nonsense");
		}
	}
	return 0;
}
