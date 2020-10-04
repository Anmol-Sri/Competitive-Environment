#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 2e5 + 1;
vector < ll > arr;
ll ans;
ll n;
ll t;

void recur(ll l, ll r){
	if(l > r) return ;
	if(l == r){
		if(arr[l] < t) ans++;
		return;
	}
	ll mid = (l + r) / 2;
	vector < ll > pref;
	ll te = 0;
	for(ll i = mid + 1; i <= r; i++){
		te += arr[i];
		pref.push_back(te);
	}
	sort(pref.begin(), pref.end());
	te = 0;
	for(ll i = mid; i >= l; i--){
		te += arr[i];
		ll add = lower_bound(pref.begin(), pref.end(),  t - te) - pref.begin();
		ans += add;
	}
	recur(l, mid);
	recur(mid + 1, r);
}

void solve(){
	cin >> n >> t;
	arr.assign(n, 0);
	for(ll i = 0; i < n; i++){
		cin >> arr[i];
	}
	recur(0, n - 1);
	cout << ans << "\n";
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