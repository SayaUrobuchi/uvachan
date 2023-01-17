#include "heap.h"
#include <algorithm>
#include <vector>
using namespace std;

vector<int> heap;

int getMax(){
    return heap[0];
}

int getSize(){
    return heap.size();
}

void insert(int element){
	heap.emplace_back(element);
	push_heap(heap.begin(), heap.end());
}

void removeMax(){
	pop_heap(heap.begin(), heap.end());
	heap.pop_back();
}
