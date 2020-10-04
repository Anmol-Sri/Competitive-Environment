#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n;
	cin >> n;
	ll arr[n];
	for(ll &i:arr) cin >> i;
	ll dp[n]={0};
	ll ans = n;
	for(ll i =1 ; i < n; i++){
		if(arr[i] >= arr[i - 1]){
			dp[i] = dp[i - 1] + 1;
		}
		ans += dp[i];
	}
	cout << ans << "\n";
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