#include<stdio.h>
int main()
{
    int a,b,c,d,e=0,f;
    while(scanf("%d",&a)==1)
    {
        for(a;a>0;a--)
        {
            scanf("%d %d",&b,&c);
            e++;
            b-=b%2;
            b++;
            c+=c%2;
            c--;
            d=b+c;
            d*=c/2-b/2+1;
            d/=2;
            printf("Case %d: %d\n",e,d);
        }
    }
    return 0;
}
