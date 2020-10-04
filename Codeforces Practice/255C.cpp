#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	int n;
	cin >> n;
	int arr[n];
	map < int, int > mp;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
		mp[arr[i]]++;
	}
	int cnt = 0;
	for(auto &x : mp) x.second = cnt++;
	for(auto &x : arr) x = mp[x];
	// for(auto x : arr) cout << x << " ";
	vector < vector < int > > dp(n, vector < int > (n, 1));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < i; j++){
			dp[i][arr[j]] = max(dp[i][arr[j]], 1 + dp[j][arr[i]]);
		}
	}
	int mx = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++)
			mx = max(mx, dp[i][j]);
	}
	cout << mx << "\n";
	return;
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