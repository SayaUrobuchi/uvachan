#include<stdio.h>
int main()
{
    int a,b,c,d,e[100001],f,g;
    for(a=0;a<100000;a++)
	{
		e[a]=0;
	}
	e[1]=2;
	e[2]=3;
	a=6;
	f=3;
	for(d=433236;d>0;a+=6,d-=2)
	{
		a--;
		for(c=1;e[c]*e[c]<=a;c++)
		{
			if(e[c]==0)
			{
				break;
			}
			else
			{
			    b=a%e[c];
			    if(b==0)
				{
			    	break;
				}
			}
		}
		if(b!=0)
		{
			e[f]=a;
			f++;
		}
		a+=2;
        for(c=1;e[c]*e[c]<=a;c++)
		{
			if(e[c]==0)
			{
				b=c;
				break;
			}
			else
			{
			    b=a%e[c];
			    if(b==0)
				{
			    	break;
				}
			}
		}
		if(b!=0)
		{
			e[f]=a;
			f++;
		}
		a--;
	}
    while(scanf("%d",&d)==1)
    {
        for(a=0,b=100000,c=50000,f=0;;c=(a+b)/2)
        {
            if(d==e[c])
            {
                f++;
                break;
            }
            else if(d>e[c]&&a!=c)
            {
                a=c;
            }
            else if(d<e[c]&&a!=c)
            {
                b=c;
            }
            else if(a==c)
            {
                break;
            }
        }
        if(f==0)
        {
            printf("%d is not prime.\n",d);
        }
        else
        {
            g=d;
            for(c=d%10,d/=10;d>0;d/=10)
            {
                c*=10;
                c+=d%10;
            }
            d=c;
            for(a=0,b=100000,c=50000,f=0;;c=(a+b)/2)
            {
                if(d==e[c])
                {
                    f++;
                    break;
                }
                else if(d>e[c]&&a!=c)
                {
                    a=c;
                }
                else if(d<e[c]&&a!=c)
                {
                    b=c;
                }
                else if(a==c)
                {
                    break;
                }
            }
            if(f==0||g==d)
            {
                printf("%d is prime.\n",g);
            }
            else
            {
                printf("%d is emirp.\n",g);
            }
        }
   	}
	return 0;
}
