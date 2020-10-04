#include <bits/stdc++.h>
#define ll long long int
using namespace std;

/*
Codeforces : 1335 - E1
void solve(){
	int n;
	cin >> n;
	int  arr[n];
	for(int& i : arr) cin >> i;

	int dp[26][n+1];
	memset(dp, 0, sizeof(dp));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 26; j++){
			dp[j][i + 1] = dp[j][i];
		}
		dp[arr[i] - 1][i + 1]++;
	}

	int ans = 0;
	for(int i = 0; i < 26; i++) ans = max(ans, dp[i][n - 1]);
	for(int l = 0; l < n; l++){
		for(int r = l; r < n; r++){
			int in = 0,out = 0;
			for(int each = 0; each < 26; each++){
				in = max(in, dp[each][r + 1] - dp[each][l]);
				out = max(out, 2 * min(dp[each][l],  dp[each][n] - dp[each][r + 1]));
			}
			ans = max(ans , in + out);
		}
	}
	cout << ans << "\n";
	return ;
}
*/

// Codeforces : 1335 E2
`
void solve(){
	int  n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	int dp[200][n + 1];
	memset(dp, 0, sizeof(dp));
	std::vector<vector<int>> pos(200);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < 200; j++){
			dp[j][i + 1] =  dp[j][i];
		}
		dp[arr[i] - 1][i + 1]++;
		pos[arr[i] - 1].push_back(i);
	}
	int ans = 0;
	for(int i = 0; i < 200; i++){
		ans=max(ans, (int)pos[i].size());
		for(int p = 0; p < (int)(pos[i].size()/2); p++){
			int l = pos[i][p] + 1;
			int r = pos[i][(int)pos[i].size() - p - 1] - 1;
			for(int each = 0; each < 200 ; each++ ){
				int sum = dp[each][r + 1] - dp[each][l];
				ans = max(ans, (p + 1) * 2 + sum);
			}
		}
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