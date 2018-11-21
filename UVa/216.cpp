#include<stdio.h>
#include<math.h>
int a,b,c,d,e,f,g,h,k[8][2],m[8],n[8];
bool l[8];
double i,j,x,y,z[8][8];
int abcc(int p)
{
	int w;
	if(b==a)
	{
		if(i>j||!i)
		{
			i=j;
			for(g=0;g<a;g++)
			{
				n[g]=m[g];
			}
		}
		return 0;
	}
	for(w=0;w<a;w++)
	{
		if(l[w])
		{
			l[w]=0;
			m[b]=w;
			j+=z[p][w];
			b++;
			abcc(w);
			b--;
			j-=z[p][w];
			l[w]=1;
		}
	}
	return 0;
}
int main()
{
	h=0;
	while(scanf("%d",&a)==1)
	{
		if(!a)
		{
			break;
		}
		printf("**********************************************************\n");
		printf("Network #%d\n",++h);
		for(b=0;b<a;b++)
		{
			scanf("%d%d",&k[b][0],&k[b][1]);
			for(c=0;c<b;c++)
			{
				z[b][c]=(k[b][0]-k[c][0])*(k[b][0]-k[c][0])+(k[b][1]-k[c][1])*(k[b][1]-k[c][1]);
				z[b][c]=sqrt(z[b][c])+16;
				z[c][b]=z[b][c];
			}
			l[b]=1;
		}
		for(c=0,i=0;c<a;c++)
		{
			b=1;
			j=0;
			l[c]=0;
			m[0]=c;
			abcc(c);
			l[c]=1;
		}
		for(a--,b=0;b<a;b++)
		{
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",k[n[b]][0],k[n[b]][1],k[n[b+1]][0],k[n[b+1]][1],z[n[b]][n[b+1]]);
		}
		printf("Number of feet of cable required is %.2f.\n",i);
	}
}