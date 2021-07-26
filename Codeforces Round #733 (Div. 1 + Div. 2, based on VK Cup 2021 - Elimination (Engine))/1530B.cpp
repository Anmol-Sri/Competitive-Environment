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

void solve(){
	int n, m; cin >> n >> m;
    // int s1[n][m], s2[n][m];
    vector < vector < int > > s1(n, vector < int > (m, -1));
    vector < vector < int > > s2(n, vector < int > (m, -1));
    vector < vector < int > > s3(n, vector < int > (m, -1));
    vector < vector < int > > s4(n, vector < int > (m, -1));
    vector < vector < int > > s5(n, vector < int > (m, -1));
    vector < vector < int > > s6(n, vector < int > (m, -1));
    auto calc = [&](int x, int y, vector < vector < int > > a){
        if(!(x == 0 || y == 0 || x == n - 1 || y == m - 1)) return 0;
        if(x - 1 >= 0 && a[x - 1][y] == 1) return 0;
        if(y - 1 >= 0 && a[x][y - 1] == 1) return 0;
        if(x + 1 < n && a[x + 1][y] == 1) return 0;
        if(y + 1 < m && a[x][y + 1] == 1) return 0;
        if(x - 1 >= 0 && y - 1 >= 0 && a[x - 1][y - 1] == 1) return 0;
        if(x - 1 >= 0 && y + 1 < m && a[x - 1][y + 1] == 1) return 0;
        if(x + 1 < n && y - 1 >= 0 && a[x + 1][y - 1] == 1) return 0;
        if(x + 1 < n && y + 1 < m && a[x + 1][y + 1] == 1) return 0;
        return 1;
    };
    s1[0][0] = 1;
    s2[0][1] = 1;
    s3[1][0] = 1;
    s4[n - 1][0] = 1;
    s5[0][m - 1] = 1;
    s6[n - 1][m - 1] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s1[i][j] == -1) s1[i][j] = calc(i, j, s1);
            if(s2[i][j] == -1) s2[i][j] = calc(i, j, s2);
            if(s3[i][j] == -1) s3[i][j] = calc(i, j, s3);
        }
        for(int j = m - 1; ~j; j--){
            if(s5[i][j] == -1) s5[i][j] = calc(i, j, s5);
        }
    }
    for(int i = n - 1; ~i; i--){
        for(int j = m - 1; ~j; j--){
            if(s6[i][j] == -1) s6[i][j] = calc(i, j, s6);
        }
        for(int j = 0; j < m - 1; j++){
            if(s4[i][j] == -1) s4[i][j] = calc(i, j, s4);
        }
    }
    vector < int > cnt(7, 0);
    int mxi = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cnt[1] += s1[i][j];
            cnt[2] += s2[i][j];
            cnt[3] += s3[i][j];
            cnt[4] += s4[i][j];
            cnt[5] += s5[i][j];
            cnt[6] += s6[i][j];
        }
    }
    for(int i = 0; i < 7; i++) if(cnt[i] > cnt[mxi]) mxi = i;
    map < int, vector < vector < int > > > mp;
    mp[1] = s1;
    mp[2] = s2;
    mp[3] = s3;
    mp[4] = s4;
    mp[5] = s5;
    mp[6] = s6;
    vector < vector < int > > ans = mp[mxi];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) cout << ans[i][j];
        cout << endl;
    }
    cout << endl;
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	// cout << setprecision(10) << fixed;
	
	int t = 1;
	cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}