#include <stdio.h>
#include <string.h>
bool x[605][605];
char str[605][605];
int main()
{
	int a,b,c,d,e,f,g,h,len;
	unsigned long int ans[605],ans1[605],answer;
	while(scanf("%d %d %d",&a,&b,&c)==3)
	{
		if(a==0 && (b==0 && c==0))
		{
			break;
		}
		for(d=1;d<=c;d++)
		{
			scanf("%s",&str[d]);
		}
		if(b==0)
		{
			printf("1\n");
			continue;
		}
		len=strlen(str[1]);
		if(len>b)
		{
			printf("0\n");
			continue;
		}
		for(d=1;d<=c;d++)
		{
			for(e=1;e<=c;e++)
			{
				for(f=0;f<len-1;f++)
				{
					if(str[e][f]!=str[d][f+1])
					{
						x[d][e]=0;
						goto next;
					}
				}
				x[d][e]=1;
				next:;
			}
		}
		for(d=1;d<=c;d++)
		{
			ans[d]=1;
			ans1[d]=0;
		}
		for(d=len+1;d<=b;d++)
		{
			for(e=1;e<=c;e++)
			{
				for(f=1;f<=c;f++)
				{
					if(x[f][e]==1)
					{
						ans1[e]+=ans[f];
					}
				}
			}
			for(e=1;e<=c;e++)
			{
				ans[e]=ans1[e];
				ans1[e]=0;
			}
		}
		answer=0;
		for(d=1;d<=c;d++)
		{
			answer+=ans[d];
		}
		printf("%lu\n",answer);
	}
	return 0;
}
