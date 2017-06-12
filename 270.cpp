#include <stdio.h>
#include <stdlib.h>

char s[100];
int ary[700][2];

int main()
{
	int count, n, i, j, k, l, p, q, temp, ans;
	scanf("%d", &count);
	gets(s);
	gets(s);
	while(count--)
	{
		n = 0;
		while(gets(s))
		{
			if(sscanf(s, "%d%d", &ary[n][0], &ary[n][1]) != 2)
			{
				break;
			}
			n++;
		}
		if(n == 1)
		{
			printf("1\n");
		}
		else
		{
			for(i=1, l=0, ans=0; i<n; i++)
			{
				for(j=0; j<i; j++)
				{
					if(n < 50 || (rand() % 50))
					{
						p = ary[i][0] - ary[j][0];
						q = ary[i][1] - ary[j][1];
						for(k=0, temp=0; k<n; k++)
						{
							if((ary[i][0] - ary[k][0]) * q == (ary[i][1] - ary[k][1]) * p)
							{
								temp++;
							}
						}
						if(temp > ans)
						{
							ans = temp; 
						}
					}
				}
			}
			printf("%d\n", ans);
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
