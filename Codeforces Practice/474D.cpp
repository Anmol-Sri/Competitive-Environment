#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1234567;
const int MOD = 1e9 + 7;
ll dp[mxN];
ll pref[mxN];

void solve(){
	int n, k;
	cin >> n >> k;
	dp[0] = 1;
	for(int i = 1;  i < mxN; i++){
		dp[i] = dp[i - 1];
		if(i >= k) dp[i] += dp[i - k], dp[i] %= MOD;
	}
	pref[0] = 0;
	for(int i = 1; i < mxN; i++) pref[i] += pref[i - 1] + dp[i], pref[i] %= MOD;
	while(n--){
		int a, b;
		cin >> a >> b;
		cout << (pref[b] - pref[a - 1] + MOD) % MOD << "\n";
	}
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