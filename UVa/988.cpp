#include<stdio.h>
int a,b,c,d,e,f,g,h,i,j,k[50][51],l[50],m[50];
int main()
{
	char check;
	check = 0;
	while(scanf("%d",&a)==1)
	{
		if(check) printf("\n");
		check = 1;
		for(b=0;b<a;b++)
		{
			l[b]=0;
			m[b]=0;
		}
		l[0]=1;
		for(b=0;b<a;b++)
		{
			scanf("%d",&k[b][0]);
			k[b][0]++;
			for(c=1;c<k[b][0];c++)
			{
				scanf("%d",&k[b][c]);
				m[k[b][c]]++;
			}
		}
		while(1)
		{
			for(b=0;b<a;b++)
			{
				if(!m[b])
				{
					for(c=1;c<k[b][0];c++)
					{
						l[k[b][c]]+=l[b];
						m[k[b][c]]--;
					}
					m[b]=-1;
					break;
				}
			}
			if(b==a)
			{
				break;
			}
		}
		for(b=0,i=0;b<a;b++)
		{
			if(k[b][0]==1)
			{
				i+=l[b];
			}
		}
		printf("%d\n",i);
	}
	return 0;
}
