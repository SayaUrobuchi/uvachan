#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int a,b,c,d,e,f,g,h;
char x,z[11];
typedef struct abc
{
	char i[11],j[11];
}abc;
abc y[100005];
int abcc(const void *p,const void *q)
{
	return strcmp((*(abc*)p).j,(*(abc*)q).j);
}
int main()
{
	a=0;
	while(scanf("%c",&y[a].i[0])==1)
	{
		if(y[a].i[0]==10)
		{
			break;
		}
		y[a].i[1]='\0';
		scanf("%s%s",&z,&y[a].j);
		strcpy(y[a].i,strcat(y[a].i,z));
		a++;
		scanf("%c",&x);
	}
	qsort(y,a,sizeof(abc),abcc);
	a--;
	while(scanf("%s",&z)==1)
	{
		b=0;
		c=a;
		while(1)
		{
			d=b+c;
			d/=2;
			if(strcmp(z,y[d].j)==0)
			{
				printf("%s\n",y[d].i);
				break;
			}
			else if(strcmp(z,y[d].j)>0)
			{
				b=d+1;
			}
			else
			{
				c=d-1;
			}
			if(b>c)
			{
				printf("eh\n");
				break;
			}
		}
	}
	return 0;
}