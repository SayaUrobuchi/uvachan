#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e[5500],f,g[3505];
    for(a=0;a<3550;a++)
	{
		e[a]=0;
	}
	e[1]=2;
	e[2]=3;
	a=6;
	f=3;
	for(d=11000;d>0;a+=6,d-=2)
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
        if(d==0)
        {
            break;
        }
        for(b=0;b<3505;b++)
        {
            g[b]=0;
        }
    	for(b=1,c=1;b<d;b++)
    	{
    	    for(f=0;f<e[b];f++,c++)
    	    {
    	        if(c==d+1)
    	        {
    	            c=1;
    	        }
    	        if(g[c]!=0)
    	        {
    	            f--;
    	        }
    	    }
    	    g[c-1]=1;
    	    //printf("%d %d  ",c-1,e[b]);
    	}
    	for(b=1;b<d+1;b++)
    	{
    	    if(g[b]==0)
    	    {
    	        printf("%d\n",b);
    	        break;
    	    }
    	}
   	}
    return 0;
}
