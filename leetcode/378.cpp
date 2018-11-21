int heap[16384], hn;
int *ary[16384];

void heapdown(int t)
{
	int left, right, temp;
	while ((left=(t<<1)) <= hn)
	{
		right = left+1;
		if (right > hn || *ary[heap[left]] < *ary[heap[right]])
		{
			if (*ary[heap[t]] > *ary[heap[left]])
			{
				temp = heap[t];
				heap[t] = heap[left];
				heap[left] = temp;
				t = left;
			}
			else
			{
				return;
			}
		}
		else
		{
			if (*ary[heap[t]] > *ary[heap[right]])
			{
				temp = heap[t];
				heap[t] = heap[right];
				heap[right] = temp;
				t = right;
			}
			else
			{
				return;
			}
		}
	}
}

int kthSmallest(int** matrix, int matrixRowSize, int matrixColSize, int k) {
	int i, res;
    for (i=0; i<matrixRowSize; i++)
    {
    	heap[i+1] = i;
    	ary[i] = matrix[i];
    }
    hn = matrixRowSize;
    for (i=hn; i>0; i--)
    {
    	heapdown(i);
    }
    while (k--)
    {
    	res = *ary[heap[1]]++;
    	if (ary[heap[1]]-matrix[heap[1]] >= matrixColSize)
    	{
    		heap[1] = heap[hn--];
    	}
    	heapdown(1);
    }
    return res;
}
