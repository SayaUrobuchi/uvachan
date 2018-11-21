#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j,k[5843];
	k[1]=1;
	c=1;
	d=1;
	e=1;
	i=1;
	for(a=2;a<=5842;a++)
	{
		f=k[c]*2;
		g=k[d]*3;
		h=k[e]*5;
		j=k[i]*7;
		if(f<=g&&f<=h&&f<=j&&k[a-1]!=f)
		{
			k[a]=f;
			c++;
		}
		if(g<=f&&g<=h&&g<=j&&k[a-1]!=g)
		{
			k[a]=g;
			d++;
		}
		if(h<=f&&h<=g&&h<=j&&k[a-1]!=h)
		{
			k[a]=h;
			e++;
		}
		if(j<=g&&j<=h&&j<=f&&k[a-1]!=j)
		{
			k[a]=j;
			i++;
		}
		/*printf("%d\n",k[a]);*/
	}
	while(scanf("%d",&j)==1)
	{
		if(j==0)
		{
			break;
		}
		printf("The %d",j);
		if(j%10==1&&j%100!=11)
		{
			printf("st");
		}
		else if(j%10==2&&j%100!=12)
		{
			printf("nd");
		}
		else if(j%10==3&&j%100!=13)
		{
			printf("rd");
		}
		else
		{
			printf("th");
		}
		printf(" humble number is %d.\n",k[j]);
	}
    return 0;
}
