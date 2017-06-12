#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g;
    while(scanf("%d",&a)==1)
    {
        for(a;a>0;a--)
        {
            scanf("%d %d",&b,&c);
            if(b%2!=c%2||c>b)
            {
                printf("impossible\n");
            }
            else
            {
                printf("%d %d\n",b/2+(c+1)/2,b/2-c/2);
            }
        }
    }
    return 0;
}
