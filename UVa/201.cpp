#include <stdio.h>

int main()
{
	int n, m, i, j, tmp, v[10][10], h[10][10], ans[10], cas;
	char in[2], check;
	cas = 0;
	check = 0;
	for(i=0; i<10; i++)
	{
		v[0][i] = 0;
		h[i][0] = 0;
	}
	while(scanf("%d%d", &n, &m)==2)
	{
		if(check) printf("\n**********************************\n\n");
		check = 1;
		printf("Problem #%d\n\n", ++cas);
		for(i=1, n++; i<n; i++)
		{
			ans[i] = 0;
			for(j=1; j<n; j++)
			{
				v[i][j] = 0;
				h[i][j] = 0;
			}
		}
		while(m--)
		{
			scanf("%s%d%d", in, &i, &j);
			if(in[0] == 'H') h[i][j+1] = 1;
			else v[j+1][i] = 1;
		}
		for(i=1; i<n; i++)
		{
			for(j=1; j<n; j++)
			{
				if(h[i][j]) h[i][j] += h[i][j-1];
				if(v[i][j]) v[i][j] += v[i-1][j];
				tmp = h[i][j];
				if(tmp > v[i][j]) tmp = v[i][j];
				if(tmp)
				{
					while(tmp)
					{
						if(h[i-tmp][j] > tmp - 1 && v[i][j-tmp] > tmp - 1) ans[tmp]++;
						tmp--;
					}
				}
			}
		}
		for(i=1, tmp=0, n--; i<n; i++)
		{
			if(ans[i])
			{
				printf("%d square (s) of size %d\n", ans[i], i);
				tmp = 1;
			}
		}
		if(!tmp) printf("No completed squares can be found.\n");
	}
	return 0;
}
