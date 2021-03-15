#include <iostream>

int tbl[1048576];

int main()
{
	int n, m, ans;
	long long i, j;
	scanf("%d%d", &n, &m);
	for (i=2, ans=-1; i<=n&&ans==-1; i++)
	{
		if (!tbl[i])
		{
			if (--m == 0)
			{
				ans = i;
				break;
			}
			for (j=i*i; j<=n; j+=i)
			{
				if (!tbl[j])
				{
					tbl[j] = i;
					if (--m == 0)
					{
						ans = j;
						break;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}