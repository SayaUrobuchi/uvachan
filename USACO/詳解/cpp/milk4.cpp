/*
ID: dd.ener1
PROG: milk4
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int Q,P;
int s[110];//桶 
int v[21000];//每个数需要用几个桶
int pre_v[21000];
int pre_s[21000];
bool used[110];

int compare(const void* a,const void* b){
	return *((int*)b) - *((int*)a);
}
void input(){
	freopen("milk4.in","r",stdin);
	scanf("%d%d",&Q,&P);
	for(int i=0;i<P;++i)
		scanf("%d",s+i);
	qsort(s,P,sizeof(int),compare);
}
bool better(int i,int j){
	while(i&&j){
		if(pre_s[i]>pre_s[j])
			return true;
		if(pre_s[i]<pre_s[j])
			return false;
		i=pre_v[i];
		j=pre_v[j]; 
	}
	return false;
}
void solve(){
	v[0]=0;
	memset(pre_v,-1,sizeof(pre_v));
	memset(pre_s,0,sizeof(pre_s));
	for(int i=1;i<=Q;++i)
		v[i]=10000000;
	for(int i=0;i<P;++i)
		for(int k=0;k<=Q;++k)
			for(int d=1;;++d){
				int now=k+s[i]*d;
				if(now>Q)break;
				if(v[now]>v[k]+1||((v[now]==v[k]+1)&&((i>pre_s[now])||(i==pre_s[now]&&better(k,pre_v[now]))))){
					v[now]=v[k]+1;
					pre_s[now]=i;
					pre_v[now]=k;
				}
			}
	memset(used,0,sizeof(used));
	for(int i=Q;i!=0;i=pre_v[i]){
		used[pre_s[i]]=true;
	}
}
void output(){
	freopen("milk4.out","w",stdout);
	printf("%d",v[Q]);
	for(int i=P-1;i>=0;--i)
		if(used[i])printf(" %d",s[i]);
	putchar('\n');
}
int main(){
	//freopen("milk4.log","w",stdout);
	input();
	solve();
	output();
}
