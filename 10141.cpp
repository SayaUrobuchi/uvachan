#include<stdio.h>
#include<string.h>
int main()
{
	double x,y;
	char i[90],j[90],k[90];
	int a,b,c,d,e,f,g;
	g=0;
	while(scanf("%d %d",&a,&b)==2)
	{
		if(a==0&&b==0)
		{
			break;
		}
		g++;
		gets(k);
		f=0;
		for(c=0;c<a;c++)
		{
			gets(k);
		}
		for(c=0;c<b;c++)
		{
			gets(i);
			scanf("%lf %d",&x,&d);
			if(d>f)
			{
				f=d;
				strcpy(j,i);
				y=x;
			}
			else if(d==f)
			{
				if(x<y)
				{
					y=x;
					strcpy(j,i);
				}
			}
			gets(k);
			for(d;d>0;d--)
			{
				gets(k);
			}
		}
		if(g>1)
		{
			printf("\n");
		}
		printf("RFP #%d\n",g);
		printf("%s\n",j);
	}
}