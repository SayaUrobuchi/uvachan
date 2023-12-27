#include <iostream>
using namespace std;

const int N = 305;
const int B = 1005;

char dig[B][N];
char buf[N];

int main()
{
	int b, i, j, k;
	scanf("%d", &b);
	for (i=0; i<b; i++)
	{
		scanf("%s", dig[i]);
	}
	scanf("%s", buf);
	int ans = 0;
	for (i=0; buf[i]; i+=k)
	{
		for (j=0; j<b; j++)
		{
			for (k=0; dig[j][k]&&buf[i+k]&&dig[j][k]==buf[i+k]; k++);
			if (!dig[j][k])
			{
				break;
			}
		}
		ans = (ans * b) + j;
	}
	printf("%d\n", ans);
	return 0;
}
