/*
ID: dd.ener1
PROG: job
LANG: C++
*/

#include <cstdio>
using namespace std;

long N,M1,M2;
long A[25],B[25];
long res1,res2;
long a[1100],b[1100];

void input(){
	freopen("job.in","r",stdin);
	scanf("%d%d%d",&N,&M1,&M2);
	for(long i=0;i<M1;++i)
		scanf("%d",A+i);
	for(long i=0;i<M2;++i)
		scanf("%d",B+i);
}

long nA[25],nB[25];

long putA(long t){
	long a=0,min=1000000000;
	for(long i=0;i<M1;++i){
		long beg=t>nA[i]?t:nA[i];
		if(beg+A[i]<min||(beg+A[i]==min&&A[i]>A[a])){
			min=beg+A[i];
			a=i;
		}
	}
	return nA[a]=(t>nA[a]?t:nA[a])+A[a];
}
long putB(long t){
	long b=0,min=1000000000;
	for(long i=0;i<M2;++i){
		long beg=t>nB[i]?t:nB[i];
		if(beg+B[i]<min||(beg+B[i]==min&&B[i]>B[b])){
			min=beg+B[i];
			b=i;
		}
	}
	return nB[b]=(t>nB[b]?t:nB[b])+B[b];
}
void solve(){
	for(long i=0;i<N;++i){
		a[i]=putA(0);
		b[i]=putB(0);
	}
	res1=a[N-1];
	res2=0;
	for(long i=0;i<N;++i)
		if(a[i]+b[N-i-1]>res2)res2=a[i]+b[N-i-1];
}
void output(){
	freopen("job.out","w",stdout);
	printf("%d %d\n",res1,res2);
}
int main(){
	input();
	solve();
	output();
}
