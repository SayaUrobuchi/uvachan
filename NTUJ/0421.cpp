#include <stdio.h>

int arr[100005];

int main()
{
	int n, m, i, s, p, q, c, cc, mm, ans, tmp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0, s=0, mm=0; i<n; i++)
		{
			scanf("%d", &arr[i]);
			s += arr[i];
			if(arr[i] > mm)
			{
				mm = arr[i];
			}
		}
		for(p=mm, q=s, ans=s; p<=q; )
		{
			c = ((p+q)>>1);
			for(i=0, cc=0, tmp=0; i<n&&cc<m; i++)
			{
				if(tmp + arr[i] > c)
				{
					cc++;
					tmp = 0;
				}
				tmp += arr[i];
			}
			if(cc < m)
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
