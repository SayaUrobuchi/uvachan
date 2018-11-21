/*
ID: dd.ener1
PROG: fracdec
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long N,D;
long shang[150000];
long yu[150000];
bool xunhuan;
long n,beg;
void input(){
	freopen("fracdec.in","r",stdin);
	scanf("%d%d",&N,&D);
}
void solve(){
	long A=N%D;
	long B=D;
	xunhuan=true;
	memset(yu,-1,sizeof(yu));
	for(n=0;;){
		if(A==0){
			xunhuan=false;
			return;
		}
		shang[n]=A/B;
		A%=B;
		if(yu[A]!=-1){
			beg=yu[A];
			return;
		}
		yu[A]=n++;
		A*=10;
	}
}
void output(char c){
	static long time=-1;
	if(time%76==75&&c!='\n')putchar('\n');
	++time;
	putchar(c);
}
void output(){
	freopen("fracdec.out","w",stdout);
	char str[20];
	sprintf(str,"%d.",N/D);
	for(long i=0;str[i];++i)
		output(str[i]);
	if(!(N%D)){
		output('0');
		output('\n');
		return;
	}
	if(!xunhuan)
		for(long i=1;i<n;++i)
			output('0'+shang[i]);
	else{
		for(long i=1;i<=beg;++i)
			output('0'+shang[i]);
		output('(');
		for(long i=beg+1;i<=n;++i)
			output('0'+shang[i]);
		output(')');
	}
	output('\n');
}
int main(){
	input();
	solve();
	output();
}
