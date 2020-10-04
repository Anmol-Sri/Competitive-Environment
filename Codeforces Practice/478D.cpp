#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MOD = 1e9 + 7;
const int mxN = 1e6 + 5;
int max_val[1005];
int dp[mxN];
void solve(){
	int r, g;
	cin >> r >> g;
	int mx = 1;
	while((mx + 1) * (mx + 2) / 2 <= r + g) ++mx;
	dp[0] = 1;
	for(int i = 1; i <= mx; i++){
		for(int j = r; j >= i; j--){
			dp[j] += dp[j - i];
			dp[j] %= MOD;
		}
	}
	int ans = 0;
	for(int i = max(0, mx * (mx + 1) / 2 - g); i <= r; i++) ans = (ans + dp[i]) % MOD;
	cout << ans << "\n";
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