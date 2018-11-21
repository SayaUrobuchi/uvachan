/*
ID: dd.ener1
PROG: checker
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long N;
long nums[15];
long answer=0;
bool jiao1[30],jiao2[30];
long next[15];
long list_beg=0;

void input(){
	freopen("checker.in","r",stdin);
	scanf("%d",&N);
	fclose(stdin);
	memset(jiao1,false,sizeof(jiao1));
	memset(jiao2,false,sizeof(jiao2));
	memset(next,-1,sizeof(next));
	freopen("checker.out","w",stdout);
	for(long i=0;i<N;++i)next[i]=i+1;
	next[N-1]=-1;
}
void output(){
	if(++answer>3)return;
	printf("%d",nums[0]);
	for(long i=1;i<N;++i)printf(" %d",nums[i]);
	putchar('\n');
}
inline long getjiao1(const long n,const long i){
	if(i<=n)return n-i;
	return i-n+N;
}
inline long getjiao2(const long n,const long i){
	return getjiao1(n,N-i);
}
inline bool canput(const long n,const long i){
	if(jiao1[getjiao1(n,i)])return false;
	if(jiao2[getjiao2(n,i)])return false;
	return true;
}
inline void put(const long n,const long i){
	jiao1[getjiao1(n,i)]=true;
	jiao2[getjiao2(n,i)]=true;
	nums[n]=i+1;
}
inline void unput(const long n,const long i){
	jiao1[getjiao1(n,i)]=false;
	jiao2[getjiao2(n,i)]=false;
}
void search(long n){
	if(n==N-1){
		if(canput(n,list_beg)){
			put(n,list_beg);
			output();
			unput(n,list_beg);
		}
		return;
	}
	long i=list_beg;
	long j=next[i];
	if(canput(n,i)){
		list_beg=j;
		put(n,i);
		search(n+1);
		unput(n,i);
		list_beg=i;
	}
	while(j!=-1){
		if(canput(n,j)){
			next[i]=next[j];
			put(n,j);
			search(n+1);
			unput(n,j);
			next[i]=j;
		}
		i=j;
		j=next[j];
	}
}
void outans(){
	printf("%d\n",answer);
}
int main(){
	input();
	search(0);
	outans();
}
