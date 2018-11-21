#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char r[305][305], buf[305], used[305];

int comp(const void *p, const void *q)
{
	return *(char*)p - *(char*)q;
}

int main()
{
	int cas, n, m, i, j, k;
	char temp;
	cas = 0;
	while(scanf("%s%d", buf, &m) == 2)
	{
		if(!strcmp(buf, "END") && m == 0)
		{
			break;
		}
		temp = buf[m-1];
		for(i=0; buf[i]; i++)
		{
			r[i][0] = buf[i];
			/*printf("%d %d: %c\n", i, 0, r[i][0]);*/
		}
		n = i;
		qsort(buf, n, sizeof(char), comp);
		for(i=0; i<n; i++)
		{
			r[i][1] = buf[i];
			/*printf("%d %d: %c\n", i, 1, r[i][1]);*/
		}
		for(k=2; k<n; k++)
		{
			memset(used, 0, sizeof(used));
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					if(!used[j] && !strncmp(r[i], r[j]+1, k-1))
					{
						/*printf("XDDD %d %d: %c\n", i, j, r[i][k-1]);*/
						used[j] = 1;
						r[j][k] = r[i][k-1];
						break;
					}
				}
			}
			/*for(i=0; i<n; i++)
			{
				printf("%d %d: %c\n", i, k, r[i][k]);
			}*/
		}
		r[m-1][n] = temp;
		r[m-1][n+1] = 0;
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		puts(r[m-1]+1);
	}
	return 0;
}
