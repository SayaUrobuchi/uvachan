/*
ID: dd.ener1
PROG: ariprog
LANG: C++
*/
#include <fstream>
using namespace std;

long n,m,len;
bool* is;
long *list,ll;
inline void swap(long& l,long& r){
    long tmp=r;
    r=l;
    l=tmp;
}
void qsort(long s1[],long low,long hi){
    if(low>=hi)return;
    long x=s1[(low+hi)/2];
    swap(s1[low],s1[(low+hi)/2]);
    long l=low,r=hi;
    while(l<r){
        while(l<r&&s1[r]>=x)--r;
        s1[l]=s1[r];
        while(l<r&&s1[l]<=x)++l;
        s1[r]=s1[l];
    }
    s1[l]=x;
    qsort(s1,low,l-1);
    qsort(s1,r+1,hi);
}
void init(){
	ifstream cin("ariprog.in");
	cin>>n>>m;
	len=2*m*m+1;
	is=new bool[len];
	memset(is,false,sizeof(bool)*len);
	list=new long[m*(m+1)];
	ll=0;
	for(long i=0;i<=m;++i)
		for(long j=i;j<=m;++j){
			long t=i*i+j*j;
			if(is[t])continue;
			list[ll++]=t;
			is[t]=true;
		}
	qsort(list,0,ll-1);
}
inline bool ok(long a,long b){
	for(long i=n-1;i>=0;--i)
		if(!is[a+i*b])return false;
	return true;
}
int main(){
	init();
	bool found=false;
	ofstream cout("ariprog.out");
	for(long b=1;b*(n-1)<len;++b)
		for(long i=0;list[i]+(n-1)*b<len;++i){
			if(ok(list[i],b)){
				found=true;
				cout<<list[i]<<' '<<b<<endl;
			}
		}
	if(!found)cout<<"NONE"<<endl;
}
