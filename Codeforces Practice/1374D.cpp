#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n,k;
	cin>>n>>k;
	map<ll,ll> mp;
	int arr[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]%k==0) continue;
		ll sec=k*((arr[i]/k)+1) - arr[i];
		mp[sec]++;
	}
	ll ans=0;
	for(auto x:mp){
		// cout<<x.first<<" - "<<x.second<<"\n";
		ll calc=k*(x.second-1)+x.first+1;
		ans=max(ans,calc);
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}