#include <bits/stdc++.h>
#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()
#define mem(arr,x) memset(arr, x, sizeof arr)
#define db(arr) for(auto x : arr) cout << x << " "; cout << "\n";
using namespace std;

// #include <ext/pb_ds/tree_policy.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

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
	vector < vector < ll > > g(n, vector < ll > (n, 0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if((i - j + n) & 2) g[i][j] = (1LL << (i + j));
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
	int q;
	cin >> q;
	while(q--){
		ll s;
		cin >> s;
		cout << "1 1" << endl;
		int r = 0, c= 0;
		for(int i = 0;  i < 2 * n - 2; i++){
			ll chk = s & (1LL << (i + 1));
			if(r + 1 < n && g[r + 1][c] == chk) r++;
			else c++;
			cout << r + 1 << " " << c + 1 << endl;
		}
	}
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