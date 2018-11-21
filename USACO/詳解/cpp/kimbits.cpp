/*
ID: dd.ener1
PROB: kimbits
LANG: C++
*/
#include <cstdio>
using namespace std;

long C[100][100];
long L,N,I;
bool bits[35];

void input(){
	freopen("kimbits.in","r",stdin);
	scanf("%d%d%d",&N,&L,&I);
}
void solveC(){
	//C(n,k)=C(n-1,k)+C(n-1,k-1);
	C[0][0]=1;
	C[1][0]=1;
	C[1][1]=1;
	for(long n=2;n<=N;++n){
		C[n][0]=1;
		for(long k=1;k<n;++k)
			C[n][k]=C[n-1][k]+C[n-1][k-1];
		C[n][n]=1;
	}
}
long min(long a,long b){
	return a<b?a:b;
}
void solve(){
	solveC();
	long now=1;
	long used=0;
	for(long n=0;n<N;++n){
		//如果第n位填1的话
		//next=now+sigma(C(N-n+1,j))0<=j<=min(L-used,N-n+1);
		long next=now;
		for(long j=0;j<=min(L-used,N-n-1);++j)
			next+=C[N-n-1][j];
		if(next<=I){
			now=next;
			bits[n]=true;
			++used;
		}
	}
}
void output(){
	freopen("kimbits.out","w",stdout);
	for(long i=0;i<N;++i)
		putchar('0'+bits[i]);
	putchar('\n');
}
int main(){
	input();
	solve();
	output();
}
