#include <stdio.h>
#include <string.h>

int sx, sy;
long long int nx[4], ny[4];
long long int px[4], py[4];
long long int tx[4], ty[4];
int used[4];
int list[4];

int chk()
{
	/* 2+2 */
	/* XX */
	tx[0] = px[0] * py[1] + px[1] * py[0];
	ty[0] = py[0] * py[1];
	tx[1] = px[2] * py[3] + px[3] * py[2];
	ty[1] = py[2] * py[3];
	tx[2] = tx[0] * ty[1] + tx[1] * ty[0];
	ty[2] = ty[0] * ty[1];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	tx[2] = tx[0] * tx[1];
	ty[2] = ty[0] * tx[1] + ty[1] * tx[0];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	/* XY */
	tx[0] = px[0] * py[1] + px[1] * py[0];
	ty[0] = py[0] * py[1];
	ty[1] = py[2] * px[3] + py[3] * px[2];
	tx[1] = px[2] * px[3];
	tx[2] = tx[0] * ty[1] + tx[1] * ty[0];
	ty[2] = ty[0] * ty[1];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	tx[2] = tx[0] * tx[1];
	ty[2] = ty[0] * tx[1] + ty[1] * tx[0];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	/* YX */
	ty[0] = py[0] * px[1] + py[1] * px[0];
	tx[0] = px[0] * px[1];
	tx[1] = px[2] * py[3] + px[3] * py[2];
	ty[1] = py[2] * py[3];
	tx[2] = tx[0] * ty[1] + tx[1] * ty[0];
	ty[2] = ty[0] * ty[1];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	tx[2] = tx[0] * tx[1];
	ty[2] = ty[0] * tx[1] + ty[1] * tx[0];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	/* YY */
	ty[0] = py[0] * px[1] + py[1] * px[0];
	tx[0] = px[0] * px[1];
	ty[1] = py[2] * px[3] + py[3] * px[2];
	tx[1] = px[2] * px[3];
	tx[2] = tx[0] * ty[1] + tx[1] * ty[0];
	ty[2] = ty[0] * ty[1];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	tx[2] = tx[0] * tx[1];
	ty[2] = ty[0] * tx[1] + ty[1] * tx[0];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	/* 3+1 */
	/* XXX */
	tx[0] = px[0] * py[1] + px[1] * py[0];
	ty[0] = py[0] * py[1];
	tx[1] = tx[0] * py[2] + px[2] * ty[0];
	ty[1] = py[2] * ty[0];
	tx[2] = px[3] * ty[1] + tx[1] * py[3];
	ty[2] = py[3] * ty[1];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	tx[2] = px[3] * tx[1];
	ty[2] = py[3] * tx[1] + ty[1] * px[3];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	/* XYX */
	ty[0] = py[0] * px[1] + py[1] * px[0];
	tx[0] = px[0] * px[1];
	tx[1] = tx[0] * py[2] + px[2] * ty[0];
	ty[1] = py[2] * ty[0];
	tx[2] = px[3] * ty[1] + tx[1] * py[3];
	ty[2] = py[3] * ty[1];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	tx[2] = px[3] * tx[1];
	ty[2] = py[3] * tx[1] + ty[1] * px[3];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	/* XXY */
	tx[0] = px[0] * py[1] + px[1] * py[0];
	ty[0] = py[0] * py[1];
	ty[1] = ty[0] * px[2] + py[2] * tx[0];
	tx[1] = px[2] * tx[0];
	tx[2] = px[3] * ty[1] + tx[1] * py[3];
	ty[2] = py[3] * ty[1];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	tx[2] = px[3] * tx[1];
	ty[2] = py[3] * tx[1] + ty[1] * px[3];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	/* XYY */
	ty[0] = py[0] * px[1] + py[1] * px[0];
	tx[0] = px[0] * px[1];
	ty[1] = ty[0] * px[2] + py[2] * tx[0];
	tx[1] = px[2] * tx[0];
	tx[2] = px[3] * ty[1] + tx[1] * py[3];
	ty[2] = py[3] * ty[1];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	tx[2] = px[3] * tx[1];
	ty[2] = py[3] * tx[1] + ty[1] * px[3];
	if(tx[2] * sy == ty[2] * sx)
	{
		return 1;
	}
	return 0;
}

int dfs(int depth)
{
	int i;
	if(depth == 4)
	{
		for(i=0; i<4; i++)
		{
			px[i] = nx[list[i]];
			py[i] = ny[list[i]];
		}
		return chk();
	}
	for(i=0; i<4; i++)
	{
		if(!used[i])
		{
			list[depth] = i;
			used[i] = 1;
			if(dfs(depth+1))
			{
				return 1;
			}
			used[i] = 0;
		}
	}
	return 0;
}

int main()
{
	int cas, i;
	cas = 0;
	while(scanf("%d%d", &sx, &sy) == 2)
	{
		if(!sx && !sy)
		{
			break;
		}
		if(sx > (1<<12) || sy > (1<<12))
		{
			while(1);
		}
		if(sx <= 0 || sy <= 0)
		{
			while(1);
		}
		for(i=0; i<4; i++)
		{
			scanf("%d%d", &nx[i], &ny[i]);
			if(nx[i] > (1<<12) || ny[i] > (1<<12))
			{
				while(1);
			}
			if(nx[i] <= 0 || ny[i] <= 0)
			{
				while(1);
			}
		}
		memset(used, 0, sizeof(used));
		if(dfs(0))
		{
			printf("Set %d: Yes\n", ++cas);
		}
		else
		{
			printf("Set %d: No\n", ++cas);
		}
	}
	return 0;
}
