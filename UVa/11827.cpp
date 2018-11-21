#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[1000005];
char *ptr, s[1000005];

int gcd(int p, int q)
{
	while((p%=q)&&(q%=p));
	return p+q;
}

int main()
{
	int count, i, j, g, ans;
	gets(s);
	sscanf(s, "%d", &count);
	while(count--)
	{
		gets(s);
		ptr = strtok(s, " ");
		i = 0;
		ans = 1;
		do
		{
			ary[i] = atoi(ptr);
			for(j=i-1; j>=0; j--)
			{
				g = gcd(ary[i], ary[j]);
				if(g > ans)
				{
					ans = g;
				}
			}
			i++;
		}while(ptr=strtok(NULL, " "));
		printf("%d\n", ans);
	}
	return 0;
}
