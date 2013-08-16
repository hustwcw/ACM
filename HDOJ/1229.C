#include <stdio.h>

int Check( int a , int b , int k )
{
	int m = 1;
	int i;
	for( i = 1 ; i <= k ; i++ )
	{
		if( ((a%(m*10))/m) != ((b%(m*10))/m) )
			return 0;
		m *= 10;
	}
	return 1;
}

int main()
{
	int a,b,k;
	while( scanf( "%d%d%d" , &a , &b , &k ) && (a||b) )
	{
		if( Check(a,b,k) )
			printf( "-1\n" );
		else
			printf( "%d\n" , a+b );
	}
	return 1;
}