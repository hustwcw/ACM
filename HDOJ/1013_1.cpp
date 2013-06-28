
#include<stdio.h>
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int a;
	char c;
    for(;scanf("%1d",&a),a>0;printf("%d\n",--a%9u+1))
        while(((c=getchar())-'0')<10)
            a+=(c-'0');
    return 0;
}