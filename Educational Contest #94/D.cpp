#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define ar array
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
#define read(arr) for(auto &x : arr) cin >> x;
#define nl "\n"
#define sz(x) (int)x.size()
using namespace std;

 
// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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

void solve(){
	int n;
	cin >> n;
	vector < int > a(n);
	read(a);
	vector < int > left(n + 100);
	ll ans = 0;
	for(int l = 0; l < n; l++){
		vector < int > right(n + 100);
		for(int r = n - 1; r > l; r--){
			ans += left[a[r]] * right[a[l]];
			right[a[r]]++;
		}
		left[a[l]]++;
	}
	cout << ans << nl;
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