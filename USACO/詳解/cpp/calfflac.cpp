/*
ID: dd.ener1
PROG: calfflac
LANG: C++
*/
#undef DEBUG
#include <fstream>
using namespace std;

#ifdef DEBUG
ofstream clog("calfflac.log");
#endif

inline char to_lower(char c){
	if('A'<=c&&c<='Z')return c-'A'+'a';
	return c;
}
inline bool is_alpha(char c){
	return(('a'<=c&&c<='z')||('A'<=c&&c<='Z'));
}
int main(){
	string s1,s2;
	{
		ifstream cin("calfflac.in");
		while(cin)
			s1+=cin.get();
	}
	basic_string<long> is;
	{
		long len=s1.length();
		for(long i=0;i<len;++i)
			if(is_alpha(s1[i])){
				s2+=to_lower(s1[i]);
				is+=i;
			}
	}
	#ifdef DEBUG
	clog<<s2<<endl;
	#endif

	long res_beg=-1,res_end=-2;
	long len=s2.length();
	for(long mid=0;mid<len;++mid){//这一遍是找奇数的回文串 
		for(long delta=0;;++delta){
			if(mid-delta<0)break;
			if(mid+delta>=len)break;
			if(s2[mid-delta]!=s2[mid+delta])break;
			else if(2*delta>res_end-res_beg){
					res_end=mid+delta;
					res_beg=mid-delta;
				}
		}
	}

	for(long mid2=0;mid2+1<len;++mid2){//找偶数 
		for(long delta=0;;++delta){
			if(mid2-delta<0)break;
			if(mid2+delta>len)break;
			if(s2[mid2-delta]!=s2[mid2+delta+1])break;
			else if(2*delta+2>res_end-res_beg){
					res_end=mid2+delta+1;
					res_beg=mid2-delta;
				}
		}
	}

	ofstream cout("calfflac.out");
	cout<<res_end-res_beg+1<<endl;
	res_beg=is[res_beg];
	res_end=is[res_end];
	for(;res_beg<=res_end;++res_beg)
		cout<<s1[res_beg];
	cout<<endl;
	return 0;
}
