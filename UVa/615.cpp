#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j[100],k[100];
	h=0;
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a==-1&&b==-1)
		{
			break;
		}
		if(!a&&!b)
		{
			printf("Case %d is a tree.\n",++h);
			continue;
		}
		e=0;
		if(a==b)
		{
			e=1;
		}
		j[1]=a;
		k[1]=0;
		j[2]=b;
		k[2]=1;
		c=3;
		while(scanf("%d%d",&a,&b)==2)
		{
			if(!a&&!b)
			{
				break;
			}
			if(a==b)
			{
				e=1;
			}
			if(e)
			{
				continue;
			}
			for(d=1;d<c;d++)
			{
				if(j[d]==a)
				{
					break;
				}
			}
			if(d==c)
			{
				j[c]=a;
				k[c++]=0;
			}
			for(f=1;f<c;f++)
			{
				if(j[f]==b)
				{
					if(k[f])
					{
						e=1;
						break;
					}
					else
					{
						k[f]=d;
					}
				}
			}
			if(f==c)
			{
				j[c]=b;
				k[c++]=d;
			}
		}
		if(e)
		{
			printf("Case %d is not a tree.\n",++h);
		}
		else
		{
			for(a=1,b=0;a<c;a++)
			{
				if(!k[a])
				{
					if(b)
					{
						e=1;
						break;
					}
					else
					{
						b=a;
					}
				}
			}
			if(e||!b)
			{
				printf("Case %d is not a tree.\n",++h);
			}
			else
			{
				for(a=1;a<c;a++)
				{
					j[a]=0;
				}
				a--;
				j[b]=1;
				while(--a)
				{
					j[b]++;
					for(d=1;d<c;d++)
					{
						if(k[d]==b)
						{
							if(!j[d])
							{
								j[d]=1;
							}
						}
					}
					for(d=1;d<c;d++)
					{
						if(j[d]==1)
						{
							b=d;
							break;
						}
					}
				}
				for(a=1;a<c;a++)
				{
					if(!j[a])
					{
						e=1;
						break;
					}
				}
				if(e)
				{
					printf("Case %d is not a tree.\n",++h);
				}
				else
				{
					printf("Case %d is a tree.\n",++h);
				}
			}
		}
	}
	return 0;
}