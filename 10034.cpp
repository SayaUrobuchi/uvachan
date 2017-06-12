#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e,f,g,h,j;
    double i,k[100][2],l[100],x,y;
    char check;
    check = 0;
    scanf("%d",&h);
    for(h;h>0;h--)
    {
			if(check) printf("\n");
			check = 1;
        scanf("%d",&a);
        for(b=0;b<a;b++)
        {
            scanf("%lf%lf",&k[b][0],&k[b][1]);
            l[b]=0;
        }
        x=0;
        c=0;
        l[c]=-1;
        while(--b)
        {
            for(d=0,i=0;d<a;d++)
            {
                if(l[d]!=-1)
                {
                    y=pow(k[c][0]-k[d][0],2)+pow(k[c][1]-k[d][1],2);
                    y=sqrt(y);
                    if(y<l[d]||!l[d])
                    {
                        l[d]=y;
                    }
                    if(i>l[d]||!i)
                    {
                        i=l[d];
                        j=d;
                    }
                }
            }
            x+=l[j];
            c=j;
            l[c]=-1;
        }
        printf("%.2f\n",x);
    }
    return 0;
}
