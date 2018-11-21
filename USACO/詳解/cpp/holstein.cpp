/*
ID: dd.ener1
PROG: holstein
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long maxV=30,maxG=20;
long V,G;
long need[maxV];
long s[maxG][maxV];
long stack[maxG],best[maxG];
long stack_size,best_size;
long MaxDepth;

void input(){
	freopen("holstein.in","r",stdin);
	scanf("%d",&V);
	for(long i=0;i<V;++i)scanf("%d",need+i);
	scanf("%d",&G);
	for(long i=0;i<G;++i)
		for(long j=0;j<V;++j)
			scanf("%d",&s[i][j]);
	best_size=G+1;
}
inline void fillnew(){
	best_size=stack_size;
	for(long i=0;i<stack_size;++i)
		best[i]=stack[i];
}
inline bool can(){
	if(stack_size>=best_size)return false;
	for(long i=0;i<V;++i){
		long now=0;
		for(long j=0;j<stack_size;++j){
			now+=s[stack[j]][i];
		}
		if(now<need[i])return false;
	}
	return true;
}
void search(long k){
	if(k==G){
		if(can())fillnew();
		return;
	}
	stack[stack_size++]=k;
	search(k+1);
	--stack_size;
	search(k+1);
}
void output(){
	freopen("holstein.out","w",stdout);
	printf("%d",best_size);
	for(long i=0;i<best_size;++i)
		printf(" %d",best[i]+1);
	printf("\n");
}
int main(){
	input();
	search(0);
	output();
}
