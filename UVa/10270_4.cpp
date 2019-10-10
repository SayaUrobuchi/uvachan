#include <stdio.h>

const int N = 64;
const int PN = 14;

int px[N], py[N], ps[N];

int gcd(int p, int q)
{
	while ((p%=q) && (q%=p));
	return p+q;
}

int recurs(int x, int y, int width, int height, int sc)
{
	while (width != height)
	{
		while (width < height)
		{
			height -= width;
			px[sc] = x;
			py[sc] = y + height;
			ps[sc] = width;
			sc++;
		}
		while (width > height)
		{
			width -= height;
			px[sc] = x + width;
			py[sc] = y;
			ps[sc] = height;
			sc++;
		}
	}
	if (width)
	{
		px[sc] = x;
		py[sc] = y;
		ps[sc] = width;
		sc++;
	}
	return sc;
}

int recursEX(int x, int y, int width, int height, int sc)
{
	int i, j, k, w, mv, mv2, tc, ttt;
	int tx[N], ty[N], ts[N];
	int tx2[N], ty2[N], ts2[N];
	while (width != height)
	{
		while (width < height)
		{
			height -= width;
			px[sc] = x;
			py[sc] = y + height;
			ps[sc] = width;
			sc++;
		}
		while (width > height)
		{
			width -= height;
			px[sc] = x + width;
			py[sc] = y;
			ps[sc] = height;
			sc++;
		}
	}
	if (width == 1 && height == 1)
	{
		return sc;
	}
	mv = 1048576;
	for (i=width-1; i+i>width-1; i--)
	{
		w = width - i;
		tc = sc;
		px[tc] = x + w;
		py[tc] = y;
		ps[tc] = i;
		tc++;
		/*tc = recurs(x, y+height-w, width, w, tc);
		tc = recursEX(x, y, w, height-w, tc);*/
		ttt = recurs(x+w, y+height-w, i, w, tc);
		mv2 = 1048576;
		for (j=1; j<=w; j++)
		{
			tc = ttt;
			tc = recursEX(x, y, w, j, tc);
			tc = recurs(x, y+j, w, height-j, tc);
			if (tc < mv2)
			{
				mv2 = tc;
				for (k=sc+1; k<tc; k++)
				{
					tx2[k] = px[k];
					ty2[k] = py[k];
					ts2[k] = ps[k];
				}
			}
		}
		for (j=sc+1; j<mv2; j++)
		{
			px[j] = tx2[j];
			py[j] = ty2[j];
			ps[j] = ts2[j];
		}
		tc = mv2;
		if (tc < mv)
		{
			mv = tc;
			for (j=sc; j<tc; j++)
			{
				tx[j] = px[j];
				ty[j] = py[j];
				ts[j] = ps[j];
			}
		}
	}
	for (i=sc; i<mv; i++)
	{
		px[i] = tx[i];
		py[i] = ty[i];
		ps[i] = ts[i];
	}
	return mv;
}

int main()
{
	int count, i, n, t, cc, gc;
	/*freopen("2.txt", "w", stdout);*/
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		if(n & 1)
		{
			for (i=((n+1)>>1), gc=1; i<n; i++)
			{
				t = gcd(i, n-i);
				if (t > gc)
				{
					gc = t;
				}
			}
			n /= gc;
			t = (n >> 1);
			px[0] = 1;
			py[0] = 1;
			ps[0] = t+1;
			cc = 1;
			if (n > 1)
			{
				px[1] = 1;
				py[1] = t+2;
				ps[1] = t;
				px[2] = t+2;
				py[2] = 1;
				ps[2] = t;
				cc = recursEX(1+t, 1+t, n-t, n-t, 3);
			}
			//printf("%d: ", n);
			printf("%d\n", cc);
			for (i=0; i<cc; i++)
			{
				px[i] = (px[i]-1) * gc + 1;
				py[i] = (py[i]-1) * gc + 1;
				ps[i] *= gc;
				printf("%d %d %d\n", px[i], py[i], ps[i]);
			}
			#ifndef ONLINE_JUDGE
			char board[N+1][N+1];
			for (i=0; i<cc; i++)
			{
				for (int j=px[i]; j<px[i]+ps[i]; j++)
				{
					for (int k=py[i]; k<py[i]+ps[i]; k++)
					{
						board[j][k] = (i<10?i+'0':i-10+'A');
					}
				}
			}
			for (i=1; i<=n*gc; i++)
			{
				for (int j=1; j<=n*gc; j++)
				{
					printf("%c", board[i][j]);
				}
				puts("");
			}
			#endif
		}
		else
		{
			n >>= 1;
			printf("4\n");
			printf("%d %d %d\n", 1, 1, n);
			printf("%d %d %d\n", 1, n+1, n);
			printf("%d %d %d\n", n+1, 1, n);
			printf("%d %d %d\n", n+1, n+1, n);
		}
	}
	return 0;
}
