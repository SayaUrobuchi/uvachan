#include<stdio.h>
#include<stdlib.h>
struct wood
{
	int len[3];
};
int comp(const void *p,const void *q)
{
	return (*(wood*)q).len[0]-(*(wood*)p).len[0];
}
int main()
{
	int n,lis[91][3],i,j,cas,count,max,tmp;
	cas=0;
	wood ary[91];
	while(scanf("%d",&n)==1)
	{
		if(!n)
		{
			break;
		}
		for(i=0;n>0;n--)
		{
			scanf("%d%d%d",&ary[i].len[0],&ary[i].len[1],&ary[i].len[2]);
			if(ary[i].len[0]<ary[i].len[1])
			{
				j=ary[i].len[0];
				ary[i].len[0]=ary[i].len[1];
				ary[i].len[1]=j;
			}
			i++;
			ary[i].len[2]=ary[i-1].len[0];
			ary[i].len[0]=ary[i-1].len[1];
			ary[i].len[1]=ary[i-1].len[2];
			if(ary[i].len[0]<ary[i].len[1])
			{
				j=ary[i].len[0];
				ary[i].len[0]=ary[i].len[1];
				ary[i].len[1]=j;
			}
			i++;
			ary[i].len[2]=ary[i-2].len[1];
			ary[i].len[0]=ary[i-2].len[0];
			ary[i].len[1]=ary[i-2].len[2];
			if(ary[i].len[0]<ary[i].len[1])
			{
				j=ary[i].len[0];
				ary[i].len[0]=ary[i].len[1];
				ary[i].len[1]=j;
			}
			i++;
		}
		count=i;
		qsort(ary,count,sizeof(wood),comp);
		for(i=0,max=0;i<count;i++)
		{
			for(j=i-1,tmp=ary[i].len[2];j>-1;j--)
			{
				if(lis[j][0]>ary[i].len[0])
				{
					if(lis[j][1]>ary[i].len[1])
					{
						if(lis[j][2]+ary[i].len[2]>tmp)
						{
							tmp=lis[j][2]+ary[i].len[2];
						}
					}
				}
			}
			if(tmp>max)
			{
				max=tmp;
			}
			lis[i][0]=ary[i].len[0];
			lis[i][1]=ary[i].len[1];
			lis[i][2]=tmp;
		}
		printf("Case %d: maximum height = %d\n",++cas,max);
	}
	return 0;
}