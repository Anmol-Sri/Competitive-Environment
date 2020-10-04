#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int MOD = 1e9 + 9;
const int mxN = 1e6 + 1;
ll dp[mxN];
void calc(){
	dp[0]=1;
	for(ll i = 1; i <= mxN; i++){
		if(i - 2 >= 0){
			dp[i] += dp[i - 2];
			dp[i] %= MOD;
		}
		if(i - 3 >= 0){
			dp[i] += dp[i - 3];
			dp[i] %= MOD;
		}
	}
	return ;
}

void solve(){
	ll x;
	cin >> x;
	cout << dp[x] << "\n";
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
		
	calc();

	int t;
	cin>>t;

	while(t--){
		solve();
	}

	return 0;
}