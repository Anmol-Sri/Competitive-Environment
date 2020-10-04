#include <bits/stdc++.h>
#define ll long long int
using namespace std;
#define F first
#define S second

void solve(){
	ll n;
	cin >> n;
	vector < pair < ll, ll > > arr;
	for(ll i = 0; i < n; i++){
		ll x, h;
		cin >> x >> h;
		arr.emplace_back(x, h);
	}
	sort(arr.begin(), arr.end());
	map < ll, ll > L;
	map < ll, ll > R;
	for(int i = 0; i < n; i++) R[arr[i].F + arr[i].S] = max(R[arr[i].F + arr[i].S], R[arr[i].F] + arr[i].S);
	for(int i = n - 1; i >= 0; i--) L[arr[i].F - arr[i].S] = max(L[arr[i].F - arr[i].S], L[arr[i].F] + arr[i].S);
	ll ans = 0;
	for(auto x : R) ans = max(ans, R[x.F] + L[x.F]);
	for(auto x : L) ans = max(ans, R[x.F] + L[x.F]);
	cout << ans << "\n";
	return ;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("timber_input.txt","r",stdin);
		freopen("COut.txt","w",stdout);
	#endif
		
	int t;
	cin>>t;

	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}