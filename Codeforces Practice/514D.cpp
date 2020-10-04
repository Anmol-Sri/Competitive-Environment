#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define ar array
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define db2d(arr) for(auto x : arr){ for(auto y : x) cout << y << " "; cout << "\n";}
#define read(arr) for(auto &x : arr) cin >> x;
#define nl "\n"
#define sz(x) (int)x.size()
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
// order_of_key (k) : Number of items strictly smaller than k 
// find_by_order(k) : K-th element in a set (counting from zero)

const ll inf = (ll)1e18;
const int mod = (ll)1e9 + 7;
const ld eps = (ld)1e-9;
const ld pi = acos(-1.0);
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int d8x[8]={-1, -1, 0, 1, 1, 1, 0, -1};
const int d8y[8]={0, 1, 1, 1, 0, -1, -1, -1};

ll power(ll n,ll m){
	if(m==0) return 1;
	ll val=power(n,m/2);
	if(m%2==0) return (val*val); else return ((val*val)*n);
}

ll powermod(ll n,ll m,ll MOD){
	if(m==0) return 1;
	ll val=powermod(n,m/2,MOD);
	val %= MOD;
	if(m%2==0) return (val*val) % MOD; else return (((val*val) % MOD) * n) % MOD;
}

struct segment_tree{
	int n;
	vector <  int > v;
	segment_tree(int _n){
		for(n = 1; n < _n; n *= 2);
		v = vector < int > (n * 2 - 1, 0);
	}
	void set(int i, int x){
		int k = i + n - 1;
		v[k] = x;
		while(k > 0){
			k = (k - 1) / 2;
			v[k] = max(v[k * 2 + 1], v[k * 2 + 2]);
		}
	}
	int _get(int i, int j, int k, int l, int r){
		if(r <= i || j <= l) return 0;
		if(i <= l && r <= j) return v[k];
		int vl = _get(i, j, k * 2 + 1, l, (l + r) / 2);
		int vr = _get(i, j, k * 2 + 2, (l + r) / 2, r);
		return max(vl, vr);
	}
	int get(int i, int j){
		return _get(i, j, 0, 0, n);
	}
};

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	vector < segment_tree > st(m, segment_tree(n));
	for(int i = 0; i < n; i++){
		for(int j = 0;  j < m; j++){
			int x;
			cin >> x;
			st[j].set(i, x);
		}
	}
	int mxi = 0;
	vector < int > ans(m);
	int r = 0;
	for(int l = 0; l <= n; l++){
		while(true){
			if(r + 1 > n) break;
			int sum = 0;
			for(int j = 0; j < m; j++) sum += st[j].get(l, r + 1);
			if(sum > k) break;
			r++;
		}
		if(r - l > mxi){
			mxi = r - l;
			for(int j = 0; j < m; j++) ans[j] = st[j].get(l, r);
		}
	}
	for(int i = 0; i < m; i++) cout << ans[i] << " ";	
	cout << nl;
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