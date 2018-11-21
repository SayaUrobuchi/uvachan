/*
ID: dd.ener1
PROG: prefix
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

class CharTrie{
	public:
		CharTrie(){
			reset_find();
		}
		int append_find(char c){//返回-1表示树中根本没有这样一个分支，返回1表示找到一个单词，否则返回0 
			if(!c)return -1;
			now=now->child[c-'A'];
			if(!now)return -1;
			return now->coverd;
		}
		void append_insert(char c){
			int n=c-'A';
			if(now->child[n]==0)now->child[n]=new TrieNode;
			now=now->child[n];
		}
		void end_insert(){
			now->coverd=true;
			reset_find();
		}
		void reset_find(){
			now=&root;
		}
	private:
		class TrieNode{
			public:
			TrieNode():coverd(false){
				memset(child,0,sizeof(child));
			}
			bool coverd;
			TrieNode* child[26];
		};
		TrieNode root;
		TrieNode* now;
}Trie;
char s[201000];
bool can[201000];
long len;
void input1(){
	for(;;){
		char c=getchar();
		switch(c){
			case ' ':
			case '\n':
				Trie.end_insert();
				break;
			case '.':
				getchar();
				return;
			default:
				Trie.append_insert(c);
		}
	}
}
void input2(){
	len=0;
	for(;;){
		char c=getchar();
		switch(c){
			case ' ':
			case '\n':
				break;
			case EOF:
				return;
			default:
				s[len++]=c;
		}
	}
}
void input(){
	freopen("prefix.in","r",stdin);
	input1();
	input2();
	memset(can,0,sizeof(can));
}
void solve(){
	can[0]=true;
	for(long i=0;i<len;++i){
		if(!can[i])continue;
		Trie.reset_find();
		for(long j=i;;++j){
			int r=Trie.append_find(s[j]);
			if(r==-1)break;
			if(r==1)can[j+1]=true;
		}
	}
}
void output(){
	long res;
	for(res=len;!can[res];--res);
	freopen("prefix.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	solve();
	output();
	return 0;
}
