#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k;
	while(scanf("%d %d %d",&a,&b,&c)==3)
	{
		if(a==0&&b==0&&c==0)
		{
			break;
		}
		for(d=0,i=1024,j=1024;a>0;a/=2)
		{
			if(b==i&&c==j)
			{
				d++;
				break;
			}
			if(b>i)
			{
				e=b-i;
				g=1;
			}
			else
			{
				e=i-b;
				g=-1;
			}
			if(c>j)
			{
				f=c-j;
				h=1;
			}
			else
			{
				f=j-c;
				h=-1;
			}
			if(e<=a&&f<=a)
			{
				d++;
			}
			i+=a*g;
			j+=a*h;
		}
		printf("%3d\n",d);
	}
	return 0;
}