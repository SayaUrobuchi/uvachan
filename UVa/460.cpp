#include<stdio.h>
#include<stdlib.h>
int abcc(const void *p,const void *q)
{
	return *(int*)p-*(int*)q;
}
int main()
{
	int a,b,c,d,e,g[4],h,i[4],j[4],k[4],s;
	s=0;
	scanf("%d",&h);
	for(h;h>0;h--)
	{
		if(s)
		{
			printf("\n");
		}
		s=1;
		for(a=0;a<4;a++)
		{
			scanf("%d",&j[a]);
		}
		for(a=0;a<4;a++)
		{
			scanf("%d",&k[a]);
		}
		if(k[2]>j[0]&&j[2]>k[0])
		{
			if(k[3]>j[1]&&j[3]>k[1])
			{
				i[0]=j[0];
				i[1]=j[2];
				i[2]=k[0];
				i[3]=k[2];
				g[0]=j[1];
				g[1]=j[3];
				g[2]=k[1];
				g[3]=k[3];
				qsort(i,4,sizeof(int),abcc);
				qsort(g,4,sizeof(int),abcc);
				printf("%d %d %d %d\n",i[1],g[1],i[2],g[2]);
			}
			else
			{
				printf("No Overlap\n");
			}
		}
		else
		{
			printf("No Overlap\n");
		}
	}
	return 0;
}