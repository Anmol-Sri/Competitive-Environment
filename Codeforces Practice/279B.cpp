#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define debug(a) for(auto x : a) cout << x << " " ; cout << "\n";
void solve(){
	int n, t;
	cin >> n >> t;
	int arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	ll pref[n + 1];
	pref[0] = 0;
	for(int i = 1; i <= n; i++) pref[i] = pref[i - 1] + arr[i - 1];
	// debug(pref);
	int ans = 0;
	for(int i = 0; i < n; i++){
		int x = upper_bound(pref + i, pref + n + 1, t + pref[i]) - pref - i - 1;
		// cout << x << " ";
		ans = max(ans, x);
	}
	// cout << "\n";
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}