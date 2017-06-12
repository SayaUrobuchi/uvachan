#include<stdio.h>
#include<string.h>
char str[10][10],ans[10][200],tmp[2];
int main()
{
	int i,j,a,f,count;
	tmp[0]=10;
	tmp[1]=0;
	for(i=1;i<10;i++)
	{
		ans[i][0]=0;
		for(j=0;j<i;j++)
		{
			str[i][j]=i+48;
		}
		str[i][j]=0;
		for(j=1;j<i;j++)
		{
			strcat(ans[i],str[j]);
			strcat(ans[i],tmp);
		}
		for(j;j>0;j--)
		{
			strcat(ans[i],str[j]);
			strcat(ans[i],tmp);
		}
	}
	scanf("%d",&count);
	while(count--)
	{
		scanf("%d%d",&a,&f);
		for(f;f>0;f--)
		{
			printf("%s",ans[a]);
			if(f>1)
			{
				printf("\n");
			}
		}
		if(count>0)
		{
			printf("\n");
		}
	}
	return 0;
}
