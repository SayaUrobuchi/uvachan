#include <stdio.h>
#include <math.h>

#define tmt 10000
#define MD 10000000

int ary[15];
long long px[15][15], py[15][15];

long long get_dis(long long x, long long y)
{
	return x*x+y*y;
}

int equals(double p, double q)
{
	return fabs(p-q)<1e-5;
}

long long gcd(long long p, long long q)
{
	while((p%=q)&&(q%=p));
	return p+q;
}

double get_ang(double ax, double ay, double bx, double by, double cx, double cy)
{
    double p,q;
    double x1,x2,pi=acos(-1.0);
    
    p=ax-bx;
    q=ay-by;
    
    if(p<1E-8 && p>-1E-8)
    {
        if(q>0)
        {
            x1=90;
        }
        else
        {
            x1=-90;
        }
    }
    else
    {
        x1=atan(q/p);
        x1*=(180.0/pi);
    }
    
    if(p<0)
    {
        x1+=180;
    }
    else 
    {
        if(q<0)
        {
            x1+=360;
        }
    }
    
    p=cx-bx;
    q=cy-by;
    if(p<1E-8 && p>-1E-8)
    {
        if(q>0)
        {
            x2=90;
        }
        else
        {
            x2=-90;
        }
    }
    else
    {
        x2=atan(q/p);
        x2*=(180.0/pi);
    }
    
    if(p<0)
    {
        x2+=180;
    }
    else 
    {
        if(q<0)
        {
            x2+=360;
        }
    }

    x2-=x1;
    if(x2<0)
    {
        x2+=360;
    }
    
    return x2;
}

int main()
{
	int n, m, i, j, k, l, p, cnt, flag;
	double rat, t, crat, ang;
	long long dd, tt, gg, lr, rr;
	/*while(scanf("%d%d%d%d%d%d", &n, &m, &i, &j, &k, &l) == 6)
	{
		printf("%lf\n", get_ang(n, m, i, j, k, l));
	}*/
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%lf%lf", &t, &rat);
				px[i][j] = (int)(t*tmt+1e-6);
				py[i][j] = (int)(rat*tmt+1e-6);
			}
		}
		for(i=0; i<n; i++)
		{
			ary[0] = i+1;
			for(j=i+1, cnt=1; j<n; j++)
			{
				for(k=0; k<m; k++)
				{
					for(l=0; l<m; l++)
					{
						for(p=0; p<m; p++)
						{
							dd = get_dis(px[i][(k+p+1)%m]-px[i][(k+p)%m], py[i][(k+p+1)%m]-py[i][(k+p)%m]);
							tt = get_dis(px[j][(l+p+1)%m]-px[j][(l+p)%m], py[j][(l+p+1)%m]-py[j][(l+p)%m]);
							//if(i==0&&j<3)printf("ohoh %d %d: %lf %lf! rat: %lf/%lf\n", j, p, rat, t, crat, rat/t);
							gg = gcd(dd, tt);
							if(p == 0)
							{
								lr = tt/gg;
								rr = dd/gg;
							}
							else
							{
								if(((dd%MD)*lr)%MD != ((tt%MD)*rr)%MD || ((dd/MD)*lr)+((dd%MD)*lr)/MD != ((tt/MD)*rr)+((tt%MD)*rr)/MD)
								//if(dd*lr != tt*rr)
								{
									break;
								}
							}
							ang = get_ang(px[i][(k+p)%m], py[i][(k+p)%m], px[i][(k+p+1)%m], py[i][(k+p+1)%m], px[i][(k+p+2)%m], py[i][(k+p+2)%m]);
							t = get_ang(px[j][(l+p)%m], py[j][(l+p)%m], px[j][(l+p+1)%m], py[j][(l+p+1)%m], px[j][(l+p+2)%m], py[j][(l+p+2)%m]);
							//if(i==0&&j<3)printf("%lf %lf %lf %lf %lf %lf: %lf\n", px[i][(k+p)%m], py[i][(k+p)%m], px[i][(k+p+1)%m], py[i][(k+p+1)%m], px[i][(k+p+2)%m], py[i][(k+p+2)%m], ang);
							//if(i==0&&j<3)printf("YOOO %lf %lf! flag:%d\n", ang, t, flag);
							if(p == 0)
							{
								if(equals(ang, t))
								{
									flag = 0;
								}
								else if(equals(ang, 360-t))
								{
									flag = 1;
								}
								else
								{
									break;
								}
							}
							else
							{
								if(flag == 0 && equals(ang, t))
								{
								}
								else if(flag == 1 && equals(ang, 360-t))
								{
								}
								else
								{
									break;
								}
							}
						}
						if(p >= m)
						{
							//printf("!\n");
							break;
						}
						for(p=0; p<m; p++)
						{
							dd = get_dis(px[i][(k+m+m-(p+1))%m]-px[i][(k+m-p)%m], py[i][(k+m+m-(p+1))%m]-py[i][(k+m-p)%m]);
							tt = get_dis(px[j][(l+p+1)%m]-px[j][(l+p)%m], py[j][(l+p+1)%m]-py[j][(l+p)%m]);
							//if(i==0&&j<3)printf("ohoh %d %d: %lf %lf! rat: %lf/%lf\n", j, p, rat, t, crat, rat/t);
							gg = gcd(dd, tt);
							if(p == 0)
							{
								lr = tt/gg;
								rr = dd/gg;
							}
							else
							{
								if(((dd%MD)*lr)%MD != ((tt%MD)*rr)%MD || ((dd/MD)*lr)+((dd%MD)*lr)/MD != ((tt/MD)*rr)+((tt%MD)*rr)/MD)
								//if(dd*lr != tt*rr)
								{
									break;
								}
							}
							ang = get_ang(px[i][(k+m-p)%m], py[i][(k+m-p)%m], px[i][(k+m+m-(p+1))%m], py[i][(k+m+m-(p+1))%m], px[i][(k+m+m-(p+2))%m], py[i][(k+m+m-(p+2))%m]);
							t = get_ang(px[j][(l+p)%m], py[j][(l+p)%m], px[j][(l+p+1)%m], py[j][(l+p+1)%m], px[j][(l+p+2)%m], py[j][(l+p+2)%m]);
							//if(i==0&&j<3)printf("%lf %lf %lf %lf %lf %lf: %lf\n", px[i][(k+p)%m], py[i][(k+p)%m], px[i][(k+p+1)%m], py[i][(k+p+1)%m], px[i][(k+p+2)%m], py[i][(k+p+2)%m], ang);
							//if(i==0&&j<3)printf("YOOO %lf %lf! flag:%d\n", ang, t, flag);
							if(p == 0)
							{
								if(equals(ang, t))
								{
									flag = 0;
								}
								else if(equals(ang, 360-t))
								{
									flag = 1;
								}
								else
								{
									break;
								}
							}
							else
							{
								if(flag == 0 && equals(ang, t))
								{
								}
								else if(flag == 1 && equals(ang, 360-t))
								{
								}
								else
								{
									break;
								}
							}
						}
						if(p >= m)
						{
							//printf("!\n");
							break;
						}
					}
					if(l < m)
					{
						break;
					}
				}
				if(k < m)
				{
					ary[cnt++] = j+1;
				}
			}
			if(cnt > 1)
			{
				break;
			}
		}
		if(cnt <= 1)
		{
			printf("0\n0\n");
		}
		else
		{
			printf("%d\n", cnt);
			printf("%d", ary[0]);
			for(i=1; i<cnt; i++)
			{
				printf(" %d", ary[i]);
			}
			printf("\n");
		}
	}
	return 0;
}
