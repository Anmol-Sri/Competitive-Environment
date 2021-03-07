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

/*
	0 2
	1 5 9 10 1 3 15
	1 1 3 5 9 10 15
	
	1 2
	1 2 7 7 9 10 11 20 26
*/
/*
	cars - i1 i2 i3... in
	i1 = x
	i2 = x + y
	i3 = x + y + z;
	..
	in = x = y + ...+ z
*/
void solve(){
	ll d, I, s, v, f; cin >> d >> I >> s >> v >> f;
	unordered_map < string , int > m;
	vector < pair < pair < ll, ll >, ll > > street(s);
	unordered_map < ll, vector < string > > intersection;
	for(int i = 0; i < s; i++){
		ll b, e; cin >> b >> e;
		string name; cin >> name;
		ll l; cin >> l;
		m[name] = i;
		street[i] = MP(MP(b, e), l);
		intersection[e].pb(name);
	}
	// for(auto x : intersection){
	// 	print(x.first); db(x.second);
	// }
	vector < vector < string > > cars(v);
	for(int i = 0; i < v; i++){
		ll p; cin >> p;
		for(int j = 0; j < p; j++){
			string x; cin >> x;
			cars[i].pb(x);
		}
	}
	unordered_map < string , vector < ll > > cnt;
	for(int i = 0; i < v; i++){
		cnt[cars[i][0]].pb(1);
		ll temp = street[m[cars[i][1]]].second + 1;
		cnt[cars[i][1]].pb(temp);
		for(int j = 2; j < (ll)(cars[i].size()) - 1; j++){
			temp += street[m[cars[i][j]]].second;
			cnt[cars[i][j]].pb(temp + 1);
		}
	}
	// for(auto x : cnt){
	// 	print(x.first); db(x.second);
	// }
	unordered_map < string, ll > dif;
	for(auto &x : cnt){
		vector < ll > arr = x.second;
		sort(all(arr));
		ll mx = arr[0];
		ll sum = 0;
		for(int i = 1; i < sz(arr); i++){
			// mx = max(mx, x.second[i] - x.second[i - 1]);
			sum += arr[i] - arr[i - 1];
		}
		mx = sum/(ll)arr.size();
		// mx = max(arr[0], arr.back() - arr[0]);
		dif[x.first] = max(mx, 1LL);
	}
	// for(auto x : dif){
	// 	print(x.first, x.second);
	// }
	ll ans = 0;
	vector < vector < pair < string, ll > > > res(I);

	for(auto x : intersection){
		bool ok = false;
		for(auto y : x.second){
			if(dif.count(y) > 0){
				if(!ok){ ans++; ok = true; }
				res[x.first].pb(MP(y, dif[y]));
			}
		}
	}

	print(ans);
	for(int i = 0; i < I; i++){
		if(res[i].size() > 0){
			print(i);
			print(res[i].size());
			for(auto x : res[i]){
				// print(x.first, max(x.second, ((d + (ll)res[i].size() - 1)/(ll)res[i].size())));
				print(x.first, x.second);
				// print(x.first, d);
			}
		}
	}
	/*
		10
		1 - a b c
			20 10 5
			
			3.3 3.3 3.3
	*/
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("f.txt","r",stdin);
		freopen("fout5.txt","w",stdout);
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