#include <stdio.h>
#include <string.h>

int main()
{
	int ans[14][14][14], n, i, j, k, tmp;
	memset(ans, 0, sizeof(ans));
	ans[1][1][1] = 1;
	for(n=2; n<14; n++)
	{
		k = n + 1;
		tmp = n - 2;
		for(i=1; i<k; i++)
		{
			for(j=1; j<k; j++)
			{
				ans[n][i][j] = ans[n-1][i][j] * tmp + ans[n-1][i-1][j] + ans[n-1][i][j-1];
			}
		}
	}
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d%d%d", &i, &j, &k);
		if(i > 13 || j > 13 || k > 13 || i < 1 || j < 1 || k < 1) printf("0\n");
		else printf("%d\n", ans[i][j][k]);
	}
	return 0;
}
