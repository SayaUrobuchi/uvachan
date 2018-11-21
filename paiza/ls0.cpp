#include <stdio.h>
int ary[10][10], tar, n;
int row[10], col[10], rc[10], cc[10], tbl[128];
int ex[100], ey[100], ep[100], en, ed;
void dfs(int depth)
{
    int x, y, i, decided;
    if (depth == en)
    {
        ed = 1;
        return;
    }
    x = ex[depth];
    y = ey[depth];
    decided = 0;
    if (rc[x] == 1)
    {
        decided = tar-row[x];
    }
    if (cc[y] == 1)
    {
        if (decided && tar-col[y] != decided)
        {
            return;
        }
        decided = tar-col[y];
    }
    if (decided)
    {
        if (tbl[decided])
        {
            return;
        }
        tbl[decided] = 1;
        row[x] += decided;
        col[y] += decided;
        rc[x]--;
        cc[y]--;
        ary[x][y] = decided;
        dfs(depth+1);
        if (ed)
        {
            return;
        }
        tbl[decided] = 0;
        row[x] -= decided;
        col[y] -= decided;
        rc[x]++;
        cc[y]++;
        return;
    }
    for (i=0; i<en; i++)
    {
        decided = ep[i];
        if (row[x]+decided > tar || col[y]+decided > tar)
        {
            return;
        }
        if (tbl[decided])
        {
            continue;
        }
        tbl[decided] = 1;
        row[x] += decided;
        col[y] += decided;
        rc[x]--;
        cc[y]--;
        ary[x][y] = decided;
        dfs(depth+1);
        if (ed)
        {
            return;
        }
        tbl[decided] = 0;
        row[x] -= decided;
        col[y] -= decided;
        rc[x]++;
        cc[y]++;
    }
}
int main(void){
    int i, j;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            scanf("%d", &ary[i][j]);
            if (ary[i][j])
            {
                row[i] += ary[i][j];
                col[j] += ary[i][j];
                tbl[ary[i][j]] = 1;
            }
            else
            {
                ex[en] = i;
                ey[en] = j;
                rc[i]++;
                cc[j]++;
                en++;
            }
        }
    }
    tar = (1+(n*n))*n/2;
    j = 0;
    for (i=1; i<=n*n; i++)
    {
        if (!tbl[i])
        {
            ep[j++] = i;
        }
    }
    dfs(0);
    for (i=0; i<n; i++)
    {
        printf("%d", ary[i][0]);
        for (j=1; j<n; j++)
        {
            printf(" %d", ary[i][j]);
        }
        printf("\n");
    }
    return 0;
}

