/*
ID: sa072682
LANG: C
TASK: calfflac
*/
#include <stdio.h>

char str[40001], s2[20001];
int tbl[20001];

char transform(char ch)
{
	if(ch > 90)
	{
		return ch - 32;
	}
	return ch;
}

int main()
{
	int n, m, i, j, k, l, ans, left, right;
	char ch;
	freopen("calfflac.in", "r", stdin);
	freopen("calfflac.out", "w", stdout);
	m = n = 0;
	while(scanf("%c", &ch) == 1)
	{
		if((ch > 64 && ch < 91) || (ch > 96 && ch < 123))
		{
			s2[m] = transform(ch);
			tbl[m++] = n;
		}
		str[n++] = ch;
	}
	for(i=0, ans=1, left=0, right=0; i<m; i++)
	{
		for(j=i-1, k=i+1, l=3; j>-1 && k<m; j--, k++, l+=2)
		{
			if(s2[j] == s2[k])
			{
				if(ans < l)
				{
					ans = l;
					left = tbl[j];
					right = tbl[k];
				}
			}
			else
			{
				break;
			}
		}
		for(j=i, k=i+1, l=2; j>-1 && k<m; j--, k++, l+=2)
		{
			if(s2[j] == s2[k])
			{
				if(ans < l)
				{
					ans = l;
					left = tbl[j];
					right = tbl[k];
				}
			}
			else
			{
				break;
			}
		}
	}
	str[right+1] = 0;
	printf("%d\n%s\n", ans, str+left);
	scanf(" ");
	return 0;
}
