#include<stdio.h>
#include<math.h>
double x,d,e,i[10],j[10];
int a,b,c,f,g,h;
int abcc()
{
    int y,z;
    for(y=d-1;y<=d+1;y++)
    {
        if(y<0)
        {
            continue;
        }
        else if(y>a-1)
        {
            break;
        }
        if(c==b)
        {
            //i++;
        }
        else
        {
            c++;
            //z=d;
            d=y;
            abcc();
            d=z;
            c--;
        }
    }
    return 0;
}
int main()
{
    while(scanf("%d %d",&a,&b)==2)
    {
		a++;
        if(b==1||a<2)
        {
            x=100;
            printf("%.5f\n",x);
        }
        else
        {
			x=pow(a,b);
			for(c=0;c<a;c++)
			{
				i[c]=1;
			}
			for(c=1;c<b;c++)
			{
				j[0]=i[0]+i[1];
				for(f=1;f<a-1;f++)
				{
					j[f]=i[f-1]+i[f]+i[f+1];
					i[f-1]=j[f-1];
				}
				j[f]=i[f]+i[f-1];
				i[f-1]=j[f-1];
				i[f]=j[f];
			}
			for(c=0,d=0;c<a;c++)
			{
				d+=i[c];
			}
			//printf("%.0f\n",d);
			d*=100;
			x=d/x;
            /*for(e=0,i=0;e<a;e++)
            {
                d=e;
                c=2;
                abcc();
            }
            printf("%d\n",i);
			i*=100;
			x=i/x;*/
            printf("%.5f\n",x);
        }
    }
    return 0;
}
