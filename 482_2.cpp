
#include<iostream>
using namespace std;

int ary[100000];
char sa[100000][32];
char s[1048576];

int main() {
	int cas, count, n, m, len, i, res;
	char *p;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("\n\n%[^\n]", s);
		for (p=s, n=0; *p; )
		{
			res = sscanf(p, "%d%n", &m, &len);
			if (res <= 0)
			{
				break;
			}
			ary[m] = n++;
			p += len;
		}
		for (i=0; i<n; i++)
		{
			scanf("%s", sa[i]);
		}
		if (cas)
		{
			puts("");
		}
		cas = 1;
		for (i=1; i<=n; i++)
		{
			printf("%s\n", sa[ary[i]]);
		}
	}
	return 0;
}
