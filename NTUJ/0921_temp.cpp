#include <stdio.h>
#include <math.h>

int cor[205], str[205];

int main()
{
	int count, n, i, j, can;
	double a, b, sp, dis, p, q, c, t, rd, tsp, v, ev, mid;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%lf%lf", &n, &a, &b);
		for(i=0; i<n; i++)
		{
			scanf("%d", &cor[i]);
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &str[i]);
		}
		sp = 0;
		for(i=0, t=0; i<n; i++)
		{
			dis = str[i];
			for(p=0, q=dis; p<q; )
			{
				if(q-p < 1e-7)
				{
					break;
				}
				c = (p+q) / 2;
				tsp = sp;
				rd = dis-c;
				for(j=1, can=1; j<=n; j++)
				{
					v = sqrt(tsp*tsp+2*a*c);
					ev = sqrt(v*v+2*(-b)*rd);
					if(ev < 0)
					{
						break;
					}
					if(ev > cor[(i+j)%n])
					{
						can = 0;
						break;
					}
					rd = str[(i+j+1)%n];
					tsp = ev;
				}
				if(can)
				{
					mid = c;
					p = c;
				}
				else
				{
					q = c;
				}
			}
			// S = ut + 0.5at^2
			t += (-sp+sqrt(sp*sp-4*0.5*a*(-mid)))/(2*0.5*a);
			sp = sqrt(sp*sp+2*a*mid);
			dis = dis - mid;
			t += (-sp+sqrt(sp*sp-4*0.5*(-b)*(-dis)))/(2*0.5*(-b));
			sp = sqrt(sp*sp+2*(-b)*dis);
		}
		printf("%.4lf\n", t);
	}
	return 0;
}
