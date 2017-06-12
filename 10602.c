#include <stdio.h>
#include <string.h>

char *str[105], ary[105][105];

int main()
{
	int count, n, i, j, p, q, res, best, targ;
	char *temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", ary[i]);
			str[i] = ary[i];
		}
		for(i=0, res=strlen(str[0]); i<n-1; i++)
		{
			for(j=i+1, best=-1; j<n; j++)
			{
				for(p=0; str[i][p]&&str[j][p]&&str[i][p]==str[j][p]; p++);
				if(p > best)
				{
					best = p;
					targ = j;
				}
			}
			res += strlen(str[targ]) - best;
			temp = str[targ];
			str[targ] = str[i+1];
			str[i+1] = temp;
		}
		printf("%d\n", res);
		for(i=0; i<n; i++)
		{
			printf("%s\n", str[i]);
		}
	}
	return 0;
}

