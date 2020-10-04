#include <bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[53][1379];

void precalc(){
	dp[0][0] = 1;
	for(int i = 1; i <= 52; i++){
		for(int j = 52; j >= 1; j--){
			for(int k = i; k <= 1378; k++){
				dp[j][k] += dp[j - 1][k - i];
			}
		}
	}
}
void solve(){
	int l, s;
	cin >> l >> s;
	if(l > 52 || s > 1378){
		cout  << "0\n";
		return ;
	}
	cout << dp[l][s] << "\n";
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
	precalc();
	for(int i = 1; i <= t; i++){
		cout << "Case " << i << ": ";
		solve();
	}

	return 0;
}