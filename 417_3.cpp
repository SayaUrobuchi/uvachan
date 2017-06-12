#include <stdio.h>
#include <string.h>

int ql[100000], qq[100000];
char qs[100000][8], s[100000];

int main()
{
	int i, j, k;
	qs[0][0] = 0;
	ql[0] = 0;
	qq[0] = 'a';
	for(i=0, j=1; i<j; i++)
	{
		if(ql[i] >= 5)
		{
			break;
		}
		for(k=qq[i]; k<='z'; k++)
		{
			sprintf(qs[j], "%s%c", qs[i], k);
			ql[j] = ql[i]+1;
			qq[j] = k+1;
			j++;
		}
	}
	while(scanf("%s", s) == 1)
	{
		for(i=1; s[i]; i++)
		{
			if(s[i] <= s[i-1] || i >= 5)
			{
				break;
			}
		}
		if(s[i])
		{
			printf("0\n");
		}
		else
		{
			for(i=1; i<j; i++)
			{
				if(strcmp(s, qs[i]) == 0)
				{
					break;
				}
			}
			printf("%d\n", i);
		}
	}
	return 0;
}
