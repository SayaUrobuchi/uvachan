/*
ID: dd.ener1
PROG: spin
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long v[5];
bool no[5][360];
long roted[5];

void input(){
	freopen("spin.in","r",stdin);
	memset(no,0,sizeof(no));
	for(long i=0;i<5;++i){
		long m;
		scanf("%d%d",v+i,&m);
		do{
			long a,s;
			scanf("%d%d",&a,&s);
			for(long k=0;k<=s;++k)
				no[i][(a+k)%360]=true;
		}while(--m);
	}
	memset(roted,0,sizeof(roted));
}
void rotate(){
	for(long i=0;i<5;++i){
		roted[i]+=v[i];
		roted[i]%=360;
	}
}
bool get(long k,long b){
	return no[k][(b-roted[k]+360)%360];
}
bool can(){
	for(long i=0;i<360;++i)
		if(get(0,i)&&get(1,i)&&get(2,i)&&get(3,i)&&get(4,i))return true;
	return false;
}
long solve(){
	for(long res=0;res<360;++res){
		if(can())return res;
		rotate();
	}
	return -1;
}
void output(long res){
	freopen("spin.out","w",stdout);
	if(res!=-1)printf("%d\n",res);
	else puts("none");
}
int main(){
	//freopen("spin.log","w",stdout);
	input();
	output(solve());
}
