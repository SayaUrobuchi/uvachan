#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j;
	char k[30][120],x[12],y,t;
	for(a=0;a<119;a++)
	{
		k[0][a]=32;
	}
	k[0][a]='\0';
	while(scanf("%d%c",&a,&y)==2)
	{
		scanf("%s",&x);
		if(a==0&&strcmp(x,"0")==0)
		{
			break;
		}
		h=strlen(x);
		t=a+2;
		t*=h;
		t+=h-1;
		g=2*a+3;
		for(b=1;b<=g;b++)
		{
			strcpy(k[b],k[0]);
		}
		for(b=1,c=0;c<h;b+=3,c++)
		{
			if(x[c]==49||x[c]==52)
			{
				b+=a;
				continue;
			}
			for(d=0;d<a;d++,b++)
			{
				k[1][b]='-';
			}
		}
		k[1][t]=0;
		for(b=0,c=0;c<h;c++,b+=2)
		{
			if(x[c]==49||x[c]==50||x[c]==51||x[c]==55)
			{
				b++;
			}
			else
			{
				k[2][b]='|';
				b++;
			}
			b+=a;
			if(x[c]!=53&&x[c]!=54)
			{
				k[2][b]='|';
			}
		}
		k[2][t]=0;
		for(b=1,i=3;b<a;b++,i++)
		{
			strcpy(k[i],k[2]);
		}
		for(b=1,c=0;c<h;b+=3,c++)
		{
			if(x[c]==48||x[c]==49||x[c]==55)
			{
				b+=a;
			}
			else
			{
				for(d=0;d<a;d++,b++)
				{
					k[i][b]='-';
				}
			}
		}
		k[i][t]=0;
		i++;
		for(b=0,c=0;c<h;c++,b+=2)
		{
			if(x[c]==48||x[c]==50||x[c]==54||x[c]==56)
			{
				k[i][b]='|';
				b++;
			}
			else
			{
				b++;
			}
			b+=a;
			if(x[c]!=50)
			{
				k[i][b]='|';
			}
		}
		k[i][t]=0;
		for(b=1,j=i,i+=1;b<a;b++,i++)
		{
			strcpy(k[i],k[j]);
		}
		for(b=1,c=0;c<h;b+=3,c++)
		{
			if(x[c]==49||x[c]==52||x[c]==55)
			{
				b+=a;
			}
			else
			{
				for(d=0;d<a;d++,b++)
				{
					k[i][b]='-';
				}
			}
		}
		k[i++][t]=0;
		for(b=1;b<i;b++)
		{
			printf("%s\n",k[b]);
		}
		printf("\n");
	}
	return 0;
}
