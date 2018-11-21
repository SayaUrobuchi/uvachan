#include<stdio.h>
int main()
{
	int a[256],b[256];
	char c, check;
	int d,e=0,f,g;
	for(d=0;d<256;d++)
	{
		a[d]=0;
	}
	check = 0;
	while(scanf("%c",&c)==1)
	{
		if(c==10)
		{
			for(d=0;d<256;d++)
			{
				if(a[d]!=0)
				{
					b[e]=d;
					e++;
				}
			}
			b[e]=0;
			for(d=0;b[d]!=0;d++)
			{
				g=e;
				for(e;e>1;e--)
				{
					if(a[b[e-1]]>a[b[e-2]])
					{
						f=b[e-1];
						b[e-1]=b[e-2];
						b[e-2]=f;
					}
				}
				e=g;
			}
			if(check) printf("\n");
			check = 1;
			for(d;d>0;d--)
			{
				printf("%d %d\n",b[d-1],a[b[d-1]]);
				a[b[d-1]]=0;
			}
			e=0;
		}
		else
		{
			a[c]++;
		}
	}
	return 0;
}
