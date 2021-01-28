/*
	Author : legend_is_born
	Created On : 04/01/2021 21:02:57
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

bool cmp(array < int, 3 > x, array  < int, 3 > y){
	if(x[1] < y[1]) return true; else if(x[1] > y[1]) return false;
	if(x[2] < y[2]) return true; else if(x[2] > y[2]) return false;
	return x[0] < y[0];
}

void solve(){
	// int n; cin >> n;
	// for(auto x : ans) cout << x+1 << ' ';
	// print();
	int n; cin >> n;
	map < int, int > mp;
	vector < int > ans(n +  3);
	vector < pair < int, int > > store;
	multiset < pair < int, int > > mult;
	vector < int > a(n), b(n);
	vector < array < int, 3 > > arr(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i];
		mp[a[i]]++, mp[b[i]]++;
		arr.pb({b[i], a[i], i + 1});
		arr.pb({a[i], b[i], i + 1});
	} 
	for(int i = 0; i < n + 3; i++) ans[i] = -1;
	sort(all(arr));
	ll temp_store = -1;
	// for(int i = n - 1; i > 0; i--){
	// 	if(arr[i][1] > arr[0][1] && arr[i][2] > arr[0][2]) {ans[i] = arr[0][0]; continue; }
	// 	int i2 = i - 1;
	// 	while(arr[i][1] > arr[i2][2] && i2 > 0){
	// 		if(arr[i][2] > arr[i2][1]){
	// 			ans[i] = arr[i2][0];
	// 			break;
	// 		}
	// 		i2--;
	// 	}
	for(auto x : arr){
		int fir = x[0];
		int sec = x[1];
		ll idx = x[2];
		if(mult.size() > 0){
			auto it = mult.lower_bound(MP(sec, -1LL));
			if(it != mult.begin()) it--, ans[idx] = (*it).second;
		}
		// vector < array < int, 3 > > arr(n);
		// for(int i = 0; i < n; i++) {cin >> arr[i][1] >> arr[i][2]; arr[i][0] = i;}
		// sort(all(arr), cmp);
		// vector < int > ans(n);
		// 	if(i2 == 0) ans[i] = -2;
		// }
		store.pb(MP(sec, idx));
		mp[fir]--;
		if(mp[fir] == 0){
			temp_store = fir;
			while(store.size() > 0){
				mult.insert(store.back());
				store.pop_back();
			}
		}
	}
	for(int i = 1; i <= n; i++) if(ans[i] <= 0) cout << -1 << ' '; else cout << ans[i] << ' ';
	print();
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	int t = 1;
	cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}