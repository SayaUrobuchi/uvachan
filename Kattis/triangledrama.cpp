#include <iostream>
using namespace std;

const int N = 128;

int conn[N][N];

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		for (j=1; j<=n; j++)
		{
			scanf("%d", &conn[i][j]);
		}
	}
	int best = -1;
	int ax, ay, az;
	for (i=1; i<=n; i++)
	{
		for (j=i+1; j<=n; j++)
		{
			for (k=j+1; k<=n; k++)
			{
				int sum = conn[i][j] * conn[i][k] * conn[j][k];
				if (sum > best)
				{
					best = sum;
					ax = i;
					ay = j;
					az = k;
				}
			}
		}
	}
	printf("%d %d %d\n", ax, ay, az);
	return 0;
}
