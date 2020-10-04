#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define endl "\n"
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

const int mxN = 1e6;
void solve(){
	auto square = [&](ll x){
		ll k = sqrtl(x);
		return k * k == x;
	};
	set < ll > s;
	ll l, r, val, i, q, k;
	for(i = 2; i <= mxN; i++){
		int op = 18.0 / log10(i);
		val = 1LL * i * i;
		for(k = 3; k <= op; k++){
			val *= i;
			if(!square(val)) s.insert(val);
		}
	}
	vector < ll > v(all(s));
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		ll a = floor(sqrtl(r));
		ll b = ceil(sqrtl(l));
		ll ans1 = upper_bound(all(v), r) - lower_bound(all(v), l);
		ll ans2 = a  - b + 1;
		cout << ans1 + ans2 << endl;
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