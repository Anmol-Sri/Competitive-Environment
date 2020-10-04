#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n;
	cin>>n;
	vector<ll> arr;
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		arr.push_back(x);
	}
	ll dp[25][n];
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++){
		for(int j=0;j<25;j++){
			dp[j][i]=arr[i]%2;
			arr[i]/=2;
		}
	}
	for(int i=0;i<25;i++) sort(dp[i],dp[i]+n);
	ll ans=0;
	for(int i=0;i<n;i++){
		ll val=0;
		ll prod=1;
		for(int j=0;j<25;j++){
			val+=dp[j][i]*prod;
			prod*=2;
		}
		ans+=val*val;
	}
	cout<<ans<<"\n";
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
		
	int t=1;

	while(t--){
		solve();
	}

	return 0;
}