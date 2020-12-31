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

const int mxN = 5e5 + 10;
vector < int > par(mxN), cnt(mxN), res(mxN);
ll xtotal = 0;
ll cur = 1;

int find(int u){
	if(par[u] == u) return u;
	return par[u] = find(par[u]);
}

void solveD(){
	// int n; cin >> n;
	// for(int i = 0; i <= n; i++) g[i].clear();
	// vector < int > w(n); read(w);
	// for(int i = 0; i < n - 1; i++){
	// 	int x, y; cin >> x >> y;
	// 	x--; y--;
	// 	g[x].pb(y); g[y].pb(x);
	// }
	// sort(all(w));
	// vector < ll > ans(n - 1, 0);
	ll res = 0;
	ll arr[200015], cnt[200015] = {0};
	ll n; cin >> n;
	multiset < ll > s;
	ll i = 1;
	while(i <= n){
		cin >> arr[i];
		res += arr[i];
		i++;
	}
	i = 1;
	while(i < n){
		int x, y; cin >> x >> y;
		cnt[x]++; cnt[y]++;
		if(cnt[x] > 1) s.insert(arr[x]);
		if(cnt[y] > 1) s.insert(arr[y]);
		i++;
	}
	cout << res << ' ';
	for(auto itr = s.rbegin(); itr != s.rend(); itr++){
		res += *itr;
		cout << res << ' ';
	}
	cout << '\n';
}

void solve(){
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++) par[i] = i;
	for(int i = 1; i <= n; i++){
		int choice; cin >> choice;
		if(choice == 1){
			int idx; cin >> idx;
			idx = find(idx);
			if(cnt[idx]) continue;
			else {
				cnt[idx] = 1;
				cur = cur * 2 % MOD;
				res[++xtotal] = i;
			}
		}
		else {
			int p, q; cin >> p >> q;
			p = find(p);
			q = find(q);
			if(p == q) continue;
			else {
				if(cnt[p] && cnt[q]) continue;
				else if(cnt[p] == 0 && cnt[q] == 0){
					par[p] = q;
					cur = cur * 2 % MOD;
					res[++xtotal] = i;
				}
				else {
					par[p] = q;
					cnt[q] = 1;
					cur = cur * 2 % MOD;
					res[++xtotal] = i;
				}
			}
		}
	}
	cout << cur << ' ' << xtotal << '\n';
	for(int i = 1; i <= xtotal; i++){
		cout << res[i] << ' ';
	}
	cout << '\n';
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