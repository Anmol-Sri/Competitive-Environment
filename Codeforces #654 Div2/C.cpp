#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll a,b,n,m;
	cin>>a>>b>>n>>m;
	if((a+b)<(n+m)){
		cout<<"No\n";
		return ;
	}
	if(min(a,b)<m){
		cout<<"No\n";
		return ;
	}
	if(a<b){
		a-=m;
	}
	else{
		b-=m;
	}
	if((a+b)<n){
		cout<<"No\n";
		return ;
	}
	cout<<"Yes\n";
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