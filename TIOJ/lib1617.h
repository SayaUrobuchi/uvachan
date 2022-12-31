#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int T = 100;

int times;
int buf[1600];

int Get_Box( void )
{
	int n;
	scanf("%d", &n);
	int i;
	for (i=1; i<=n; i++)
	{
		buf[i] = i;
	}
	srand(time(0));
	for (i=0; i<T; i++)
	{
		int a = rand() % n + 1;
		int b = rand() % n + 1;
		swap(buf[a], buf[b]);
	}
	for (i=1; i<=n; i++)
	{
		printf("%3d", buf[i]);
	}
	puts("");
	return n;
}

int Med3( int a, int b, int c )
{
	++times;
	if (a == b || a == c || b == c)
	{
		puts("ERROR!!");
	}
	if (buf[a] < max(buf[a], max(buf[b], buf[c])) && buf[a] > min(buf[a], min(buf[b], buf[c])))
	{
		return a;
	}
	if (buf[b] < max(buf[a], max(buf[b], buf[c])) && buf[b] > min(buf[a], min(buf[b], buf[c])))
	{
		return b;
	}
	return c;
}

void Report( int a )
{
	printf("%d guesses\n", times);
	printf("==%d==\n", buf[a]);
	if (buf[a] == 8)
	{
		puts("AC");
	}
	else
	{
		puts("WA");
	}
}