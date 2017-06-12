#include<stdio.h>
int main()
{
	unsigned long b,h,a,c,d,f,g;
	scanf("%d",&a);
	for(a;a>0;a--)
	{
		scanf("%d",&b);
		for(f=0;f<1000;f++)
		{
			h=0;
			d=0;
			c=b;
		    for(c;c>0;c/=10)
			{
		    	d++;
			}
			g=b;
		    for(d;d>0;d--)
			{
				h*=10;
				h+=(g%10);
				g/=10;
			}
			if(h==b)
			{
				if(b<5)
				{
					printf("%lu %lu\n",f+1,h*2);
					break;
				}
				else if(f==0)
				{
					b+=h;
				}
				else
				{
				    printf("%lu %lu\n",f,h);
				    break;
				}
			}
			else
			{
				b+=h;
			}
		}
	}
	return 0;
}
