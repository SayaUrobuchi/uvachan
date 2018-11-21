/*
ID: dd.ener1
PROG: runround
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long M;
void input(){
	freopen("runround.in","r",stdin);
	scanf("%d",&M);
}
bool is_runround(long n){
	static char str[12];
	static bool exist[10]; 
	memset(exist,0,sizeof(exist));
	static bool used[12];
	memset(used,0,sizeof(used));
	sprintf(str,"%d",n);
	long len=strlen(str);
	for(long i=0;;){
		long now=str[i]-'0';
		if(!now)return false;
		if(exist[now])return false;
		exist[now]=true; 
		long next=(i+now)%len;
		used[next]=true;
		if(!next)break;
		i=next;
	}
	for(long i=0;i<len;++i)
		if(!used[i])return false;
	return true;
}
void output(long res){
	freopen("runround.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	for(;;){
		++M;
		if(is_runround(M)){
			output(M);
			return 0;
		}
	}
}
