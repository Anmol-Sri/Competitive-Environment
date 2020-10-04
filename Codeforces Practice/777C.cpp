#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1e5 + 1;

void solve(){
	int n, m;
	cin >> n >> m;
	int arr[n][m];
	int dp[n][m];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];
			dp[i][j] = 1;
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 1; j < n; j++){
			if(arr[j][i] >= arr[j - 1][i]){
				dp[j][i] += dp[j - 1][i];
			}
		}
	}
	int best[n] = {0};
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			best[i] = max(best[i], dp[i][j]);
		}
	}
	int k;
	cin >> k;
	while(k--){
		int l, r;
		cin >> l >> r;
		l--, r--;
		if(best[r] >= r - l + 1){
			cout << "Yes\n";
		}
		else{
			cout << "No\n";
		}
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