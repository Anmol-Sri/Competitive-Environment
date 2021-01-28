/*
	Author : redarch
	Created On : 24/01/2021 16:24:37
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

void solve(){
	int n; cin >> n;
	vector < int > arr(n); read(arr); sort(all(arr));
	if(n == 1){
		print(-1); return;
	}
	if(n == 2){
		int d = arr[1] - arr[0];
		if(d == 0){
			print(1);
			print(arr[0]);
		}
		else if(d % 2 == 0){
			print(3);
			print(arr[0] - d, arr[0] + d/2,  arr[1] + d);
		}
		else{
			print(2);
			print(arr[0] - d, arr[1] + d);
		}
		return;
	}
	set < int > s;
	vector < int > d;
	map < int, int > mp;
	for(int i = 1; i < n; i++){
		s.insert(arr[i] - arr[i - 1]);
		mp[arr[i] - arr[i - 1]]++;
	}
	for(auto x : s) d.pb(x);
	if(d.size() == 1){
		if(d[0] == 0){
			print(1);
			print(arr[0]);
			return;
		}
		print(2);
		print(arr[0] - d[0], arr.back() + d[0]);
		return;
	}
	if(d.size() == 2){
		// db(d);
		int more, less;
		tie(more, less) = mp[d[0]] >= mp[d[1]] ? mt(d[0], d[1]) : mt(d[1], d[0]);
		if(mp[less] == 1 && less == more * 2){
			print(1);
			for(int i = 1; i < n; i++){
				if(arr[i] - arr[i - 1] == less){
					print(arr[i - 1] + more);
					return;
				}
			}
		}
		else{
			print(0);
		}
		return;
	}
	print(0);

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