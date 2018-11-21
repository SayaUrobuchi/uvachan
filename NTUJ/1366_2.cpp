#include <stdio.h>
#include <string.h>

int tbl[128];
char s[10000005];

int main()
{
	int count, i, j, k, l, len, res, mx, p, q, ans, d;
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
		for(i='a', res=0; i<='z'&&res<2; i++)
		{
			res += (tbl[i]&1);
		}
		if(res >= 2)
		{
			printf("Impossible\n");
			continue;
		}
		for(i=0, j=len-1, ans=0; i<j; i++, j--)
		{
			memset(tbl, 0, sizeof(tbl));
			for(k=i, mx=len+len; k<j; k++)
			{
				if(tbl[s[k]] == 0)
				{
					tbl[s[k]] = 1;
					for(l=j; l>k; l--)
					{
						if(s[l] == s[k])
						{
							break;
						}
					}
					if(l != k)
					{
						d = k-i+j-l;
						if(d < mx)
						{
							mx = d;
							p = k;
							q = l;
						}
					}
				}
			}
			ans += mx;
			for(k=p; k>i; k--)
			{
				s[k] = s[k-1];
			}
			for(k=q; k<j; k++)
			{
				s[k] = s[k+1];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
