/*
ID: dd.ener1
PROG: hamming
LANG: C++
*/
#include <cstdio>
using namespace std;

long N,B,D;
long max;
long stack[80];
long size;
bool* cans;
void input(){
	freopen("hamming.in","r",stdin);
	scanf("%d%d%d",&N,&B,&D);
	size=0;
	max=1<<(B+1);
}
void solve_can(){
	cans=new bool[max];
	for(long i=0;i<max;++i){
		long c=i;
		long res=0;
		while(c){
			if(c&1)++res;
			c>>=1;
		}
		cans[i]=(res>=D);
	}
}
inline bool can(long a,long b){
	return cans[a^b];
}
bool search(long n){
	if(size==N)return true;
	for(long i=size-1;i>=0;--i)if(!can(stack[i],n))return false;
	stack[size++]=n;
	for(long i=n+1;i<max;++i)
		if(search(i))return true;
	--size;
	return false;
}
void search(){
	for(long k=0;k<max;++k){
		size=0;
		if(search(k))return;
	}
}
void output(){
	freopen("hamming.out","w",stdout);
	for(long i=0;i<size-1;++i){
		if(!((i+1)%10))printf("%d\n",stack[i]);
		else printf("%d ",stack[i]);
	}
	printf("%d\n",stack[size-1]);
}
int main(){
	input();
	solve_can();
	search();
	output();
}
	
