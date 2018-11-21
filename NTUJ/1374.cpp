#include <stdio.h>
#include <math.h>

int ary[5] = {18, 28, 38, 47, 57};
char s[1005][1005];

int main()
{
	int n, i, j, cnt, t;
	double res, ans;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, cnt=0; i<n; i++)
		{
			scanf("%s", s[i]);
			for(j=0; j<n; j++)
			{
				cnt += 1-(s[i][j]-'0');
			}
		}
		res = cnt*100.0/(n*n);
		for(i=0, ans=100000; i<5; i++)
		{
			if(fabs(res-ary[i]) < ans)
			{
				ans = fabs(res-ary[i]);
				t = i;
			}
		}
		printf("%d\n", t+1);
	}
	return 0;
}
