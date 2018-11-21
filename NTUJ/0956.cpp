#include <stdio.h>
#include <stdlib.h>

int px[300005], py[300005], ptx[300005], pty[300005], pxloc[300005], pyloc[300005];

int xcomp(const void *p, const void *q)
{
	if(px[*(int*)p] != px[*(int*)q])
	{
		return px[*(int*)p] < px[*(int*)q] ? -1 : 1;
	}
	return py[*(int*)p] < py[*(int*)q] ? -1 : 1;
}

int ycomp(const void *p, const void *q)
{
	if(py[*(int*)p] != py[*(int*)q])
	{
		return py[*(int*)p] < py[*(int*)q] ? -1 : 1;
	}
	return px[*(int*)p] < px[*(int*)q] ? -1 : 1;
}

int main()
{
	int count, n, m, i, j, pxnum, pynum, x1, x2, y1, y2, cnt, tx, ty, p, q, c, tar, lside, rside;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			ptx[i] = i;
			pty[i] = i;
		}
		qsort(ptx, n, sizeof(int), xcomp);
		qsort(pty, n, sizeof(int), ycomp);
		pxloc[0] = 0;
		for(i=1, pxnum=1; i<n; i++)
		{
			if(px[ptx[i]] != px[ptx[i-1]])
			{
				pxloc[pxnum++] = i;
			}
		}
		pxloc[pxnum] = n;
		pyloc[0] = 0;
		for(i=1, pynum=1; i<n; i++)
		{
			if(py[pty[i]] != py[pty[i-1]])
			{
				pyloc[pynum++] = i;
			}
		}
		pyloc[pynum] = n;
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			cnt = 0;
			tx = x1;
			for(p=0, q=pxnum-1; p<=q; )
			{
				c = ((p+q)>>1);
				if(px[ptx[pxloc[c]]] == tx)
				{
					break;
				}
				else if(px[ptx[pxloc[c]]] > tx)
				{
					q = c-1;
				}
				else
				{
					p = c+1;
				}
			}
			if(p <= q)
			{
				tar = c;
				for(p=pxloc[tar], q=pxloc[tar+1]-1, lside=2147483647; p<=q; )
				{
					c = ((p+q)>>1);
					if(py[ptx[c]] >= y1)
					{
						lside = c;
						q = c-1;
					}
					else
					{
						p = c+1;
					}
				}
				for(p=pxloc[tar], q=pxloc[tar+1]-1, rside=-2147483647; p<=q; )
				{
					c = ((p+q)>>1);
					if(py[ptx[c]] > y2)
					{
						q = c-1;
					}
					else
					{
						rside = c;
						p = c+1;
					}
				}
				if(lside <= rside)
				{
					cnt += rside - lside + 1;
				}
			}
			tx = x2;
			for(p=0, q=pxnum-1; p<=q; )
			{
				c = ((p+q)>>1);
				if(px[ptx[pxloc[c]]] == tx)
				{
					break;
				}
				else if(px[ptx[pxloc[c]]] > tx)
				{
					q = c-1;
				}
				else
				{
					p = c+1;
				}
			}
			if(p <= q)
			{
				tar = c;
				for(p=pxloc[tar], q=pxloc[tar+1]-1, lside=2147483647; p<=q; )
				{
					c = ((p+q)>>1);
					if(py[ptx[c]] >= y1)
					{
						lside = c;
						q = c-1;
					}
					else
					{
						p = c+1;
					}
				}
				for(p=pxloc[tar], q=pxloc[tar+1]-1, rside=-2147483647; p<=q; )
				{
					c = ((p+q)>>1);
					if(py[ptx[c]] > y2)
					{
						q = c-1;
					}
					else
					{
						rside = c;
						p = c+1;
					}
				}
				if(lside <= rside)
				{
					cnt += rside - lside + 1;
				}
			}
			// ------
			ty = y1;
			for(p=0, q=pynum-1; p<=q; )
			{
				c = ((p+q)>>1);
				if(py[pty[pyloc[c]]] == ty)
				{
					break;
				}
				else if(py[pty[pyloc[c]]] > ty)
				{
					q = c-1;
				}
				else
				{
					p = c+1;
				}
			}
			if(p <= q)
			{
				tar = c;
				for(p=pyloc[tar], q=pyloc[tar+1]-1, lside=2147483647; p<=q; )
				{
					c = ((p+q)>>1);
					if(px[pty[c]] > x1)
					{
						lside = c;
						q = c-1;
					}
					else
					{
						p = c+1;
					}
				}
				for(p=pyloc[tar], q=pyloc[tar+1]-1, rside=-2147483647; p<=q; )
				{
					c = ((p+q)>>1);
					if(px[pty[c]] >= x2)
					{
						q = c-1;
					}
					else
					{
						rside = c;
						p = c+1;
					}
				}
				if(lside <= rside)
				{
					cnt += rside - lside + 1;
				}
			}
			ty = y2;
			for(p=0, q=pynum-1; p<=q; )
			{
				c = ((p+q)>>1);
				if(py[pty[pyloc[c]]] == ty)
				{
					break;
				}
				else if(py[pty[pyloc[c]]] > ty)
				{
					q = c-1;
				}
				else
				{
					p = c+1;
				}
			}
			if(p <= q)
			{
				tar = c;
				for(p=pyloc[tar], q=pyloc[tar+1]-1, lside=2147483647; p<=q; )
				{
					c = ((p+q)>>1);
					if(px[pty[c]] > x1)
					{
						lside = c;
						q = c-1;
					}
					else
					{
						p = c+1;
					}
				}
				for(p=pyloc[tar], q=pyloc[tar+1]-1, rside=-2147483647; p<=q; )
				{
					c = ((p+q)>>1);
					if(px[pty[c]] >= x2)
					{
						q = c-1;
					}
					else
					{
						rside = c;
						p = c+1;
					}
				}
				if(lside <= rside)
				{
					cnt += rside - lside + 1;
				}
			}
			printf("%d\n", cnt);
		}
	}
	return 0;
}
