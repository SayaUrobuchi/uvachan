#include <iostream>
using namespace std;

int heap[16384], hn;

void sift_down(int heap[], const int hn, int pos)
{
	int left, right, nxt;
	while (pos <= hn)
	{
		left = (pos << 1);
		right = (left | 1);
		if (left > hn)
		{
			break;
		}
		nxt = left;
		if (right <= hn && heap[left] < heap[right])
		{
			nxt = right;
		}
		if (heap[pos] >= heap[nxt])
		{
			break;
		}
		swap(heap[pos], heap[nxt]);
		pos = nxt;
	}
}

void sift_up(int heap[], const int hn, int pos)
{
	int parent;
	while (pos > 1)
	{
		parent = (pos >> 1);
		if (heap[pos] <= heap[parent])
		{
			break;
		}
		swap(heap[pos], heap[parent]);
		pos = parent;
	}
}

void build(int heap[], int &hn)
{
	int i;
	for (i=hn; i>=1; i--)
	{
		sift_down(heap, hn, i);
	}
}

int pop(int heap[], int &hn)
{
	int t = heap[1];
	heap[1] = heap[hn];
	hn--;
	sift_down(heap, hn, 1);
	return t;
}

void push(int heap[], int &hn, int val)
{
	hn++;
	heap[hn] = val;
	sift_up(heap, hn, hn);
}

int main()
{
	int n, i;
	long long ans;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=1; i<=n; i++)
		{
			scanf("%d", &heap[i]);
			heap[i] = -heap[i];
		}
		hn = n;
		build(heap, hn);
		ans = 0;
		while (hn > 1)
		{
			int t = pop(heap, hn);
			t += pop(heap, hn);
			ans -= t;
			push(heap, hn, t);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
