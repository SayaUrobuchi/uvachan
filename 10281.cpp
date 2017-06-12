#include<stdio.h>
int main()
{
	int a,b,c,d,f,g,h,j,k;
	double e,i;
	char x,y,z;
	i=0;
	j=1;
	k=0;
	while(scanf("%d%c%d%c%d%c",&a,&x,&b,&y,&c,&z)==6)
	{
		if(z==10)
		{
			d=a*3600+b*60+c;
			d-=j;
			e=d*k/3600.0;
			e+=i;
			printf("%02d:%02d:%02d %.2f km\n",a,b,c,e);
		}
		else
		{
			d=a*3600+b*60+c;
			f=d-j;
			i+=f*k/3600.0;
			j=d;
			scanf("%d",&k);
		}
	}
	return 0;
}