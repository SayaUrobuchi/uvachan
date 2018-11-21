#include <stdio.h>
#include <math.h>

int n;
double cor[205], str[205];
double a, b;

void gloom()
{
	int ttt[105];
    int i,j,k;
    double t1,t2,t3,tt;
    for(i=0;i<n;i++)
    {
        ttt[i]=i;
    }
    
    for(i=1;i<=n;i++)
    {
        for(j=1;j<n;j++)
        {
            if(cor[ttt[j]]<cor[ttt[j-1]])
            {
                k=ttt[j];
                ttt[j]=ttt[j-1];
                ttt[j-1]=k;
            }
        }
    }
    
    for(i=0;i<n;i++)
    {
        j=ttt[i];
        for(;;)
        {
            k=j-1;
            if(k<0)
            {
                k=n-1;
                
                t1=0;
                t2=10000;
                do
                {
                    t3=(t1+t2)/2;
                    
                    tt=0.5;
                    tt*=t3;
                    tt*=(2*cor[j]+t3*b);
                    
                    if(tt>str[k])
                    {
                        t2=t3;
                    }
                    else
                    {
                        t1=t3;
                    }
                    
                }while(t2-t1>1E-6);
            }
            
            if(cor[j]+t3*b<=cor[k])
            {
                cor[k]=cor[j]+t3*b;
                j=k;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
	int count, i, j, can;
	double sp, dis, p, q, c, t, v, ev, mid, edsp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%lf%lf", &n, &a, &b);
		for(i=0; i<n; i++)
		{
			scanf("%lf", &cor[i]);
		}
		for(i=0; i<n; i++)
		{
			scanf("%lf", &str[i]);
		}
		gloom();
		sp = 0;
		for(i=0, t=0; i<n; i++)
		{
			dis = str[i];
			edsp = cor[(i+1)%n];
			for(p=0, q=dis; p<q; )
			{
				if(q-p < 1e-10)
				{
					break;
				}
				c = (p+q) / 2;
				v = sqrt(sp*sp+2*a*c);
				ev = sqrt(v*v+2*(-b)*(dis-c));
				if(ev <= edsp || fabs(ev-edsp) < 1e-12)
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
