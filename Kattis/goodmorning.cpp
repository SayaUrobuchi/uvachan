#include <iostream>

int key[][2] = {{-1, -1}, {2, 4}, {3, 5}, {6, -1}, 
						  {5, 7}, {6, 8}, {9, -1}, 
						  {8, -1}, {0, 9}, {-1, -1}};
int nxt[16];

bool check(int n)
{
	int i, j;
	for (j=n%10, n/=10; n; j=i, n/=10)
	{
		i = n%10;
		if (!(nxt[i] & (1<<j)))
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int count, n, i, j, ans;
	for (i=9; i>=0; i--)
	{
		nxt[i] = (1<<i);
		for (j=0; j<2&&key[i][j]>=0; j++)
		{
			nxt[i] |= (1<<key[i][j]) | nxt[key[i][j]];
		}
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; ; i++)
		{
			if (i && n-i >= 0)
			{
				if (check(n-i))
				{
					ans = n-i;
					break;
				}
			}
			if (check(n+i))
			{
				ans = n+i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
