main(){int n;scanf("%d",&n);for(printf("%d\n",(int)log2(n)+1);n/=2;putchar(n%2?'+':'-'));puts("+");}
