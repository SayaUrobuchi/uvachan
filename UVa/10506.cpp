#include <stdio.h>
#include <string.h>

int n, m, lim;
int chk[65536];
char str[100000];

int trans(char *ptr, int len)
{
	int i, j, res;
	for(i=0, j=1, res=0; i<len; i++, j*=m)
	{
		res += (ptr[i] - 48) * j;
	}
	return res;
}

int dfs(int now, int next)
{
	int i, temp;
	str[next] = 0;
	/*printf("%d %s\n", now, str);*/
	if(next == lim)
	{
		for(i=0; i<n-1; i++)
		{
			str[next+i] = str[i];
			if(chk[trans(str+now+i, n)])
			{
				/*printf("%d\n", i);*/
				return 0;
			}
		}
		str[next] = 0;
		printf("%s\n", str);
		return 1;
	}
	for(i=0; i<m; i++)
	{
		str[next] = i + '0';
		if(!chk[temp=trans(str+now, n)])
		{
			chk[temp] = 1;
			if(dfs(now+1, next+1))
			{
				return 1;
			}
			chk[temp] = 0;
		}
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			str[i] = '0';
		}
		for(i=0, lim=1; i<n; i++, lim*=m);
		memset(chk, 0, sizeof(chk));
		chk[0] = 1;
		dfs(1, n);
	}
	return 0;
}
