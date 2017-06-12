#include <stdio.h>

int main()
{
    int n, ary[1000], in, zero, ptr;
    while(scanf("%d", &n) == 1)
    {
        if(!n) break;
        zero = 0;
        ptr = 0;
        while(n--)
        {
            scanf("%d", &in);
            if(in)
            {
                ary[ptr++] = in;
            }
            else
            {
                zero++;
            }
        }
        if(ptr)
        {
            printf("%d", ary[0]);
            for(n=1; n<ptr; n++)
            {
                printf(" %d", ary[n]);
            }
            printf("\n");
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}
