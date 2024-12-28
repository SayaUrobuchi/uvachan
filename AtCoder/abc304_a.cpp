#include <iostream>
using namespace std;

const int N = 128;
const int SN = 16;

char nam[N][SN];

int main()
{
	int n, i;
	scanf("%d", &n);
	int st;
	int age = 2e9;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%s%d", nam[i], &t);
		if (t < age)
		{
			age = t;
			st = i;
		}
	}
	for (i=0; i<n; i++)
	{
		int idx = (st + i) % n;
		puts(nam[idx]);
	}
	return 0;
}
