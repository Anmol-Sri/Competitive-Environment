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

void solve(){
	ll n, x; cin >> n;
	vector<ll> line[n][2];
	map <ll, ll> collision;
	ll res = 0;
	if(n == 1)
	{
		cin >> x;
		ll positive = 0,negative = 0;
		for(ll i = 0; i < x; i++){
			ll storeants; cin >> storeants;
			if(storeants < 0) negative += 1; else positive += 1;
		}
		print(negative * positive);
		return ;
	}
	for(ll i = 0; i < n; i++){
		cin >> x;
		for(ll iter = 0; iter < x; iter++){
			ll storeants; cin >> storeants;
			collision[abs(storeants)]++;
			if(collision[abs(storeants)] == 2) res += 1;
			int j = 1;
			if(storeants < 0) j = 0;
			line[i][j].pb(storeants);
		}
		reverse(all(line[i][0]));
	}
	for(ll i = 0; i < n; i++){
		map <ll, ll > m;
		vector < ll > storeants;
		ll count = sz(line[i][0]);
		for(ll j = 0; j < sz(line[i][0]); j++){
			if(collision[abs(line[i][0][j])] > 1){
				m[abs(line[i][0][j])] = 1;
				res += (count - j - 1);
			}
		}
		for(ll k = 0, j = 0; j < sz(line[i][1]); ){
			if(k >= sz(line[i][0])){
				if(collision[line[i][1][j]] > 1){
					storeants.pb(line[i][1][j]);
					res += (line[i][1].size() - 1 - j);
				}
				else res += count;
				j++;
			}
			else if(abs(line[i][0][k]) <= line[i][1][j]){
				if(m[-line[i][0][k]]) count--;
				k++;
			}
			else {
				if(collision[line[i][1][j]] > 1){
					storeants.pb(line[i][1][j]);
					res += (line[i][1].size() - 1 - j);
				}
				else res += count;
				j++;
			}
		}
		count = 0;
		for(ll j = 0, k = 0; k != sz(storeants); j++){
			if(j >= sz(line[i][0])){
				res += count;
				k++;
				continue;
			}
			while(k != sz(storeants) && abs(line[i][0][j]) > storeants[k]){
				res += count;
				k++;
			}
			count++;
			if(collision[-line[i][0][j]] > 1) count--;
		}
	}
	print(res);
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
	cin >> t;

	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}

