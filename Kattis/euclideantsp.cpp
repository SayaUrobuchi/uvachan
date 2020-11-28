#include <iostream>
#include <cmath>

int n;
double p, s, v;

double calc(double c)
{
    double a, b;
    a = n/p/1e9*pow(log2(n), c*sqrt(2));
    b = s*(1+1.0/c)/v;
    return a+b;
}

int main()
{
    double l, r, m0, m1, t0, t1;
    while (scanf("%d%lf%lf%lf", &n, &p, &s, &v) == 4)
    {
        for (l=1, r=1e3; r-l>1e-9; )
        {
            m0 = l + (r-l)/3;
            m1 = r - (r-l)/3;
            t0 = calc(m0);
            t1 = calc(m1);
            //if (r-l > 1e-2) printf("!? %.10lf %.10lf\n", t0, t1);
            if (t0 <= t1)
            {
                r = m1;
            }
            else
            {
                l = m0;
            }
        }
        printf("%.10lf %.10lf\n", calc((l+r)/2), (l+r)/2);
    }
    return 0;
}
