// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const ll INFL = (ll)1e18;
const int INF = (int)1e9;
const ld eps = (ld)1e-9;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const vector<pair<int, int>> DXY = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

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

// const ll mxN = 2e7 + 10;
// vector < ll > mindiv(mxN, -1), numdiv(mxN);
// void sieve(){
// 	// mindiv -> stores the minimum prime divisor of a number
// 	// numdiv -> stores the number of unique prime divisor of a number
// 	mindiv[1] = 1;
// 	for(ll i = 2; i < mxN; i++) if(mindiv[i] == -1) for(ll j = i; j < mxN; j += i) if(mindiv[j] == -1) mindiv[j] = i;
// 	for(ll i = 2; i < mxN; i++){
// 		ll j = i / mindiv[i];
// 		numdiv[i] = numdiv[j] + (mindiv[i] != mindiv[j]); // 
// 	}
// }

//Uses both path compression and union by rank
struct UnionFind {
	vector < ll > p, rank, setSize;
	ll numSets;
    public : 
	UnionFind(ll N){
        numSets = N;
        p.resize(N);
		rank.resize(N);
		setSize.resize(N);
		for (ll i = 0; i < N; i++) {  p[i] = i; setSize[i] = 1; }
	}
	int findSet(ll i) { return p[i] == i ? i : (p[i] = findSet(p[i])); }
	bool isSameSet(ll i, ll j) { return findSet(i) == findSet(j); }
	void unionSet(ll i, ll j){ 
		if (isSameSet(i, j)) return;
		numSets--; 
		ll x = findSet(i), y = findSet(j);
		if(rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
		else{
            p[x] = y; setSize[y] += setSize[x];
			if(rank[x] == rank[y]) rank[y]++; 
		} 
	}
	ll numDisjointSets() { return numSets; }
	ll sizeOfSet(ll i) { return setSize[findSet(i)]; }
};

const int mxN = 1e5 + 100;
vector < ll > dp(mxN);
void solve(){
	ll n, k; cin >> n >> k;
	dp[0] = 1;
	for(ll i = 1; i < mxN; i++) if(i >= k) dp[i] = (dp[i - k] + dp[i - 1]) % MOD; else dp[i] = dp[i - 1];
	for(ll i = 1; i < mxN; i++) dp[i] = (dp[i -  1] + dp[i]) % MOD;
	while(n--){
		ll a, b; cin >> a >> b;
		print((dp[b] - dp[a - 1] + MOD) % MOD);
	}
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	// cout << setprecision(10) << fixed;
	
	int t = 1;
	// cin >> t >> k;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}