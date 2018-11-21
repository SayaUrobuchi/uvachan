/*
ID: dd.ener1
PROG: money
LANG: C++
*/
#include <fstream>
using namespace std;

long V,N;
long v[30];
long long s[10001]; 
void input(){
	ifstream cin("money.in");
	long vt;
	cin>>vt>>N;
	do{
		long a;
		cin>>a;
		if(a>N)continue;
		bool found=false;
		for(long i=0;i<V;++i)
			if(a==v[i]){
				found=true;
				break;
			}
		if(!found)v[V++]=a;
	}while(--vt);
}
void solve(){
	memset(s,0,sizeof(s));
	for(long i=0;;++i){
		if(i*v[0]>N)break;
		s[i*v[0]]=1;
	}
	for(long k=1;k<V;++k)
		for(long j=0;j<=N;++j){
			if(j-v[k]>=0)s[j]+=s[j-v[k]];
		}
}
void output(){
	ofstream cout("money.out");
	cout<<s[N]<<endl;
}
int main(){
	input();
	solve();
	output();
}
