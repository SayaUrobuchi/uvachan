#include<iostream>
#include <string.h>
using namespace std;

int tbl[5][5];
int nn[5];
char s[10485760];

int main() {
	int n, i, j, k, len, cc;
	long long res, best;
	while (scanf("%s", s) == 1)
	{
		scanf("%d", &n);
		for (i=0; i<5; i++)
		{
			for (j=0; j<5; j++)
			{
				scanf("%d", &tbl[i][j]);
			}
		}
		memset(nn, 0, sizeof(nn));
		len = strlen(s);
		for (i=0; i<=len-n; i++)
		{
			nn[s[i]-'a']++;
		}
		for (i=0; i<n; i++)
		{
			best = -1;
			cc = 0;
			for (j=0; j<5; j++)
			{
				res = 0;
				for (k=0; k<5; k++)
				{
					res += (long long)nn[k] * tbl[j][k];
				}
				if (res > best)
				{
					best = res;
					cc = j;
				}
			}
			printf("%c", cc+'a');
			if (i < n-1)
			{
				nn[s[i+(len-n)+1]-'a']++;
				nn[s[i]-'a']--;
			}
		}
		puts("");
	}
	return 0;
}
