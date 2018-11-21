#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ary[5], queue[5201], step[5201], buf[5], buf2[5], n;

struct node
{
	int now;
	struct node *left, *right;
};

char chk(struct node *ptr, int target)
{
	if(ptr -> now == target)
	{
		return 0;
	}
	else if(ptr -> now > target)
	{
		if(ptr -> left)
		{
			return chk(ptr->left, target);
		}
		ptr -> left = (struct node*)malloc(sizeof(struct node));
		ptr = ptr -> left;
		ptr -> now = target;
		ptr -> left = ptr -> right = NULL;
		return 1;
	}
	if(ptr -> right)
	{
		return chk(ptr->right, target);
	}
	ptr -> right = (struct node*)malloc(sizeof(struct node));
	ptr = ptr -> right;
	ptr -> now = target;
	ptr -> left = ptr -> right = NULL;
	return 1;
}

void decode(int now)
{
	int i;
	for(i=0; i<n; i++)
	{
		buf[i] = now % 51;
		now /= 51;
	}
}

int encode(int* str)
{
	int i, j, ans;
	for(i=0, j=1, ans=0; i<n; i++, j*=51)
	{
		ans += str[i] * j;
	}
	return ans;
}

int getgcd(int p, int q)
{
	if(p % q)
	{
		return getgcd(q, p%q);
	}
	return q;
}

int main()
{
	int i, j, k, p, q, gcd, target, temp;
	struct node *head;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			if(i)
			{
				gcd = getgcd(gcd, ary[i]);
			}
			else
			{
				gcd = ary[i];
			}
		}
		scanf("%d", &target);
		for(i=0, k=0; i<n; i++)
		{
			if(ary[i] >= target)
			{
				k++;
			}
		}
		if(!k)
		{
			printf("-1\n");
		}
		else if(target % gcd)
		{
			printf("-1\n");
		}
		else
		{
			queue[0] = 0;
			step[0] = 0;
			head = (struct node*)malloc(sizeof(struct node));
			head -> now = 0;
			head -> left = head -> right = NULL;
			for(i=0, j=1; i<j; i++)
			{
				decode(queue[i]);
				for(p=0; p<n; p++)
				{
					for(k=0; k<n; k++)
					{
						buf2[k] = buf[k];
					}
					buf2[p] = 0;
					temp = encode(buf2);
					if(chk(head, temp))
					{
						step[j] = step[i] + 1;
						queue[j++] = temp;
					}
					buf2[p] = ary[p];
					temp = encode(buf2);
					if(chk(head, temp))
					{
						if(ary[p] == target)
						{
							printf("%d\n", step[i] + 1);
							break;
						}
						step[j] = step[i] + 1;
						queue[j++] = temp;
					}
				}
				if(p < n)
				{
					break;
				}
				for(p=0; p<n; p++)
				{
					for(q=0; q<n; q++)
					{
						if(p != q)
						{
							for(k=0; k<n; k++)
							{
								buf2[k] = buf[k];
							}
							if(ary[q] - buf[q] < buf[p])
							{
								buf2[p] -= ary[q] - buf[q];
								buf2[q] = ary[q];
								temp = encode(buf2);
								if(chk(head, temp))
								{
									if(buf2[p] == target)
									{
										printf("%d\n", step[i] + 1);
										break;
									}
									step[j] = step[i] + 1;
									queue[j++] = temp;
								}
							}
							else
							{
								buf2[p] = 0;
								buf2[q] += buf[p];
								temp = encode(buf2);
								if(chk(head, temp))
								{
									if(buf2[q] == target)
									{
										printf("%d\n", step[i] + 1);
										break;
									}
									step[j] = step[i] + 1;
									queue[j++] = temp;
								}
							}
						}
					}
					if(q < n)
					{
						break;
					}
				}
				if(p < n)
				{
					break;
				}
			}
		}
	}
	return 0;
}
