#include <iostream>
using namespace std;

char buf[128];

void read(int &res)
{
	int i;
	res = 0;
	fgets(buf, sizeof(buf), stdin);
	for (i=0; buf[i]>=' '; i++)
	{
		if (buf[i] != ' ')
		{
			res = res*10 + (buf[i]-'0');
		}
	}
}

void write(int t)
{
	if (t < 10)
	{
		putchar('0'+t);
		return;
	}
	write(t/10);
	printf(" %d", t%10);
}

int main()
{
	int n, i, a, b;
	scanf("%d", &n);
	fgets(buf, sizeof(buf), stdin);
	for (i=0; i<n; i++)
	{
		read(a);
		read(b);
		//fprintf(stderr, "%d %d => %d\n", a, b, a+b);
		write(a+b);
		puts("");
	}
	return 0;
}
