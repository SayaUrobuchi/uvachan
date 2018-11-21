/*
ID: dd.ener1
PROG: fence8
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

long N,R;
long boards[60];
long rails[1200];
long best;

void input(){
	freopen("fence8.in","r",stdin);
	scanf("%d",&N);
	for(long i=0;i<N;++i)
		scanf("%d",boards+i);
	scanf("%d",&R);
	for(long i=0;i<R;++i)
		scanf("%d",rails+i);
}
int compare(const void* a,const void* b){
	return *((long*)a) - *((long*)b);
}
void sort(){
	qsort(rails,R,sizeof(long),compare);
	qsort(boards,N,sizeof(long),compare);
}
bool search(long k,long beg){
	bool res=false;
	for(long i=beg;i<N;++i){
		if(boards[i]==rails[k]){
			if(k==0)return true;
			boards[i]=0;
			res=search(k-1,(rails[k]==rails[k-1])?i+1:0);
			boards[i]=rails[k];
			return res;
		}
	}
	for(long i=beg;i<N;++i){
		if(boards[i]>rails[k]){
			if(k==0)return true;
			if(i!=0&&boards[i]==boards[i-1])continue;
			boards[i]-=rails[k];
			res=search(k-1,(rails[k]==rails[k-1])?i:0);
			boards[i]+=rails[k];
		}
		if(res)return true;
	}
	return false;
}
inline bool tryit(long n){
	return search(n-1,0);
}
long solve(){
	sort();
	long sumB=0,sumR=0;
	for(long i=0;i<N;++i)
		sumB+=boards[i];
	for(long i=0;i<R;++i){
		sumR+=rails[i];
		if(sumR>sumB){
			R=i;
			break;
		}
	}
	long l=0,r=R+1;
	for(;;){
		if(l+1==r)return l;
		long m=(l+r)/2;
		if(tryit(m))l=m;
		else r=m;
	}
}
void output(){
	freopen("fence8.out","w",stdout);
	printf("%d\n",best);
}
int main(){
	//freopen("fence8.log","w",stdout);
	input();
	best=solve();
	output();
}
