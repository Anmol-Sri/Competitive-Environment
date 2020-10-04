#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 101;
const int MOD = 1e8;
ll dp[101][101][11][11];
int f, h, k1, k2;

ll recur(int f, int h, int kf, int kh){
	if(dp[f][h][kf][kh] == -1){
		ll ans ;
		if(f + h == 0) ans = 1;
		else{
			ans = 0;
			if(f > 0 && kf > 0) ans = (ans + recur(f - 1, h, kf - 1, k2)) % MOD;
			if(h > 0 && kh > 0) ans = (ans + recur(f, h - 1, k1, kh - 1)) % MOD;
		}
		dp[f][h][kf][kh] = ans;
	}
	return dp[f][h][kf][kh];
}

void solve(){
	memset(dp, -1, sizeof dp);
	cin >> f >> h >> k1 >> k2;
	cout << recur(f, h, k1, k2) << "\n";
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
	// cin>>t;

	while(t--){
		solve();
	}

	return 0;
}