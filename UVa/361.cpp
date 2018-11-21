#include <stdio.h>

int cx[205], cy[205];
int rx[205], ry[205];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int range(int b1, int b2, int target)
{
	return target >= min(b1, b2) && target <= max(b1, b2);
}

int cross(int x1, int x2, int y1, int y2)
{
	return x1*y2 - x2*y1;
}

int main()
{
	int cas, c, r, o, i, j, k, l, x, y, tx, ty;
	long long p, q;
	cas = 0;
	while(scanf("%d%d%d", &c, &r, &o) == 3)
	{
		if(!c && !r && !o)
		{
			break;
		}
		for(i=0; i<c; i++)
		{
			scanf("%d%d", &cx[i], &cy[i]);
			cx[i] *= 3;
			cy[i] *= 3;
		}
		for(i=0; i<r; i++)
		{
			scanf("%d%d", &rx[i], &ry[i]);
			rx[i] *= 3;
			ry[i] *= 3;
		}
		printf("Data set %d:\n", ++cas);
		while(o--)
		{
			scanf("%d%d", &x, &y);
			x *= 3;
			y *= 3;
			for(i=0; i<c; i++)
			{
				for(j=i+1; j<c; j++)
				{
					for(k=j+1; k<c; k++)
					{
						tx = cx[i] + cx[j] + cx[k];
						tx /= 3;
						ty = cy[i] + cy[j] + cy[k];
						ty /= 3;
						l = 0;
						p = cross(cx[i]-cx[j], cx[i]-x, cy[i]-cy[j], cy[i]-y);
						q = cross(cx[i]-cx[j], cx[i]-tx, cy[i]-cy[j], cy[i]-ty);
						if(!p && range(cx[i], cx[j], x) && range(cy[i], cy[j], y))
						{
							break;
						}
						l += (p*q > 0);
						p = cross(cx[i]-cx[k], cx[i]-x, cy[i]-cy[k], cy[i]-y);
						q = cross(cx[i]-cx[k], cx[i]-tx, cy[i]-cy[k], cy[i]-ty);
						if(!p && range(cx[i], cx[k], x) && range(cy[i], cy[k], y))
						{
							break;
						}
						l += (p*q > 0);
						p = cross(cx[k]-cx[j], cx[k]-x, cy[k]-cy[j], cy[k]-y);
						q = cross(cx[k]-cx[j], cx[k]-tx, cy[k]-cy[j], cy[k]-ty);
						if(!p && range(cx[k], cx[j], x) && range(cy[k], cy[j], y))
						{
							break;
						}
						l += (p*q > 0);
						if(l == 3)
						{
							break;
						}
					}
					if(k < c)
					{
						break;
					}
				}
				if(j < c)
				{
					break;
				}
			}
			if(i < c)
			{
				printf("     Citizen at (%d,%d) is safe.\n", x/3, y/3);
			}
			else
			{
				for(i=0; i<r; i++)
				{
					for(j=i+1; j<r; j++)
					{
						for(k=j+1; k<r; k++)
						{
							tx = rx[i] + rx[j] + rx[k];
							tx /= 3;
							ty = ry[i] + ry[j] + ry[k];
							ty /= 3;
							l = 0;
							p = cross(rx[i]-rx[j], rx[i]-x, ry[i]-ry[j], ry[i]-y);
							q = cross(rx[i]-rx[j], rx[i]-tx, ry[i]-ry[j], ry[i]-ty);
							if(!p && range(rx[i], rx[j], x) && range(ry[i], ry[j], y))
							{
								break;
							}
							l += (p*q > 0);
							p = cross(rx[i]-rx[k], rx[i]-x, ry[i]-ry[k], ry[i]-y);
							q = cross(rx[i]-rx[k], rx[i]-tx, ry[i]-ry[k], ry[i]-ty);
							if(!p && range(rx[i], rx[k], x) && range(ry[i], ry[k], y))
							{
								break;
							}
							l += (p*q > 0);
							p = cross(rx[k]-rx[j], rx[k]-x, ry[k]-ry[j], ry[k]-y);
							q = cross(rx[k]-rx[j], rx[k]-tx, ry[k]-ry[j], ry[k]-ty);
							if(!p && range(rx[k], rx[j], x) && range(ry[k], ry[j], y))
							{
								break;
							}
							l += (p*q > 0);
							if(l == 3)
							{
								break;
							}
						}
						if(k < r)
						{
							break;
						}
					}
					if(j < r)
					{
						break;
					}
				}
				if(i < r)
				{
					printf("     Citizen at (%d,%d) is robbed.\n", x/3, y/3);
				}
				else
				{
					printf("     Citizen at (%d,%d) is neither.\n", x/3, y/3);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
