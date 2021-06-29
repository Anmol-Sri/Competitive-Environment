#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int arr[n];
	bool ok = false;
	set < ll > s;
	ll cur = 0;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	if(n > m){
		cout << "YES\n";
		return ;
	}
	bool dp[n + 1][m + 1];
	memset(dp, false, sizeof dp);
	dp[0][0] = true;
	for(int i = 1; i <= n; i++){
		dp[i][0] = true;
		for(int j = 0; j <= m; j++){
			dp[i][j] = dp[i - 1][j] | dp[i - 1][(j + arr[i - 1]) % m];
		}
	}
	if(dp[n][m]) cout << "YES\n"; else cout << "NO\n";
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