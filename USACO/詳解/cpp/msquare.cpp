/*
ID: dd.ener1
PROG: msquare
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

struct item{
	item(){}
	item(char _s[8],char _way,long _times,long _prev):way(_way),times(_times),prev(_prev){
		for(long i=0;i<8;++i)
			s[i]=_s[i];
	}
	char s[8];
	char way;
	long times;
	long prev;
};
item que[40320+20];
long que_end;
char fnl[8];
char origin[8]={0,1,2,3,4,5,6,7};
bool hash[40320+20];
inline void input(){
	freopen("msquare.in","r",stdin);
	for(long i=0;i<8;++i){
		scanf("%c ",fnl+i);
		fnl[i]-='1';
	}
	memset(hash,0,sizeof(hash));
}
inline item putA(long prev){
	/*
	0 1 2 3  -  7 6 5 4 
	7 6 5 4  -  0 1 2 3
	*/
	char* s1=que[prev].s;
	char s2[8];
	s2[0]=s1[7];
	s2[1]=s1[6];
	s2[2]=s1[5];
	s2[3]=s1[4];
	s2[4]=s1[3];
	s2[5]=s1[2];
	s2[6]=s1[1];
	s2[7]=s1[0];
	return item(s2,'A',que[prev].times+1,prev);
}
inline item putB(long prev){
	/*
	0 1 2 3  - 3 0 1 2
	7 6 5 4  - 4 7 6 5
	*/
	char* s1=que[prev].s;
	char s2[8];
	s2[0]=s1[3];
	s2[1]=s1[0];
	s2[2]=s1[1];
	s2[3]=s1[2];
	s2[4]=s1[5];
	s2[5]=s1[6];
	s2[6]=s1[7];
	s2[7]=s1[4];
	return item(s2,'B',que[prev].times+1,prev);
}
inline item putC(long prev){
	/*
	0 1 2 3  - 0 6 1 3
	7 6 5 4  - 7 5 2 4
	*/
	char* s1=que[prev].s;
	char s2[8];
	s2[0]=s1[0];
	s2[1]=s1[6];
	s2[2]=s1[1];
	s2[3]=s1[3];
	s2[4]=s1[4];
	s2[5]=s1[2];
	s2[6]=s1[5];
	s2[7]=s1[7];
	return item(s2,'C',que[prev].times+1,prev);
}
inline long shash(char *s){
	static const long h[]={0,1,2,6,24,120,720,5040};
	long res=0;
	for(long i=1;i<=8;++i)
		for(long j=0;j<i;++j)
			if(s[i]<s[j])res+=h[i];
	return res;
}
inline bool add(item i){
	long h=shash(i.s);
	if(hash[h])return false;
	hash[h]=true;
	que[++que_end]=i;
	return true;
}
inline bool final(){
	char *s=que[que_end].s;
	for(long i=0;i<8;++i)
		if(s[i]!=fnl[i])return false;
	return true;
}
inline void search(){
	add(item(origin,'\n',0,-1));
	if(final())return;
	long ii=0;
	for(;;){
		if(add(putA(ii))&&final())return;
		if(add(putB(ii))&&final())return;
		if(add(putC(ii))&&final())return;
		++ii;
	}
}
void output(long k){
	if(k==-1)return;
	output(que[k].prev);
	putchar(que[k].way);
}
inline void output(){
	freopen("msquare.out","w",stdout);
	printf("%d",que[que_end].times);
	output(que_end);
	putchar('\n');
}
int main(){
	input();
	search();
	output();
}
