#include<stdio.h>
#include<string.h>
int main()
{
	char k[20],x;
	int a,b,c,d,e,f,g,h,i[26],j;
	while(scanf("%d%c",&a,&x)==2)
	{
		if(a==-1)
		{
			break;
		}
		for(b=0;b<26;b++)
		{
			i[b]=0;
		}
		gets(k);
		b=strlen(k);
		for(c=0,d=0;c<b;c++)
		{
			e=k[c]-97;
			if(i[e]!=1)
			{
				i[e]=1;
				d++;
			}
		}
		b=d;
		gets(k);
		e=strlen(k);
		for(c=0,f=0;c<e;c++)
		{
			d=k[c]-97;
			if(i[d]==1)
			{
				i[d]=-1;
				b--;
			}
			else if(i[d]==0)
			{
				i[d]=-1;
				f++;
				if(f==7)
				{
					break;
				}
			}
		}
		printf("Round %d\n",a);
		if(f==7)
		{
			printf("You lose.\n");
		}
		else
		{
			if(b==0)
			{
				printf("You win.\n");
			}
			else
			{
				printf("You chickened out.\n");
			}
		}
	}
	return 0;
}