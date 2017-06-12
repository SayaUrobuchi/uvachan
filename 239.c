#include <stdio.h>

#define MAX_SIZE 12000
#define EMPTY -1

int next[7000], used[7000];

typedef struct queue
{
	int data[MAX_SIZE], front, rear;
}queue;

typedef struct stack
{
	int data[MAX_SIZE], top;
}stack;

queue *bottom;
stack *one_minute, *five_minute, *hour;

void initialize()
{
	bottom = (queue*)malloc(sizeof(queue));
	one_minute = (stack*)malloc(sizeof(stack));
	five_minute = (stack*)malloc(sizeof(stack));
	hour = (stack*)malloc(sizeof(stack));
	bottom->rear = 0;
	bottom->front = 0;
	one_minute->top = 0;
	five_minute->top = 0;
	hour->top = 0;
}

int fullqueue(queue* q)
{
	return q->rear >= MAX_SIZE;
}

int emptyqueue(queue* q)
{
	return q->rear == q->front;
}

int fullstack(stack* s)
{
	return s->top >= MAX_SIZE;
}

int emptystack(stack* s)
{
	return s->top == 0;
}

int getstacksize(stack* s)
{
	return s->top;
}

void enqueue(queue* q, int element)
{
	if(!fullqueue(q))
	{
		q->data[q->rear++] = element;
	}
}

int dequeue(queue* q)
{
	if(!emptyqueue(q))
	{
		return q->data[q->front++];
	}
	return EMPTY;
}

void push(stack* s, int element)
{
	if(!fullstack(s))
	{
		s->data[s->top++] = element;
	}
}

int pop(stack* s)
{
	if(!emptystack(s))
	{
		return s->data[--s->top];
	}
	return EMPTY;
}

int getlength(int now, int depth)
{
	used[now] = 1;
	if(used[next[now]])
	{
		return depth;
	}
	return getlength(next[now], depth+1);
}

long long getgcd(long long p, long long q)
{
	if(q == 0)
	{
		return 0;
	}
	if(p % q)
	{
		return getgcd(q, p%q);
	}
	return q;
}

long long getlcm(long long p, long long q)
{
	long long gcd;
	gcd = getgcd(p, q);
	if(gcd == 0)
	{
		return 0;
	}
	return (p/gcd) * q;
}

int main()
{
	int n, i, ball, temp;
	long long lcm;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		initialize();
		for(i=0; i<n; i++)
		{
			enqueue(bottom, i);
		}
		for(i=0; i<720; i++)
		{
			ball = dequeue(bottom);
			push(one_minute, ball);
			if(getstacksize(one_minute) == 5)
			{
				ball = pop(one_minute);
				push(five_minute, ball);
				while(!emptystack(one_minute))
				{
					ball = pop(one_minute);
					enqueue(bottom, ball);
				}
				if(getstacksize(five_minute) == 12)
				{
					ball = pop(five_minute);
					push(hour, ball);
					while(!emptystack(five_minute))
					{
						ball = pop(five_minute);
						enqueue(bottom, ball);
					}
					if(getstacksize(hour) == 12)
					{
						temp = pop(hour);
						while(!emptystack(hour))
						{
							ball = pop(hour);
							enqueue(bottom, ball);
						}
						enqueue(bottom, temp);
					}
				}
			}
		}
		for(i=0; i<n; i++)
		{
			ball = dequeue(bottom);
			next[i] = ball;
			/*printf("%d %d\n", i, next[i]);*/
		}
		memset(used, 0, sizeof(used));
		for(i=0, lcm=1; i<n; i++)
		{
			if(!used[i])
			{
				temp = getlength(i, 1);
				/*printf("cycle length %d\n", temp);*/
				lcm = getlcm(lcm, temp);
			}
		}
		printf("%d balls cycle after %lld days.\n", n, lcm>>1);
	}
	return 0;
}
