#include <stdio.h>

int ary[100005];

int main()
{
	int n, m, i, j, k;
	long long ans, ux, uy, dx, dy, tx, ty, area, last;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		scanf("%d%I64d", &m, &dy);
		for(i=1, ux=uy=dx=0, j=0, ans=0; i<m; i++)
		{
			for(; j<n&&ux<=dx; ux+=ary[j++], uy+=ary[j++]);
			area = (ux-dx) * (dy-uy+ary[j-1]);
			if(area > ans)
			{
				ans = area;
			}
			for(k=j, tx=ux, ty=uy, last=0; k<=n&&dy>ty; tx+=ary[k++], ty+=ary[k++])
			{
				area = (tx+ary[k]-dx) * (dy-ty);
				if(area < last)
				{
					break;
				}
				/*printf("XDDDDDDD %I64d\n", area);
				printf("%I64d %I64d %I64d %I64d\n", tx, ty, dx, dy);*/
				if(area > ans)
				{
					ans = area;
				}
				last = area;
			}
			scanf("%d", &tx);
			dx += tx;
			i++;
			if(i < m)
			{
				scanf("%d", &ty);
			}
			dy += ty;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}
