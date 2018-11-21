#include <stdio.h>
#include <string.h>

int tbl[11];
int queue[30000][52], len[30000];
char str[100];

int main()
{
	int b, i, j, k, div, now;
	int *ptr;
	while(scanf("%d%s", &b, str) == 2)
	{
		memset(tbl, 0, sizeof(tbl));
		for(i=0; str[i]; i++)
		{
			tbl[str[i]-48] = 1;
		}
		queue[0][0] = 0;
		len[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			div = len[i] + 1;
			for(k=0, now=0, ptr=queue[i]; k<len[i]; k++)
			{
				now *= b;
				now += ptr[k];
				now %= div;
			}
			now *= b;
			for(k=0; k<b; k++)
			{
				if(len[i] || k)
				{
					if(tbl[k] && !((now+k) % div))
					{
						memcpy(queue[j], queue[i], div<<2);
						queue[j][div-1] = k;
						len[j++] = div;
					}
				}
			}
		}
		for(i=0, j--, ptr=queue[j]; i<len[j]; i++)
		{
			printf("%d", ptr[i]);
		}
		printf("\n");
	}
	return 0;
}
