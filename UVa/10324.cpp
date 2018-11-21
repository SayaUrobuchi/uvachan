#include<stdio.h>
int main()
{
    char m;
    int c,d=0,e,f,g,k,n;
    short a[1000002];
    while(scanf("%c",&m)==1)
    {
        a[0]=0;
        d++;
        n=m;
        for(c=1,k=0;c<1000003;c++)
        {
            scanf("%c",&m);
            if(m==10)
            {
                break;
            }
            if(n==m)
            {
                a[c]=k;
            }
            else
            {
                k++;
                a[c]=k;
                n=m;
            }
        }
        printf("Case %d:\n",d);
        scanf("%d",&e);
        for(e;e>0;e--)
        {
            scanf("%d %d",&f,&g);
            if(a[f]==a[g])
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
        scanf("%c",&m);
    }
    return 0;
}
