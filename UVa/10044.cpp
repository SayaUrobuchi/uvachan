#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node
{
    int n;
    char *name;
    node *left, *right;
};

int n, map[10000][201], table[10000], queue[10000], dp[10000];
char buf[1000000], check[10000];
node *head;

int findnode(char *str)
{
    int tmp, len;
    node *ptr;
    ptr = head;
    while(1)
    {
		    tmp = strcmp(ptr -> name, str);
		    if(!tmp)
		    {
		        return ptr -> n;
		    }
		    else if(tmp < 0)
		    {
		        if(ptr -> right == NULL)
		        {
		            ptr -> right = (node*)malloc(sizeof(node));
		            ptr = ptr -> right;
		            ptr -> n = n++;
		            len = strlen(str);
								ptr -> name = (char*)malloc(len + 1);
		            strcpy(ptr -> name, str);
		            ptr -> left = NULL;
		            ptr -> right = NULL;
		            return ptr -> n;
		        }
		        else
		        {
		            ptr = ptr -> right;
		        }
		    }
		    else
		    {
		    		if(ptr -> left == NULL)
		        {
		            ptr -> left = (node*)malloc(sizeof(node));
		            ptr = ptr -> left;
		            ptr -> n = n++;
		            len = strlen(str);
								ptr -> name = (char*)malloc(len + 1);
		            strcpy(ptr -> name, str);
		            ptr -> left = NULL;
		            ptr -> right = NULL;
		            return ptr -> n;
		        }
		        else
		        {
		            ptr = ptr -> left;
		        }
		    }
		}
}

int main()
{
    int cas, count, mcount, ncount, i, j, k, now, limit;
    char *str, *ptr;
    cas = 0;
    scanf("%d", &count);
    while(count--)
    {
        scanf("%d%d", &mcount, &ncount);
        gets(buf);
        n = 1;
        head = (node*)malloc(sizeof(node));
        head->n = 0;
        head->name = "ErdosP.";
        head->left = NULL;
        head->right = NULL;
        memset(dp, 0, sizeof(dp));
        memset(check, 1, sizeof(check));
        for(i=0; i<10000; i++)
        {
            map[i][0] = 1;
        }
        while(mcount--)
        {
            gets(buf);
            ptr = strtok(buf, ":");
            str = strtok(ptr, ", ");
            k = 0;
            do
            {
				        strcat(str, strtok(NULL, ", "));
				        table[k++] = findnode(str);
				        str = strtok(NULL, ", ");
            }while(str != NULL);
            for(i=1; i<k; i++)
            {
                for(j=0; j<i; j++)
                {
                    map[table[i]][map[table[i]][0]++] = table[j];
                    map[table[j]][map[table[j]][0]++] = table[i];
                }
            }
        }
        queue[0] = 0;
        check[0] = 0;
        for(i=0, j=1; i<j; i++)
        {
            now = queue[i];
            for(k=1, limit=map[now][0]; k<limit; k++)
            {
                if(check[map[now][k]])
                {
                    check[map[now][k]] = 0;
                    queue[j++] = map[now][k];
                    dp[map[now][k]] = dp[now] + 1;
                }
            }
        }
        printf("Scenario %d\n", ++cas);
        while(ncount--)
        {
            gets(buf);
            printf("%s ", buf);
            str = strtok(buf, ", ");
            strcat(str, strtok(NULL, ", "));
            now = findnode(str);
            if(dp[now])
            {
                printf("%d\n", dp[now]);
            }
            else
            {
                printf("infinity\n");
            }
        }
    }
    return 0;
}
