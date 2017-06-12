#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j,k[1501];
	k[1]=1;
	c=1;
	d=1;
	e=1;
	for(a=2;a<=1500;a++)
	{
		f=k[c]*2;
		g=k[d]*3;
		h=k[e]*5;
		if(f<=g&&f<=h&&k[a-1]!=f)
		{
			k[a]=f;
			c++;
		}
		if(g<=f&&g<=h&&k[a-1]!=g)
		{
			k[a]=g;
			d++;
		}
		if(h<=f&&h<=g&&k[a-1]!=h)
		{
			k[a]=h;
			e++;
		}
		//printf("%d\n",k[a]);
	}
	printf("The 1500'th ugly number is %d.\n",k[1500]);
	//while(1);
    return 0;
}
