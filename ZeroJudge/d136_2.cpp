#include <stdio.h>

char s[30000005];
unsigned long long ary1[1000005];

int main()
{
	int n, m, i, j, jj, ans;
	unsigned long long k, res;
	gets(s);
	sscanf(s, "%d%d", &m, &n);
	while(m--)
	{
		gets(s);
		for(i=0, j=0; i<n; i++)
		{
			for(res=0; s[j]&&s[j]!=' '; j++)
			{
				res *= 10;
				res += s[j]-48;
			}
			ary1[i] = res;
			for(; s[j]&&s[j]==' '; j++);
		}
		gets(s);
		for(i=0, j=0, jj=0, ans=0; i<n; i++)
		{
			for(res=0; s[jj]&&s[jj]!=' '; jj++)
			{
				res *= 10;
				res += s[jj]-48;
			}
			k = res;
			for(; s[jj]&&s[jj]==' '; jj++);
			for(; j<n&&ary1[j]<k; j++);
			if(ary1[j] == k)
			{
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
