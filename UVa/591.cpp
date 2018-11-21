#include<stdio.h>
int main()
{
	int a[50],b,c,d=0,e=0;
	while(scanf("%d",&b)==1)
	{
	    if(b==0)
	    {
	        break;
	    }
		e++;
		for(c=0;c<b;c++)
		{
			scanf("%d",&a[c]);
		}
		for(b;b>0;b--)
		{
			d+=a[b-1];
		}
		b=0;
		d/=c;
		for(c;c>0;c--)
		{
		    a[c-1]-=d;
		    if(a[c-1]<0)
		    {
		        a[c-1]*=-1;
		    }
			b+=a[c-1];
		}
		b/=2;
		d=0;
		printf("Set #%d\nThe minimum number of moves is %d.\n\n",e,b);
	}
	return 0;
}
