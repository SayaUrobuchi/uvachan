/*
ID: dd.ener1
PROG: contact
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

struct item{
	char *str;
	long len;
	unsigned long x;
	item(){}
	item(char* _str,long _len,unsigned long _x):str(_str),len(_len),x(_x){}
};

long A,B,N;
bool s[200100];
long n;
unsigned long trie[0x10000];
bool stack[15];
long stack_size;
item res[10000];
long res_len;

bool operator<(const item lhs,const item rhs){
	if(lhs.x<rhs.x)return true;
	if(lhs.x>rhs.x)return false;
	if(lhs.len<rhs.len)return false;
	if(lhs.len>rhs.len)return true;
	return strcmp(lhs.str,rhs.str)>0;
}
template<class T>
inline void swap(T& l,T& r){
    T tmp=r;
    r=l;
    l=tmp;
}
template<class T>
void qsort(T s1[],long low,long hi){
    if(low>=hi)return;
    T x=s1[(low+hi)/2];
    swap(s1[low],s1[(low+hi)/2]);
    long l=low,r=hi;
    while(l<r){
        while(l<r&&s1[r]<x)--r;
        s1[l]=s1[r];
        while(l<r&&x<s1[l])++l;
        s1[r]=s1[l];
    }
    s1[l]=x;
    qsort(s1,low,l-1);
    qsort(s1,r+1,hi);
}
void input(){
	freopen("contact.in","r",stdin);
	scanf("%d %d %d\n",&A,&B,&N);
	n=0;
	for(;;)
		switch(getchar()){
			case '0':
				s[n++]=false;
				break;
			case '1':
				s[n++]=true;
				break;
			case EOF:
				return;
		}
	memset(trie,0,sizeof(trie));
}
void solve(){
	long iter;
	for(long beg=0;beg<n;++beg){
		iter=1;
		for(long now=beg;now<n&&now<=beg+B;++now){
			++trie[iter];
			iter*=2;
			if(s[now])++iter;
		}
		++trie[iter];
	}
}
void add_stack(unsigned long n){
	char *str=new char[stack_size+1];
	for(long i=0;i<stack_size;++i)
		str[i]=('0'+stack[i]);
	str[stack_size]='\0';
	res[res_len++]=item(str,stack_size,n);
}
void addout(long k){
	if(trie[k]==0)return;
	if(stack_size>B)return;
	if(stack_size>=A)add_stack(trie[k]);
	stack[stack_size++]=false;
	addout(k*=2);
	--stack_size;
	stack[stack_size++]=true;
	addout(++k);
	--stack_size;
}
void addout(){
	stack_size=0;
	res_len=0;
	addout(1);
}
void output(){
	freopen("contact.out","w",stdout);
	for(long i=0;i<res_len&&N;){
		printf("%d\n",res[i].x);
		printf("%s",res[i].str);
		long nn=1;
		long j;
		for(j=i+1;j<res_len;++j){
			if(res[i].x!=res[j].x)break;
			if(nn!=0)putchar(' ');
			printf("%s",res[j].str);
			if(++nn==6){
				nn=0;
				putchar('\n');
			}
		}
		if(nn!=0)putchar('\n');
		i=j;
		--N;
	}
}
int main(){
	input();
	solve();
	addout();
	qsort(res,0,res_len-1);
	output();
}
