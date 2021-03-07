/*
	Author : _reyna_
	Created On : 06/03/2021 19:50:14
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

void solve(){
	int h, m; cin >> h >> m;
	string s; cin >> s;
	int inv[] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};
	auto convert = [&](int n) -> string{
		string q = "";
		string check = to_string(n);
		for(int i = 0; i < check.size(); i++){
			int d = (check[i] - '0');
			if(inv[d] == -1) return "";
			q += to_string(inv[d]);
		}
		for(int i = q.size(); i < 2; i++) q += '0';
		reverse(all(q));
		return q;
	};
	int x = stoi(s.substr(0, 2));
	string hour = "", min = "";
	string HH = "", MM = "";
	for(int i = x; i < h; i++){
		string cur = convert(i);
		if(cur == "") continue;
		int c = stoi(cur);
		if(c < h && c < m){
			hour = cur;
			break;
		}
	}
	if(hour == "" || stoi(hour) < x){
		HH = "00";
	}
	else{
		HH = hour;
	}
	int y = stoi(s.substr(3, 2));
	for(int i = y; i < m; i++){
		string cur = convert(i);
		if(cur == "") continue;
		int c = stoi(cur);
		if(c < h && c < m){
			min = cur;
			break;
		}
	}
	if(min == "" || stoi(min) < y || s.substr(0, 2) != HH){
		MM = "00";
	}
	else{
		MM = min;
	}
	// auto near = [&](char ch){
	// 	int d = ch - '0';
	// 	bool ok = false;
	// 	for(int i = d; i < 10; i++){
	// 		if(inv[i] != -1) return i;
	// 	}
	// 	for(int i = 0; i < d; i++){
	// 		if(inv[i] != -1) return i;
	// 	}
	// 	return -1;
	// };
	// int hour = 0, min = 0;
	// for(int i = 0; i < 2; i++){
	// 	int d = near(s[i]);
	// 	if(hour != 0) hour = hour * 10 + d;
	// 	else hour = d;
	// }
	// if(hour < m && hour < h);
	// else hour = 0;
	// string HH = "", MM = "";
	// if(hour < stoi(s.substr(0, 2)) || hour == 0){
	// 	HH = "00";
	// }
	// else{
	// 	while(hour){
	// 		int d = hour % 10;
	// 		HH += to_string(d);
	// 		hour = hour / 10;
	// 	}
	// 	if(HH.size() < 2){
	// 		for(int i = 0; i < 2 - HH.size(); i++) HH += '0';
	// 		// print("error");
	// 	}
	// 	reverse(all(HH));
	// }
	// for(int i = 3; i < 5; i++){
	// 	int d = near(s[i]);
	// 	if(min != 0) min = min * 10 + d;
	// 	else min = d;
	// }
	// if(min < h && min < m);
	// else min = 0;
	// if(to_string(HH) != s.substr(0, 2) || min == 0 || min < stoi(s.substr(3, 2))){
	// 	MM = "00";
	// }
	// else{
	// 	while(min){
	// 		int d = min % 10;
	// 		MM += to_string(d);
	// 		min = min / 10;
	// 	}
	// 	if(MM.size() < 2){
	// 		for(int i = 0; i < 2 - MM.size(); i++) MM += '0';
	// 	}
	// 	reverse(all(MM));
	// }
	cout << HH << ':' << MM << '\n';
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