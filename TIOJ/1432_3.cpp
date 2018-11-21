#include <stdio.h>

int arr[1005];

int main()
{
	int n, m, i, p, q, s, c, cc, mx, ans, tmp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		for(i=0, mx=0, s=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
			if(arr[i] > mx)
			{
				mx = arr[i];
			}
			s += arr[i];
		}
		for(p=mx, q=s; p<=q; )
		{
			c = ((p+q)>>1);
			for(i=0, cc=0, tmp=0; i<n&&cc<=m; i++)
			{
				if(tmp + arr[i] > c)
				{
					tmp = 0;
					cc++;
				}
				tmp += arr[i];
			}
			if(cc <= m)
			{
				ans = c;
				q = c - 1;
			}
			else
			{
				p = c + 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
