/*
ID: dd.ener1
PROG: hidden
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=210000;
int N;
char s[maxn];
int v[maxn];
int next[maxn];
int prev[maxn];
int head;

void input(){
	memset(s,'z'+1,sizeof(s));
	freopen("hidden.in","r",stdin);
	int n;
	scanf("%d\n",&n);
	N=0;
	for(;;){
		char c=getchar();
		if(c==EOF)break;
		if('a'<=c&&c<='z')s[N++]=c;
	}
	memcpy(s+N,s,sizeof(char)*N);
	N*=2;
}
void buildlist(){
	for(int k=0;k<N;++k){
		prev[k]=k-1;
		next[k]=k+1;
	}
	next[N-1]=-1;
	head=0;
}
void remove(int x){
	if(prev[x]!=-1)next[prev[x]]=next[x];
	if(next[x]!=-1)prev[next[x]]=prev[x];
	if(head==x)head=next[x];
}
void solve(){
	buildlist();
	memset(v,0,sizeof(v));
	for(;;){
		int least=10000;
		for(int i=head;i!=-1;i=next[i])
			if(s[i+v[i]]<least)least=s[i+v[i]];
		int max=-1;
		for(int i=head;i!=-1;i=next[i]){
			if(v[i+v[i]]>0){
				remove(i+v[i]);
				v[i]+=v[i+v[i]];
			}
			else if(s[i+v[i]]==least)
				++v[i];
			if(v[i]>max)max=v[i];
		}
		for(int i=head;i!=-1;i=next[i]){
			if(v[i]<max)
				remove(i);
		}
		if(next[head]==-1)break;
	}
}
void output(){
	freopen("hidden.out","w",stdout);
	printf("%d\n",head);
}
int main(){
	//freopen("hidden.log","w",stdout);
	input();
	solve();
	output();
}
