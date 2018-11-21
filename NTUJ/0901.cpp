#include <stdio.h>
#include <string.h>

int able[100005], list[100005], slen[100005];
char str[100005][250];

int recurs(char *s, int p, int q)
{
	int temp, i, res, dep, type, last;
	if(s[p] == 'C')
	{
		return 1;
	}
	if(s[p] >= '0' && s[p] <= '9')
	{
		sscanf(s+p, "%d", &temp);
		return able[temp];
	}
	if(s[p] == '(')
	{
		for(i=p+1, res=-1, type=-1, dep=1, last=p+1; i<=q; i++)
		{
			if(s[i] == 'A' && dep == 1)
			{
				if(res == -1)
				{
					res = recurs(s, last, i-1);
				}
				else
				{
					res &= recurs(s, last, i-1);
				}
				type = 0;
				last = i+1;
			}
			else if(s[i] == 'O' && dep == 1)
			{
				if(res == -1)
				{
					res = recurs(s, last, i-1);
				}
				else
				{
					res |= recurs(s, last, i-1);
				}
				type = 1;
				last = i+1;
			}
			else if(s[i] == '(')
			{
				dep++;
			}
			else if(s[i] == ')')
			{
				dep--;
				if(dep == 0)
				{
					if(type == -1)
					{
						res = recurs(s, last, i-1);
					}
					else if(type == 0)
					{
						res &= recurs(s, last, i-1);
					}
					else
					{
						res |= recurs(s, last, i-1);
					}
				}
			}
		}
		return res;
	}
	return 0;
}

int main()
{
	int count, n, i, len, f;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=1; i<=n; i++)
		{
			scanf("%s", str[i]);
			list[i-1] = i;
			slen[i] = strlen(str[i]);
		}
		len = n;
		memset(able, 0, sizeof(able));
		while(1)
		{
			for(i=0, f=0; i<len; i++)
			{
				if(recurs(str[list[i]], 0, slen[list[i]]))
				{
					able[list[i]] = 1;
					list[i] = list[--len];
					f = 1;
				}
			}
			if(!f)
			{
				break;
			}
		}
		printf("%d\n", n-len);
	}
	return 0;
}
