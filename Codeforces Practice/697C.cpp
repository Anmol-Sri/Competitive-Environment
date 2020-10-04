#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

ll power(ll n,ll m){
	if(m==0) return 1;
	ll val=power(n,m/2);
	if(m%2==0) return (val*val); else return ((val*val)*n);
}

ll powermod(ll n,ll m,ll MOD){
	if(m==0) return 1;
	ll val=powermod(n,m/2,MOD);
	val %= MOD;
	if(m%2==0) return (val*val) % MOD; else return (((val*val) % MOD) * n) % MOD;
}

map<ll, ll> mp;
 
ll LCA(ll v, ll u) {
	set<ll> S;
	while (v) S.insert(v), v >>= 1;
	while (u) if (S.find(u) != S.end()) return u;else u >>= 1;
}
 
void add(ll v, ll w) {
	if (mp.find(v) == mp.end()) mp[v] = w;
	else mp[v] += w;
}
 
void sum(ll v, ll &ans) {
	if (mp.find(v) != mp.end()) ans += mp[v];
}
 
void solve() {
	int Q;
	int x;
	ll v, u, w;
	cin >> Q;
	while (Q--) {
		cin >> x;
		if (x == 1) {
			cin >> v >> u >> w;
			ll f = LCA(v, u);
			while (v != f) add(v, w), v >>= 1;
			while (u != f) add(u, w), u >>= 1;
		}
		else {
			cin >> v >> u;
			ll f = LCA(v, u);
			ll ans = 0;
			while (v != f) sum(v, ans), v >>= 1;
			while (u != f) sum(u, ans), u >>= 1;
			cout << ans << "\n";
		}
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

	int t = 1;
	// cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}