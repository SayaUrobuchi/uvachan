#include<stdio.h>
#include<math.h>
int a,b,c,d,e,f,g,h,i,j[1000010];
int main()
{
    j[0]=0;
    j[1]=0;
    j[2]=1;
    i=3;
    while(scanf("%d",&a)==1)
    {
        for(b=i;b<a+1;b++,i++)
        {
            j[b]=j[b-1];
            if(b%2==0)
            {
                j[b]+=j[b/2]-j[b/2-1]+1;
            }
            else
            {
                for(e=3;e<(int)(sqrt(b))+1;e+=2)
                {
                    if(b%e==0)
                    {
                        j[b]+=j[b/e]-j[b/e-1]+1;
                        goto abcc;
                    }
                }
                j[b]++;
                abcc:;
            }
        }
        printf("%d\n",j[a]);
    }
    return 0;
}
