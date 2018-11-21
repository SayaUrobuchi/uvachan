typedef struct {
    int v;
} NumArray;

NumArray* numArrayCreate(int* nums, int numsSize) {
	NumArray *res = (NumArray*)malloc(sizeof(NumArray)*(numsSize+1));
	res[0].v = 0;
	for (int i=1; i<=numsSize; i++)
	{
		res[i].v = res[i-1].v + nums[i-1];
	}
	return res;
}

int numArraySumRange(NumArray* obj, int i, int j) {
    return obj[j+1].v-obj[i].v;
}

void numArrayFree(NumArray* obj) {
    //free(obj);
}

/**
 * Your NumArray struct will be instantiated and called as such:
 * struct NumArray* obj = numArrayCreate(nums, numsSize);
 * int param_1 = numArraySumRange(obj, i, j);
 * numArrayFree(obj);
 */
