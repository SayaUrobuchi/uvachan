/*
ID: dd.ener1
PROG: zerosum
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

long N;
char op_stack[15];
long num_stack[15];
long op_size,num_size;
bool solve(){
	long res=num_stack[0];
	for(long i=1;i<num_size;++i)
		switch(op_stack[i-1]){
			case '-':
				res-=num_stack[i];
				break;
			case '+':
				res+=num_stack[i];
		}
	return res==0;
}
void output(long n){
	static char chr[20];
	sprintf(chr,"%d",n);
	long len=strlen(chr);
	putchar(chr[0]);
	for(long i=1;i<len;++i){
		putchar(' ');
		putchar(chr[i]);
	}
}
void output(){
	output(num_stack[0]);
	for(long i=1;i<num_size;++i){
		putchar(op_stack[i-1]);
		output(num_stack[i]);
	}
	putchar('\n');
}
void search(long k){//表示该加上数字k了 
	if(k==N+1){
		if(solve())output();
		return;
	}
	num_stack[num_size-1]*=10;
	num_stack[num_size-1]+=k;
	search(k+1);
	num_stack[num_size-1]/=10;
	op_stack[op_size++]='+';
	num_stack[num_size++]=k;
	search(k+1);
	--op_size;
	--num_size;
	op_stack[op_size++]='-';
	num_stack[num_size++]=k;
	search(k+1);
	--op_size;
	--num_size;
}
void input(){
	freopen("zerosum.in","r",stdin);
	scanf("%d",&N);
	num_size=op_size=0;
	freopen("zerosum.out","w",stdout);
}
int main(){
	input();
	num_stack[num_size++]=1;
	search(2);
}
