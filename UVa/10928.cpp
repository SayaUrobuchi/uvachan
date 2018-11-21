#include <stdio.h>
#include <string.h>

int ary[1001];
char str[100001];

int main()
{
	int count, n, i, c, num, neighbour;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		gets(str);
		for(i=1, neighbour=200000, num=0; i<=n; i++)
		{
			gets(str);
			strtok(str, " ");
			c = 1;
			while(strtok(NULL, " "))
			{
				c++;
			}
			if(c < neighbour)
			{
				neighbour = c;
				ary[0] = i;
				num = 1;
			}
			else if(c == neighbour)
			{
				ary[num++] = i;
			}
		}
		printf("%d", ary[0]);
		for(i=1; i<num; i++)
		{
			printf(" %d", ary[i]);
		}
		printf("\n");
	}
	return 0;
}
