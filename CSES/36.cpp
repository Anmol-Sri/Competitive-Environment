#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	ll n,x;
	cin>>n>>x;
	ll arr[n];
	for(ll i=0;i<n;i++){
		cin>>arr[i];
	}
	map<ll,ll> mp;
	ll cur=0;
	ll ans=0;
	mp[0]++;
	for(ll i=0;i<n;i++){
		cur+=arr[i];
		ans+=mp[cur-x];
		mp[cur]++;
	}
	cout<<ans<<"\n";
	return ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

 //    #ifndef ONLINE_JUDGE
	//     freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif
		
	int t=1;

	while(t--){
		solve();
	}
    return 0;
}