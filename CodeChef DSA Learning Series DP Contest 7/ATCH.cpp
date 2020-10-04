#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll INF = 1e11;
void solve(){
	int n;
	cin >> n;
	ll arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	ll cur = 0;
	ll mn = INF;
	ll ans = -INF;
	for(int i = 0; i < n; i++){
		cur += arr[i];
		ans = max({ans, cur - mn, cur});
		if(cur < 0){
			cur = 0;
			mn = INF;
		}
		else{
			mn = min(mn, arr[i]);
		}
		// cout << i << " " << ans << " " << cur << "\n";
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