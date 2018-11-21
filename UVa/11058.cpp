#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,j[123][101];
	char i[123],k[101],x[2],y[2];
	h=0;
	while(gets(k))
	{
		for(a=97;a<123;a++)
		{
			j[a][0]=1;
		}
		a=strlen(k);
		for(b=0;b<a;b++)
		{
			j[k[b]][j[k[b]][0]]=b;
			j[k[b]][0]++;
		}
		for(b=97;b<123;b++)
		{
			scanf("%s",&x);
			i[b]=x[0];
		}
		x[a]='\0';
		for(b=97;b<123;b++)
		{
			for(c=j[b][0]-1;c>0;c--)
			{
				k[j[b][c]]=i[b];
			}
		}
		scanf("%d",&g);
		for(g;g>0;g--)
		{
			scanf("%d%s%s",&b,&x,&y);
			for(c=j[x[0]][0]-1;c>0;c--)
			{
				if(j[x[0]][c]<b)
				{
					break;
				}
				k[j[x[0]][c]]=y[0];
			}
		}
		printf("Case #%d: The encoding string is %s.\n\n",++h,k);
		gets(k);
		gets(k);
	}
	return 0;
}
