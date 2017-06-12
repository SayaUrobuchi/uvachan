#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j,k[10001];
	h=0;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(!a&&!b)
		{
			break;
		}
		for(c=0;c<10001;c++)
		{
			k[c]=0;
		}
		for(a;a>0;a--)
		{
			scanf("%d",&c);
			k[c]++;
		}
		printf("CASE# %d:\n",++h);
		for(a=1;a<10001;a++)
		{
			k[a]+=k[a-1];
		}
		for(b;b>0;b--)
		{
			scanf("%d",&a);
			if(!a)
			{
				if(!k[a])
				{
					printf("%d not found\n",a);
				}
				else
				{
					printf("%d found at 1\n",a);
				}
			}
			else
			{
				if(k[a]==k[a-1])
				{
					printf("%d not found\n",a);
				}
				else
				{
					printf("%d found at %d\n",a,k[a-1]+1);
				}
			}
		}
	}
	return 0;
}
