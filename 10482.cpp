#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define arysize 500000

short queue[arysize][2];
char check[641][641];

int comp(const void *p, const void *q)
{
    return *(int*)q - *(int*)p;
}

int main()
{
    int cas, count, n, ary[32], i, sum, sum3, min, p, q, first, second, third, tmp, big, small;
    cas = 0;
    scanf("%d", &count);
    while(count--)
    {
        scanf("%d", &n);
        for(i=0, sum=0; i<n; i++)
        {
            scanf("%d", &ary[i]);
            sum += ary[i];
        }
        qsort(ary, n, 4, comp);
        memset(check, 1, sizeof(check));
        min = 1000;
        queue[0][0] = 0;
        queue[0][1] = 0;
        for(i=0, q=1; i<n; i++)
        {
            tmp = ary[i];
            for(p=q-1; p>-1; p--)
            {
                first = queue[p][0] + tmp;
                second = queue[p][1];
                third = sum - first - second;
                big = first;
                if(second > big) big = second;
                if(third > big) big = third;
                small = first;
                if(second < small) small = second;
                if(third < small) small = third;
                if(big - small < min)
                {
                    min = big - small;
                    if(!min) break;
                }
                if(check[first][second])
                {
                    check[first][second] = 0;
                    queue[q][0] = first;
                    queue[q++][1] = second;
                }
                first -= tmp;
                second += tmp;
                big = first;
                if(second > big) big = second;
                if(third > big) big = third;
                small = first;
                if(second < small) small = second;
                if(third < small) small = third;
                if(big - small < min)
                {
                    min = big - small;
                    if(!min) break;
                }
                if(check[first][second])
                {
                    check[first][second] = 0;
                    queue[q][0] = first;
                    queue[q++][1] = second;
                }
            }
            if(p > -1) break;
        }
        printf("Case %d: %d\n", ++cas, min);
    }
    return 0;
}