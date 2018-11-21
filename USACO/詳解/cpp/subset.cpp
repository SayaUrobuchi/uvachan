/*
ID: dd.ener1
PROG: subset
LANG: C++
*/

#include <cstdio>
using namespace std;

long N;
long f[100][5050];
//f[i][j]��ʾǰi�����ֳ�һ����Ϊj�ļ��ϵķ�����
//f[i][j]=f[i-1][j]����ʹ��i�������+f[i-1][j-i]����j>i��ʹ��i�������; 

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
