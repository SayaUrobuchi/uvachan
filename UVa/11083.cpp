#include<stdio.h>
#include<math.h>
int main()
{
    int b,f,g,h,j,k;
    unsigned int a,c;
    long long d,e,i;
    while(scanf("%lu%d",&a,&b)==2)
    {
        if(!a&&!b)
        {
            break;
        }
        if(a<2)
        {
            printf("0\n");
            continue;
        }
        f=sqrt(b)+1;
		if(!(b%2))
        {
            e=2;
            b/=2;
        }
        for(c=3;c<f;c+=2)
        {
            if(!(b%c))
            {
                e=c;
                b/=c;
            }
        }
        if(b>1)
        {
            e=b;
        }
		f=e;
		for(i=0;e<=a;e*=f)
		{
	        c=a/e-1;
			d=c;
			d*=c+1;
			d/=2;
			i+=d*e;
			d=a%e+1;
			i+=d*c+d;
		}
        printf("%lld\n",i);
    }
    return 0;
}