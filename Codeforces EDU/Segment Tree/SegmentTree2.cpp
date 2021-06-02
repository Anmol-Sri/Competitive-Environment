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

template <typename T1, typename T2>
constexpr typename std::common_type<T1, T2>::type floor_div(T1 x, T2 y) {
	assert(y != 0);
	if (y < 0) x = -x, y = -y;
	return x < 0 ? (x - y + 1) / y : x / y;
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

struct SegTree{

	vector < pair < ll, ll > > arr;
	ll size;
	pair < ll, ll > NEUTRAL_ELEMENT = MP(INFL, 0);

	pair < ll, ll > merge(pair < ll,  ll > x, pair < ll, ll > y){
		if(x.first < y.first) return x;
		if(x.first > y.first) return y;
		return MP(x.first, x.second + y.second);
	}

	void init(ll n){
		size = 1;
		while(size < n) size *= 2;
		arr.resize(2 * size);
	}

	void build(vector < ll >&a, ll x, ll lx, ll rx){
		if(rx - lx == 1){
			if(lx < sz(a)) arr[x] = MP(a[lx], 1);
			return;
		}
		ll m = (lx + rx) / 2;
		build(a, 2 * x + 1, lx, m);
		build(a, 2 * x + 2, m, rx);
		arr[x] = merge(arr[2 * x + 1], arr[2 * x + 2]);
	}

	void build(vector < ll > &a){
		build(a, 0, 0, size);
	}

	void set(ll i, ll v, ll x, ll lx, ll rx){
		if(rx - lx == 1){
			arr[x] = MP(v, 1);
			return;
		}
		ll m = (lx + rx) / 2;
		if(i < m) set(i, v, 2 * x + 1, lx, m);
		else set(i, v, 2 * x + 2, m, rx);
		arr[x] = merge(arr[2 * x + 1], arr[2 * x + 2]);
	}

	void set(ll i, ll v){
		set(i, v, 0, 0, size);
	}

	pair < ll, ll > calc(ll l, ll r, ll x, ll lx, ll rx){
		if(lx >= r || rx <= l) return NEUTRAL_ELEMENT;
		if(lx >= l && rx <= r) return arr[x];
		ll m = (lx + rx) / 2;
		pair < ll, ll > a = calc(l, r, 2 * x + 1, lx, m);
		pair < ll, ll > b = calc(l, r, 2 * x + 2, m, rx);
		return merge(a, b);

	}

	pair < ll, ll > calc(ll l, ll r){
		return calc(l, r, 0, 0, size);
	}
};

void solve(){
	ll n, m; cin >> n >> m;
	vector < ll > arr(n); read(arr);
	SegTree st;
	st.init(n);
	st.build(arr);
	while(m--){
		ll o, x, y; cin >> o >> x >> y;
		if(o == 1) st.set(x, y);
		else{
			auto store = st.calc(x, y);
			print(store.first, store.second);
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

	// cout << setprecision(10) << fixed;
	
	int t = 1;
	// cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}