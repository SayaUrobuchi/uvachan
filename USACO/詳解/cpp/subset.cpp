/*
ID: dd.ener1
PROG: subset
LANG: C++
*/

#include <cstdio>
using namespace std;

long N;
long f[100][5050];
//f[i][j]表示前i个数分出一个和为j的集合的方案数
//f[i][j]=f[i-1][j]（不使用i这个数）+f[i-1][j-i]（若j>i，使用i这个数）; 

void input(){
	freopen("subset.in","r",stdin);
	scanf("%d",&N);
}
void solve(){
	f[1][1]=1;
	for(long i=2;i<=N;++i){
		long end=(1+i)*i/2;
		for(long j=1;j<=end;++j){
			f[i][j]=f[i-1][j]+(j>i?f[i-1][j-i]:0);
		}
		f[i][end]=1;
	}
}
void output(long res){
	freopen("subset.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	if(((1+N)*N%4))
		output(0);
	else{
		solve();
		output(f[N][(1+N)*N/4]);
	}
}
