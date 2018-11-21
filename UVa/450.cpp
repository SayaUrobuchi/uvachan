#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char k[8][60];
}abc;
int abcc(const void *r,const void *s)
{
	return strcmp((*(abc*)r).k[2],(*(abc*)s).k[2]);
}
int a,b,c,d,e,f,g,h,i,j;
char p[300],q[60],x,z[300];
abc y[4000];
int main()
{
	scanf("%d%c",&h,&x);
	j=0;
	for(h;h>0;h--)
	{
		gets(z);
		while(gets(p))
		{
			a=strlen(p);
			if(a==0)
			{
				break;
			}
			for(b=0,c=0,d=0;b<a;b++,d++)
			{
				if(p[b]==',')
				{
					q[d]='\0';
					strcpy(y[j].k[c],q);
					c++;
					d=-1;
				}
				else
				{
					q[d]=p[b];
				}
			}
			q[d]='\0';
			strcpy(y[j].k[c],q);
			strcpy(y[j++].k[c+1],z);
		}
	}
	qsort(y,j,sizeof(abc),abcc);
	for(a=0;a<40;a++)
	{
		z[a]='-';
	}
	z[a]='\0';
	for(i=0;i<j;i++)
	{
		printf("%s\n",z);
		printf("%s %s %s\n",y[i].k[0],y[i].k[1],y[i].k[2]);
		printf("%s\n",y[i].k[3]);
		printf("Department: %s\n",y[i].k[7]);
		printf("Home Phone: %s\n",y[i].k[4]);
		printf("Work Phone: %s\n",y[i].k[5]);
		printf("Campus Box: %s\n",y[i].k[6]);
	}
	return 0;
}