#include <iostream>
using namespace std;

const int N = 128;

char ary[N][N], bry[N][N];

void read(char ary[][N], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		scanf("%s", ary[i]);
	}
}

int main()
{
	int n, i, j;
	scanf("%d", &n);
	read(ary, n);
	read(bry, n);
	int ax, ay;
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (ary[i][j] != bry[i][j])
			{
				ax = i + 1;
				ay = j + 1;
			}
		}
	}
	printf("%d %d\n", ax, ay);
	return 0;
}
