#include <iostream>
using namespace std;

const int N = 100005;

int ary[N], bry[N];

void print(const char *start, int ary[], int m)
{
	int i, j;
	printf(start);
	for (i=0; i<m; i=j)
	{
		for (j=i+1; j<m&&ary[j]==ary[j-1]+1; j++);
		if (i)
		{
			if (j < m)
			{
				printf(", ");
			}
			else
			{
				printf(" and ");
			}
		}
		if (j == i+1)
		{
			printf("%d", ary[i]);
		}
		else
		{
			printf("%d-%d", ary[i], ary[j-1]);
		}
	}
	puts("");
}

int main()
{
	int n, m, i, j, last, bn;
	scanf("%d%d", &n, &m);
	for (i=0, bn=0, last=1; i<m; i++)
	{
		scanf("%d", &ary[i]);
		for (; last<ary[i]; bry[bn]=last, bn++, last++);
		last = ary[i] + 1;
	}
	for (; last<=n; bry[bn]=last, bn++, last++);
	print("Errors: ", ary, m);
	print("Correct: ", bry, bn);
	return 0;
}
