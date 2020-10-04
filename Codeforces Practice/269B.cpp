#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 5000;
int dp[mxN];
int arr[mxN];
int n, m;

void solve(){
	cin >> n >> m;
	double x;
	for(int i = 0; i < n; i++){
		cin >> arr[i] >> x;
	}
	memset(dp, 0, sizeof dp);
	int ans = -1;
	for(int i = 0; i < n; i++){
		dp[i] = 1;
		for(int j = 0; j < i; j++){
			if(arr[j] <= arr[i])
				dp[i] = max(dp[i], dp[j] + 1);;
		}
		ans = max(ans, dp[i]);
	}
	cout << n - ans  << "\n";
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