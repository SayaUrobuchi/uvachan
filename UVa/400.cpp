#include<stdio.h>
#include<string.h>
int main()
{
	int a,b,c,d,e,f,g,h,i,j[105];
	char k[105][65],x,y[61][61],z[65];
	for(a=1;a<61;a++)
	{
		for(b=0;b<a;b++)
		{
			y[a][b]=32;
		}
		y[a][b]='\0';
	}
	while(scanf("%d%c",&a,&x)==2)
	{
		for(b=0,i=0;b<a;b++)
		{
			gets(k[b]);
			j[b]=strlen(k[b]);
			if(i<j[b])
			{
				i=j[b];
			}
		}
		a--;
		for(b=0,d=a;b<a;b++,d--)
		{
			for(c=0,e=0;c<a;c++)
			{
				for(f=0;f<j[c]&&f<j[c+1];f++)
				{
					if(k[c][f]>k[c+1][f])
					{
						strcpy(z,k[c]);
						strcpy(k[c],k[c+1]);
						strcpy(k[c+1],z);
						g=j[c];
						j[c]=j[c+1];
						j[c+1]=g;
						e++;
						break;
					}
					else if(k[c][f]<k[c+1][f])
					{
						break;
					}
				}
				if(f==j[c+1])
				{
					strcpy(z,k[c]);
					strcpy(k[c],k[c+1]);
					strcpy(k[c+1],z);
					g=j[c];
					j[c]=j[c+1];
					j[c+1]=g;
					e++;
				}
			}
			if(e==0)
			{
				break;
			}
		}
		for(b=0;b<60;b++)
		{
			printf("-");
		}
		if(a==0)
		{
			printf("\n%s\n",k[0]);
			continue;
		}
		printf("\n");
		b=60-i;
		i+=2;
		b/=i;
		b++;
		a++;
		f=a/b;
		if(a%b>0&&b!=1)
		{
			f++;
		}
		for(c=0;c<f;c++)
		{
			printf("%s",k[c]);
			for(d=c+f,e=c;d<a;d+=f,e+=f)
			{
				printf("%s%s",y[i-j[e]],k[d]);
			}
			printf("\n");
		}
	}
	return 0;
}