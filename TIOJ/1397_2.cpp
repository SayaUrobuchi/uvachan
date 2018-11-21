#include <stdio.h>

char buf[100005], res[100005];

int main()
{
	int n, m, i, j, l;
	while(scanf("%d%d", &n, &m) == 2)
	{
		scanf("%s", buf);
		for(i=0, l=-1; buf[i]=='0'; i++, m--);
		res[++l] = buf[i++];
		for(j=0; buf[i]; i++)
		{
			res[++l] = buf[i];
			for(; l>1&&m>0&&res[l]<res[l-1]; res[l-1]=res[l], l--, m--);
			if(buf[i] == '0')
			{
				if(res[l-1] != '0')
				{
					j = l-1;
				}
			}
			else
			{
				if(j>=0&&m-(l-j)>=0)
				{
					if(res[j] > res[l])
					{
						res[j] = res[l];
						m -= l-j;
						l = j;
					}
				}
			}
		}
		for(; m>0; l--, m--);
		res[++l] = 0;
		puts(res);
	}
	return 0;
}
