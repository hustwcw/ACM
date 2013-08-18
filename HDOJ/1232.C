#include <stdio.h>
#include <string.h>
int map[1004][1004];

int fa[1004];

int Getfa( int t )  //�Ҹ���
{
	if( fa[t] == t )  return t;
	fa[t] = Getfa(fa[t]);
	return fa[t];
}

int main()
{
	int n,m,i;
	while( scanf( "%d" , &n ) && n )
	{
		for( i = 1 ; i <= n ; i++ )  fa[i] = i;
		scanf( "%d" , &m );
		while( m-- ) //����ʱֱ�Ӳ�
		{
			int x,y;
			scanf( "%d%d" , &x , &y );
			fa[Getfa(x)] = Getfa(y);
		}

		int road = 0;  //ͳ�������·��
		for( i = 1 ; i <= n ; i++ )
			for( int j = 1 ; j <= n ; j++ )
				if( Getfa(i) != Getfa(j) )  //�飬δ���ӣ���
				{
					fa[Getfa(i)] = Getfa(j);
					road++;
				}
		printf( "%d\n" , road );  //���
	}
	return 1;
}