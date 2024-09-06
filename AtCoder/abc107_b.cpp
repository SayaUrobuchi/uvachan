#include <iostream>
using namespace std;

const int R = 105;
const int C = 105;

char s[R][C];
int row[R], col[C];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", s[i]);
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<m&&s[i][0]=='.'&&s[i][j]==s[i][0]; j++);
		row[i] = (j < m);
	}
	for (j=0; j<m; j++)
	{
		for (i=0; i<n&&s[0][j]=='.'&&s[i][j]==s[0][j]; i++);
		col[j] = (i < n);
	}
	for (i=0; i<n; i++)
	{
		if (row[i])
		{
			for (j=0; j<m; j++)
			{
				if (col[j])
				{
					putchar(s[i][j]);
				}
			}
			puts("");
		}
	}
	return 0;
}
