#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j;
    char k[100],l;
    scanf("%d",&h);
    for(g=0;h>0;h--)
    {
        scanf("%d",&a);
        if(!a)
        {
            printf("Case #%d: 0\n",++g);
            continue;
        }
        for(b=0;b<100;b++)
        {
            k[b]=0;
        }
        l=1;
		if(a<0)
        {
            l=0;
            a*=-1;
        }
        for(b=a,c=0;b>0;b/=2,c++)
        {
            k[c]=b%2;
        }
        k[c]=0;
        for(b=0;b<c;b++)
        {
            if(k[b]==2)
            {
                k[b]=0;
                k[b+1]++;
            }
            else if(b%2==l)
            {
                if(k[b])
                {
                    k[b+1]++;
				}
            }
        }
        while(k[b])
        {
            if(k[b]==2)
            {
                k[b+1]=1;
                k[b]=0;
            }
            else if(b%2==l)
            {
                k[b+1]=1;
            }
            b++;
        }
        printf("Case #%d: ",++g);
        for(b--;b>-1;b--)
        {
            printf("%d",k[b]);
        }
        printf("\n");
	}
    return 0;
}