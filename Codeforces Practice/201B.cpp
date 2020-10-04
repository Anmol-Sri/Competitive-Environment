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

const int mxN = 1e3 + 10;
int n, m;
int a[mxN][mxN];
ll sumx[mxN], sumy[mxN];
ll costx[mxN], costy[mxN];

void solve(){
	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) cin >> a[i][j];
	for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) sumx[i] += a[i][j], sumy[j] += a[i][j];
	for(int i = 0; i <= n; i++) for(int j = 0; j < n; j++) costx[i] += sumx[j] * (2 * i - 2 * j - 1) * (2 * i - 2 * j - 1);
	for(int i = 0; i <= m; i++) for(int j = 0; j < m; j++) costy[i] += sumy[j] * (2 * i - 2 * j - 1) * (2 * i - 2 * j - 1);
	int ansx = int(min_element(costx, costx + n + 1) - costx);
	int ansy = int(min_element(costy, costy + m + 1) - costy);
	cout << 4 * (costx[ansx] + costy[ansy]) << nl << ansx << " " << ansy << nl;
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