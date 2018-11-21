#include <stdio.h>
#include <string.h>

int n, num, ptr[10010][2], ary[10010], queue[10010];
char str[10010];

void recursion()
{
	int tmp;
	tmp = num;
	ary[tmp] = n;
	if(str[n--] < 91)
	{
		ptr[tmp][1] = ++num;
		recursion();
		ptr[tmp][0] = ++num;
		recursion();
	}
	else
	{
		ptr[tmp][0] = -1;
		ptr[tmp][1] = -1;
	}
}

int main()
{
	int count, i, j, now;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", str);
		num = 0;
		n = strlen(str) - 1;
		recursion();
		queue[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			now = queue[i];
			if(ptr[now][0] != -1)
			{
				queue[j++] = ptr[now][0];
				queue[j++] = ptr[now][1];
			}
		}
		for(i--; i>-1; i--)
		{
			printf("%c", str[ary[queue[i]]]);
		}
		printf("\n");
	}
	return 0;
}
