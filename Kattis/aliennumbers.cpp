#include <iostream>
#include <cstring>

int a, b;
char buf[1024], buf2[1024], buf3[1024];

void print(int n)
{
	if (!n)
	{
		return;
	}
	print(n/b);
	putchar(buf3[n%b]);
}

int main()
{
	int cas, count, i, j, n;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s%s%s", buf, buf2, buf3);
		a = strlen(buf2);
		b = strlen(buf3);
		for (i=0, n=0; buf[i]; i++)
		{
			for (j=0; buf2[j]&&buf2[j]!=buf[i]; j++);
			n = n*a + j;
		}
		printf("Case #%d: ", ++cas);
		print(n);
		puts("");
	}
	return 0;
}
