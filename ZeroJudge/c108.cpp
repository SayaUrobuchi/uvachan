#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	bool k[27];
	int x[14];
	/*x[1]=2;
	x[2]=7;
	x[3]=5;
	x[4]=30;
	x[5]=169;
	x[6]=441;
	x[7]=1872;
	x[8]=7632;
	x[9]=1740;
	x[10]=93313;
	x[11]=459901;
	x[12]=1358657;
	x[13]=2504881;*/
	for(a=1;a<14;a++)
	{
		b=a*2;
		for(c=1;c<=a;c++)
		{
			k[c]=1;
		}
		for(c=a+1;;c++)
		{
			if(c%b==1)
			{
				c+=a;
			}
			for(d=a+1;d<=b;d++)
			{
				k[d]=1;
			}
			for(d=b,g=1;d>a;d--)
			{
				e=c%d;
				if(e==0)
				{
					e=d;
				}
				for(f=0;;g++)
				{
					if(g>b)
					{
						g=1;
					}
					f+=k[g];
					if(f==e)
					{
						break;
					}
				}
				if(g<=a)
				{
					break;
				}
				k[g]=0;
			}
			if(d==a)
			{
				x[a]=c;
				break;
			}
		}
	}
	while(scanf("%d",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		printf("%d\n",x[a]);
	}
	return 0;
}
