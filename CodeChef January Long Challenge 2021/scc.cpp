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
#define nl '\n'
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// template <typename T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (k) : Number of items strictly smaller than k 
// find_by_order(k) : K-th element in a set (counting from zero)

void dbvar() { cerr << "]" << endl; }
template<class H, class... T> void dbvar(H h, T... t){
	cerr << to_string(h);
	if(sizeof...(t))
		cerr << ", ";
	dbvar(t...);
}

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

ll modInverse(ll n, ll _MOD)
{
	if (_MOD == 1) return 0;
	ll store_mod = _MOD;
	ll y = 0, x = 1;
	while (n > 1){
		ll q = n / _MOD;
		ll t = _MOD;
		_MOD = n % _MOD, n = t;
		t = y;
		y = x - q * y;
		x = t;
	}
	if (x < 0) x += store_mod;
	return x;
}

ll mult(ll x, ll y){
	return ((x * y) % MOD2);
}

ll add(ll x, ll y){
	return ((x + y) % MOD2);
}

const int mxN = 1e5 + 20;

void solve(){
	ll m, n, nt;
	cin >> m >> n >> nt;

	if(nt == 1){
		cout << 1;
		return;
	}

	vector < ll > p(2 * n + 5, 0);
	p[0] = 1;

	for(int i = 1; i < 2 * n + 5; i++){
		p[i] = mult(p[i - 1], nt);
	}

	if(m == 1){
		ll ans;
		vector < ll > dp(n + 5, 0);
		for(int i = n; i > 0; i--){
			dp[i] = add(dp[i + 1], mult(nt - 1, add(p[n - i], dp[i + 1])));
			if(i == 1){
				dp[i] = mult(nt, (add(p[n - 1], dp[2])));
				ans = dp[i];
				break;
			}
		}

		ll fir = powermod(nt, n * m, MOD2);
		ll sec = modInverse(fir, MOD2);
		print(mult(ans, sec));
		return ;
	}
	ll ans;
	vector < vector < ll > > dp(n + 5, vector< ll > (2, 0));
	for(int i = n; i > 0; i--)
	{
		int ind = 2 * (n - i);
		dp[i][1] = (mult(nt - 2, add(p[ind], dp[i+1][0])) + mult(2, dp[i + 1][0]) + dp[i + 1][1] + add(mult(2, p[ind]), dp[i + 1][1]) + mult(mult(nt - 1, nt - 2), add(mult(2, p[ind]), dp[i + 1][1])) + mult(mult(2, nt - 2), add(p[ind], dp[i + 1][1]))) % MOD2;
		dp[i][0] = (mult(mult(2, nt - 1), add(p[ind], dp[i+1][1])) + mult(mult(nt - 1LL, nt - 2LL), add(mult(2LL, p[ind]), dp[i+1][1])) + mult(nt-1, add(p[ind], dp[i+1][0])) + dp[i+1][0]) % MOD2;
		if(i == 1){
			dp[i][0] = mult(nt, add(p[ind], dp[2][0]));
			dp[i][1] = mult(mult(nt, nt - 1), add(mult(2, p[ind]), dp[2][1]));
			ans = add(dp[i][0], dp[i][1]);
			break;
		}
	}
	ll fir = powermod(nt, n * m, MOD2);
	ll sec = modInverse(fir, MOD2);
	print(mult(ans, sec));
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
