#include <stdio.h>
#include <string.h>

int ans[2][16], tbl[16], list[7], count, n, m, p, a, b, c, d, ab, ac, ad, bc, bd, cd;

void dfs(int depth)
{
	int i, temp;
	if(depth == 7)
	{
		temp = n - list[0] - list[1] - list[2];
		if(temp < 1 || temp > 7)
		{
			return;
		}
		tbl[0] = list[0];
		tbl[1] = list[1];
		tbl[2] = list[2];
		tbl[3] = temp;
		temp = n - list[3] - list[4] - list[5];
		if(temp < 1 || temp > 7)
		{
			return;
		}
		tbl[4] = list[3];
		tbl[5] = list[4];
		tbl[6] = list[5];
		tbl[7] = temp;
		temp = n - list[0] - list[3] - list[6];
		if(temp < 1 || temp > 7)
		{
			return;
		}
		tbl[8] = list[6];
		tbl[12] = temp;
		temp = n - temp - tbl[3] - tbl[6];
		if(temp < 1 || temp > 7)
		{
			return;
		}
		tbl[9] = temp;
		temp = n - temp - tbl[1] - tbl[5];
		if(temp < 1 || temp > 7)
		{
			return;
		}
		tbl[13] = temp;
		/*printf("%d %d %d %d\n", tbl[0], tbl[1], tbl[2], tbl[3]);
		printf("%d %d %d %d\n", tbl[4], tbl[5], tbl[6], tbl[7]);
		printf("%d %d\n%d %d\n", tbl[8], tbl[9], tbl[12], tbl[13]);
		printf("123\n");*/
		ab = n - tbl[8] - tbl[9];
		cd = n - tbl[12] - tbl[13];
		ac = n - tbl[2] - tbl[6];
		bd = n - tbl[3] - tbl[7];
		ad = n - tbl[0] - tbl[5];
		if(ab + cd != ac + bd)
		{
			return;
		}
		/*printf("%d %d %d %d %d\n", ab, cd, ac, bd, ad);*/
		a = ab + ac + ab + cd + ac + bd + ad - cd - cd - cd - ab - ab - ab;
		/*printf("a %d\n", a);*/
		if(a % 2)
		{
			return;
		}
		a /= 2;
		b = ab - a;
		c = ac - a;
		d = ad - a;
		/*printf("XDDD %d %d %d %d\n", a, b, c, d);*/
		if(a < 1 || a > 7)
		{
			return;
		}
		if(b < 1 || b > 7)
		{
			return;
		}
		if(c < 1 || c > 7)
		{
			return;
		}
		if(d < 1 || d > 7)
		{
			return;
		}
		tbl[10] = a;
		tbl[11] = b;
		tbl[14] = c;
		tbl[15] = d;
		for(i=0, temp=1; i<16; i++)
		{
			temp *= tbl[i];
			temp %= m;
		}
		if(temp > p)
		{
			return;
		}
		if(count < 2)
		{
			for(i=0; i<16; i++)
			{
				ans[count][i] = tbl[i];
			}
		}
		count++;
		return;
	}
	for(i=1; i<=7; i++)
	{
		list[depth] = i;
		dfs(depth+1);
	}
}

int main()
{
	int cas, i, j, k;
	cas = 0;
	while(scanf("%d%d%d", &n, &m, &p) == 3)
	{
		if(!n && !m && !p)
		{
			break;
		}
		count = 0;
		if(n >= 4 && n <= 28)
		{
			dfs(0);
		}
		printf("Set %d:\n%d\n", ++cas, count);
		if(count)
		{
			for(i=0; i<16; i++)
			{
				printf("%d", ans[0][i]);
				if(i % 4 == 3)
				{
					printf("\n");
				}
			}
			printf("....\n");
			if(count > 1)
			{
				for(i=0; i<16; i++)
				{
					printf("%d", ans[1][i]);
					if(i % 4 == 3)
					{
						printf("\n");
					}
				}
				printf("....\n");
			}
		}
	}
	return 0;
}
