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

const ll INFL = (ll)1e18;
const int INF = (int)1e9;
const ld eps = (ld)1e-9;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

ll power(ll n,ll m){
	if(m==0) return 1;
	ll val=power(n,m/2);
	if(m%2==0) return (val*val); else return ((val*val)*n);
}

ll powermod(ll n,ll m,ll _MOD){
	if(m==0) return 1;
	ll val=powermod(n,m/2,_MOD);
	val %= _MOD;
	if(m%2==0) return (val*val) % _MOD; else return (((val*val) % _MOD) * n) % _MOD;
}

const int mxN = 2e5 + 10;

ll powmod[70];
ll calc[63];

void solve(){
	ll n; cin >> n;
	vector < ll > totcount(n+1, 0);
	vector < ll > store(n + 1, 0);
	vector < ll > arr(n);
	vector< ll > countval(70, 0);
	ll i = 0;
	ll res = 0;
	while(i < n){
		cin >> arr[i];
		ll temp = arr[i];
		ll t1 = 0;
		while(temp > 0){
			countval[t1] += temp % 2;
			temp/=2;
			t1++;
		}
		i++;
	}
	i = 0;
	for(;i < n; i++){
		ll temp = arr[i];
		for(ll t1 = 0; t1 <= 61; t1++){
			if(temp & (calc[t1])){
				totcount[i] += (powmod[t1] * n) % MOD;
				if(totcount[i] >= MOD) totcount[i] -= MOD;
				continue;
			}
			totcount[i] += (powmod[t1] * countval[t1]) % MOD;
			if(totcount[i] >= MOD) totcount[i] -= MOD;
		}
	}
	i = 0;
	while(i < n){
		ll temp = arr[i];
		ll t1 = 0;
		while(t1 <= 61){
			if(calc[t1] & temp){
				store[i] += (powmod[t1] * countval[t1]) % MOD;
				if(store[i] >= MOD) store[i] -= MOD;
			}
			t1++;
		}
		i++;
	}
	i = 0;
	while(i < n){
		res += (totcount[i] * store[i]) % MOD;
		if(res >= MOD) res -= MOD;
		i++;
	}
	cout << res << "\n";
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

	calc[0] = 1;
	powmod[0] = 1;
	int i = 1;
	while(i < 63) {
		calc[i] = 2LL * calc[i - 1];
		i++;
	}

	i = 1;
	while(i < 66){
		powmod[i] = (2 * powmod[i - 1]) % MOD;
		i++;
	}

	for(i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}