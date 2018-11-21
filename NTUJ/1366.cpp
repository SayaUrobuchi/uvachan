#include <stdio.h>
#include <string.h>

int tbl[128];
char s[100005];

int main()
{
	int count, i, j, k, len, ans, res, t;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", s);
		memset(tbl, 0, sizeof(tbl));
		for(i=0; s[i]; i++)
		{
			tbl[s[i]]++;
		}
		len = i;
		for(i='a', res=0; i<='z'; i++)
		{
			res += (tbl[i]&1);
			if(tbl[i]&1)
			{
				t = i;
			}
		}
		if(res > 1)
		{
			printf("Impossible\n");
			continue;
		}
		if(res)
		{
			for(i=0, j=0; s[i]; i++)
			{
				if(s[i] == t)
				{
					j++;
					if(j+j > tbl[i])
					{
						break;
					}
				}
			}
			if(i+i < len)
			{
				for(i=0, j=len-1; i<j; i++, j--)
				{
					t = s[i];
					s[i] = s[j];
					s[j] = t;
				}
			}
		}
		for(i=0, j=len-1, ans=0; i<=j; i++, j--)
		{
			if(s[i] != s[j])
			{
				for(k=j-1; k>i; k--)
				{
					if(s[k] == s[i])
					{
						break;
					}
				}
				if(k == i)
				{
					for(; k<((i+j)>>1); k++, ans++)
					{
						t = s[k];
						s[k] = s[k+1];
						s[k+1] = t;
					}
				}
				else
				{
					for(; k<j; k++, ans++)
					{
						t = s[k];
						s[k] = s[k+1];
						s[k+1] = t;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
