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

const int mxN = 1e6 + 10;
vector < int > g[mxN];
vector < ll > vec;
const int MOD = 1e9 + 7;
int n, m;
int a[mxN], sz[mxN];

void dfs(int v, int p){
	sz[v] = 1;
	for(int  x : g[v]){
		if(x != p){
			dfs(x, v);
			sz[v] += sz[x];
		}
	}
	if(p != 0){
		vec.push_back(1LL * sz[v] * (n - sz[v]));
	}
}

void solve(){
	cin >> n;
	vec.clear();
	for(int i = 1; i <= n; i++){
		g[i].clear();
	}
	for(int i = 1; i <= n - 1; i++){
		int x, y;
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin >> m;
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	sort(a + 1,  a + m + 1);
	while(m > n - 1) a[m - 1] = (1LL * a[m - 1] * a[m])  % MOD, m--;
	dfs(1, 0);
	sort(all(vec));
	int tot = 0;
	for(int i = n - 2; ~i; i--){
		if(m == 0){
			tot = (tot + vec[i]) % MOD;
		}
		else{
			tot = (tot + 1LL * vec[i] % MOD * a[m]) % MOD;
			m--;
		}
	}
	cout << tot << "\n";
	return ;
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