#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){
	ll n, m, a;
	cin >> n >> m >> a;
	ll b[n];
	ll p[m];
	for(ll i = 0; i < n; i++){
		cin >> b[i];
	}
	for(ll i = 0; i < m; i++){
		cin >> p[i];
	}
	sort(b, b + n);
	sort(p, p + m);
	ll l = 0;
	ll r = min(n, m);
	while(l < r){
		ll mid = (l + r + 1) >> 1;
		ll cur = 0;
		for(ll i = 0; i < mid; i++){
			cur += p[i] - min(b[n - mid + i], p[i]);
		}
		if(cur <= a) l = mid;
		else r = mid - 1;
	}
	ll sum = 0;
	for(ll i = 0; i < l; i++){
		sum += p[i];
	}
	cout << l << " " << max(sum - a, 0LL) << "\n";
	// cout << l << "\n";
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