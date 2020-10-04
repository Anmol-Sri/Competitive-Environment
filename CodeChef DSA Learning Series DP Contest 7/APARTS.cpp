#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	int arr[n + 1][m + 1];
	for(int i = 1; i <= n ; i++){
		for(int j = 1; j <= m; j++){
			cin >> arr[i][j];
		}
	}
	int dp[n + 1][m + 1];
	int ans[n + 1][m + 1];
	memset(dp ,0, sizeof(dp));
	memset(dp ,0, sizeof(dp));

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j]=  max(0, max(dp[i - 1][j - 1], max(dp[i - 1][j], dp[i - 1][j + 1])));
			if(dp[i][j] > arr[i][j]){
				ans[i][j] = 0;
			}
			else{
				ans[i][j] = 1;
				dp[i][j] = arr[i][j];
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout  << ans[i][j];
		}
		cout << "\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}