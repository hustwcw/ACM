#include<iostream>
#include<cstring>
#include <algorithm>

using namespace std;

int main(){
    int n,a[101];
    while(cin>>n){
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
	a[0] = 0;
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(a[i] > ans+1)
		{
			break;
		}
		else
		{
			ans += a[i];
		}
	}
	cout << ans+1 << endl;
    }
}

