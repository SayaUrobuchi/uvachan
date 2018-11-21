#include<stdio.h>
int main()
{
	int a,b[1000],c,d,e,f;
	while(scanf("%d",&a)==1)
	{
		for(c=0;c<a;c++)
		{
			scanf("%d",&b[c]);
		}
		f=0;
		for(c=0;c<a-1;c++)
		{
			for(d=0;d<a-1;d++)
			{
				if(b[d]>b[d+1])
				{
					e=b[d];
					b[d]=b[d+1];
					b[d+1]=e;
					f++;
				}
			}
			if(f==0)
			{
				break;
			}
		}
		printf("Minimum exchange operations : %d\n",f);
	}
	return 0;
}