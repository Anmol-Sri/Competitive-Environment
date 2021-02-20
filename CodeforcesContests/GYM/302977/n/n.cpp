/*
	Author : redarch
	Created On : 07/02/2021 18:08:55
*/

#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define MP make_pair
#define mt make_tuple
#define eb emplace_back
#define ar array
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define db2d(arr) for(auto x : arr){ for(auto y : x) cout << y << " "; cout << "\n";}
#define read(arr) for(auto &x : arr) cin >> x;
#define sz(x) (int)x.size()
#define MOD 1000000007
#define MOD2 998244353
#define nl '\n'
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k 
// find_by_order(k) : K-th element in a set (counting from zero)

string to_string(char c) {
	return string(1, c);
}

string to_string(bool b) {
	return b ? "true" : "false";
}

string to_string(const char* s) {
	return string(s);
}

string to_string(string s) {
	return s;
}

string to_string(vector < bool > v) {
	string res;
	for(int i = 0; i < sz(v); i++)
		res += char('0'+v[i]);
	return res;
}
 
template < size_t S > string to_string(bitset < S > b) {
	string res;
	for(int i = 0; i < S; i++)
		res += char('0' + b[i]);
	return res;
}

template < class T > string to_string(T v) {
    bool f = 1;
    string res;
    for(auto x : v) {
		if(!f)
			res+=' ';
		f=0;
		res += to_string(x);
	}
    return res;
}
 
void dbvar() { cerr << "]" << endl; }
template<class H, class... T> void dbvar(H h, T... t){
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	dbvar(t...);
}

template<class A> void write(A x) {
	cout << to_string(x);
}

template<class H, class... T> void write(const H& h, const T&... t) { 
	write(h);
	write(t...);
}

void print() {
	write("\n");
}

template<class H, class... T> void print(const H& h, const T&... t) { 
	write(h);
	if(sizeof...(t))
		write(' ');
	print(t...);
}

const ll INFL = (ll)1e18;
const int INF = (int)1e9;
const ld eps = (ld)1e-9;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

ll power(ll n, ll m){
	if(m == 0) return 1;
	ll val = power(n, m/2);
	if(m % 2 == 0) return (val * val); else return ((val * val) * n);
}

ll powermod(ll n, ll m, ll _MOD){
	if(m == 0) return 1;
	ll val = powermod(n,m/2,_MOD);
	val %= _MOD;
	if(m % 2 == 0) return (val * val) % _MOD; else return (((val * val) % _MOD) * n) % _MOD;
}

ll dp[(1 << 16) + 1][16][16], cost[16][16], cost2[16][16];
void solve(){
	int n, m; cin >> n >> m;
	ll arr[n][m];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> arr[i][j];
	ll cost[16][16];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cost[i][j] = INFL;
			cost2[i][j] = INFL;
			for(int k = 0; k < m; k++) cost[i][j] = min(cost[i][j], abs(arr[i][k] - arr[j][k]));
			for(int k = 0; k < m - 1; k++) cost2[i][j] = min(cost2[i][j], abs(arr[i][k] - arr[j][k + 1]));
		}
	}
	for(int i = 0; i < n; i++) dp[(1 << i)][i][i] = INT_MAX;
	for(ll mask = 1; mask < (1 << n) - 1; mask++){
		for(ll i = 0; i < n; i++){
			for(ll j = 0; j < n; j++){
				int bits = __builtin_popcount(mask);
				if(bits == 1 || i != j){
					if((mask & (1 << i))){
						if(mask & (1 << j)){
							for(ll k = 0; k < n; k++){
								if(!((mask & (1 << k)))){
									ll mask2 = mask | (1 << k);
									ll val = cost[j][k];
									ll val2 = min(dp[mask][i][j], val);
									dp[mask2][i][k] = max(dp[mask2][i][k], val2);
								}
							}
						}
					}
				}
			}
		}
	}
	ll ans = 0;
	for(ll i = 0; i < n; i++){
		for(ll j = 0; j < n; j++){
			ans = max(ans, min(dp[(1 << n) - 1][i][j], cost2[i][j]));
		}
	}
	print(ans);
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	// cout << setprecision(10) << fixed;
	
	int t = 1;
	// cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}