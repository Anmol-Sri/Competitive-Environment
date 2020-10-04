#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	int d=(c-b)/a;
	cout<<d*a+b<<"\n";
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}