#include <stdio.h>
#include <string.h>

int n, m, o;
int row[35], column[35];
int x1[201], x2[201], y1[201], y2[201];
int aryx[201], aryy[201];
int ary2x[201], ary2y[201];
int putx[35], puty[35];
int chkx[35], chky[35];

int dfsc(int depth)
{
	int i;
	if(depth > m)
	{
		for(i=0; i<o; i++)
		{
			if((row[x1[i]] + aryx[i] == 3 || column[y2[i]] + aryy[i] == 3) && (ary2x[i] == 5 || row[x2[i]] + ary2x[i] == 3 || column[y1[i]] + ary2y[i] == 3))
			{
				return 0;
			}
		}
		return 1;
	}
	if(chky[depth])
	{
		column[depth] = chky[depth];
		if(dfsc(depth+1))
		{
			return 1;
		}
	}
	else
	{
		if(!puty[depth] || puty[depth] & 1)
		{
			column[depth] = 1;
			if(dfsc(depth+1))
			{
				return 1;
			}
		}
		if(puty[depth] && puty[depth] & 2)
		{
			column[depth] = 2;
			if(dfsc(depth+1))
			{
				return 1;
			}
		}
	}
	return 0;
}

int dfsr(int depth)
{
	if(depth > n)
	{
		if(dfsc(1))
		{
			return 1;
		}
		return 0;
	}
	if(chkx[depth])
	{
		row[depth] = chkx[depth];
		if(dfsr(depth+1))
		{
			return 1;
		}
	}
	else
	{
		if(!putx[depth] || putx[depth] & 1)
		{
			row[depth] = 1;
			if(dfsr(depth+1))
			{
				return 1;
			}
		}
		if(putx[depth] && putx[depth] & 2)
		{
			row[depth] = 2;
			if(dfsr(depth+1))
			{
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int count, i, chk, noans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		memset(putx, 0, sizeof(putx));
		memset(puty, 0, sizeof(puty));
		memset(chkx, 0, sizeof(chkx));
		memset(chky, 0, sizeof(chky));
		for(i=0, chk=0, noans=0; i<o; i++)
		{
			scanf("%d%d%d%d", &x1[i], &y1[i], &x2[i], &y2[i]);
			if(!noans)
			{
				if(x1[i] < x2[i])
				{
					aryy[i] = 1;
					puty[y2[i]] |= 1;
				}
				else if(x1[i] == x2[i])
				{
					aryy[i] = 4;
					chk += 1;
				}
				else
				{
					aryy[i] = 2;
					puty[y2[i]] |= 2;
				}
				if(y1[i] < y2[i])
				{
					aryx[i] = 1;
					putx[x1[i]] |= 1;
				}
				else if(y1[i] == y2[i])
				{
					aryx[i] = 4;
					chk += 2;
				}
				else
				{
					aryx[i] = 2;
					putx[x1[i]] |= 2;
				}
				if(chk)
				{
					ary2x[i] = 5;
					if(chk == 1)
					{
						if(chky[y2[i]] && chky[y2[i]] != aryy[i])
						{
							noans=1;
							continue;
						}
						else
						{
							chky[y2[i]] = aryy[i];
						}
					}
					else if(chk == 2)
					{
						if(chkx[x1[i]] && chkx[x1[i]] != aryx[i])
						{
							noans=1;
							continue;
						}
						else
						{
							chkx[x1[i]] = aryx[i];
						}
					}
				}
				else
				{
					if(x1[i] < x2[i])
					{
						ary2y[i] = 1;
						puty[y1[i]] |= 1;
					}
					else if(x1[i] == x2[i])
					{
						ary2y[i] = 4;
					}
					else
					{
						ary2y[i] = 2;
						puty[y1[i]] |= 2;
					}
					if(y1[i] < y2[i])
					{
						ary2x[i] = 1;
						putx[x2[i]] |= 1;
					}
					else if(y1[i] == y2[i])
					{
						ary2x[i] = 4;
					}
					else
					{
						ary2x[i] = 2;
						putx[x2[i]] |= 2;
					}
				}
			}
			chk = 0;
		}
		if(!noans && dfsr(1))
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}
	return 0;
}
