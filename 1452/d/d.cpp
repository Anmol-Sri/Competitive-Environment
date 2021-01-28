/*
	Author : legend_is_born
	Created On : 03/12/2020 21:02:24
*/

#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define MP make_pair
#define ar array
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define db2d(arr) for(auto x : arr){ for(auto y : x) cout << y << " "; cout << "\n";}
#define read(arr) for(auto &x : arr) cin >> x;
#define sz(x) (int)x.size()
#define MOD 1000000007
#define MOD2 998244353
using namespace std;
 
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// #define ordered_set_int tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
// #define ordered_set_ll tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update> 
// order_of_key (k) : Number of items strictly smaller than k 
// find_by_order(k) : K-th element in a set (counting from zero)
 
void dbvar() { cerr << "]" << endl; }
template<class H, class... T> void dbvar(H h, T... t){
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	dbvar(t...);
}
 
const int INF = (int)(1e9);
const ll INFL = (ll)(1e18);
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
 
ll power(ll n,ll m){
	if(m==0) return 1;
	ll val=power(n,m/2);
	if(m%2==0) return (val*val); else return ((val*val)*n);
}
 
ll powermod(ll n,ll m,ll _MOD){
	if(m==0) return 1;
	ll val=powermod(n,m/2,_MOD);
	val %= _MOD;
	if(m%2==0) return (val*val) % _MOD; else return (((val*val) % _MOD) * n) % _MOD;
}
 
void solve(){
	ll n; cin >> n;
	vector < ll > fib(n+1);
	fib[0] = 0; fib[1] = 1;
	for(int i = 2; i <= n; i++){
		fib[i] = (fib[i - 2] + fib[i - 1]) % MOD2;
	}
	cout << (fib[n] * powermod(powermod((ll)2ll, n, MOD2), (ll)MOD2 - 2ll, MOD2)) % MOD2;
}
 
int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
 
	int t = 1;
	// cin >> t;
 
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}
 
	return 0;
}