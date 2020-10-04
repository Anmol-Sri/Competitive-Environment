#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 8010;
ll  dp[1010][1010];
vector< ll > cnt(mxN);
void solve(){
	ll n, k;
	cin >> n >> k;
	vector< ll > arr(n);
	for(ll i =0; i < n; i++){
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	vector< ll > vec;
	vec.push_back(-1);
	for(ll i = 0; i <= 8000; i++){
		if( cnt[i] > 0){
			vec.push_back(cnt[i]);
		}
	}
	k = min(k, (ll)vec.size());
	dp[0][0] = 1;
	for(int i = 1; i < vec.size(); i++){
		dp[i][0] = 1;
		for(int j = 1; j <= k; j++){
			dp[i][j] = (dp[i - 1][j] + (dp[i - 1][j - 1] * vec[i])%MOD) % MOD;
 		}
	}
	ll ans = 0;
	for(ll i = 0; i <= k; i++){
		ans = (dp[vec.size() - 1][i] + ans) % MOD;
	}
	cout << ans%MOD << "\n";
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}