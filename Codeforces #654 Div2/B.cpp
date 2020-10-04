#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n,r;
	cin>>n>>r;
	if(r==1){
		cout<<"1\n";
		return ;
	}
	if(n<=r){
		cout<<(n*(n+1))/2-n+1<<"\n";
		// cout<<r<<"\n";
		return ;
	}
	else{
		cout<<(r*(r+1))/2<<"\n";
	}
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